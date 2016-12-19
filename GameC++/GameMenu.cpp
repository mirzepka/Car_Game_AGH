#include "headers.h"


GameMenu::GameMenu(ALLEGRO_DISPLAY * displayFromMain) : FontSize{64}, Number{1}
{
    eventQueue=al_create_event_queue();
    for(int i=0;i<11;i++)
    {
            color[i]=al_map_rgb(255,255,0);
    }
    mapMenu=al_load_bitmap("menuBack.jpg");
    al_register_event_source(eventQueue,al_get_mouse_event_source());
    font=al_load_font("heav.ttf",FontSize,NULL);
    display = displayFromMain;
    ScrHeight=al_get_display_height(display);
    ScrWidth=al_get_display_width(display);
    init();

}
GameMenu::~GameMenu()
{
    al_destroy_font(font);
    al_destroy_bitmap(mapMenu);
    al_destroy_event_queue(eventQueue);
}
void GameMenu::init()
{

    x.push_back((ScrWidth-al_get_text_width(font, "NOWA GRA"))/2);
    x.push_back(al_get_text_width(font, "NOWA GRA"));
    x.push_back((ScrWidth-al_get_text_width(font, "OPCJE"))/2);
    x.push_back(al_get_text_width(font, "OPCJE"));
    x.push_back((ScrWidth-al_get_text_width(font, "KONIEC"))/2);
    x.push_back(al_get_text_width(font, "KONIEC"));
    x.push_back((ScrWidth-al_get_text_width(font, "NA PEWNO?"))/2);
    x.push_back(al_get_text_width(font, "NA PEWNO?"));
    x.push_back((ScrWidth-al_get_text_width(font, "TAK"))/2-al_get_text_width(font, "TAK"));
    x.push_back(al_get_text_width(font, "TAK"));
    x.push_back(x[9]+(ScrWidth-al_get_text_width(font, "NIE"))/2);
    x.push_back(al_get_text_width(font, "NIE"));
    //12
    x.push_back((ScrWidth-al_get_text_width(font, "LICZBA GRACZY:"))/2);
    x.push_back(al_get_text_width(font, "LICZBA GRACZY:"));
    x.push_back((ScrWidth-al_get_text_width(font, "1"))/2-al_get_text_width(font, "1"));
    x.push_back(al_get_text_width(font, "1"));
    x.push_back(x[15]+(ScrWidth-al_get_text_width(font, "2"))/2);
    x.push_back(al_get_text_width(font, "2"));
    //18
    x.push_back((ScrWidth-al_get_text_width(font, "STEROWANIE GRACZAX"))/2);
    x.push_back(al_get_text_width(font, "STEROWANIE GRACZAX"));

    x.push_back((ScrWidth-al_get_text_width(font, "KLAWIATURA"))/2);
    x.push_back(al_get_text_width(font, "KLAWIATURA"));
    x.push_back((ScrWidth-al_get_text_width(font, "TELEFON"))/2);
    x.push_back(al_get_text_width(font, "TELEFON"));
    //24
    x.push_back((ScrWidth-al_get_text_width(font, "DALEJ"))/2);
    x.push_back(al_get_text_width(font, "DALEJ"));

    y.push_back(((ScrHeight-FontSize)/2)-2*(FontSize));
    y.push_back((ScrHeight-FontSize)/2);
    y.push_back(((ScrHeight-FontSize)/2)+2*(FontSize));
    y.push_back(FontSize-FontSize/7);
    y.push_back(((ScrHeight-FontSize)/2)-(FontSize));
}

