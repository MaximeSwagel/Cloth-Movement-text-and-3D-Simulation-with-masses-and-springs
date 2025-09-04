#include "Systeme.h"
using namespace std;

//constructeur

	Systeme::Systeme (liste_tissus const& tissus, liste_contraintes const& contraintes)
	:tissus_(tissus), contraintes_(contraintes)
	{}

//getters

	liste_tissus Systeme::get_tissus() const {

		return tissus_;

		}


	size_t Systeme::nbr_masses() const {

		size_t nbr(0);

		for (auto const& t : tissus_) {

			nbr += t->nbr_masses();
		}

		return nbr;

	}

	size_t Systeme::nbr_ressorts() const {

		size_t nbr(0);

		for (auto const& t : tissus_) {

			nbr += t->nbr_ressorts();

		}

		return nbr;
		
	}
		
	double Systeme::get_t() const{

		return t;

	}

//methodes publiques

	void Systeme::dessine_sur(SupportADessin& support) { 
		
		support.dessine(*this);
		
	}

	ostream& Systeme::affiche_masses (ostream& out, size_t& i) const { //Ici on affiche les masses seules, chacune associee à un indice (selon la methode affiche_masses() de Tissu)

		for (auto const& tissu : tissus_) {
				
			tissu->affiche_masses(out,i);
		}
		
		return out;
	}

	std::ostream& Systeme::affiche_ressorts (ostream& out, size_t& i) const { //Ici on affiche les ressorts seuls, chacun associe à un indice (selon la methode affiche_ressorts() de Tissu)

		for (auto const& tissu : tissus_) {

			tissu->affiche_ressorts(out, i);

		}

		return out;
	}

	ostream& Systeme::affiche (ostream& out) const { //On affiche les masses et les ressorts associes à des indices, grâce aux methodes affiches_ressorts() et affche_masses() définies juste avant

		out<<"Le système est constitué de "<<nbr_masses()<<" masses et de "<<nbr_ressorts()<< " ressorts :"<<endl; //dire a omar de rajouter le masse

		size_t i(1);

		affiche_masses(out,i);

		i=1;
		affiche_ressorts(out,i);

		return out;

	}

	void Systeme::evolue(Integrateur& I, double dt){ //Cette methode permet de faire evoluer le systeme par un Integrateur, en ayant precedemment mis à jour les forces puis appliqué les contraintes						
		
		for (auto tissu : tissus_){
			
			tissu->maj_forces();
			
			for (auto contrainte : contraintes_){
				
				contrainte->appliquer( *tissu, t);
			}
		}
		
		for(auto element : tissus_){
			element->evolue(I,dt);
		}
		
		t += dt; // on increment le temps du systeme apres l'avoir fait evolué du pas de temps choisi
	}

// surchage externe

	std::ostream& operator<<(std::ostream& out, Systeme const& S) {

		return S.affiche(out);

	}
