#pragma once

#include <FL/Fl.H>
#include <FL/Fl_Double_Window.H>
#include <FL/fl_draw.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Sys_Menu_Bar.H>
#include <FL/Fl_Text_Editor.H>
#include <FL/Fl_Text_Buffer.H>
#include <iostream>
#include <string>
#include <fstream>
#include <memory>

const char FILE_PATH[] = "../resources/note.txt";

struct NoteColor {
    Fl_Color titlebar;
    Fl_Color bg;
    Fl_Color buttonDarker;
    Fl_Color buttonLighter;
};

const NoteColor YELLOW {
    fl_rgb_color(251, 235, 97),
    fl_rgb_color(252, 244, 167),
    fl_rgb_color(214, 183, 59),
    fl_rgb_color(255, 255, 230)
};

const NoteColor BLUE {
    fl_rgb_color(135, 206, 235),
    fl_rgb_color(173, 216, 230),
    fl_rgb_color(100, 149, 237),
    fl_rgb_color(202, 225, 255)
};

const NoteColor GREEN {
    fl_rgb_color(134, 228, 134),
    fl_rgb_color(152, 251, 152),
    fl_rgb_color(56, 149, 97),
    fl_rgb_color(193, 255, 193)
};

void save_callback(Fl_Widget *widget, void *userdata);
void color_callback(Fl_Widget *widget, void *userdata);
//void new_note_callback(Fl_Widget *widget, void *userdata);
std::string read_file();
void write_file(const std::string& content);

const Fl_Menu_Item menuitems[] = {
    { "&File",              0, 0, 0, FL_SUBMENU },
        { "&New Note", FL_COMMAND + 'n', nullptr/*(Fl_Callback *)new_note_callback*/, nullptr },
        { 0 },
    { "&Color", 0, 0, 0, FL_SUBMENU },
        { "&Yellow", 0, (Fl_Callback *)color_callback, (void*)&YELLOW },
        { "&Blue",   0, (Fl_Callback *)color_callback, (void*)&BLUE },
        { "&Green",  0, (Fl_Callback *)color_callback, (void*)&GREEN },
        { 0 },
    { 0 }
};

class NoteWindow : public Fl_Double_Window {
private:
    static constexpr int TITLE_BAR_HEIGHT = 20;
    static constexpr int CLOSE_BUTTON_SIZE = 12;
    static constexpr int PADDING = 10;
    static constexpr int RESIZE_HANDLE_SIZE = 16;
    
    std::unique_ptr<Fl_Text_Editor> textbox;
    std::unique_ptr<Fl_Sys_Menu_Bar> menubar;
    std::unique_ptr<Fl_Text_Buffer> textbuf;
    bool dragging;
    bool resizing;
    int drag_x, drag_y;
    bool changed = false;
    NoteColor current_color;

    void draw_title_bar();

    bool in_close_button(int x, int y) const;

    bool in_resize_handle(int x, int y) const;

    // static void changed_callback(int pos, int nInserted, int nDeleted, int nRestyled, const char* deletedText, void* v);

public:
    NoteWindow(int w, int h, const char* title = nullptr);

    ~NoteWindow();

    void draw() override;

    int handle(int event) override;

    void resize(int X, int Y, int W, int H) override;

    Fl_Text_Editor* get_textbox() const;
    Fl_Text_Buffer* get_textbuf() const;

    void set_color(const NoteColor& c);
};