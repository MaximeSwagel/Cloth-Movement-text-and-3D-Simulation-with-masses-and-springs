#include "TissuCompose.h"
#include <cmath>
using namespace std;

TissuCompose::TissuCompose (vector<Tissu*> tissus, double epsilon, double K) 
: epsilon (epsilon), raideur_raccomodage(K)
{

    for (auto const& tissu : tissus) {

        for (size_t i(0) ; i < tissu->nbr_masses(); ++i) {

            //on transfére les masses des anciens tissus vers le tissu compose
            masses_.push_back(tissu->get_masse(i));

        }

        for (size_t i(0) ; i < tissu->nbr_ressorts(); ++i) {

            //On transfere les ressorts des anciens tissus vers le tissu compose
            ressorts_.push_back(tissu->get_ressort(i));

        }

        //On fait le choix de vider les anciens tissus de leurs ressorts pour éviter les segmentation fault
        //Cela correspond à la situation réelle, apprés avoir raccomodé deux tisuu, on n'a plus que le tissu raccomodé (plus les anciens)
        tissu->vider_masses();
        tissu->vider_ressorts();

    }

}

void TissuCompose::raccomode() {

    for (size_t i(0); i < masses_.size(); ++i) {

        for (size_t j(0); j < masses_.size(); ++j) {

            if ( i != j ) // les deux masses sont les mêmes ?
            
            {

                if ( not (masses_[i]->is_connected_to(masses_[j])) ) // i et j connectées ?
                
                {

                    if ( (masses_[i]->position() - masses_[j]->position()).norme() <= epsilon ) // Les deux masses sont-elles assez proches pour être connectées ?
                    
                     {

                        connecte(i, j, raideur_raccomodage, (masses_[i]->position() - masses_[j]->position()).norme());
                    
                    }
                }
            }
        }
    }
}

void TissuCompose::operator+=(Tissu& t) {

    for(auto masse : t.get_masses()) masses_.push_back(masse);

    for (auto ressort : t.get_ressorts()) ressorts_.push_back(ressort);

    t.vider_masses();

    t.vider_ressorts();

}
