#include "IntegrateurEulerCromer.h"


using namespace std;

void TestIntegrateur(Masse& M1, Masse& M2, Masse& M3, unsigned int recurrence, double dt ,IntegrateurEulerCromer integrateur);

int main(){
	
	Vecteur3D position_ini1(0,0,0);
	Vecteur3D position_ini2(2,0,0);
	Vecteur3D position_ini3(0,2,0);
	Vecteur3D vitesse_ini(0,0,0);
	
	Masse M1(1, position_ini1, vitesse_ini);
	
	Masse M2(1, position_ini2, vitesse_ini);
	
	Masse M3(1, position_ini3, vitesse_ini);
	
	Ressort R1(&M1 ,&M2, 9.0 ,1.5);
	
	Ressort R2(&M1, &M3, 1.9, 1.75);
	
	Ressort R3(&M2, &M3, 5.5, 1.25);
	
	cout<< "Masse 1 : "<< endl
		<< M1 << endl;
		
	cout<< "Masse 2 : " << endl
		<< M2 << endl;
		
	cout<<"Masse 3 : " << endl
		<< M3 << endl;
	
	cout<<"Ressort 1 : "<< endl
		<< R1 << endl;
		
	cout<<"Ressort 2 : "<< endl
		<< R2 << endl;
	
	cout<<"Ressort 3 : "<< endl
		<< R3 << endl;
		
	IntegrateurEulerCromer integrateur;
		
	TestIntegrateur(M1,M2,M3,5,0.1, integrateur);
	
	
	
	cout <<" Test2 : "<< endl
		 <<"Maintenant on fait le test avec toutes les mêmes caractéristiques mais en contraction au départ, c'est à dire qu'on choisit une longueur à vide supérieur à la distance entre les masses. "<< endl<< endl;
	
	Masse M4(1, position_ini1, vitesse_ini);
	
	Masse M5(1, position_ini2, vitesse_ini);
	
	Masse M6(1, position_ini3, vitesse_ini);
	
	Ressort R4(&M4 ,&M5, 9.0 ,4);
	
	Ressort R5(&M4, &M6, 1.9, 4);
	
	Ressort R6(&M5, &M6, 5.5, 6);
	
	cout<< "Masse 4 : "<< endl
		<< M4 << endl;
		
	cout<< "Masse 5 : " << endl
		<< M5 << endl;
		
	cout<<"Masse 6 : " << endl
		<< M6 << endl;
	
	cout<<"Ressort 4 : "<< endl
		<< R4 << endl;
		
	cout<<"Ressort 5 : "<< endl
		<< R5 << endl;
	
	cout<<"Ressort 6 : "<< endl
		<< R6 << endl;
	
	TestIntegrateur(M4, M5, M6, 5, 0.1, integrateur);
	
	cout <<"Test 3 :"<< endl
		 <<"Pour finir on met les longueurs à vide de telle sorte que le système soit immédiatement à l'équilibre."<< endl << endl;
		 
	
	Masse M7(1, position_ini1, vitesse_ini);
	
	Masse M8(1, {3,0,0}, vitesse_ini);
	
	Masse M9(1, {0,4,0}, vitesse_ini);
	
	Ressort R7(&M7 ,&M8, 9.0 ,3);
	
	Ressort R8(&M7, &M9, 1.9, 4);
	
	Ressort R9(&M8, &M9, 5.5, 5);
	
	cout<< "Masse 7 : "<< endl
		<< M7 << endl;
		
	cout<< "Masse 8 : " << endl
		<< M8 << endl;
		
	cout<<"Masse 9 : " << endl
		<< M9 << endl;
	
	cout<<"Ressort 7 : "<< endl
		<< R7 << endl;
		
	cout<<"Ressort 8 : "<< endl
		<< R8 << endl;
	
	cout<<"Ressort 9 : "<< endl
		<<R9<< endl;
		
	TestIntegrateur(M7,M8,M9,5,0.1,integrateur);
	
		cout << "Attention nous avons fait certains tests supplementaires. Le test associé aux valeurs données est le premier(Voir ci-dessus)." << endl;
	
return 0;
}

//On définit ci-dessous la méthode qui nous permet de tester nos intégrateurs selon la demarche voulue :
//- on boucle un certain nombre de fois (recurrence fois) -> correspond au nombre de boucles d'integration
//- dans la boucle on met à 0 les forces dans la direction de z en calculant la reaction
// -enfin on integre les masses (fonction evolue()) et on les affiche

void TestIntegrateur(Masse& M1, Masse& M2, Masse& M3, unsigned int recurrence,double dt ,IntegrateurEulerCromer integrateur){ 
	
	double t(0.0);
	
	Vecteur3D reaction_normale(0,0,0);
	
	for( unsigned int i(0) ; i<recurrence ; ++i){
	cout<< "=================================" << endl << endl;
	
	t+=0.1;
	
	M1.maj_forces();
	M2.maj_forces();
	M3.maj_forces();
	
	reaction_normale.set_z(-(M1.force()).get_coord('z'));
	M1.ajoute_force(reaction_normale);

	Vecteur3D reaction_normale={0,0,0};
 	reaction_normale.set_z(-(M2.force()).get_coord('z'));
	 M2.ajoute_force(reaction_normale);
	
	reaction_normale={0,0,0};
	reaction_normale.set_z(-(M3.force()).get_coord('z'));
	M3.ajoute_force(reaction_normale);
	
	integrateur.evolue(M1,dt);
	integrateur.evolue(M2,dt);
	integrateur.evolue(M3,dt);
	
	cout<<" t = "<< t << endl
		<<"Masse 1 : "<< M1 << endl
		<<"Masse 2 : "<< M2 << endl
		<<"Masse 3 : "<< M3 << endl;
	}
}
