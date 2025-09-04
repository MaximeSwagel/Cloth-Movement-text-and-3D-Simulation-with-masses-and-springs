#include "Tissu.h"
using namespace std;

void TestIntegrateur(Tissu& T, unsigned int recurrence, double dt ,IntegrateurEulerCromer integrateur);

int main(){
	
Masse M1(1, {0,0,0}, {0,0,0});
Masse M2(1, {2,0,0}, {0,0,0});
Masse M3(1, {0,2,0}, {0,0,0});

vector<Masse*> vect1 ({&M1,&M2,&M3});

Tissu tissu_test1(vect1);


tissu_test1.connecte(0, 1, 9.0, 1.5);
tissu_test1.connecte(0, 2, 1.9, 1.75);
tissu_test1.connecte(1, 2, 5.5, 1.25);

if(tissu_test1.check()) cout<<"Le tissu est conforme aux exigences du projet"<<endl;
    
else cout<<"Le tissu n'est pas conforme aux exigences du projet"<<endl;

cout<< "Masse 1 : "<< endl
	<< M1 << endl;
		
cout<< "Masse 2 : " << endl
	<< M2 << endl;
		
cout<<"Masse 3 : " << endl
	<< M3 << endl;
	
cout<<"Ressort 1 : "<< endl
	<< *tissu_test1.get_ressort(0) << endl;
		
cout<<"Ressort 2 : "<< endl
	<< *tissu_test1.get_ressort(1) << endl;
	
cout<<"Ressort 3 : "<< endl
	<< *tissu_test1.get_ressort(2) << endl;

		
IntegrateurEulerCromer I;
		
TestIntegrateur(tissu_test1, 5, 0.1, I);
	
	
	
	cout <<" Test2 : "<< endl
		 <<"Maintenant on fait le test avec toutes les mêmes caractéristiques mais en contraction au départ, c'est à dire qu'on choisit une longueur à vide supérieur à la distance entre les masses. "<< endl<< endl;
	
Masse M4(1, {0,0,0}, {0,0,0});
Masse M5(1, {2,0,0}, {0,0,0});
Masse M6(1, {0,2,0}, {0,0,0});

vector<Masse*> vect2 ({&M4,&M5,&M6});

Tissu tissu_test2(vect2);


tissu_test2.connecte(0, 1, 9.0, 4);
tissu_test2.connecte(0, 2, 1.9, 4);
tissu_test2.connecte(1, 2, 5.5, 6);

if(tissu_test2.check()) cout<<"Le tissu est conforme aux exigences du projet"<<endl;
    
else cout<<"Le tissu n'est pas conforme aux exigences du projet"<<endl;

cout<< "Masse 1 : "<< endl
	<< M4 << endl;
		
cout<< "Masse 2 : " << endl
	<< M5 << endl;
		
cout<<"Masse 3 : " << endl
	<< M6 << endl;
	
cout<<"Ressort 1 : "<< endl
	<< *tissu_test2.get_ressort(0) << endl;
		
cout<<"Ressort 2 : "<< endl
	<< *tissu_test2.get_ressort(1) << endl;
	
cout<<"Ressort 3 : "<< endl
	<< *tissu_test2.get_ressort(2) << endl;

	
TestIntegrateur(tissu_test2, 5, 0.1, I);
	
cout <<"Test 3 :"<< endl
	 <<"Pour finir on met les longueurs à vide de telle sorte que le système soit immédiatement à l'équilibre."<< endl << endl;
		 
	
Masse M7(1, {0,0,0}, {0,0,0});
Masse M8(1, {3,0,0}, {0,0,0});
Masse M9(1, {0,4,0}, {0,0,0});

vector<Masse*> vect3 ({&M7,&M8,&M9});

Tissu tissu_test3(vect3);


tissu_test3.connecte(0, 1, 9.0, 3);
tissu_test3.connecte(0, 2, 1.9, 4);
tissu_test3.connecte(1, 2, 5.5, 5);

if(tissu_test3.check()) cout<<"Le tissu est conforme aux exigences du projet"<<endl;
    
else cout<<"Le tissu n'est pas conforme aux exigences du projet"<<endl;

cout<< "Masse 7 : "<< endl
	<< M7 << endl;
		
cout<< "Masse 8 : " << endl
	<< M8 << endl;
		
cout<<"Masse 9 : " << endl
	<< M9 << endl;
	
cout<<"Ressort 1 : "<< endl
	<< *tissu_test3.get_ressort(0) << endl;
		
cout<<"Ressort 2 : "<< endl
	<< *tissu_test3.get_ressort(1) << endl;
	
cout<<"Ressort 3 : "<< endl
	<< *tissu_test3.get_ressort(2) << endl;
		
TestIntegrateur(tissu_test3, 5,0.1 , I);
	
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
	
	reaction_normale.set_z(-(T.get_masse(0)->force()).get_coord('z'));
	T.get_masse(0)->ajoute_force(reaction_normale);
	
	Vecteur3D reaction_normale2(0,0,0);
	reaction_normale2.set_z(-(T.get_masse(1)->force()).get_coord('z'));
	T.get_masse(1)->ajoute_force(reaction_normale);
	
	reaction_normale={0,0,0};
	reaction_normale.set_z(-(T.get_masse(2)->force()).get_coord('z'));
	T.get_masse(2)->ajoute_force(reaction_normale);
	
	
	T.evolue(integrateur, dt);
	
	cout<<" t = "<< t << endl
		<<"Masse 1 : "<< *T.get_masse(0) << endl
		<<"Masse 2 : "<< *T.get_masse(1) << endl
		<<"Masse 3 : "<< *T.get_masse(2) << endl;
	}
}
