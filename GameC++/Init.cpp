#include "headers.h"

Init::Init()
{
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//OOO init and testing if allegro 5 links correctly + allegro initialization OOO
    if(!al_init())
    {
        al_show_native_message_box(NULL,"Error",NULL,"Could not load allegro5!",NULL,ALLEGRO_MESSAGEBOX_ERROR);
    }
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//OOO init font addon OOO
    al_init_font_addon();
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//OOO init and testing font tff OOO
    if(!al_init_ttf_addon())
    {
        al_show_native_message_box(NULL,"Error",NULL,"Could not initialize font!",NULL,ALLEGRO_MESSAGEBOX_ERROR);
    }
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//OOO init music OOO
    al_init_acodec_addon();
    al_install_audio();
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//OOO init keyboard OOO
    al_install_keyboard();

    al_init_image_addon();

    al_install_mouse();
    al_init_primitives_addon();
}

Init::~Init()
{

}

