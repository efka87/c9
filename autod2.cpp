#include <iostream>

using namespace std;

void soiduauto()
{
    cout << "Teie valik on soiduauto";
}
void maastur()
{
    cout << "Teie valik on maastur";
}
void pakibuss()
{
    cout << "Teie valik on pakibuss";
}
	
int main()
{
  int valik;
  
  cout<<"1. Soiduauto\n";
  cout<<"2. Maastur\n";
  cout<<"3. Pakibuss\n";
  cout<<"4. Välju\n";
  cout<<"Valik: ";
  cin>> valik;
  switch ( valik ) {
  case 1:
    soiduauto();
    break;
  case 2:
    maastur();
    break;
  case 3:
    pakibuss();
    break;
  case 4:
    cout<<"Tänan külastamast!\n";
    break;
  default:
    cout<<"Esines viga. Valige '1', '2', '3' või '4'\n";
    break;
  }
  cin.get();
}