#pragma once
#include "Contrainte.h"
#include "Tissu.h"

class Crochet : public Contrainte {
	
	public :
		
		using Contrainte::Contrainte; //herite du constructeur de Contrainte
		
		~Crochet() = default; //On explicite le destructeur par bonne pratique, au cas où on voudrait definir une sous classe de crochet
		
		void appliquer(Tissu const& a_modifier, double t) override; //redefinition de la methode virtuelle pure de contrainte (permet de faire de crochet une classe instanciable - soit non abstraite)
};
