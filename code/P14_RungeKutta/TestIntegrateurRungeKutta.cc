#include "IntegrateurRungeKutta.h"
#include "TextViewer.h"

using namespace std;
		
int main() {

	double t(0.0);

	TextViewer support_texte(cout);
	
	Vecteur3D position_ini(0,0,1);
	
	Vecteur3D vitesse_ini(1,0,2);
	
	Masse masse1(0.127, position_ini, vitesse_ini, 0.0);
	
	cout<<"//Situation de départ1: "<< endl;
	
	cout<< masse1 << endl;
	
	IntegrateurRungeKutta integre;
	
	for( int i(1); i<=70 ; ++i){
		
		cout<<"t = "<<t<< endl;
		integre.evolue(masse1, 0.01);
		support_texte.dessine(masse1);
		t+=0.01;
	}
	
	return 0;
}
