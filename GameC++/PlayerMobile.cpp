#include "headers.h"

PlayerMobile::PlayerMobile(int x,int y) : Player(x,y)
{
    al_register_event_source(eventQueue,al_get_keyboard_event_source());
    /////////////SOCKETY
    client.init();
    tmpToClient=0;
}
PlayerMobile::~PlayerMobile()
{


}
int PlayerMobile::movingKey()
{
    int NewPosY,NewPosX;
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
                   out=client.getData();
                   TempX=(out>>8)&0xff;
                   TempX=(240-TempX);
                    TempY=out&0xff;

                   if(gravity!=2)
                   {
                    if(gravity<1.99)
                        gravity+=0.01;
                    else if(gravity>2.01)
                        gravity-=0.01;
                    else
                        gravity=2;
                   }

                    if(al_key_down(&myKey1,ALLEGRO_KEY_LEFT))
                        {
                            angle=(angle-3.0*sin(moveSpeed*(90.0/MAXF)*3.14/180.0));//*abs(moveSpeed/10.0));
                            if(moveSpeed>acceleration && gravity<3)
                            gravity+=0.0015*moveSpeed;
                        }
                    else if(al_key_down(&myKey1,ALLEGRO_KEY_RIGHT))
                        {
                            angle=(angle+3.0*sin(moveSpeed*(130.0/MAXF)*3.14/180.0));//*abs(moveSpeed/10.0));
                            if(moveSpeed>acceleration && gravity>1)
                            gravity-=0.0015*moveSpeed;
                        }

                    if(TempY>200)
                            if(moveSpeed<MAXF)
                            moveSpeed+=acceleration;
                   else if(TempY>120&&TempY<200){

                    moveSpeed+=acceleration*(TempY-120.0)/80.0;

                   }
                   else if(TempY>40&&TempY<=120){
                        if(moveSpeed>0)
                    moveSpeed+=3*acceleration*(TempY-120.0)/80.0;
                    else if(moveSpeed>-MAXB)
                        moveSpeed+=acceleration*(TempY-120.0)/80.0;
                   }
                   else{
                    if(moveSpeed>0)
                    moveSpeed+=3*(-acceleration);
                    else
                        moveSpeed+=(-acceleration);
                   }
                        NewPosY+=(moveSpeed*sin(((double)((int)angle%360))*3.14/180.0));
                        NewPosX+=(moveSpeed*cos(((double)((int)angle%360))*3.14/180.0));
                        posY+=(moveSpeed*sin(((double)((int)angle%360))*3.14/180.0));
                        posX+=(moveSpeed*cos(((double)((int)angle%360))*3.14/180.0));
                        if (mapa.IsCollision(NewPosX+2*screenx,NewPosY+2*screeny))
                            std::cout<<"kolizja"<<std::endl;
                        al_identity_transform(&camera);

                        if(angle>360)
                            angle-=360;
                        else if(angle<0)
                            angle+=360;

                        al_translate_transform(&camera,-posX+screenx,-posY+screeny);
                      //  al_rotate_transform(&camera,-(angle)*3.14/(180.0)-3.14/2.0);
                       // al_scale_transform(&camera,1-fabs(0.008*moveSpeed),1-fabs(0.008*moveSpeed));
                       // al_translate_transform(&camera,screenx,screeny);
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
            al_draw_rotated_bitmap(model,al_get_bitmap_width(model)/2,gravity*al_get_bitmap_height(model)/4,posX,posY,angle*3.14/(180.0)+3.14/2.0,NULL);
            al_flip_display();
       }
    return 1;
}

