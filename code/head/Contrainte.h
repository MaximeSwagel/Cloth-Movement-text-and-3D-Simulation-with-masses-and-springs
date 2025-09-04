#pragma once
#include "Masse.h"

class Tissu;


//on représente l'envergure de la contrainte par une boule d'un ceertain rayon et dont on specifie la position du centre

struct Boule {

	double rayon;
	Vecteur3D position;

};

class Contrainte {

	protected :
	
		Boule champ_action_;
		
	public :
	
	//constructeurs 

		Contrainte(Boule champ_action)
			:champ_action_(champ_action)
		{if (champ_action.rayon < margin_) throw 0;}
		
		Contrainte(double rayon, Vecteur3D position) //on surchage le constructeur pour que l'initialisation soit simplifiee (avec un Vecteur3D et un double au lieu d'une boule)
			:champ_action_({rayon, position})
		{if (rayon < margin_) throw 0;}

	//destructeur
		
		virtual ~Contrainte() = default;

	//methodes publiques
		
		virtual void appliquer(Tissu const& a_modifier, double t) = 0;
		
		//Cette methode verifie si une masse est dans le champ d'action d'une contrainte

		bool sujet_a_contrainte (Masse const& masse) const { 
			
			if ((masse.position()-champ_action_.position).norme()-champ_action_.rayon < margin_) { //"si la distance entre le centre de la boule et la position de la masse est inférieure au rayon de la boule" (utilise margin pour comparer des doubles) :
				
				return true; //"la masse est sujette a la contrainte"

			}

			else return false; //sinon : "la masse n?est pas sujet a la contrainte."
			
			}
};