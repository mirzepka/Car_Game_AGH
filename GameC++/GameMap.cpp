#include "headers.h"


GameMap::GameMap()
{
    numberOfSquares=0;
    numberOfObstacles=0;
    MapSizeX=3200;
    MapSizeY=3200;
    freespace=100;
    numberOfCheckpoints=2;
    SX=5;
    SY=SX;
    mapFront = al_load_bitmap("mapNO1.png");
    init();
    promienCheckpoint=20;
    initCheckpoints();
    currentCheckpoint = new Obstacles(checkpointObj[0].first,checkpointObj[0].second,promienCheckpoint,promienCheckpoint);
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
        if((rogiX[j]<0) || (rogiX[j] > MapSizeX) || (rogiY[j] <0) || (rogiY[j]>MapSizeY))
            return true;
        }
    return false;
}
bool GameMap::IsCollision(const double &posx,const double &posy,const double &angle,int &checkpointCounter){
    rogiCalculate(posx,posy,angle);

    for(auto x:obstac){
          if(x.isCollision(rogiX,rogiY,posx,posy,angle))
          return true;
   }

    for(int i=0;i<numberOfSquares;i++)
    {

        if(pow(rogiX[1]-(squareX[i].second-squareX[i].first)/2,2)+pow(rogiY[1]-(squareY[i].second-squareY[i].first)/2,2)>sqrt((pow((squareX[i].second-squareX[i].first)/2,2))+(pow((squareY[i].second-squareY[i].first)/2,2) )+70.0)){
        for(int j=0;j<8;j++)
            {
            if((rogiX[j]>squareX[i].first) && (rogiX[j] < squareX[i].second) && (rogiY[j] >squareY[i].first) && (rogiY[j]<squareY[i].second))
                return true;
            }
        }
    }
    //brzegi
    if(Obstacles(checkpointObj[checkpointCounter].first,checkpointObj[checkpointCounter].second,promienCheckpoint,promienCheckpoint).isCollision(rogiX,rogiY,posx,posy,angle))
    {
        checkpointCounter++;
    }
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
void GameMap::initCheckpoints()
{

    bool check1,check2;
    int licznik=0;
    double x1,y1;
    for(int i=0;i<numberOfCheckpoints;i++)
    {
        while(1)
        {
            check1=false,check2=false;
            licznik=0;
            x1=rand()%((int)(MapSizeX/(numberOfCheckpoints*1.0)))+i*MapSizeX/(numberOfCheckpoints*1.0);
            y1=rand()%((int)(MapSizeY/(numberOfCheckpoints*1.0)))+i*MapSizeY/(numberOfCheckpoints*1.0);
            for(auto x:squareX)
                {
                    if(x1>x.first && x1<x.second && y1>squareY[i].first && y1<squareY[i].second)
                        check1=true;
                    licznik++;
                }
            for(auto x:obstac)
               {

                   if((pow(x1-x.returnValues()[0],2)+pow((y1-x.returnValues()[1])*x.returnValues()[3]/x.returnValues()[2],2))<=pow(x.returnValues()[3],2))
                       check2 = true;
               }
            if(check1==false && check2== false)
                break;
        }
        checkpointObj.push_back(std::pair<double,double>(x1,y1));
    }
    std::random_shuffle ( checkpointObj.begin(), checkpointObj.end() );
}
void GameMap::drawingCheckpoint(int n)
{
    Obstacles(checkpointObj[n].first,checkpointObj[n].second,promienCheckpoint,promienCheckpoint).drawColor(al_map_rgb(255,0,0));
}
int GameMap::returnCheckpoints()
{
    return  numberOfCheckpoints;
}
