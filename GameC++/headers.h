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
class Obstacles{
    double xCenter, yCenter;
double scaleX,scaleY;
ALLEGRO_COLOR color;
public:
    //////////////////
 static    double rogiX[4];
static double rogiY[4];
    ////////////////////
Obstacles(double tempx=200,double tempy=200,double scax=100,double scay=200);
bool isCollision(double x,double y,double angle);
void draw();
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
    std::vector<Obstacles> obstac;   // przeszkody eliptyczne
    void init();
public:
    static double xtmp[4];
    static double ytmp[4];
    bool IsCollision(double,double,double);
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
    ALLEGRO_DISPLAY* display;
    ALLEGRO_EVENT_QUEUE * eventQueue;
    ALLEGRO_BITMAP* model;
    ALLEGRO_TRANSFORM camera;
    double screenx,screeny;
    double posX,posY;                                          //current position
    double moveSpeed;
    double acceleration;
    double gravity;
    double MAXF,MAXB;
    double angle;
    double NewPosY,NewPosX;
    double tempAngle,tempMoveSpeed;
    double turning;
    int keyL,keyR,keyU,keyD;

public:
    Player(ALLEGRO_DISPLAY*,int,int);
    ~Player();
    void draw();
};

class PlayerKeyboard : public Player
{
    public:
        static bool secondPlayer;
    PlayerKeyboard(ALLEGRO_DISPLAY*,int,int);
    ~PlayerKeyboard();
    int movingKey();
};
class SocketClient
 {
     WSAData version;//We need to check the version.
     WORD mkword;
     SOCKET u_sock;
     sockaddr_in addr;
     char vect[4];
     int startPositionX,startPositionY;

    public:
     void init(void);
     int getData(void);

 };
class PlayerMobile : public Player
{
    SocketClient client;
    int tmpToClient;
    int out,TempX,TempY,StartX,StartY;
    public:
    PlayerMobile(ALLEGRO_DISPLAY*,int,int);
    ~PlayerMobile();
    int movingKey();
};

class PlayerKeyboard2 : public PlayerKeyboard
{
private:
    ALLEGRO_BITMAP* model2;
    ALLEGRO_BITMAP* screen1;
    ALLEGRO_BITMAP* screen2;
    double posX2,posY2;
    double moveSpeed2;
    double acceleration2;
    double gravity2;
    double MAXF2,MAXB2;
    double angle2;
    double NewPosY2,NewPosX2;
    double tempAngle2,tempMoveSpeed2;
    double turning2;
    void drawing2();
    ALLEGRO_TRANSFORM camera2;
    public:
    PlayerKeyboard2(ALLEGRO_DISPLAY*,int,int);
    int movingKey();
};
