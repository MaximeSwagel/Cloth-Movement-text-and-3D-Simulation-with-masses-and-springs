#pragma once
#include "Tissu.h"
#include "Contrainte.h"
#include "Dessinable.h"

typedef std::vector<Contrainte*> liste_contraintes; //typedef pour faciliter la lecture
typedef std::vector<Tissu*> liste_tissus;

class Systeme : public Dessinable {

public :

//constructeur

	Systeme (liste_tissus const&, liste_contraintes const& contraintes = {});
	
 //Getters :
 
 	liste_tissus get_tissus() const; 

	size_t nbr_masses() const; 

	size_t nbr_ressorts() const; 
	
	double get_t() const; //renvoie le temps associé a l'instance (attribut double t)

	
//methodes publiques


	//trois methodes d'affichae qui affichent chacune des attributs. 

	std::ostream& affiche_masses (std::ostream&, size_t&) const;

	std::ostream& affiche_ressorts (std::ostream&, size_t&) const;
	
	std::ostream& affiche (std::ostream&) const; //methode utilisee pour la surchage externe de l'oprerator<<

	void evolue(Integrateur& I, double dt); // methode qui evolue le systeme grace a un integrateur (avec polymorphisme sur le type d'integrateur)

	virtual void dessine_sur(SupportADessin&) override; // methode qui redefinit la methode virtuelle pure de dessinable -- permet de dessiner le systeme sur le supportADessin voulu : 
														//double polymorphisme (sur le type de dessinabe, ici systeme, et le SupportADessin)
	
 private :
 
	liste_tissus tissus_;
	
	liste_contraintes contraintes_;
	
	double t; //le temps du systeme -> utile pour l'integration du systeme
	
};

//Surcharge externe d'opérateurs :

std::ostream& operator<<(std::ostream& out, Systeme const& S);
