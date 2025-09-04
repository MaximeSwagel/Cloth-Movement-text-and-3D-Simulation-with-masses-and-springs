#include "IntegrateurRungeKutta.h"
using namespace std;

    //implémentation de l'algorithme fournit dans le complément mathématique
    void IntegrateurRungeKutta::evolue (Masse& masse, double dt) {

        k1 = masse.vitesse();
        K_1 = masse.acceleration();
        k2 = masse.vitesse() + ((dt/2.0) * K_1);

        Masse masse2(masse.masse(), masse.position() + (dt/2.0)*k1, masse.vitesse() + (dt/2.0)*K_1 );

        K_2 = masse2.acceleration();
        k3 = masse.vitesse() + ((dt/2.0) * K_2);

        masse2 = {masse.masse(), masse.position() + (dt/2.0)*k2, masse.vitesse() + (dt/2.0)*K_2 };

        K_3 = masse2.acceleration();
        k4 = masse.vitesse() + (dt * K_3);

        masse2 = {masse.masse(), masse.position() + (dt/2.0)*k3, masse.vitesse() + (dt/2.0)*K_3 };

        K_4 = masse2.acceleration();

        masse.set_position( masse.position() + ((dt/6) * ( k1 + 2*k2 + 2*k3 + k4 )) );

        masse.set_vitesse ( masse.vitesse() + ((dt/6) * ( K_1 + 2*K_2 + 2*K_3 + K_4 )) );

    }