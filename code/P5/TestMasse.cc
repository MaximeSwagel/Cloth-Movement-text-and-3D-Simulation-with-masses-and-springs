#include "Masse.h"
using namespace std;

int main(){
	
	cout << "Déclaration des vecteurs positions, vitesses et force :" << endl<<endl;
	
		Vecteur3D position(1,2,3), vitesse(4,5,6), force(1.1,2.2,3.3);

	cout << "Position : "<< position << " Vitesse : "<< vitesse << " Force : "<< force << endl<<endl;
	
	cout<<"Déclaration des masses ( test des constructeurs )."<< endl<<endl;
	
		Masse A(1.5, position, vitesse);
	
	cout<< A << endl;
	cout<<"tests des get_force()"<< endl<<endl;
	cout<<"position : " << A.position() << endl;
	cout<<"vitesse : "<< A.vitesse() << endl;
	cout<<"accélération : "<< A.acceleration()<< endl << endl;
	
	
	cout<<"test des ajoute force()" << endl<<endl
		<<"test 1: ajoute "<< force << endl;
		
		A.ajoute_force(force);
	
	cout<<"nouvelle force = " << A.force() << endl
		<<"test 2 : ajoute son opposé" << endl;
		force-=A.force();
		A.ajoute_force(force);
	
	cout<<"nouvelle force =" << A.force() << endl << endl;
	
	cout << "Test de mise à jour des forces()"<< endl << endl;
		
		A.maj_forces();
	
	cout <<"force = "<< A.force() << endl
		 <<"accélération = "<<A.acceleration() << endl<< endl;
	
	cout<< "Test des cas limites"<< endl<< endl ;


	//ajouter test ressorts !!!
	
		try{
		Masse Wrong(-5, position, vitesse);
		}
		catch(int i){cerr<< "Erreur : La masse ne peut être négative ou nulle." << endl << endl;}
		
	return 0;
}
