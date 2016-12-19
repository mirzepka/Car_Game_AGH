#include "headers.h"


GameMap::GameMap()
{
    numberOfSquares=0;
    numberOfObstacles=0;
    MapSizeX=3200;
    MapSizeY=3200;
    freespace=100;
    numberOfCheckpoints=10;
    SX=5;
    SY=SX;
    mapFront = al_load_bitmap("mapNO1.png");
    init();
    checkP=Checkpoints(numberOfCheckpoints,squareX,squareY,obstac,MapSizeX,MapSizeY);
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
    checkP.draw();

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
        if((rogiX[j]<0) || (rogiX[j] > MapSizeX) || (rogiY[j] <0) || (rogiY[j]>MapSizeY))
            return true;
        }
    return false;
}
bool GameMap::IsCollision(const double &posx,const double &posy,const double &angle){
    rogiCalculate(posx,posy,angle);

    for(auto x:obstac){
          if(x.isCollision(rogiX,rogiY,posx,posy,angle))
          return true;
   }

    for(int i=0;i<numberOfSquares;i++)
    {
        for(int j=0;j<8;j++)
            {
            if((rogiX[j]>squareX[i].first) && (rogiX[j] < squareX[i].second) && (rogiY[j] >squareY[i].first) && (rogiY[j]<squareY[i].second))
                return true;
            }
    }
    //brzegi
    if(isCollisionBox())
        return true;
    return false;

}
void GameMap::rogiCalculate(const double &x,const double &y,const double &angle)
{
     double xtmp,ytmp,wsp=25.0;
    for(int i=0;i<2;i++){
        xtmp=35*sin((-angle+wsp+90.0+180.0*i)*M_PI/180.0)+x;
        ytmp=35*cos((-angle+wsp+90.0+180.0*i)*M_PI/180.0)+y;
        rogiX[i]=xtmp;
        rogiY[i]=ytmp;
        xtmp=35*sin((-angle-wsp+90.0+180.0*i)*M_PI/180.0)+x;
        ytmp=35*cos((-angle-wsp+90.0+180.0*i)*M_PI/180.0)+y;
        rogiX[i+2]=xtmp;
        rogiY[i+2]=ytmp;
    }
    rogiX[4]=x+((rogiX[0]-rogiX[2])/2.0);
    rogiY[4]=y+((rogiY[0]-rogiY[2])/2.0);
    rogiX[5]=x+((rogiX[2]-rogiX[1])/2.0);
    rogiY[5]=y+((rogiY[2]-rogiY[1])/2.0);
    rogiX[6]=x+((rogiX[1]-rogiX[3])/2.0);
    rogiY[6]=y+((rogiY[1]-rogiY[3])/2.0);
    rogiX[7]=x+((rogiX[3]-rogiX[0])/2.0);
    rogiY[7]=y+((rogiY[3]-rogiY[0])/2.0);
}
