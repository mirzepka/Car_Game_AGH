#include "headers.h"


GameMap::GameMap()
{
    numberOfSquares=0;
    numberOfObstacles=0;
    MapSizeX=3200;
    MapSizeY=3200;
    freespace=100;
    SX=5;
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
    for(int i=0;i<numberOfSquares;i++)
    {
           al_draw_filled_rectangle(squareX[i].first,squareY[i].first,squareX[i].second, squareY[i].second, al_map_rgb(i*100%255,i*90%255,i*100%255));

    }
    al_draw_line(0, 0, 3200, 0,al_map_rgb(10,0,0), 10);
    for(auto x:obstac){
        x.draw();
    }


}
void GameMap::init()
{
    int a=1,b=0;
    int temporary1,temporary2,tmp3;
    int XWidth=(MapSizeX-SX*freespace)/SX;
    int XHeight=(MapSizeY-SY*freespace)/SY;
    for(int i=0;i<SX;i++)
    {
        temporary1=0;
        temporary2=0;
         for(int j=a;j<SY;j++)
        {
            b=rand()%10;
            if(j!=b)
            {
                numberOfSquares++;
                tmp3=rand()%(3*XWidth/4);
                temporary1=i*(XWidth+freespace)+tmp3;
                temporary2=50+temporary1+rand()%(XWidth-tmp3);

                squareX.push_back(std::pair<double,double>(temporary1,temporary2));
                tmp3=rand()%(3*XHeight/4);
                temporary1=j*(XHeight+freespace)+tmp3;
                temporary2=50+temporary1+rand()%(XHeight-tmp3);

                squareY.push_back(std::pair<double,double>(temporary1,temporary2));
            }
            else
            {
                numberOfObstacles++;
               obstac.push_back(Obstacles(XWidth/2+(freespace+XWidth)*i,XHeight/2+(freespace+XHeight)*j,50+rand()%(XWidth/2),50+rand()%(XHeight/2)));
            }
        }
        a=0;
    }
}
bool GameMap::isCollisionBox()
{
    for(int j=0;j<8;j++)
        {
        if((Obstacles::rogiX[j]<0) || (Obstacles::rogiX[j] > MapSizeX) || (Obstacles::rogiY[j] <0) || (Obstacles::rogiY[j]>MapSizeY))
            return true;
        }
    return false;
}
bool GameMap::IsCollision(double posx,double posy,double angle){


    for(auto x:obstac){
           if(x.isCollision(posx,posy,angle))
           return true;
    }
    // kod na kwadraty korzystac z funkcji wywolanej w obstac.iscollision wiec przynajmniej jedno kolko musik byc na mapie
    for(int i=0;i<numberOfSquares;i++)
    {
        for(int j=0;j<8;j++)
            {
            if((Obstacles::rogiX[j]>squareX[i].first) && (Obstacles::rogiX[j] < squareX[i].second) && (Obstacles::rogiY[j] >squareY[i].first) && (Obstacles::rogiY[j]<squareY[i].second))
                return true;
            }
    }
    //brzegi
    if(isCollisionBox())
        return true;
    return false;

}
