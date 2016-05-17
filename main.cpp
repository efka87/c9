#include "autod.h"
#include "klient_klass.h"
#include "autod.h"
#include <vector>
#include <string>
#include <iostream>
#include <fstream>

using namespace std;


vector<Klient*> klientLisamine(string Eesnimi, string Perenimi, int Kliendi_id, string Telefon, string Email,int W, vector<Klient*> klientNimekiri){
    string vaheInt;
    
    cout << endl << "Enter kliendi Eesnimi: ";
    getline(cin,Eesnimi);  //getline lisamisel lahenes tühiku kasutamise probleem aga tekkis failist lugemise error(failis pole andmetüüpe, loeb tühikust tühikuni)
    cout << endl << "Enter kliendi Perenimi: ";
    getline(cin,Perenimi);
  //  cout << endl << "Enter kliendi Kliendi_id: ";
  //  getline(cin, vaheInt);
  //  Kliendi_id=atoi(vaheInt.c_str());
    Kliendi_id = W;
    cout << endl << "Enter kliendi Telefon: ";
    getline(cin,Telefon);
    cout << endl << "Enter kliendi Email: ";
    getline(cin,Email);
    
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

int getID( vector<Autod*> autoNimekiri){
    int u,v,ID;
    // kui autoNimekisi on tühi siis esimene auto saab id-ks 0
    if(autoNimekiri.size()==0){
        ID=1;
    }
    //kõigi ülejäänud autode id tuleb viimase auto id pluss 1
    else{
        u=autoNimekiri.size()-1;
        v=autoNimekiri[u]->getautoID() ;
        ID=v+1;
    }
    return ID;
}

vector<Autod*> autoLisamine(string mark, string mudel,int aasta, string kytus, float mootor, string kaigukast, string veoskeem, string vin,int autoID, vector<Autod*> autoNimekiri){
    
    int valik;
    string mootorString;
    string aastaString;
    string valikString;
    
    cout << endl << "Enter auto mark: ";
    getline(cin, mark);
    cout << endl << "Enter auto mudel: ";
    cin >> mudel;
    
    cout << endl << "Enter auto aasta: ";
    //teeb kuni mootori maht on õiges vahemikus
    while(aasta<1900 || aasta>2016){
        //loeb sisestuse stringi
        getline(cin, aastaString);
        //teeb stringi int-iks
        aasta=atoi(aastaString.c_str());
        //kui suurus ei ole õiges vahemikus edastab veateate
        if(1900<aasta && aasta<=2016){
            
        }
        else{
            cout << "\nAasta peab jääma vahemiku 1900-2016\n";
            
        }
    }
    
    cout << endl << "Enter auto kytus: \n";
    while(valik<1 || valik>3){
        cout<<"1. Bensiin\n";
        cout<<"2. Diisel\n";
        cout<<"3. Gaas\n";
        cout<<"Valik: ";
        //loeb sisestuse stringi
        getline(cin, valikString);
        //teeb stringi int-iks
        valik=atoi(valikString.c_str());
        switch ( valik ) {
            case 1:
                kytus="bensiin";
            break;
            case 2:
                kytus="diisel";
            break;
            case 3:
                kytus="gaas";
            break;
            default:
                cout<<"Esines viga. Valige '1', '2', '3' \n";
            break;
        }
    }
    valik=0;
    
    cout << endl << "Enter auto mootor liitrites (2.5): \n";
    //teeb kuni mootori maht on õiges vahemikus
    while(mootor<0.5 || mootor>9){
        //loeb sisestuse stringi
        getline(cin, mootorString);
        //teeb stringi float-iks
        mootor=atof(mootorString.c_str());
        //kui suurus ei ole õiges vahemikus edastab veateate
        if(0.5<mootor && mootor<=9){
            
        }
        else{
            cout << "\nMootor peab jääma vahemiku 0.6-9\n";
            
        }
    }
    
    cout << endl << "Enter auto kaigukast: \n";
    while(valik<1 || valik>2){
        cout<<"1. Manuaal\n";
        cout<<"2. Automaat\n";
        cout<<"Valik: ";
        //loeb sisestuse stringi
        getline(cin, valikString);
        //teeb stringi int-iks
        valik=atoi(valikString.c_str());
        switch ( valik ) {
            case 1:
                kaigukast="manuaal";
            break;
            case 2:
                kaigukast="automaat";
            break;
            default:
                cout<<"Esines viga. Valige '1', '2' \n";
            break;
        }
    }
    valik=0;
    
    cout << endl << "Enter auto veoskeem: \n";
    while(valik<1 || valik>3){
        cout<<"1. Esivedu\n";
        cout<<"2. Tagavedu\n";
        cout<<"3. Nelikvedu\n";
        cout<<"Valik: ";
        //loeb sisestuse stringi
        getline(cin, valikString);
        //teeb stringi int-iks
        valik=atoi(valikString.c_str());
        switch ( valik ) {
            case 1:
                veoskeem="esivedu";
            break;
            case 2:
                veoskeem="tagavedu";
            break;
            case 3:
                veoskeem="nelikvedu";
            break;
            default:
                cout<<"Esines viga. Valige '1', '2', '3' \n";
            break;
        }   
    }
    valik=0;
    
    cout << endl << "Enter auto vin: ";
    getline(cin,vin);    
    
    //võtan autoID-le väärtuse
    autoID=getID(autoNimekiri);

    Autod *newAuto = new Autod(mark, mudel, aasta, kytus, mootor, kaigukast, veoskeem, vin, autoID);
    autoNimekiri.push_back(newAuto);
    cout << "New product entered successfully" << endl;
    
    return autoNimekiri;

}

// autode failist lugemine

vector<Autod*> nimekirjaFailistLugemine(string mark, string mudel,int aasta, string kytus, float mootor, string kaigukast, string veoskeem, string vin,int autoID, vector<Autod*> autoNimekiri){
    
    ifstream iFile;
    iFile.open("autod.txt");
    
    while(iFile.good()){
        
        iFile >> mark >> mudel >> aasta >> kytus >> mootor >> kaigukast >> veoskeem >> vin >> autoID;                  // loen failist auto andmed
        Autod *newAuto = new Autod(mark, mudel, aasta, kytus, mootor, kaigukast, veoskeem, vin, autoID);   // panen auto andmed newAuto viita
        autoNimekiri.push_back(newAuto);                   // Lükkan auto newAuto viida autoNimekirja
        
    }
    //kustutab autoNimekiri viimase elemendi mida ta kogemata topelt luges
    autoNimekiri.pop_back();
    
    iFile.close();
    
    return autoNimekiri;
}


void nimekirjaFailiSalvestamine(vector<Autod*> autoNimekiri){
    
    ofstream oFile;
    oFile.open("autod.txt");
    
    for(int i=0; i<autoNimekiri.size();i++){
        oFile << autoNimekiri[i]->getmark() 
            << " " << autoNimekiri[i]->getmudel()
            << " " << autoNimekiri[i]->getaasta() 
            << " " << autoNimekiri[i]->getkytus()
            << " " << autoNimekiri[i]->getmootor()
            << " " << autoNimekiri[i]->getkaigukast()
            << " " << autoNimekiri[i]->getveoskeem()
            << " " << autoNimekiri[i]->getvin()
            << " " << autoNimekiri[i]->getautoID()
            << endl;
    }
    
    cout << "Edukalt salvestatud" << endl;
    oFile.close();
}

int main(){
    
    // muutujate deklareerimine
    vector<Autod*> autoNimekiri;
    string mark, mudel, kytus, kaigukast, veoskeem, vin;
    int aasta, autoID, valik=0;
    float mootor;
    int a[5][8];
    int rida,veerg;
    int q,w;
    vector<Klient*> klientNimekiri;
    string Eesnimi, Perenimi, Telefon, Email;
    int Kliendi_id;
    
    
    // loeb autod failist nimekirja
    autoNimekiri=nimekirjaFailistLugemine(mark,mudel,aasta, kytus, mootor, kaigukast, veoskeem,  vin, autoID, autoNimekiri);
    // auto käsitsi nimekirja lisamine
    autoNimekiri=autoLisamine(mark,mudel,aasta, kytus, mootor, kaigukast, veoskeem,  vin, autoID, autoNimekiri);
    // salvestab autonimekirja faili
    nimekirjaFailiSalvestamine(autoNimekiri);
    
    
    q=autoNimekiri.size()-1;
    w=autoNimekiri[q]->getautoID() ; //võtab nimekirja viimase sissekande ID
    
     // loeb klient failist nimekirja
    klientNimekiri=nimekirjaFailistLugemine(Eesnimi, Perenimi, Kliendi_id, Telefon, Email, klientNimekiri);
    // kliendi käsitsi nimekirja lisamine
    klientNimekiri=klientLisamine(Eesnimi, Perenimi, Kliendi_id, Telefon, Email,w, klientNimekiri);
    // salvestab klient nimekirja faili
    andmeteFailiSalvestamine(klientNimekiri);

    // väljastab autoNimekiri sisu - seda kui kasutada tuleb teha eraldi menüü valik
    for(int i = 0;i<autoNimekiri.size();i++){
        cout << i+1 <<": ";
        autoNimekiri[i]->getInfo();
        cout << endl;
    }
    /*
    //üritan aasta järgi auto andmeid saada
    for(int i = 0;i<autoNimekiri.size();i++){
        if(autoNimekiri[i]->getaasta()==1985){
        autoNimekiri[i]->getInfo();
        }

    }
    */
    
    // matrixi failist lugemine
    ifstream iFile;
    iFile.open("matrix.txt");
    
    while(iFile.good()){
        for(rida=0; rida<5; rida++){
            for(veerg=0; veerg<8; veerg++){
                iFile >> a[rida][veerg];
            }
            cout << endl;
        }
    }
    
    iFile.close();
    

    cout<<"Nadala tunnitabel"<<endl << endl;
    // kuvab faili sisu
    for(rida=0; rida<5; rida++){
        for(veerg=0; veerg<8; veerg++){
            cout << a[rida][veerg] << " ";
        }
        cout << endl;
    }
    while(valik<1 || valik>5){
        cout<<"1. Esmaspäev\n";
        cout<<"2. Teisipäev\n";
        cout<<"3. Kolmapäev\n";
        cout<<"4. Neljapäev\n";
        cout<<"5. Reede\n";
        cout<<"Valik: ";
        cin>> valik;
        switch ( valik ) {
            case 1:
                rida=0;
            break;
            case 2:
                rida=1;
            break;
            case 3:
                rida=2;
            break;
            case 4:
                rida=3;
            break;
            case 5:
                rida=4;
            break;
            default:
                cout<<"Esines viga. Valige '1', '2', '3' või '4'\n";
            break;
        }
    }
    valik=0;
    
    while(valik<1 || valik>8){
        cout<<"1. 8-9\n";
        cout<<"2. 9-10\n";
        cout<<"3. 10-11\n";
        cout<<"4. 11-12\n";
        cout<<"5. 13-14\n";
        cout<<"6. 14-15\n";
        cout<<"7. 15-16\n";
        cout<<"8. 16-17\n";
        cout<<"Valik: ";
        cin>> valik;
        switch ( valik ) {
            case 1:
                veerg=0;
            break;
            case 2:
                veerg=1;
            break;
            case 3:
                veerg=2;
            break;
            case 4:
                veerg=3;
            break;
            case 5:
                veerg=4;
            break;
            case 6:
                veerg=5;
            break;
            case 7:
                veerg=6;
            break;
            case 8:
                veerg=7;
            break;
            default:
                cout<<"Esines viga. Valige '1', '2', '3' või '4'\n";
            break;
        }
    }
    
    //kontrollib kas aeg on vaba, kui aeg on vaba kirjutab ID tabelisse
    if(a[rida][veerg] == 0){
        cout << "aeg on vaba" << endl;
        a[rida][veerg]=w;
        
        // matrixi faili kirjutamine
        ofstream oFile;
        oFile.open("matrix.txt");
    
        for(rida=0; rida<5; rida++){
            for(veerg=0; veerg<8; veerg++){
                oFile << a[rida][veerg] << " ";
            }   
            cout << endl;
        }    
    
        cout << "Edukalt salvestatud" << endl;
        oFile.close();
        
    }
    else{
        cout << "See aeg on voetud\nProovi monda teist aega"<< endl;
    }
    
    for(rida=0; rida<5; rida++){
        for(veerg=0; veerg<8; veerg++){
            cout << a[rida][veerg] << " ";
        }
        cout << endl;
    }
    
    
}