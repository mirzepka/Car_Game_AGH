#include "headers.h"

PlayerKeyboard2::PlayerKeyboard2(ALLEGRO_DISPLAY* d,int x,int y) : PlayerKeyboard(d,x,y)
{
    checkpointCounter2=0;
    collisionFlag2=false;
    posX2=x;                                                                         //starting position
    posY2=y;
    angle2=M_PI/2.0;
    moveSpeed2=0;
    gravity2=2;
    acceleration2=0.3;
    MAXF2=5;
    MAXB2=5;
    NewPosY2=0;
    NewPosX2=0;
    tempAngle2=0;
    tempMoveSpeed2=0;
    turning2=5.0;
    model2=al_load_bitmap("car1.png");
    al_convert_mask_to_alpha(model2,al_map_rgb(255,255,255));
    screen1=al_create_bitmap(screenx,screeny*2);
    screen2=al_create_bitmap(screenx,screeny*2);
}
void PlayerKeyboard2::drawingHUD2()
{

    al_draw_filled_rectangle(posX2-screenx/2,posY2+4*screeny/5,posX2+screenx/2,posY2+5*screeny/4,al_map_rgb(0,0,255));
    al_draw_line(posX2-screenx/2+20, posY2+4*screeny/5+50, posX2-screenx/2+260,  posY2+4*screeny/5+50,al_map_rgb(255,0,0), 2);
    al_draw_filled_triangle(posX2-screenx/2+130+20*moveSpeed2,posY2+4*screeny/5+50,posX2-screenx/2+136+20*moveSpeed2,posY2+4*screeny/5+50,posX2-screenx/2+133+20*moveSpeed2,posY2+4*screeny/5+40,al_map_rgb(0,255,0));

}
int PlayerKeyboard2::movingKey()
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
                   /* zmiana osi
                   if(gravity!=2)
                   {
                    if(gravity<1.99)
                        gravity+=0.01;
                    else if(gravity>2.01)
                        gravity-=0.01;
                    else
                        gravity=2;
                   }*/
                    al_get_keyboard_state(&myKey1);
//--------------------------CONTROL OF PLAYER 1 ------------------------------------------------------------------
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
//--------------------------CONTROL OF PLAYER 1 ------------------------------------------------------------------
                    if(al_key_down(&myKey1,ALLEGRO_KEY_A))
                        {
                            tempAngle2=angle2;
                            angle2=(angle2-turning2*sin(moveSpeed2*(90.0/MAXF2)*M_PI/180.0));//*abs(moveSpeed/10.0));
                            if(moveSpeed2>acceleration2 && gravity2<3)
                            gravity2+=0.0015*moveSpeed2;
                        }
                    else if(al_key_down(&myKey1,ALLEGRO_KEY_D))
                        {
                            tempAngle2=angle2;
                            angle2=(angle2+5.0*sin(moveSpeed2*(130.0/MAXF2)*M_PI/180.0));//*abs(moveSpeed/10.0));
                            if(moveSpeed2>acceleration2 && gravity2>1)
                            gravity2-=0.0015*moveSpeed2;
                        }
                    if(al_key_down(&myKey1,ALLEGRO_KEY_S))
                        {
                            tempMoveSpeed2=moveSpeed2;
                            if(moveSpeed2>0)
                            moveSpeed2-=3.0*acceleration2;
                            else if(moveSpeed2>-MAXB2)
                                moveSpeed2-=acceleration2;
                        }
                    else if(al_key_down(&myKey1,ALLEGRO_KEY_W))
                        {
                            tempMoveSpeed2=moveSpeed2;
                            if(moveSpeed2<MAXF2)
                            moveSpeed2+=acceleration2;
                        }
                        else{
                                if(moveSpeed2>=acceleration2)
                            moveSpeed2-=acceleration2/5.0;
                                else if(moveSpeed2<=-acceleration2/3.0)
                            moveSpeed2+=acceleration2;
                            else
                                moveSpeed2=0;
                        }
                        if(angle2>360)
                            angle2-=360;
                        else if(angle2<0)
                            angle2+=360;
