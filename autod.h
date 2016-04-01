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
    Autod(std::string mark, std::string mudel, int aasta, std::string kytus, int mootor, std::string kaigukast, std::string veoskeem, std::string vin){
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
    
};

#endif