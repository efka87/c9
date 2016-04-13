#include <iostream>
#include <string>


char valik;
char teenus;
  


using namespace std; 
    
  void kliendiinfo (char name[], char perenimi[], char telefon[], char email[], char automark[], char automudel[], char vinkood[])
{  
    
        using namespace std; 
  cout << "Kirjuta nimi" << "\n\n" << endl;
  cin >> name;
  cout << "Kirjuta perenimi" << "\n\n" << endl;
  cin >> perenimi;
  cout << "Kirjuta telefoni number" << "\n\n" <<endl;
  cin >> telefon;
  cout << "Kirjuta email" << "\n\n" << endl;
  cin >> email;
  cout << "Kirjuta automark" << "\n\n" << endl;
  cin >> automark;
  cout << "Kirjuta auto mudel" << "\n\n" << endl;
  cin >> automudel;
  cout << "Kirjuta vinkood" << "\n\n" << endl;
  cin >> vinkood;
  
  
}
void autoteenus (char teenus)
{
    using namespace std;
    cout<< "A.. Õlivahetus" << "\n" <<endl;
    cout<< "B.. Rehvivahetus" << "\n" <<endl;
    cout<< "C.. Kogu kompot" << "\n" <<endl;
    
    switch (teenus)
{
}
cout << " Milline teenus (A,B,C)" << "\n\n" << endl;
cin >> teenus;
}
  void autovalik (char valik)
{    
      using namespace std; 
cout<< "\t\t\t\t" << " Autoteenindus " << "\n" <<endl;
cout<< "\n\n\n" << "Sõiduki liik" << "\n" << endl;
cout<< "A.. Maastur" <<  "\n" << endl;
cout<< "B.. Sõiduauto" << "\n" << endl;
cout<< "C.. Pakibuss" << "\n" << endl;


  
   switch (valik)
{
  
} 

cout << " Milline sõiduki liik vajab teenindust (A,B,C)" << "\n\n" << endl;
cin >> valik;

}


int main ()
{ 
  char valik;
  char teenus;
  
using namespace std;
 char name[50], perenimi[50], telefon[50], email[50], automark[50], automudel[50], vinkood[50];
 

autovalik (valik); 
autoteenus (teenus);
kliendiinfo (name,perenimi,telefon,email,automark,automudel,vinkood);

cout << "\t\t\t\t" << "Ülevaade" << endl; 
cout << "\n\n\n\n\n\t\t\t\t" << name << "\n\t\t\t\t" << perenimi << "\n\t\t\t\t" << telefon << "\n\t\t\t\t" << email << "\n\t\t\t\t" << automark << "\n\t\t\t\t"<< automudel << "\n\t\t\t\t"<< vinkood << "\n\t\t\t\t" << endl;

return 0;
}