// ------------------------CHANGING POSITION OF PLAYER 1 ----------------------
                        NewPosY=(moveSpeed*sin((angle)*M_PI/180.0));
                        NewPosX=(moveSpeed*cos((angle)*M_PI/180.0));
                        if (mapa.IsCollision(posX+NewPosX,posY+NewPosY,angle,checkpointCounter1))
                            {
                               angle=tempAngle;
                                if(collisionFlag1==false)
                                {
                                    collisionFlag1=true;
                                    moveSpeed=-moveSpeed/2.0;
                                }
                            }
                            else
                            {
                                collisionFlag1=false;
                                posY+=NewPosY;
                                posX+=NewPosX;
                            }

// ------------------------CHANGING POSITION OF PLAYER 2 ----------------------
                        NewPosY2=(moveSpeed2*sin((angle2)*M_PI/180.0));
                        NewPosX2=(moveSpeed2*cos((angle2)*M_PI/180.0));
                        if (mapa.IsCollision(posX2+NewPosX2,posY2+NewPosY2,angle2,checkpointCounter2))
                            {
                                angle2=tempAngle2;
                                if(collisionFlag2==false)
                                {
                                    collisionFlag2=true;
                                    moveSpeed2=-moveSpeed2/2.0;
                                }
                            }
                            else
                            {
                                collisionFlag2=false;
                                posY2+=NewPosY2;
                                posX2+=NewPosX2;
                            }

//--------------------CAMERA----------------------------------------------------------------------------------
                    al_identity_transform(&camera);
                    al_translate_transform(&camera,-posX+screenx/2,-posY+4*screeny/5);
                    al_identity_transform(&camera2);
                    al_translate_transform(&camera2,-posX2+screenx/2,-posY2+4*screeny/5);
                    //al_use_transform(&camera);
                }
            draw=true;
       }
        if(checkWinning1())
            return 2;
        else if(checkWinning2())
            return 3;

       if(draw)
       {
            draw=false;
            drawing2();
       }
    return 1;

}

void PlayerKeyboard2::drawing2()
{
//-----------Player 1 ------------------------------------------
    al_set_target_bitmap(screen1);
    al_clear_to_color(al_map_rgb(0,0,240));
    mapa.draw();
    mapa.drawingCheckpoint(checkpointCounter1);
    al_draw_rotated_bitmap(model,al_get_bitmap_width(model)/2,al_get_bitmap_height(model)/2,posX,posY,angle*M_PI/(180.0)+M_PI/2.0,NULL);
    al_draw_rotated_bitmap(model2,al_get_bitmap_width(model2)/2,al_get_bitmap_height(model2)/2,posX2,posY2,angle2*M_PI/(180.0)+M_PI/2.0,NULL);
    al_use_transform(&camera);
    drawingHUD1();
//------------Player 2-------------------------------------------
    al_set_target_bitmap(screen2);
    al_clear_to_color(al_map_rgb(0,0,240));
    mapa.draw();
    mapa.drawingCheckpoint(checkpointCounter2);
    al_draw_rotated_bitmap(model,al_get_bitmap_width(model)/2,al_get_bitmap_height(model)/2,posX,posY,angle*M_PI/(180.0)+M_PI/2.0,NULL);
    al_draw_rotated_bitmap(model2,al_get_bitmap_width(model2)/2,al_get_bitmap_height(model2)/2,posX2,posY2,angle2*M_PI/(180.0)+M_PI/2.0,NULL);
    al_use_transform(&camera2);
    drawingHUD2();
//--------- Together------------------------------------------
    al_set_target_bitmap(al_get_backbuffer(display));
    al_draw_bitmap(screen1,0,0,NULL);
    al_draw_bitmap(screen2,screenx,0,NULL);
    al_flip_display();
    al_clear_to_color(al_map_rgb(0,0,240));
}
bool PlayerKeyboard2::checkWinning2()
{
    if(checkpointCounter2==mapa.returnCheckpoints())
        return true;
    else
        return false;
}
