#include "headers.h"



Window::Window() : Options()
{
    al_set_new_display_flags(ScreenFlags  );//| ALLEGRO_FULLSCREEN_WINDOW
    display = al_create_display(ScreenWidth,ScreenHeight);
    al_set_system_mouse_cursor(display, ALLEGRO_SYSTEM_MOUSE_CURSOR_DEFAULT);
    al_show_mouse_cursor(display);

}

Window::~Window()
{
    al_destroy_display(display);
}

void Window::change(std::string option,std::string value)
{
    changeOptions(option,value);
    ScreenOptions();
    al_resize_display(display,ScreenWidth,ScreenHeight);
    al_set_new_display_flags(ScreenFlags);

}

int Window::getHeight()
{
    return al_get_display_height(display);
}
int Window::getWidth()
{
    return al_get_display_width(display);
}
ALLEGRO_DISPLAY * Window::getDisplay()
{
    return display;
}
