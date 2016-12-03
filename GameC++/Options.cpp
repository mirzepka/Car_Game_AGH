#include "headers.h"


Options::Options()
{
    ScreenFlags=0;
    ScreenOptions();


}
Options::~Options()
{

}
int Options::getIntOptionFromTxt(std::string option)
{
    std::string test;
    std::string out;
    int i=0;
    std::ifstream config("config1.txt",std::ios::binary);
    if(!config)
    {
        //blad
    }
    while(!config.eof())
    {
        getline(config,test);
        if(i=test.find(option)!=std::string::npos)
        {
           out= test.substr(i+option.size());
           return atoi(out.c_str());
        }
    }
    config.close();
    return 0;
}
std::string Options::getStringOptionFromTxt(std::string option)
{
    std::string test;
    std::string out;
    int i=0;
    std::ifstream config("config1.txt",std::ios::binary);
    if(!config)
    {
        //blad
    }
    while(!config.eof())
    {
        getline(config,test);
        if(i=test.find(option)!=std::string::npos)
        {
           out= test.substr(i+option.size());
           out.pop_back();
           return out;
        }
    }
    config.close();
    return "";
}
 void Options::ScreenOptions()
{
    if(getStringOptionFromTxt("FullScreen")=="YES")
    {
        ScreenFlags|=ALLEGRO_FULLSCREEN;
    }
    else if(getStringOptionFromTxt("FullScreen")=="NO")
    {
        ScreenFlags&=~ALLEGRO_FULLSCREEN;
    }

      if(getStringOptionFromTxt("Frame")=="YES")
    {

        ScreenFlags&=~ALLEGRO_NOFRAME;
    }
    else if(getStringOptionFromTxt("Frame")=="NO")
    {
        ScreenFlags|=ALLEGRO_NOFRAME;
    }
    ScreenHeight=getIntOptionFromTxt("Height");
    ScreenWidth=getIntOptionFromTxt("Width");
}

void Options::changeOptions(std::string option,std::string value)
{
    std::string oldValue=getStringOptionFromTxt(option);
    std::ofstream saveFile("config.txt",std::ios::binary);
    std::string buffer,txtToCopy;
    std::ifstream readFile("config1.txt",std::ios::binary);
    while(readFile >> buffer)
    {
        if(buffer == option +":"+oldValue)
        {
            while(buffer[buffer.size()-1]!=':')
            {
                buffer.pop_back();
            }
            buffer=buffer+value;
        }
       saveFile<<buffer<<"\r\n";
    }
    readFile.close();
    remove("config1.txt");
    saveFile.close();
    std::rename("config.txt","config1.txt");




}


int Options::returnScreenWidth()
{
  return ScreenWidth;
}
int Options::returnScreenHeight()
{
  return ScreenHeight;
}
int Options::returnScreenFlags()
{
  return ScreenFlags;
}
