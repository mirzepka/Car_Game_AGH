#include "headers.h"
///////////kom
int main()
{
    srand (time(NULL));
    int OverFlag=1,option=0;
    Init initializer;
    Window mainWindow;
    GameMenu mainMenu(mainWindow.getDisplay());
while(OverFlag)
{
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
                    PlayerKeyboard g1(mainWindow.getWidth(),mainWindow.getHeight());
                    while(1)
                    {
                        //g1.draw();
                        g1.movingKey();

                    }
                }
                else
                {
                    //PlayerMobile g1(mainWindow.getWidth(),mainWindow.getHeight());
                    while(1)
                    {
                        //g1.draw();
                      // g1.movingKey();

                    }
                }
                break;
            case 2:
                if(mainMenu.WhichOption3()==1)
                {

                }
                else
                ;
                if(mainMenu.WhichOption3()==1)
                ;
                else
                ;
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
