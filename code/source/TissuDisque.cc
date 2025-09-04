#define _USE_MATH_DEFINES
#include "TissuDisque.h"
#include <cmath>
using namespace std;

//Constructeurs : 

    TissuDisque::TissuDisque(double m, Vecteur3D R, double pas, double lambda, double k, Vecteur3D  centre) {

        double alpha (M_PI/9);

        if ( pas != 0) { //si le pas vaut 0, le tissu est vide

            if ( pas < 0) pas = -pas;

            if (R == Vecteur3D(0,0,0)) R = {0,0,1};

            Vecteur3D u;

            //On cherche un vecteur orthonormal au rayon
            if ( R.get_coord('x') != 0)  u = ~Vecteur3D(-(1/R.get_coord('x'))*(R.get_coord('y') + R.get_coord('z')), 1, 1);

            else if ( R.get_coord('y') != 0)  u = ~Vecteur3D(1, -(1/R.get_coord('y'))*(R.get_coord('x') + R.get_coord('z')), 1);

            else u = ~Vecteur3D(1, 1, -(1/R.get_coord('z'))*(R.get_coord('y') + R.get_coord('x')));
            
            int n (R.norme() / pas); // Il s'agit du nombre de masses par rayon du disque

            Vecteur3D N = ~R;

            masses_.push_back( new Masse (m, centre, lambda) );

            
            // On ajoute les masse une par une sur des rayons du dique
            for (double angle (0); angle < (2*M_PI - margin_); angle += alpha) { 

                for (int j (1); j <= n ; ++j) {

                    masses_.push_back( new Masse (m, centre + ((j*pas)*u), lambda) );

                }

                u = cos(alpha)*u + (1-cos(alpha))*((u*N)*N) + sin(alpha)*(N^u);
            }

            //On connecte les masses :
            // Pour cela on sert de l'indice des masses et du nombre de masses par rayon n pour les connecter de manière adéquate 
            for ( size_t i(1); i < nbr_masses() ; ++i) {
            
                if (n == 1) {

                connecte (0, i, k, pas);

                if ( i != nbr_masses()-1) connecte (i, i+1, 0, 2*pas*sin(alpha/2));

                else if ( i == nbr_masses()-1) connecte (i, 1, 0, 2*pas*sin(alpha/2)); // le dernier parmètre représente la distance entre les deux masses qu'on connecte

                }

                else {

                if ( i % n == 1) connecte (0, i, k, pas);

                if ( i % n != 1 and i != 0) connecte (i, i-1, k, pas);

                if ( i > n and (i % n) != 0 ) connecte (i, i-n, k, 2*(i%n)*pas*sin(alpha/2));

                if ( i > n and (i % n) == 0 ) connecte ( i , i-n, k, 2*n*pas*sin(alpha/2));

                if ( i > 0 and i <= n ) connecte(i, masses_.size() - (n-i+1), k, 2*i*pas*sin(alpha/2));

                }

            }

        }
    }
