#include "Impulsion_sin.h"
#include "Tissu.h"
#include <cmath>

//Consructeurs

	Impulsion_sin::Impulsion_sin(Boule champ_action_, double temps_ini, double temps_fin,  Vecteur3D force, tissus tissus_cibles, double frequence)
		: Impulsion(champ_action_,temps_ini ,temps_fin, force, tissus_cibles), frequence(frequence)
	{}
	
	Impulsion_sin::Impulsion_sin(double rayon, Vecteur3D position, double temps_ini, double temps_fin, Vecteur3D force, tissus tissus_cibles, double frequence) //surcharge pour faciliter la construction
		: Impulsion(rayon, position,temps_ini ,temps_fin, force, tissus_cibles), frequence(frequence)
	{}

//methode publique

	void Impulsion_sin::appliquer(Tissu const& a_modifier, double t){
	if ( t-temps_ini>= margin_  and t-temps_fin<= margin_){ //fonction au fonctionnement identique à celle de sa super classe Impuslion, 
															//seulement la force ajoutee varie au cours du temps selon la formule ligne 30.
		
		Vecteur3D force_appliquee(0, 0, 0);

		for(auto masse : a_modifier.get_masses()){
		
			for( auto& masse_cible : masses_cibles ){

				if(masse == masse_cible){
					
					masse->ajoute_force(- (masse->masse() * g));
					masse->ajoute_force(force*sin(2*M_PI*frequence*(t-temps_ini)));	
					
				}
				
			}
		}
	}
}
	