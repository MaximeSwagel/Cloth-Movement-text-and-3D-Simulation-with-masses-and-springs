#pragma once
#include "Masse.h"

class Integrateur{
	
	public:
//Méthodes publiques : 


	//Cette méthode héritée et redéfinie par les sous classes implémente la méthode d'intégration utilisée
	virtual void evolue(Masse& masse, double dt) = 0;
	
//Destructeur :

	virtual ~Integrateur() {}
	
};
