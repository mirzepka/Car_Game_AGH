#include "headers.h"

PlayerKeyboard::PlayerKeyboard(ALLEGRO_DISPLAY* d,int x,int y) : Player(d,x,y)
{
    al_register_event_source(eventQueue,al_get_keyboard_event_source());
}
PlayerKeyboard::~PlayerKeyboard()
{


}
int PlayerKeyboard::movingKey()
{
    bool draw;
    ALLEGRO_EVENT eventmain;
    ALLEGRO_KEYBOARD_STATE myKey1;
    al_wait_for_event(eventQueue,&eventmain);
    if(eventmain.type==ALLEGRO_EVENT_KEY_DOWN)
    {

        switch(eventmain.keyboard.keycode)
        {
            case ALLEGRO_KEY_ESCAPE:
            return 0;
        }
    }
    if(eventmain.type==ALLEGRO_EVENT_TIMER)
       {
            if(eventmain.timer.source==frameTimer)
               {
                   if(gravity!=2)
                   {
                    if(gravity<1.99)
                        gravity+=0.01;
                    else if(gravity>2.01)
                        gravity-=0.01;
                    else
                        gravity=2;
                   }
                    al_get_keyboard_state(&myKey1);
                    if(al_key_down(&myKey1,ALLEGRO_KEY_LEFT))
                        {
                            tempAngle=angle;
                            angle=(angle-turning*sin(moveSpeed*(90.0/MAXF)*M_PI/180.0));//*abs(moveSpeed/10.0));
                            if(moveSpeed>acceleration && gravity<3)
                            gravity+=0.0015*moveSpeed;
                        }
                    else if(al_key_down(&myKey1,ALLEGRO_KEY_RIGHT))
                        {
                            tempAngle=angle;
                            angle=(angle+turning*sin(moveSpeed*(130.0/MAXF)*M_PI/180.0));//*abs(moveSpeed/10.0));
                            if(moveSpeed>acceleration && gravity>1)
                            gravity-=0.0015*moveSpeed;
                        }
                    if(al_key_down(&myKey1,ALLEGRO_KEY_DOWN))
                        {
                            tempMoveSpeed=moveSpeed;
                            if(moveSpeed>0)
                            moveSpeed-=3.0*acceleration;
                            else if(moveSpeed>-MAXB)
                                moveSpeed-=acceleration;
                        }
                    else if(al_key_down(&myKey1,ALLEGRO_KEY_UP))
                        {
                            tempMoveSpeed=moveSpeed;
                            if(moveSpeed<MAXF)
                            moveSpeed+=acceleration;
                        }
                        else{
                                if(moveSpeed>=acceleration)
                            moveSpeed-=acceleration/5.0;
                                else if(moveSpeed<=-acceleration/3.0)
                            moveSpeed+=acceleration;
                            else
                                moveSpeed=0;
                        }
                        if(angle>360)
                            angle-=360;
                        else if(angle<0)
                            angle+=360;

                        NewPosY=(moveSpeed*sin((angle)*M_PI/180.0));
                        NewPosX=(moveSpeed*cos((angle)*M_PI/180.0));
                        if (mapa.IsCollision(posX+NewPosX,posY+NewPosY))
                            {
                                angle=tempAngle;
                                if(moveSpeed<3)
                                {
                                    moveSpeed=0;
                                    NewPosX=0;
                                    NewPosY=0;
                                }
                                moveSpeed=-moveSpeed/2.0;
                                posY-=NewPosY;
                                posX-=NewPosX;
                            }
                            else
                            {
                                posY+=NewPosY;
                                posX+=NewPosX;
                            }
                        al_identity_transform(&camera);



                      // al_translate_transform(&camera,screenx,screeny);
                        //al_translate_transform(&camera,-posX+screenx,-posY+screeny);
                     // al_rotate_transform(&camera,-(angle)*3.14/(180.0)-3.14/2.0);
                      al_translate_transform(&camera,-posX+screenx,-posY+screeny);
                       //al_scale_transform(&camera,1-fabs(0.008*moveSpeed),1-fabs(0.008*moveSpeed));
                        //al_translate_transform(&camera,screenx,screeny);
                        //al_build_transform(&camera, screenx-posX, screeny-posY,1, 1, 0);
                        al_use_transform(&camera);
                }
            draw=true;
       }
       if(draw)
       {
            draw=false;
            al_clear_to_color(al_map_rgb(0,0,240));
            mapa.draw();
            al_draw_rotated_bitmap(model,al_get_bitmap_width(model)/2,al_get_bitmap_height(model)/2,posX,posY,angle*M_PI/(180.0)+M_PI/2.0,NULL);
            al_flip_display();
       }
    return 1;
}
