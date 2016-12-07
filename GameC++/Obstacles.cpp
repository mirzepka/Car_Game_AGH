#include "headers.h"

Obstacles::Obstacles(double tempx,double tempy,double scax,double scay){
    xCenter=tempx;
    yCenter=tempy;
    scaleX=scax;
    scaleY=scay;
    color=al_map_rgb((int)xCenter*100%255,(int)yCenter*90%255,(int)xCenter*(int)yCenter*100%255);

}
bool Obstacles::isCollision(double x,double y,double angle){
    std::cout<<(pow(y-yCenter,2)+pow((x-xCenter)*scaleY/scaleX,2))<<std::endl;
    double xtmp,ytmp,wsp=65.0;
    for(int i=0;i<2;i++){
      xtmp=30*sin((angle+wsp+180.0*i)*M_PI/180.0)+x;
      ytmp=30*cos((angle+wsp+180.0*i)*M_PI/180.0)+y;

    al_draw_filled_rectangle(xtmp, ytmp, xtmp+20, ytmp+20,color);
      if((pow(ytmp-yCenter,2)+pow((xtmp-xCenter)*scaleY/scaleX,2))<pow(scaleY,2)){
        return true;
      }
         xtmp=35*sin((angle+2*wsp+180.0*i)*M_PI/180.0)+x;
      ytmp=35*cos((angle+2*wsp+180.0*i)*M_PI/180.0)+y;
al_draw_filled_rectangle(xtmp, ytmp, xtmp+20, ytmp+20,color);
      if((pow(ytmp-yCenter,2)+pow((xtmp-xCenter)*scaleY/scaleX,2))<pow(scaleY,2)){
        return true;
    }

    }

        return false;


}
void Obstacles::draw(){
    al_draw_filled_ellipse(xCenter, yCenter, scaleX, scaleY,color);
}

