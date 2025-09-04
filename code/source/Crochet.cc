#include "Crochet.h"

void Crochet::appliquer(Tissu const& a_modifier, double t) { //t est la variable temps qui nous sert dans impulsion, dans notre conception elle est fournie par systeme

	Vecteur3D reaction_contrainte(0,0,0); 
	
	for(auto& masse : a_modifier.get_masses()){ // On boucle sur les masses du tissu et :
												// si une massea est dans le champ d'action de la contrainte, 
												// on annule les forces et la vitesse de la masse (soit la modelisation de la contrainte que le crochet applique).

		if (this->sujet_a_contrainte(*masse)){

			masse->set_force({0,0,0});
			
			masse->set_vitesse({0,0,0});
		}

	}
}
