#ifndef KLIENT_H
#define KLIENT_H
#include <iostream>
#include <string>

// klient klassi loomine (Lauri)

class Klient{
  private:
    std::string kEesnimi;
    std::string kPerenimi;
    std::string kKliendi_id;
    int kTelefon;
    std::string kEmail;

    Klient(){};
    
  public:
    Klient(std::string Eesnimi, std::string Perenimi, std::string Kliendi_id, int Telefon, std::string Email){
        kEesnimi = Eesnimi;
        kPerenimi = Perenimi;
        kKliendi_id = Kliendi_id;
        kTelefon = Telefon;
        kEmail = Email;
        
    }      
  
};

#endif