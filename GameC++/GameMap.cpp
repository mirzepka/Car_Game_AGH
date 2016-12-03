#include "headers.h"


GameMap::GameMap()
{
    MapSizeX=3200;
    MapSizeY=3200;
    freespace=100;
    SX=10;
    SY=SX;
    mapFront = al_load_bitmap("mapNO1.png");
    init();
}
GameMap::~GameMap()
{
    al_destroy_bitmap(mapFront);
    //al_destroy_bitmap(mapBack);
}
void GameMap::draw()
{
    al_draw_bitmap(mapFront, 0, 0, 0);
    for(int i=0;i<SX*SY-1;i++)
    {
           al_draw_filled_rectangle(squareX[i].first,squareY[i].first,squareX[i].second, squareY[i].second, al_map_rgb(i*100%255,i*90%255,i*100%255));

    }
}
void GameMap::init()
{
    int a=1;
    int temporary1,temporary2,tmp3;
    int XWidth=(MapSizeX-SX*freespace)/SX;
    int XHeight=(MapSizeY-SY*freespace)/SY;
    for(int i=0;i<SX;i++)
    {
        temporary1=0;
        temporary2=0;
         for(int j=a;j<SY;j++)
        {
            tmp3=rand()%(3*XWidth/4);
            temporary1=i*(XWidth+freespace)+tmp3;
            temporary2=50+temporary1+rand()%(XWidth-tmp3);
                std::cout<<temporary1<<"--"<<temporary2<<"  ";
            squareX.push_back(std::pair<int,int>(temporary1,temporary2));
        tmp3=rand()%(3*XHeight/4);
            temporary1=j*(XHeight+freespace)+tmp3;
            temporary2=50+temporary1+rand()%(XHeight-tmp3);
                std::cout<<temporary1<<"--"<<temporary2<<std::endl;
            squareY.push_back(std::pair<int,int>(temporary1,temporary2));
        }
        a=0;
    }
}
bool GameMap::IsCollision(int posx,int posy)
{
    std::cout<<posx<<"--"<<posy<<std::endl;
    for(int i=0;i<SX*SY-1;i++)
    {
        if((posx>squareX[i].first) && (posx < squareX[i].second) && (posy >squareY[i].first) && (posy<squareY[i].second))
            return true;
    }
    return false;
}
