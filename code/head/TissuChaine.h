#pragma once
#include "Tissu.h"

class TissuChaine : public Tissu {

public:

//Constructeur : 

    TissuChaine(double masse, double lambda, double k, double l, std::vector<Vecteur3D> const& positions);

    TissuChaine(TissuChaine const&) = delete;


};