#include "headers.h"


Player::Player(ALLEGRO_DISPLAY* d,int x,int y)
{

    display=d;
    eventQueue=al_create_event_queue();
    frameTimer=al_create_timer(1.0/FPS);
    al_register_event_source(eventQueue,al_get_timer_event_source(frameTimer));
    al_start_timer(frameTimer);
    model=al_load_bitmap("car1.png");
    al_convert_mask_to_alpha(model,al_map_rgb(255,255,255));
    screenx=x/2;
    screeny=y/2;
    posX=x;                                                                         //starting position
    posY=y;
    angle=M_PI/2.0;
    moveSpeed=0;
    gravity=2;
    acceleration=0.3;
    MAXF=5;
    MAXB=2;
    NewPosY=0;
    NewPosX=0;
    tempAngle=0;
    tempMoveSpeed=0;
    turning=5.0;
}
void Player::draw()
{
    al_flip_display();
}
Player::~Player()
{
    al_stop_timer(frameTimer);
    al_destroy_event_queue(eventQueue);
    al_destroy_timer(frameTimer);
    al_destroy_bitmap(model);
    al_destroy_display(display);
}
