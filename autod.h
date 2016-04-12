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
                                     

    Autod(){};
  public:
    Autod(std::string mark, std::string mudel, int aasta, std::string kytus, int mootor, std::string kaigukast, std::string veoskeem, std::string vin){
        aMark = mark;
        aMudel = mudel;                     //konstruktor andmete sisestamiseks,  ei ole kindel vb peab seda veel muutma
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

/*    Sõidukite alaliigid, igaks juhuks kommentaarisin välja, kuna ei tea kas neid võib päris tühjaks jätta

class Maastur : public Autod{
    
};
class Soiduauto : public Autod{
    
};
class Pakibuss : public Autod{
    
};

*/

#endif