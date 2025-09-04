#pragma once
#include "Impulsion.h"

class Vecteur3D;

class Impulsion_sin : public Impulsion{
	private : //pour la conception se referencer au fichier dédié
	
		double frequence;
		
	public :

	//Constructeurs:
	
		Impulsion_sin(Boule champ_action_, double temps_ini,double temps_fin, Vecteur3D force, tissus tissus_cibles, double frequence);
		
		Impulsion_sin(double rayon, Vecteur3D position, double temps_ini, double temps_fin, Vecteur3D force, tissus tissus_cibles, double frequence);

	//Destructeur:
		
		~Impulsion_sin() = default;

	//methode publique
		
		void appliquer(Tissu const& a_modifier, double t) override; //redefinition de la methode virtuelle pure heritee de Contrainte au travers de Impuslion
};
