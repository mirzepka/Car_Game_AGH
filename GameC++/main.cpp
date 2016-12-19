#include "headers.h"
///////////kom
int main()
{
    srand (time(NULL));
    int OverFlag=1,flag=1,option=0;
    Init initializer;
    Window mainWindow;
    GameMenu mainMenu(mainWindow.getDisplay());
while(OverFlag)
{
    flag=1;
        option = mainMenu.WhichOption();
    switch(option)
    {
        case 1:
            //wybor mapy

            option=mainMenu.WhichOption2();
            switch(option)
            {
            case 1:
                if(mainMenu.WhichOption3()==1)
                {
                    PlayerKeyboard g1(mainWindow.getDisplay(),mainWindow.getWidth(),mainWindow.getHeight());
                    while(flag==1)
                    {

                        g1.movingKey();

                    }
                }
                else
                {
                    PlayerMobile g1(mainWindow.getDisplay(),mainWindow.getWidth(),mainWindow.getHeight());
                    while(flag==1)
                    {

                       g1.movingKey();

                    }
                }
                break;
            case 2:
                if(mainMenu.WhichOption3()==1)
                {
                    if(mainMenu.WhichOption3()==1)
                    {
                        PlayerKeyboard2 g(mainWindow.getDisplay(),mainWindow.getWidth(),mainWindow.getHeight());
                        while(flag==1)
                        {
                            flag=g.movingKey();
                        }
                        mainMenu.winner(flag);
                    }
                    else
                    {
                     ;
                    }
                }
                else
                {
                    if(mainMenu.WhichOption3()==1)
                    {
                       ;
                    }
                    else
                    {
                        ;
                    }
                }
                break;
            }
            break;
        case 2:
            std::cout<<"options"<<std::endl;
            break;
        case 3:
            OverFlag=0;
            break;
        default:
            break;
    }
}
    return 0;
}
