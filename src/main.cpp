#include "../include/NoteWindow.h"
#include <vector>
#include <memory>
#include <iostream>
#include <unordered_map>

namespace fs = std::filesystem;



int main() {
    WindowManager* manager = WindowManager::get_instance();
    std::unordered_map<std::string, NoteData> notes_map;
    std::unordered_map<std::string, std::string> note_contents;
    std::unordered_map<std::string, NoteMeta> notes_meta;
    const fs::path folder = "../resources";
    try {

        for (const auto& entry : fs::directory_iterator(folder)) {
            if (entry.is_regular_file()) {
                std::string str_path = std::string(entry.path().filename());
                if (str_path.substr(str_path.length() - 4) == ".txt" ){
                    std::string name = str_path.substr(0,  str_path.length() - 4);

                    note_contents[name] = read_file("../resources/" + name + ".txt");
                    std::cout << name << ".txt\n";
                }
            }
        }
        for (const auto& entry : fs::directory_iterator(folder)) {
            if (entry.is_regular_file()) {
                std::string str_path = std::string(entry.path().filename());
                if (str_path.substr(str_path.length() - 5) == ".meta" ){
                    std::string name = str_path.substr(0,  str_path.length() - 5);

                    notes_meta[name] = NoteMeta::readFromFile("../resources/" + name + ".meta");
                    std::cout << name << ".meta\n";
                }
            }
        }
    } catch (const fs::filesystem_error& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    bool found = true;
    while (found){
        found = false;
        for (auto item = note_contents.begin(); item != note_contents.end(); item++){
            if (auto search = notes_meta.find(item->first); search != notes_meta.end()){
                notes_map[item->first] = {
                    item->second,
                    search->second
                };
                std::cout << search->first << ".meta DELETED FROM MAP\n";
                notes_meta.erase(search);
                std::cout << item->first << ".txt DELETED FROM MAP\n";
                note_contents.erase(item);
                found = true;
                break;
            }
        }
    }

    

    for (auto item = note_contents.begin(); item != note_contents.end(); item++){
        std::string path = "../resources/" + item->first + ".txt";
        try {
            if (fs::remove(path))
            std::cout << "file " << path << " deleted.\n";
            else
            std::cout << "file " << path << " not found.\n";
        }
        catch(const std::filesystem::filesystem_error& err) {
            std::cout << "filesystem error: " << err.what() << '\n';
        }
    }

    for (auto item = notes_meta.begin(); item != notes_meta.end(); item++){
        std::string path = "../resources/" + item->first + ".meta";
        try {
            if (fs::remove(path))
            std::cout << "file " << path << " deleted.\n";
            else
            std::cout << "file " << path << " not found.\n";
        }
        catch(const std::filesystem::filesystem_error& err) {
            std::cout << "filesystem error: " << err.what() << '\n';
        }
    }

    if(notes_map.empty()){
        auto window = std::make_unique<NoteWindow>(300, 200, ("note" + std::to_string(NoteWindow::get_count())).c_str());
        window->border(0);
        window->end();
        window->show();
        manager->add_window(std::move(window));
    }
    else{
        for (auto item = notes_map.begin(); item != notes_map.end(); item++){
            auto window = std::make_unique<NoteWindow>(300, 200, ("note" + std::to_string(NoteWindow::get_count())).c_str());
            window->border(0);
            Fl_Text_Editor *textbox = window->get_textbox();
            Fl_Text_Buffer *textbuf = window->get_textbuf();
            textbuf->text(item->second.contents.c_str());
            window->position(item->second.meta.pos_y, item->second.meta.pos_x);
            window->set_color(item->second.meta.notecolor);
            window->end();
            window->show();
            manager->add_window(std::move(window));
        }
    }

    return Fl::run();
}