#include "Tissu.h"

class TissuCompose : public Tissu {

    public:

//Constructeur : 

    TissuCompose(std::vector<Tissu*> liste_tissus, double rayon_raccomodage, double raideur_raccomodage );

    TissuCompose(TissuCompose const&) = delete;

//Méthodes publiques : 

    //Cette méthode connecte toutes les masses à une distance inférieure au rayon de raccomodage
    void raccomode();

    //Cette méthode permet d'ajouter un tissu au tissu compose
    void operator+= (Tissu&);

private : 

    double epsilon;
    double raideur_raccomodage;

};
