#include "Masse.h"
using namespace std;

int main () {

Masse m1(1 , {0 , 0 , 0}, {0 , 0 , 0}); 
Masse m2(2 , {1 , 0 , 0}, {0 , 0 , 0});
Masse m3(3 , {2 , 0 , 0}, {0 , 0 , 0});


Ressort r1(&m1, &m2, 3, 1);

cout<<r1;

Ressort r2(&m2, &m3, 4, 5);

cout<<r2;

cout<<"=========================================================="<<endl
    <<"A) Vérification de l'intégrité des ressorts après tous les ajouts :"<<endl;

cout<<r1<<r2;

cout<<"=========================================================="<<endl
    <<"B) Nous modifions la masse 2 (position, vitesse et force)."<<endl
    <<"Les ressorts sont-ils informés des changements ?"<<endl<<endl;


m2.set_force({42,42,42});
m2.set_vitesse({42,42,42});
m2.set_position({42,42,42});

cout<<m2<<endl;

cout<<r1<<r2;

cout<<"=========================================================="<<endl
    <<"C) Vérification des forces :"<<endl;


cout<<"ressort "<<&r1<<" sur masse "<<&m1<<" : "<<r1.force_rappel(&m1)<<endl;
cout<<"ressort "<<&r1<<" sur masse "<<&m2<<" : "<<r1.force_rappel(&m2)<<endl;
cout<<"ressort "<<&r1<<" sur masse "<<&m3<<" : "<<r1.force_rappel(&m3)<<endl;

cout<<endl;

cout<<"ressort "<<&r2<<" sur masse "<<&m1<<" : "<<r2.force_rappel(&m1)<<endl;
cout<<"ressort "<<&r2<<" sur masse "<<&m2<<" : "<<r2.force_rappel(&m2)<<endl;
cout<<"ressort "<<&r2<<" sur masse "<<&m3<<" : "<<r2.force_rappel(&m3)<<endl;

return 0;

}