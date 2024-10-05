#include "../include/NoteWindow.h"

WindowManager* WindowManager::instance = nullptr;

int NoteWindow::count = 0;

WindowManager* WindowManager::get_instance(){
    if(instance == nullptr){
        instance = new WindowManager;
    }
    return instance;
}

WindowManager::WindowManager (){};

void NoteWindow::hide() {
    Fl_Double_Window::hide();
    WindowManager::get_instance()->removeWindow(this);
}

void WindowManager::add_window(std::unique_ptr<NoteWindow> window){
    win_vec.push_back(std::move(window));
}

void WindowManager::removeWindow(NoteWindow* window) {
    win_vec.erase(std::remove_if(win_vec.begin(), win_vec.end(),
        [window](const auto& ptr) { return ptr.get() == window; }),
        win_vec.end());
}

void write_file(const std::string& content, const std::string& path) {
    std::ofstream file(path);
    if (!file.is_open()) {
        std::cerr << "Error: Unable to open file for writing: " << path << std::endl;
        return;
    }
    
    file << content;
    file.close();
}

void NoteColor::serialize(std::ofstream& out) const {
    out.write(reinterpret_cast<const char*>(&titlebar), sizeof(Fl_Color));
    out.write(reinterpret_cast<const char*>(&bg), sizeof(Fl_Color));
    out.write(reinterpret_cast<const char*>(&buttonDarker), sizeof(Fl_Color));
    out.write(reinterpret_cast<const char*>(&buttonLighter), sizeof(Fl_Color));
}

void NoteColor::deserialize(std::ifstream& in) {
    in.read(reinterpret_cast<char*>(&titlebar), sizeof(Fl_Color));
    in.read(reinterpret_cast<char*>(&bg), sizeof(Fl_Color));
    in.read(reinterpret_cast<char*>(&buttonDarker), sizeof(Fl_Color));
    in.read(reinterpret_cast<char*>(&buttonLighter), sizeof(Fl_Color));
}

void NoteMeta::serialize(std::ofstream& out) const {
    out.write(reinterpret_cast<const char*>(&pos_y), sizeof(int));
    out.write(reinterpret_cast<const char*>(&pos_x), sizeof(int));
    notecolor.serialize(out);
}

void NoteMeta::deserialize(std::ifstream& in) {
    in.read(reinterpret_cast<char*>(&pos_y), sizeof(int));
    in.read(reinterpret_cast<char*>(&pos_x), sizeof(int));
    notecolor.deserialize(in);
}

void NoteMeta::writeToFile(const std::string& filename) const {
    std::ofstream out(filename, std::ios::binary);
    if (out.is_open()) {
        serialize(out);
        out.close();
    }
}

NoteMeta NoteMeta::readFromFile(const std::string& filename) {
    NoteMeta meta;
    std::ifstream in(filename, std::ios::binary);
    if (in.is_open()) {
        meta.deserialize(in);
        in.close();
    }
    return meta;
}

NoteColor NoteWindow::get_color() const {
    return current_color;
}

void NoteWindow::draw_title_bar() {
    fl_color(current_color.titlebar);
    fl_rectf(0, 0, w(), TITLE_BAR_HEIGHT);
    
    fl_color(current_color.buttonDarker);
    fl_pie(10, 4, CLOSE_BUTTON_SIZE, CLOSE_BUTTON_SIZE, 0, 360);
    fl_color(current_color.buttonLighter);
    fl_line(13, 7, 6 + CLOSE_BUTTON_SIZE, CLOSE_BUTTON_SIZE);
    fl_line(13, CLOSE_BUTTON_SIZE, 6 + CLOSE_BUTTON_SIZE, 7);
}

bool NoteWindow::in_close_button(int x, int y) const {
    return x > 10 && x < 10 + CLOSE_BUTTON_SIZE &&
            y > 5 && y < CLOSE_BUTTON_SIZE + 5;
}

bool NoteWindow::in_resize_handle(int x, int y) const {
    return x > w() - RESIZE_HANDLE_SIZE && y > h() - RESIZE_HANDLE_SIZE;
}

// static void NoteWindow::changed_callback(int pos, int nInserted, int nDeleted, int nRestyled, const char* deletedText, void* v) {
//     (void)pos; (void)nInserted; (void)nDeleted; (void)nRestyled; (void)deletedText;
//     NoteWindow *w = static_cast<NoteWindow*>(v);
//     w->changed = true;
// }
NoteWindow::NoteWindow(int w, int h, const char* title)
    : Fl_Double_Window(w, h + TITLE_BAR_HEIGHT, title),
        dragging(false),
        resizing(false),
        current_color(YELLOW) {
    
    count++;
    number = count;
    this->resizable(this);
    color(current_color.bg);

    menubar = std::make_unique<Fl_Sys_Menu_Bar>(0, TITLE_BAR_HEIGHT + 1, w, 20);
    menubar->menu(menuitems);

    textbuf = std::make_unique<Fl_Text_Buffer>();
    textbox = std::make_unique<Fl_Text_Editor>(PADDING, TITLE_BAR_HEIGHT + PADDING, 
                                                w - 2*PADDING, h - TITLE_BAR_HEIGHT - 2*PADDING);
    textbox->buffer(textbuf.get());
    // textbuf->add_modify_callback(changed_callback, this);

    textbox->box(FL_FLAT_BOX);
    textbox->color(current_color.bg);
    textbox->textcolor(FL_BLACK);
    
    resizable(textbox.get());
}

