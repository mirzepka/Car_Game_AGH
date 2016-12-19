#include "headers.h"

Checkpoints::Checkpoints()
{
    ;
}
Checkpoints::Checkpoints(int size1,std::vector<std::pair<double,double>> squareX,std::vector<std::pair<double,double>> squareY,std::vector<Obstacles> obstac,double MapSizeX,double MapSizeY)
{
    r=20;
    bool check1,check2;
    int licznik=0;
    double x1,y1;
    for(int i=0;i<size1;i++)
    {
        while(1)
        {
            check1=false,check2=false;
            licznik=0;
            x1=rand()%((int)(MapSizeX/(size1*1.0)))+i*MapSizeX/(size1*1.0);
            y1=rand()%((int)(MapSizeY/(size1*1.0)))+i*MapSizeY/(size1*1.0);
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
        checkpointObj.push_back(Obstacles(x1,y1,r,r));
    }
    std::random_shuffle ( checkpointObj.begin(), checkpointObj.end() );
}
void Checkpoints::draw()
{
    for(auto x:checkpointObj)
    {
      x.draw();
    }
}
