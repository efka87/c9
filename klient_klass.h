#ifndef KLIENT_H
#define KLIENT_H
#include <iostream>
#include <string>

// klient klassi loomine (Lauri)

class Klient{
  private:
    std::string kEesnimi;
    std::string kPerenimi;
    int kKliendi_id;
    std::string kTelefon;
    std::string kEmail;

    Klient(){};
    
  public:
    Klient(std::string Eesnimi, std::string Perenimi, int Kliendi_id, std::string Telefon, std::string Email){
        kEesnimi = Eesnimi;
        kPerenimi = Perenimi;
        kKliendi_id = Kliendi_id;
        kTelefon = Telefon;
        kEmail = Email;
        
        
    }  
    void getInfo(){
        std::cout <<"Kliendid: "<<kEesnimi << " : " << kPerenimi<< " : " << kKliendi_id<< " : " << kTelefon<< " : " << kEmail<<std::endl;
    }
     std::string getEesnimi(){
      return kEesnimi;
    }
     std::string getPerenimi(){
      return kPerenimi;
    }
     int getKliendi_id(){
      return kKliendi_id;
    }
     std::string getTelefon(){
      return kTelefon;
    }
     std::string getEmail(){
      return kEmail;
    }
  
  
};

#endif