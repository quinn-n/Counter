/*
 * counter
 * A simple counter program
 * written by Quinn Neufeld
 * May 5th 2020
*/

#include <cstdlib>
#include <sstream>
#include "counter.cxx"
#include <Fl/Fl.H>

//Callback for increment button
void cb_increment(Fl_Widget* widget, void* user_data) {
    int val = atoi(output_text->value());
    std::stringstream ss;
    ss << val + 1;
    output_text->value(ss.str().c_str());
}

//Callback for decrement button
void cb_decrement(Fl_Widget* widget, void* user_data) {
    int val = atoi(output_text->value());
    std::stringstream ss;
    ss << val - 1;
    output_text->value(ss.str().c_str());
}

//Set callback functions
void set_callbacks() {
    increment_btn->callback(cb_increment);
    decrement_btn->callback(cb_decrement);
}

int main() {
    //Setup widgets
    make_window();
    set_callbacks();
    output_text->value("0");
    //Show widgets & run fltk
    counter_win->show();
    return Fl::run();
}
