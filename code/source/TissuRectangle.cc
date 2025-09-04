#include "TissuRectangle.h"
#include <cmath>
using namespace std;

//Constructeurs :

    TissuRectangle::TissuRectangle(double m, Vecteur3D longueur, Vecteur3D largeur, double lambda, double d, double k, double l, Vecteur3D Origine) {

        if (d != 0 and longueur.norme2() != 0 and largeur.norme2() != 0) //Si la longueur ou la largeur est nulle, le tissu est vide
        
        {

            if (not (abs (~longueur * ~largeur) == 1 )) // Si la largeur et la longueur son colinéaires, c'est un tissu chaine
            
            {

                if (longueur * largeur != 0) //si les vecteurs ne son pas orthogonaux, on les orthogonalise
                
                {

                    largeur -= ((longueur*largeur) * longueur) * (1 / longueur.norme2());
                }

                if ( d < 0 ) d = -d;

                int nL (longueur.norme()*d), nl(largeur.norme()*d);

                //On crée les masses une par une
                for (int i(0); i <= nl ; ++i) { 

                    for (int j(0); j <= nL ; ++j) { 

                        masses_.push_back( new Masse (m, Origine + ((1/d)* (((j) * ~longueur) + ((i) * ~largeur))), lambda));

                    }

                }
                //On connecte les masses en se servant de leurs indices pour les repérer
                for (size_t i(0); i < masses_.size(); ++i) {

                    if ( (i) % (nL + 1) != 0 ) connecte (i, i-1, k, l);

                    if ( i >= (nL + 1) ) connecte (i, i-(nL+1), k, l);

                }

            }
        }
    }
    