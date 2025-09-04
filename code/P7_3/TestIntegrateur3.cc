#include "IntegrateurEulerCromer.h"


using namespace std;
void TestIntegrateur(Masse& M1, Masse& M2, Masse& M3, unsigned int recurrence,double dt ,IntegrateurEulerCromer integrateur);

int main(){

Masse A(0.33,{0,0,-3},{0,0,0});

Masse B(1,{-0.5,0,0},{0,0,0});

Masse C(1,{0.5,0,0},{0,0,0});

Ressort R1(&A, &C, 0.6, 2.5);

Ressort R2(&A, &B, 0.6, 2.5);

cout<< "Masse A : "<< endl
		<< A << endl;
		
	cout<< "Masse B : " << endl
		<< B << endl;
		
	cout<<"Masse C : " << endl
		<< C << endl;
	
	cout<<"Ressort 1 : "<< endl
		<< R1 << endl;
		
	cout<<"Ressort 2 : "<< endl
		<< R2 << endl;
		
	IntegrateurEulerCromer integrateur;
	
	TestIntegrateur(A,B,C,250,0.1, integrateur);

return 0;
}

void TestIntegrateur(Masse& M1, Masse& M2, Masse& M3, unsigned int recurrence,double dt ,IntegrateurEulerCromer integrateur){
	
	double t(0.0);
	
	Vecteur3D reaction_normale(0,0,0);
	
	cout<<"Test 1 : " << endl;
	
	for( unsigned int i(0) ; i< recurrence ; ++i){
	cout<< "=================================" << endl << endl;
	
	t+=0.1;
	
	M1.maj_forces();
	M2.maj_forces();
	M3.maj_forces();
	
	Vecteur3D force3(0,0,0), force2(0,0,0);
	force3 -= M3.force();
	force2 -= M2.force();
	M3.ajoute_force(force3);
	M2.ajoute_force(force2);
	
	integrateur.evolue(M1,dt);
	integrateur.evolue(M2,dt);
	integrateur.evolue(M3,dt);
	
	cout<<" t = "<< t << endl
		<<"Masse 1 : "<<endl << M1 << endl
		<<"Masse 2 : "<<endl << M2 << endl
		<<"Masse 3 : "<<endl << M3 << endl;
	}
} 
