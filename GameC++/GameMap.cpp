#include "headers.h"
double GameMap::xtmp[4];
double GameMap::ytmp[4];

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
    al_draw_line(0, 0, 3200, 0,al_map_rgb(10,0,0), 10);
    for(auto x:obstac){
        x.draw();
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
            squareX.push_back(std::pair<double,double>(temporary1,temporary2));
        tmp3=rand()%(3*XHeight/4);
            temporary1=j*(XHeight+freespace)+tmp3;
            temporary2=50+temporary1+rand()%(XHeight-tmp3);
                std::cout<<temporary1<<"--"<<temporary2<<std::endl;
            squareY.push_back(std::pair<double,double>(temporary1,temporary2));
        }
        a=0;
    }
    for(int i=0;i<7;i++){
        obstac.push_back(Obstacles(i*250,i*250,50+i*10,2*(50+i*10)));
    }
}
bool GameMap::IsCollision(double posx,double posy,double angle){


    for(auto x:obstac){
           if(x.isCollision(posx,posy,angle))
           return true;
    }

    xtmp[0]=posx+((Obstacles::rogiX[0]-Obstacles::rogiX[2])/2.0);
    ytmp[0]=posy+((Obstacles::rogiY[0]-Obstacles::rogiY[2])/2.0);
    xtmp[1]=posx+((Obstacles::rogiX[2]-Obstacles::rogiX[1])/2.0);
    ytmp[1]=posy+((Obstacles::rogiY[2]-Obstacles::rogiY[1])/2.0);
    xtmp[2]=posx+((Obstacles::rogiX[1]-Obstacles::rogiX[3])/2.0);
    ytmp[2]=posy+((Obstacles::rogiY[1]-Obstacles::rogiY[3])/2.0);
    xtmp[3]=posx+((Obstacles::rogiX[3]-Obstacles::rogiX[0])/2.0);
    ytmp[3]=posy+((Obstacles::rogiY[3]-Obstacles::rogiY[0])/2.0);

    for(int i=0;i<SX*SY-1;i++)
    {
        for(int j=0;j<4;j++)
            {
            if((Obstacles::rogiX[j]>squareX[i].first) && (Obstacles::rogiX[j] < squareX[i].second) && (Obstacles::rogiY[j] >squareY[i].first) && (Obstacles::rogiY[j]<squareY[i].second))
                return true;

            if((xtmp[j]>squareX[i].first) && (xtmp[j] < squareX[i].second) && (ytmp[j] >squareY[i].first) && (ytmp[j]<squareY[i].second))
                return true;
            }
    }
    return false;
}
