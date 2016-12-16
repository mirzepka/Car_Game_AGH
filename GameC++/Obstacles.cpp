#include "headers.h"
double Obstacles::rogiX[4];
double Obstacles::rogiY[4];

Obstacles::Obstacles(double tempx,double tempy,double scax,double scay){
    xCenter=tempx;
    yCenter=tempy;
    scaleX=scax;
    scaleY=scay;
    color=al_map_rgb((int)xCenter*100%255,(int)yCenter*90%255,(int)xCenter*(int)yCenter*100%255);




}
bool Obstacles::isCollision(double x,double y,double angle){
    if((pow(y-yCenter,2)+pow((x-xCenter)*scaleY/scaleX,2)+100)>pow(scaleY,2)){  // sprawdza czy obiekt jest blisko i dopiero wtedy liczyczy nie ma zderzenia
    double xtmp,ytmp,wsp=25.0;
    for(int i=0;i<2;i++){
      xtmp=35*sin((-angle+wsp+90.0+180.0*i)*M_PI/180.0)+x;
      ytmp=35*cos((-angle+wsp+90.0+180.0*i)*M_PI/180.0)+y;
        rogiX[i]=xtmp;
        rogiY[i]=ytmp;

      if((pow(ytmp-yCenter,2)+pow((xtmp-xCenter)*scaleY/scaleX,2))<=pow(scaleY,2)){
        return true;
      }
         xtmp=35*sin((-angle-wsp+90.0+180.0*i)*M_PI/180.0)+x;
      ytmp=35*cos((-angle-wsp+90.0+180.0*i)*M_PI/180.0)+y;
         rogiX[i+2]=xtmp;
        rogiY[i+2]=ytmp;
      if((pow(ytmp-yCenter,2)+pow((xtmp-xCenter)*scaleY/scaleX,2))<=pow(scaleY,2)){
        return true;
    }

    }

        return false;
    }
    else {
        return false;
    }


}
void Obstacles::draw(){
    al_draw_filled_ellipse(xCenter, yCenter, scaleX, scaleY,color);
}

