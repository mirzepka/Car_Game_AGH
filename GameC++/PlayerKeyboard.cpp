#include "headers.h"
bool PlayerKeyboard::secondPlayer=0;
PlayerKeyboard::PlayerKeyboard(ALLEGRO_DISPLAY* d,int x,int y) : Player(d,x,y)
{

    al_register_event_source(eventQueue,al_get_keyboard_event_source());
    if(PlayerKeyboard::secondPlayer){
        keyL=ALLEGRO_KEY_A;
        keyR=ALLEGRO_KEY_D;
        keyU=ALLEGRO_KEY_W;
        keyD=ALLEGRO_KEY_S;
    }
    else{
        keyL=ALLEGRO_KEY_LEFT;
        keyR=ALLEGRO_KEY_RIGHT;
        keyU=ALLEGRO_KEY_UP;
        keyD=ALLEGRO_KEY_DOWN;

    }
    PlayerKeyboard::secondPlayer=!PlayerKeyboard::secondPlayer;
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
                    if(al_key_down(&myKey1,keyL))
                        {
                            tempAngle=angle;
                            angle=(angle-turning*sin(moveSpeed*(90.0/MAXF)*M_PI/180.0));//*abs(moveSpeed/10.0));
                            if(moveSpeed>acceleration && gravity<3)
                            gravity+=0.0015*moveSpeed;
                        }
                    else if(al_key_down(&myKey1,keyR))
                        {
                            tempAngle=angle;
                            angle=(angle+turning*sin(moveSpeed*(130.0/MAXF)*M_PI/180.0));//*abs(moveSpeed/10.0));
                            if(moveSpeed>acceleration && gravity>1)
                            gravity-=0.0015*moveSpeed;
                        }
                    if(al_key_down(&myKey1,keyD))
                        {
                            tempMoveSpeed=moveSpeed;
                            if(moveSpeed>0)
                            moveSpeed-=3.0*acceleration;
                            else if(moveSpeed>-MAXB)
                                moveSpeed-=acceleration;
                        }
                    else if(al_key_down(&myKey1,keyU))
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
                        if (mapa.IsCollision(posX+NewPosX,posY+NewPosY,angle))
                            {
                               angle=tempAngle;
                                if(moveSpeed>1 || moveSpeed<-1)
                                   moveSpeed=0;
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
              for(int i=0;i<8;i++)
                {
                al_draw_filled_circle(Obstacles::rogiX[i],Obstacles::rogiY[i],5, al_map_rgb(i*100%255,i*90%255,i*100%255));
               // al_draw_filled_circle(GameMap::xtmp[i],GameMap::ytmp[i],5, al_map_rgb(i*100%255,i*90%255,i*100%255));
            }

                   // std::cout<<"ROGI"<<Obstacles::rogiX[0]<<std::endl;
                    std::cout<<moveSpeed<<std::endl;
                    std::cout<<angle<<std::endl;
            al_draw_rotated_bitmap(model,al_get_bitmap_width(model)/2,al_get_bitmap_height(model)/2,posX,posY,angle*M_PI/(180.0)+M_PI/2.0,NULL);
            al_flip_display();

       }
    return 1;
}
