#include "IntegrateurEulerCromer.h"

using namespace std;
		
int main(){
	
	double t(0.0);
	
	Vecteur3D position_ini(0,0,1);
	
	Vecteur3D vitesse_ini(1,0,2);
	
	Masse masse1(0.127, position_ini, vitesse_ini, 0.0);
	
	cout<<"//Situation de départ 1: "<< endl;
	
	cout<< masse1 << endl;
	
	IntegrateurEulerCromer integre;
	
	for (int i(1); i<=70 ; ++i) {

		t+=0.01;
		cout<<"t = "<<t<< endl;
		integre.evolue(masse1, 0.01);
		cout<< masse1<< endl;
	}
	
	
	//on rajoute d'autres tests a lambda_non-nul
	

	Masse masse2(1, position_ini, vitesse_ini, 0.3);
	
	cout<<"//====================================================================================================================// Situation de départ2 //====================================================================================================================// "<< endl<< endl;
	
	cout<< masse2 << endl;
	
	t = 0.0;
	
	for(int i(1); i <= 70 ; ++i) {
		t+=0.01;
		cout<<"t = "<< t<< endl;
		integre.evolue(masse2, 0.01);
		cout<<masse2<< endl;
	}
	
	cout << "Attention nous avons fait certains tests supplementaires. Le test associé aux valeurs données est le premier(Voir ci-dessus)." << endl;
	
	return 0;
}
