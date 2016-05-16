#include "klient.h"
#include <vector>
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

vector<Klient*> klientLisamine(string Eesnimi, string Perenimi, int Kliendi_id, string Telefon, string Email, vector<Klient*> klientNimekiri){
    cout << endl << "Enter kliendi Eesnimi: ";
    getline(cin,Eesnimi);  //getline lisamisel lahenes tühiku kasutamise probleem aga tekkis failist lugemise error(failis pole andmetüüpe, loeb tühikust tühikuni)
    cout << endl << "Enter kliendi Perenimi: ";
    getline(cin,Perenimi);
    cout << endl << "Enter kliendi Kliendi_id: ";
    cin >> Kliendi_id;
    cout << endl << "Enter kliendi Telefon: ";
    cin >> Telefon;
    cout << endl << "Enter kliendi Email: ";
    cin >> Email;
    
    Klient *newKlient = new Klient(Eesnimi, Perenimi, Kliendi_id, Telefon, Email);
    klientNimekiri.push_back(newKlient);
    cout << "New client entered successfully" << endl;
    
    return klientNimekiri;
}

// klientide failist lugemine

vector<Klient*> nimekirjaFailistLugemine(string Eesnimi, string Perenimi,int Kliendi_id, string Telefon, string Email, vector<Klient*> klientNimekiri){
    
    ifstream iFile;
    iFile.open("klient.txt");
    
    while(iFile.good()){
        
        iFile >> Eesnimi >> Perenimi >> Kliendi_id >> Telefon >> Email;                  // loen failist kliendi andmed
        Klient *newKlient = new Klient(Eesnimi, Perenimi, Kliendi_id, Telefon, Email);   //kliendi andmed newKlient viita
        klientNimekiri.push_back(newKlient);                   // lükkan kliendi newKlient klientNimekirja
        
    }
    klientNimekiri.pop_back();
    
    iFile.close();
    
    return klientNimekiri;
}


void andmeteFailiSalvestamine(vector<Klient*> klientNimekiri){
    
    ofstream oFile;
    oFile.open("klient.txt");
    
    for(int i=0; i<klientNimekiri.size();i++){
        oFile << klientNimekiri[i]->getEesnimi() 
            << " " << klientNimekiri[i]->getPerenimi()
            << " " << klientNimekiri[i]->getKliendi_id() 
            << " " << klientNimekiri[i]->getTelefon()
            << " " << klientNimekiri[i]->getEmail()
            << endl;
    }
    
    cout << "Edukalt salvestatud" << endl;
    oFile.close();
}

int main(){
    
    // muutujate deklareerimine
    vector<Klient*> klientNimekiri;
    string Eesnimi, Perenimi, Telefon, Email;
    int Kliendi_id;
    
    // loeb klient failist nimekirja
    klientNimekiri=nimekirjaFailistLugemine(Eesnimi, Perenimi, Kliendi_id, Telefon, Email, klientNimekiri);
    // kliendi käsitsi nimekirja lisamine
    klientNimekiri=klientLisamine(Eesnimi, Perenimi, Kliendi_id, Telefon, Email, klientNimekiri);
    // salvestab klient nimekirja faili
    andmeteFailiSalvestamine(klientNimekiri);

    // väljastab klientNimekiri sisu
    for(int i = 0;i<klientNimekiri.size();i++){
        cout << i+1 <<": ";
        klientNimekiri[i]->getInfo();
        cout << endl;
    }
    
    
}