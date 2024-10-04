#include "../include/NoteWindow.h"

int main(int argc, char **argv) {
    std::string restore = read_file();

    auto window = std::make_unique<NoteWindow>(300, 200, "Stickies++");
    window->border(0);
    
    Fl_Text_Editor *textbox = window->get_textbox();
    Fl_Text_Buffer *textbuf = window->get_textbuf();
    textbuf->text(restore.c_str());
    
    window->end();
    window->show(argc, argv);

    return Fl::run();
}