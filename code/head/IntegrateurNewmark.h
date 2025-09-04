#pragma once
#include "Integrateur.h"

class Vecteur3D;

class Masse;

class IntegrateurNewmark: public Integrateur {
	
	public:
		
//Constructeurs : 

    //Initialise le paramètre epsilon
    IntegrateurNewmark(double);

//Méthodes publiques : 

    //Méthode héritée de la classe intégrateur
		//Voir integrateur.h et conception pour plus d'informations
		void evolue (Masse& masse, double dt);

//Destructeur : 

		~IntegrateurNewmark() {}

    private : 

//Attributs privés : 

        double epsilon;
        Vecteur3D q;
        Vecteur3D r;
        Vecteur3D s;
	
};
