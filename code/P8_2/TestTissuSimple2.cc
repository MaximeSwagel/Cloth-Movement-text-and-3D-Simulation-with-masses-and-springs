#include "Tissu.h"
using namespace std;

void TestIntegrateur(Tissu& T, unsigned int recurrence,double dt ,IntegrateurEulerCromer integrateur);

int main(){

Masse A(0.33,{0,0,-3},{0,0,0});
Masse B(1,{-0.5,0,0},{0,0,0});
Masse C(1,{0.5,0,0},{0,0,0});

vector<Masse*> vect ({&A,&B,&C});

Tissu tissu_test(vect);

tissu_test.connecte(0, 2, 0.6, 2.5);
tissu_test.connecte(0, 1, 0.6, 2.5);

if(tissu_test.check()) cout<<"Le tissu est conforme aux exigences du projet"<<endl;
    
else cout<<"Le tissu n'est pas conforme aux exigences du projet"<<endl;

cout<< "Masse A : "<< endl
		<< A << endl;
		
cout<< "Masse B : " << endl
	<< B << endl;
		
cout<<"Masse C : " << endl
	<< C << endl;
	
cout<<"Ressort 1 : "<< endl
	<< *tissu_test.get_ressort(0) << endl;
		
cout<<"Ressort 2 : "<< endl
	<< *tissu_test.get_ressort(1) << endl;
		
IntegrateurEulerCromer I;
	
TestIntegrateur(tissu_test,250,0.1, I);

return 0;
}

void TestIntegrateur(Tissu& T, unsigned int recurrence,double dt ,IntegrateurEulerCromer integrateur){
	
	double t(0.0);
	
	Vecteur3D reaction_normale(0,0,0);
	
	cout<<"Test 1 : " << endl;
	
	for( unsigned int i(0) ; i< recurrence ; ++i){
	cout<< "=================================" << endl << endl;
	
	t+=0.1;
	
	T.maj_forces();
	
	Vecteur3D force3(0,0,0), force2(0,0,0); //REFAIRE CETTE PARTIE
	force3 -= T.get_masse(2)->force();
	force2 -= T.get_masse(1)->force();
	T.get_masse(2)->ajoute_force(force3);
	T.get_masse(1)->ajoute_force(force2);
	
	T.evolue(integrateur, dt);
	
	cout<<" t = "<< t << endl
		<<"Masse 1 : "<< *T.get_masse(0) << endl
		<<"Masse 2 : "<< *T.get_masse(1) << endl
		<<"Masse 3 : "<< *T.get_masse(2) << endl;
	}
} 