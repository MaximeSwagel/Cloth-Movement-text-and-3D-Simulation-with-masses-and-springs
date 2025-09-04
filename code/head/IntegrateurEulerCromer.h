#pragma once
#include "Integrateur.h"

class IntegrateurEulerCromer : public Integrateur {

	public:

//Méthodes publiques : 
		
		//Méthode héritée de la classe intégrateur
		//Voir integrateur.h et conception pour plus d'informations
		void evolue(Masse& masse, double dt);

//Destructeur : 

	~IntegrateurEulerCromer() {}
	
};
