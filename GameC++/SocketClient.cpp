#include "headers.h"
#include <iostream>
#include <winsock2.h>
#include <string>



void SocketClient::init()
{

    startPositionX=0;
    startPositionY=0;

    mkword=MAKEWORD(2,2);
    int what=WSAStartup(mkword,&version);
    if(what!=0){
        std::cout<<"This version is not supported! - \n"<<WSAGetLastError()<<std::endl;
    }
    else{
        std::cout<<"Good - Everything fine!\n"<<std::endl;
    }
    u_sock=socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
    if(u_sock==INVALID_SOCKET)
        std::cout<<"Creating socket fail\n";
    else
        std::cout<<"It was okay to create the socket\n";
    //Socket address information
    addr.sin_family=AF_INET;
    addr.sin_addr.s_addr=inet_addr("127.0.0.1");
    addr.sin_port=htons(4444);
    /*==========Addressing finished==========*/
    //Now we connect
    int conn=connect(u_sock,(SOCKADDR*)&addr,sizeof(addr));
    if(conn==SOCKET_ERROR){
        std::cout<<"Error - when connecting "<<WSAGetLastError()<<std::endl;
        closesocket(u_sock);
        WSACleanup();
    }
    //Send some message to remote host
   // char* mymsg="GET / HTTP/1.1\r\n\r\n";
startPositionX=((getData()&0xff00)>>8)-120;
    startPositionY=((getData()&0xff))-120;
}
/*
    int smsg=send(u_sock,mymsg,sizeof(mymsg),0);
    if(smsg==SOCKET_ERROR){
        std::cout<<"Error: "<<WSAGetLastError()<<std::endl;
        WSACleanup();
    }
*/

int SocketClient::getData(void){

  //  std::cout<<"prosi"<<std::endl;
    int get=recv(u_sock,vect,4,0);
   // std::cout<<"prossssi"<<std::endl;
    if(get==SOCKET_ERROR){
        std::cout<<"Error in Receiving: "<<WSAGetLastError()<<std::endl;
        return 0;
    }

    int tempX=((0x0f&(vect[0]))<<4)|((0x0f&(vect[1])));
    int tempY=((0x0f&(vect[2]))<<4)|((0x0f&(vect[3])));
    std::cout<<"startPOS"<<startPositionY<<"y z telefonu "<<tempY<<std::endl;
    ////////// Uwzglednianie pozycji startowej:
    tempX-=startPositionX;
    if(tempX<0){
        tempX+=240;
    }
    else if(tempX>240){
        tempX-=240;
    }
    tempY-=startPositionY;
    if(tempY<0){
        tempY+=240;
    }
    else if(tempY>240){
        tempY-=240;
    }
  //  std::cout<<atoi(vect)<<std::endl;
  //std::cout<<(int)vect[0]<<int(vect[1])<<std::endl;
    return (tempX<<8)|(tempY);
}

  //  clossocket(u_sock);





