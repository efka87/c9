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
    float aMootor;
    std::string aKaigukast;
    std::string aVeoskeem;
    std::string aVIN;
    int aID;
                                     

    Autod(){};
  public:
    Autod(std::string mark, std::string mudel, int aasta, std::string kytus, float mootor, std::string kaigukast, std::string veoskeem, std::string vin, int autoID){
        aMark = mark;
        aMudel = mudel;                     //konstruktor andmete sisestamiseks,  ei ole kindel vb peab seda veel muutma
        aAasta = aasta;
        aKytus = kytus;
        aMootor = mootor;
        aKaigukast = kaigukast;
        aVeoskeem = veoskeem;
        aVIN = vin;
        aID = autoID;
    }

    void getInfo(){
        std::cout <<"Auto: "<<aMark << " : " << aMudel<< " : " << aAasta<< " : " << aKytus<< " : " << aMootor<< " : " << aKaigukast<< " : " << aVeoskeem<< " : " << aVIN<< " : " << aID<<std::endl;
    }
    
    std::string getmark(){
      return aMark;
    }
    std::string getmudel(){
      return aMudel;
    } 
    int getaasta(){
      return aAasta;
    }    
    std::string getkytus(){
      return aKytus;
    }
    float getmootor(){
      return aMootor;
    } 
    std::string getkaigukast(){
      return aKaigukast;
    }    
    std::string getveoskeem(){
      return aVeoskeem;
    }
    std::string getvin(){
      return aVIN;
    }   
    int getautoID(){
      return aID;
    }
  
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