void save_callback(Fl_Widget *widget, void *userdata) {
    NoteWindow *window = static_cast<NoteWindow*>(userdata);
    if (window) {
        Fl_Text_Buffer *textbuf = window->get_textbuf();
        std::string content = textbuf->text();
        std::cout << "Saving...";
        write_file(content, "../resources/note" + std::to_string(window->get_number()) + ".txt");
        std::cout << "Successfully wrote " << content.length() << " characters to file." << std::endl;
        NoteMeta notemeta = {
            window->x(),
            window->y(),
            window->get_color()
        };

        notemeta.writeToFile("../resources/note" + std::to_string(window->get_number()) + ".meta");
    }
}

NoteWindow::~NoteWindow() {
    std::cout << "Exiting...";
    count--;
    //if (changed) {
    save_callback(nullptr, this);
    //}
}

int NoteWindow::get_number() const{
    return number;
}

int NoteWindow::get_count(){
    return count;
}

void NoteWindow::draw() {
    Fl_Double_Window::draw();
    draw_title_bar();
}

int NoteWindow::handle(int event) {
    switch(event) {
        case FL_PUSH:
            if (Fl::event_y() < TITLE_BAR_HEIGHT) {
                if (in_close_button(Fl::event_x(), Fl::event_y())) {
                    hide();
                    return 1;
                }
                dragging = true;
                drag_x = Fl::event_x();
                drag_y = Fl::event_y();
                return 1;
            } else if (in_resize_handle(Fl::event_x(), Fl::event_y())) {
                resizing = true;
                drag_x = Fl::event_x();
                drag_y = Fl::event_y();
                return 1;
            }
            break;
        case FL_RELEASE:
            dragging = false;
            resizing = false;
            return 1;
        case FL_DRAG:
            if (dragging) {
                int dx = Fl::event_x() - drag_x;
                int dy = Fl::event_y() - drag_y;
                position(x() + dx, y() + dy);
                return 1;
            } else if (resizing) {
                int dx = Fl::event_x() - drag_x;
                int dy = Fl::event_y() - drag_y;
                int new_w = w() + dx;
                int new_h = h() + dy;
                size(std::max(120, new_w), std::max(80, new_h));
                drag_x = Fl::event_x();
                drag_y = Fl::event_y();
                return 1;
            }
            break;
        default:
            return Fl_Double_Window::handle(event);
    }
    return Fl_Double_Window::handle(event);
}

void NoteWindow::resize(int X, int Y, int W, int H) {
    Fl_Double_Window::resize(X, Y, W, H);
    textbox->resize(PADDING, TITLE_BAR_HEIGHT + PADDING, 
                    W - 2*PADDING, H - TITLE_BAR_HEIGHT - 2*PADDING);
}

Fl_Text_Editor* NoteWindow::get_textbox() const { return textbox.get(); }
Fl_Text_Buffer* NoteWindow::get_textbuf() const { return textbuf.get(); }

void NoteWindow::set_color(const NoteColor& c) {
    current_color = c;
    color(c.bg);
    textbox->color(c.bg);
    redraw();
}



void color_callback(Fl_Widget *widget, void *userdata) {
    const NoteColor *color = static_cast<const NoteColor*>(userdata);
    NoteWindow *window = dynamic_cast<NoteWindow*>(widget->window());
    if (window && color) {
        window->set_color(*color);
    }
}

void new_note_callback(Fl_Widget *widget, void *userdata) {
    (void)widget; (void)userdata;
    auto new_window = std::make_unique<NoteWindow>(300, 200, ("note" + std::to_string(NoteWindow::get_count())).c_str());
    new_window->border(0);
    new_window->end();
    new_window->show();

    WindowManager::get_instance()->add_window(std::move(new_window));
}

std::string read_file(const std::string& path) {
    std::ifstream file(path);
    if (!file.is_open()) {
        std::cerr << "Error: Unable to open file for reading: " << path << std::endl;
        return "";
    }
    
    std::string content((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    file.close();
    
    std::cout << "Successfully read " << content.length() << " characters from file." << std::endl;
    return content;
}
