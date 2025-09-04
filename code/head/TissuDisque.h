#include "Tissu.h"

class TissuDisque : public Tissu {

public :

    TissuDisque(double masse, Vecteur3D Rayon_normal, double pas, double lambda, double k , Vecteur3D centre = {0,0,0});

    TissuDisque(TissuDisque const&) = delete;
};