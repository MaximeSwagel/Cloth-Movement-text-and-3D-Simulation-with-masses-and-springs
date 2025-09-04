#pragma once
#include "Tissu.h"

class TissuRectangle : public Tissu {

    public :

//Constructeurs : 

        TissuRectangle( double masse, Vecteur3D longueur, Vecteur3D largeur, double lambda, double densite, double raideur_k, double longueur_a_vide, Vecteur3D centre = {0,0,0});

        TissuRectangle(TissuRectangle const&) = delete;
};