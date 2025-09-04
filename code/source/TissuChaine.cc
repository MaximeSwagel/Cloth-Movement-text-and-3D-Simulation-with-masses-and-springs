#include "TissuChaine.h"
using namespace std;

//Constructeur :

    TissuChaine::TissuChaine(double m, double lambda, double k, double l, vector<Vecteur3D> const& positions)
    :Tissu (m, lambda, positions)
    {

        for (size_t i(0); i < masses_.size()-1; ++i) {

            connecte(i, i+1, k, l);

        }

    }


