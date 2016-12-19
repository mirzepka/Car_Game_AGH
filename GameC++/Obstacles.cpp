#include "headers.h"


Obstacles::Obstacles(double tempx,double tempy,double scax,double scay){
    xCenter=tempx;
    yCenter=tempy;
    scaleX=scax;
    scaleY=scay;
    color=al_map_rgb((int)xCenter*100%255,(int)yCenter*90%255,(int)xCenter*(int)yCenter*100%255);
    values.push_back(xCenter);
    values.push_back(yCenter);
    values.push_back(scaleX);
    values.push_back(scaleY);
}
bool Obstacles::isCollision(const double *rogiX,const double *rogiY,const double &x,const double &y,const double &angle){
    if((pow(rogiY[1]-yCenter,2)+pow((rogiX[1]-xCenter)*scaleY/scaleX,2))>(pow(scaleY,2)+70.0))
       {
            for(int i=0;i<8;i++)
            {
                if((pow(rogiY[i]-yCenter,2)+pow((rogiX[i]-xCenter)*scaleY/scaleX,2))<=pow(scaleY,2))
                {
                    return true;
                }
            }
       }
        return false;



}
void Obstacles::draw(){
    al_draw_filled_ellipse(xCenter, yCenter, scaleX, scaleY,color);
}
std::vector<double> Obstacles::returnValues()
{
    return values;
}
