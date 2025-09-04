#include "Impulsion.h"
#include "Tissu.h"

//Consructeurs

	Impulsion::Impulsion(Boule champ_action, double temps_ini, double temps_fin, Vecteur3D force, tissus tissus_cibles)
		: Contrainte(champ_action), temps_ini(temps_ini), temps_fin(temps_fin), force(force) , tissus_cibles(tissus_cibles)
		{ 
			for(auto tissu_ : tissus_cibles){ //On implemente la construction selon notre conception : 
											//une impulsion retient les masses des tissus ciblés qui à la construction de l'impulsion sont dans son champ d'action
				
				for(auto masse_ : tissu_->get_masses()){
				
					if(this->Contrainte::sujet_a_contrainte(*masse_)){
					
						masses_cibles.push_back(masse_);
					}
				}
			}
			
			if(temps_fin-temps_ini<margin_){ // si le temps ini est plus grand que le temps de fin on les swap
				double swap(temps_fin);
				temps_fin=temps_ini;
				temps_ini=swap;
			}
		} 
		
	Impulsion::Impulsion(double rayon, Vecteur3D position, double temps_ini, double temps_fin, Vecteur3D force, tissus tissus_cibles) //surchage du constructeur pour faciliter la construction des impulsions : 
																																	//fonctionnement calqué sur le premier
		: Contrainte(rayon, position), temps_ini(temps_ini), temps_fin(temps_fin), force(force) , tissus_cibles(tissus_cibles)
		{ 
			for(auto tissu_ : tissus_cibles){
				
				for(auto masse_ : tissu_->get_masses()){
				
					if(this->Contrainte::sujet_a_contrainte(*masse_)){
					
						masses_cibles.push_back(masse_);
					}
				}
			}
			
			if(temps_fin-temps_ini<margin_){
				double swap(temps_fin);
				temps_fin=temps_ini;
				temps_ini=swap;
			}
		}

//Methode publique

	void Impulsion::appliquer(Tissu const& a_modifier, double t){ //on applique l'impulsion (soit annuler le poids puis appliquer la force de l'impulsion) 
																//sur les masses du tissu fourni lors de l'appel de la fonction qui font partie des masses ciblees de l'impuslion,
																// et ce seulement si le temps du tissu (et donc du syteme) est compris entre le temps ini et le temps fin
		
		if ( t-temps_ini>= margin_  and t-temps_fin<= margin_){

			for(auto masse : a_modifier.get_masses()){
			
				for( auto& masse_cible : masses_cibles ){

					if(masse == masse_cible){
					
						masse->ajoute_force(-(masse->masse()*g));
						masse->ajoute_force(force);
						
					}
					
				}
			}
		}
	}
