#include <allegro5/allegro.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <iostream>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <cmath>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include <cstdio>
#include <time.h>
#define M_PI 3.14159265358979323846
#define FPS 60
/*
namespace patch
{
    template < typename T > std::string to_string( const T& n )
    {
        std::ostringstream stm ;
        stm << n ;
        return stm.str() ;
    }
}
*/
class Init
{
public:
    Init();
    ~Init();
};
class Options
{
    protected:
    int ScreenWidth, ScreenHeight;
    int ScreenFlags;
    void ScreenOptions();
    int getIntOptionFromTxt(std::string);
    std::string getStringOptionFromTxt(std::string);
    void changeOptions(std::string,std::string);
    public:
    Options();
    ~Options();
    int returnScreenWidth();            //returns width of screen
    int returnScreenHeight();           //returns height of screen
    int returnScreenFlags();            //returns screen flags
};

class Window : public Options
{
private:
    ALLEGRO_DISPLAY *display;
public:
    void change(std::string,std::string);
    Window();
    ~Window();
    int getHeight();
    int getWidth();
    ALLEGRO_DISPLAY * getDisplay();
};

class GameMap
{
private:
    double MapSizeX,MapSizeY;
    ALLEGRO_BITMAP *mapFront;
    //ALLEGRO_BITMAP *mapBack;
    int SX,SY;      // number of squares x and y
    int freespace; //free space between squares
    std::vector<std::pair<double,double>> squareX;    //x: parzysta+nieparzysta, Y= parzysta + nieparzysta
    std::vector<std::pair<double,double>> squareY;
    void init();
public:
    bool IsCollision(double,double);
    GameMap();
    ~GameMap();
    void draw();

};

class Timers
{
private:

public:

};
class GameMenu
{
    private:
        int ScrHeight,ScrWidth;
        int FontSize;
        int Number;
        ALLEGRO_EVENT_QUEUE * eventQueue;
        ALLEGRO_FONT * font;
        ALLEGRO_DISPLAY* display;
        ALLEGRO_BITMAP *mapMenu;
        ALLEGRO_COLOR color[11];
        std::vector<int> x;
        std::vector<int> y;
        void init();
        void draw();
        void drawSure();
        void drawChoice();
        void drawControler();
    public:
        bool YesNo();
        GameMenu(ALLEGRO_DISPLAY *);
        ~GameMenu();
        int WhichOption();
        int WhichOption2();
        int WhichOption3();
};
class Player
{
protected:
    GameMap mapa;
    ALLEGRO_TIMER* frameTimer;
    ALLEGRO_EVENT_QUEUE * eventQueue;
    ALLEGRO_BITMAP* model;
    ALLEGRO_TRANSFORM camera;
    double screenx,screeny;
    double posX,posY;                                          //current position
    int posX1,posY2;
    double moveSpeed;
    double acceleration;
    double gravity;
    double MAXF,MAXB;
    double angle;
    double NewPosY,NewPosX;
    double tempAngle,tempMoveSpeed;
public:
    Player(int,int);
    ~Player();
    void draw();
};
class PlayerKeyboard : public Player
{
    public:
    PlayerKeyboard(int,int);
    ~PlayerKeyboard();
    int movingKey();
};

class PlayerMobile : public Player
{
    SocketClient client;
    int tmpToClient;
    int out,TempX,TempY,StartX,StartY;
    public:
    PlayerMobile(int,int);
    ~PlayerMobile();
    int movingKey();
};

