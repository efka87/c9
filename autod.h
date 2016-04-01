#ifndef AUTOD_H
#define AUTOD_H
#include <iostream>
#include <string>

class Autod{
  private:
    std::string aMark;
    std::string aMudel;
    int aAasta;
    std::string aKytus;
    int aMootor;
    std::string aKaigukast;
    std::string aVeoskeem;
    std::string aVIN;
                                     //  tegelen hiljem   Autoliik(maastur/pakibuss/sõiduauto)

    Autod(){};
  public:
    Autod(std::string aMark mark, std::string aMudel mudel, int aAasta aasta, std::string aKytus kytus, int aMootor mootor, std::string aKaigukast kaigukast, std::string aVeoskeem veoskeem, std::string aVIN vin;){
        aMark = mark;
        aMudel = mudel;
        aAasta = aasta;
        aKytus = kytus;
        aMootor = mootor;
        aKaigukast = kaigukast;
        aVeoskeem = veoskeem;
        aVIN = vin;
    }

  //  void getInfo(){
    //    std::cout << "Name: " << aName << " : " << aNumber << std::endl;

  
};

class Maastur : public Autod{
    
};
class Soiduauto : public Autod{
    
};
class Pakibuss : public Autod{
    
}

#endif