bool GameMenu::YesNo()
{
    bool optionT[2] {false,false};
    while(1)
    {
        drawSure();
        ALLEGRO_EVENT eventmain1;
        al_wait_for_event(eventQueue,&eventmain1);
        if(eventmain1.type==ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
        {
            if((eventmain1.mouse.x>=x[8]) && (eventmain1.mouse.x<=(x[8]+x[9])) && (eventmain1.mouse.y>=y[1]) && (eventmain1.mouse.y<=(y[1]+y[3])))
            {
                color[3]=al_map_rgb(255,0,0);
                optionT[0]=true;
            }
            else if((eventmain1.mouse.x>=x[10]) && (eventmain1.mouse.x<=(x[10]+x[11])) && (eventmain1.mouse.y>=y[1]) && (eventmain1.mouse.y<=(y[1]+y[3])))
            {
                color[4]=al_map_rgb(255,0,0);
                optionT[1]=true;
            }
            else
            {
                for(int i=3;i<5;i++)
                {
                    color[i]=al_map_rgb(255,255,0);
                }
            }
        }
        if(eventmain1.type==ALLEGRO_EVENT_MOUSE_BUTTON_UP)
        {
            for(int i=3;i<5;i++)
            {
                color[i]=al_map_rgb(255,255,0);
            }
            if(optionT[0]==true &&(eventmain1.mouse.x>=x[8]) && (eventmain1.mouse.x<=(x[8]+x[9])) && (eventmain1.mouse.y>=y[3]) && (eventmain1.mouse.y<=(y[1]+y[3])))
            {
                color[3]=al_map_rgb(255,0,0);
                return true;
            }
            else if(optionT[1]==true &&(eventmain1.mouse.x>=x[10]) && (eventmain1.mouse.x<=(x[10]+x[11])) && (eventmain1.mouse.y>=y[3]) && (eventmain1.mouse.y<=(y[1]+y[3])))
            {
                color[4]=al_map_rgb(255,255,0);
                return false;
            }
            else
            {
                optionT[0]=false;
                optionT[1]=false;
            }
        }
    }
}

void GameMenu::drawSure()
{
    al_clear_to_color(al_map_rgb(0,0,0));
    al_draw_bitmap(mapMenu, 0, 0, 0);
    al_draw_text(font,color[0], x[6], y[0], 0,"NA PEWNO?");
    al_draw_text(font,color[3], x[8], y[1], 0,"TAK");
    al_draw_text(font,color[4], x[10], y[1], 0,"NIE");
    al_flip_display();
}
void GameMenu::draw()
{

    al_clear_to_color(al_map_rgb(0,0,0));
    al_draw_bitmap(mapMenu, 0, 0, 0);
    al_draw_text(font,color[0], x[0], y[0], 0,"NOWA GRA");
    al_draw_text(font,color[1], x[2], y[1], 0,"OPCJE");
    al_draw_text(font,color[2], x[4], y[2], 0,"KONIEC");
    al_flip_display();
}
void GameMenu::drawChoice()
{
    al_clear_to_color(al_map_rgb(0,0,0));
    al_draw_bitmap(mapMenu, 0, 0, 0);
    al_draw_text(font,color[0], x[12], y[0], 0,"LICZBA GRACZY");
    al_draw_text(font,color[5], x[14], y[1], 0,"1");
    al_draw_text(font,color[6], x[16], y[1], 0,"2");
    al_draw_text(font,color[7], x[24], y[2], 0,"DALEJ");
    al_flip_display();
}
void GameMenu::drawControler()
{
    al_clear_to_color(al_map_rgb(0,0,0));
    al_draw_bitmap(mapMenu, 0, 0, 0);
    if(Number==1)
    al_draw_text(font,color[0], x[18], y[0], 0,"STEROWANIE GRACZA1");
    else
    al_draw_text(font,color[0], x[18], y[0], 0,"STEROWANIE GRACZA2");
    al_draw_text(font,color[8], x[20], y[4], 0,"KLAWIATURA");
    al_draw_text(font,color[9], x[22], y[1], 0,"TELEFON");
    al_draw_text(font,color[10], x[24], y[2], 0,"DALEJ");
    al_flip_display();
}

int GameMenu::WhichOption()
{
    ALLEGRO_EVENT eventmain;
    bool optionTrue[3] {false,false,false};
    while(1)
    {

        draw();
        al_wait_for_event(eventQueue,&eventmain);
        if(eventmain.type==ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
        {
            if((eventmain.mouse.x>=x[0]) && (eventmain.mouse.x<=(x[0]+x[1])) && (eventmain.mouse.y>=y[0]) && (eventmain.mouse.y<=(y[0]+y[3])))
                {
                   color[0]=al_map_rgb(255,0,0);
                   optionTrue[0]=true;
                }
            else if((eventmain.mouse.x>=x[2]) && (eventmain.mouse.x<=(x[2]+x[3])) && (eventmain.mouse.y>=y[1]) && (eventmain.mouse.y<=(y[1]+y[3])))
            {
                color[1]=al_map_rgb(255,0,0);
                optionTrue[1]=true;
            }
            else if((eventmain.mouse.x>=x[4]) && (eventmain.mouse.x<=(x[4]+x[5])) && (eventmain.mouse.y>=y[2]) && (eventmain.mouse.y<=(y[2]+y[3])))
            {
                color[2]=al_map_rgb(255,0,0);
                optionTrue[2]=true;
            }
            else
            {
                for(int i=0;i<3;i++)
                {
                    color[i]=al_map_rgb(255,255,0);
                }
            }
        }
        if(eventmain.type==ALLEGRO_EVENT_MOUSE_BUTTON_UP)
        {
            for(int i=0;i<3;i++)
            {
                color[i]=al_map_rgb(255,255,0);
            }
            if(optionTrue[0]==true && (eventmain.mouse.x>=x[0]) && (eventmain.mouse.x<=(x[0]+x[1])) && (eventmain.mouse.y>=y[0]) && (eventmain.mouse.y<=(y[0]+y[3])))
            {
                return 1;
            }
            else if(optionTrue[1]==true && (eventmain.mouse.x>=x[2]) && (eventmain.mouse.x<=(x[2]+x[3])) && (eventmain.mouse.y>=y[1]) && (eventmain.mouse.y<=(y[1]+y[3])))
            {
                return 2;
            }
            else if(optionTrue[2]==true && (eventmain.mouse.x>=x[4]) && (eventmain.mouse.x<=(x[4]+x[5])) && (eventmain.mouse.y>=y[2]) && (eventmain.mouse.y<=(y[2]+y[3])))
            {
               if(YesNo())
                return 3;
            }
            for(int i=0;i<3;i++)
            {
                optionTrue[i]=false;
            }
        }
    }
}
int GameMenu::WhichOption2()
{
    ALLEGRO_EVENT eventmain;
    bool optionTrue[3] {false,false,false};
    bool next = false;
    int out=0;
    for(int k=5;k<8;k++)
    {
    color[k]=al_map_rgb(255,255,0);
    }

    while(1)
    {
        drawChoice();
        al_wait_for_event(eventQueue,&eventmain);
        if(eventmain.type==ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
        {
            if((eventmain.mouse.x>=x[14]) && (eventmain.mouse.x<=(x[14]+x[15])) && (eventmain.mouse.y>=y[1]) && (eventmain.mouse.y<=(y[1]+y[3])))
                {
                   color[5]=al_map_rgb(255,0,0);
                   optionTrue[0]=true;
                }
            else if((eventmain.mouse.x>=x[16]) && (eventmain.mouse.x<=(x[16]+x[17])) && (eventmain.mouse.y>=y[1]) && (eventmain.mouse.y<=(y[1]+y[3])))
            {
                color[6]=al_map_rgb(255,0,0);
                optionTrue[1]=true;
            }
            else if(next==true && (eventmain.mouse.x>=x[24]) && (eventmain.mouse.x<=(x[24]+x[25])) && (eventmain.mouse.y>=y[2]) && (eventmain.mouse.y<=(y[2]+y[3])))
            {
                color[7]=al_map_rgb(255,0,0);
                optionTrue[2]=true;
            }
        }
        if(eventmain.type==ALLEGRO_EVENT_MOUSE_BUTTON_UP)
        {

            if(optionTrue[0]==true && (eventmain.mouse.x>=x[14]) && (eventmain.mouse.x<=(x[14]+x[15])) && (eventmain.mouse.y>=y[1]) && (eventmain.mouse.y<=(y[1]+y[3])))
            {
                out = 1;
                color[6]=al_map_rgb(255,255,0);
                next=true;

            }
            else if(optionTrue[1]==true && (eventmain.mouse.x>=x[16]) && (eventmain.mouse.x<=(x[16]+x[17])) && (eventmain.mouse.y>=y[1]) && (eventmain.mouse.y<=(y[1]+y[3])))
            {
                out = 2;
                color[5]=al_map_rgb(255,255,0);
                next=true;
            }
            else if(optionTrue[2]==true && (eventmain.mouse.x>=x[24]) && (eventmain.mouse.x<=(x[24]+x[25])) && (eventmain.mouse.y>=y[2]) && (eventmain.mouse.y<=(y[2]+y[3])))
            {
                Number=1;
                return out;
            }
            else if(out==2)
            {
                color[5]=al_map_rgb(255,255,0);
                color[7]=al_map_rgb(255,255,0);
            }
            else if(out==1)
            {
                color[6]=al_map_rgb(255,255,0);
                color[7]=al_map_rgb(255,255,0);
            }
            else
            {
                color[5]=al_map_rgb(255,255,0);
                color[6]=al_map_rgb(255,255,0);
                color[7]=al_map_rgb(255,255,0);
            }
            for(int i=0;i<3;i++)
            {
                optionTrue[i]=false;
            }
        }
    }
}
int GameMenu::WhichOption3()
{
    ALLEGRO_EVENT eventmain;
    bool optionTrue[3] {false,false,false};
    bool next = false;
    int out=0;
    for(int k=8;k<11;k++)
    {
    color[k]=al_map_rgb(255,255,0);
    }

    while(1)
    {
        drawControler();
        al_wait_for_event(eventQueue,&eventmain);
        if(eventmain.type==ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
        {
            if((eventmain.mouse.x>=x[20]) && (eventmain.mouse.x<=(x[20]+x[21])) && (eventmain.mouse.y>=y[4]) && (eventmain.mouse.y<=(y[4]+y[3])))
                {
                   color[8]=al_map_rgb(255,0,0);
                   optionTrue[0]=true;
                }
            else if((eventmain.mouse.x>=x[22]) && (eventmain.mouse.x<=(x[22]+x[23])) && (eventmain.mouse.y>=y[1]) && (eventmain.mouse.y<=(y[1]+y[3])))
            {
                color[9]=al_map_rgb(255,0,0);
                optionTrue[1]=true;
            }
            else if(next==true && (eventmain.mouse.x>=x[24]) && (eventmain.mouse.x<=(x[24]+x[25])) && (eventmain.mouse.y>=y[2]) && (eventmain.mouse.y<=(y[2]+y[3])))
            {
                color[10]=al_map_rgb(255,0,0);
                optionTrue[2]=true;
            }
        }
        if(eventmain.type==ALLEGRO_EVENT_MOUSE_BUTTON_UP)
        {

            if(optionTrue[0]==true && (eventmain.mouse.x>=x[20]) && (eventmain.mouse.x<=(x[20]+x[21])) && (eventmain.mouse.y>=y[4]) && (eventmain.mouse.y<=(y[4]+y[3])))
            {
                out = 1;
                color[9]=al_map_rgb(255,255,0);
                next=true;

            }
            else if(optionTrue[1]==true && (eventmain.mouse.x>=x[22]) && (eventmain.mouse.x<=(x[22]+x[23])) && (eventmain.mouse.y>=y[1]) && (eventmain.mouse.y<=(y[1]+y[3])))
            {
                out = 2;
                color[8]=al_map_rgb(255,255,0);
                next=true;
            }
            else if(optionTrue[2]==true && (eventmain.mouse.x>=x[24]) && (eventmain.mouse.x<=(x[24]+x[25])) && (eventmain.mouse.y>=y[2]) && (eventmain.mouse.y<=(y[2]+y[3])))
            {
                Number++;
                return out;
            }
            else if(out==2)
            {
                color[8]=al_map_rgb(255,255,0);
                color[10]=al_map_rgb(255,255,0);
            }
            else if(out==1)
            {
                color[9]=al_map_rgb(255,255,0);
                color[10]=al_map_rgb(255,255,0);
            }
            else
            {
                color[8]=al_map_rgb(255,255,0);
                color[9]=al_map_rgb(255,255,0);
                color[10]=al_map_rgb(255,255,0);
            }
            for(int i=0;i<3;i++)
            {
                optionTrue[i]=false;
            }
        }
    }
}
void GameMenu::winner(int n)
{
    if(n==2)
        std::cout<<"winner g1"<<std::endl;
    else
        std::cout<<"winner g2"<<std::endl;
}
