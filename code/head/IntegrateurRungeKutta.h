#pragma once
#include "Integrateur.h"

class Masse;

class IntegrateurRungeKutta : public Integrateur {

    public : 

//Méthodes publiques : 

        //Méthode héritée de la classe intégrateur
		//Voir integrateur.h et conception pour plus d'informations
        void evolue(Masse& masse, double dt);

//Dsetructeur :

        ~IntegrateurRungeKutta() {}

    private :

//Attributs privés :

        Vecteur3D k1, k2, k3, k4, K_1, K_2, K_3, K_4;


};