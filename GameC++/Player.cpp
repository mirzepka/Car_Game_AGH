#include "headers.h"


Player::Player(ALLEGRO_DISPLAY* d,int x,int y)
{
    collisionFlag1=false;
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
    MAXB=5;
    NewPosY=0;
    NewPosX=0;
    tempAngle=0;
    tempMoveSpeed=0;
    turning=5.0;
    checkpointCounter1=0;
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
void Player::drawingHUD()
{

    al_draw_filled_rectangle(posX-screenx/2,posY+4*screeny/5,posX+screenx/2,posY+5*screeny/4,al_map_rgb(0,0,255));
    al_draw_line(posX-screenx+20, posY+4*screeny/5+50, posX-screenx+260,  posY+4*screeny/5+50,al_map_rgb(255,0,0), 2);
    al_draw_filled_triangle(posX-screenx+130+20*moveSpeed,posY+4*screeny/5+50,posX-screenx+136+20*moveSpeed,posY+4*screeny/5+50,posX-screenx+133+20*moveSpeed,posY+4*screeny/5+40,al_map_rgb(0,255,0));
}
void Player::drawingHUD1()
{

    al_draw_filled_rectangle(posX-screenx/2,posY+4*screeny/5,posX+screenx/2,posY+5*screeny/4,al_map_rgb(0,0,255));
    al_draw_line(posX-screenx/2+20, posY+4*screeny/5+50, posX-screenx/2+260,  posY+4*screeny/5+50,al_map_rgb(255,0,0), 2);
    al_draw_filled_triangle(posX-screenx/2+130+20*moveSpeed,posY+4*screeny/5+50,posX-screenx/2+136+20*moveSpeed,posY+4*screeny/5+50,posX-screenx/2+133+20*moveSpeed,posY+4*screeny/5+40,al_map_rgb(0,255,0));

}

