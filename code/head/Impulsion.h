#pragma once
#include "Contrainte.h"
#include <vector>

typedef std::vector<Tissu*> tissus;
typedef std::vector<Masse*> masses;

class Impulsion : public Contrainte {
	
	protected : //la classe Impuslion est définie de la manière décrite dans le fichier conception

		double temps_ini;
		double temps_fin;
		Vecteur3D force;
		tissus tissus_cibles;
		masses masses_cibles;
		
	public :

	//Constructeur
	
		Impulsion(Boule champ_action, double temps_ini, double temps_fin, Vecteur3D force, tissus tissus_cibles);
		
		Impulsion(double rayon, Vecteur3D position, double temps_ini, double temps_fin, Vecteur3D force, tissus tissus_cibles); //surchage du contructeur pour faciliter la construction d'une impuslion

	//Destructeur
		
		~Impulsion() = default; //par bonne pratique

	//methode publique
		
		void appliquer(Tissu const& a_modifier, double t) override; //redefintion de la methode virtuelle pure de Contrainte
};
