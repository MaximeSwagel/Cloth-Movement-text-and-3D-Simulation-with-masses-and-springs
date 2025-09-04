#include "IntegrateurNewmark.h"
#include<cmath>
using namespace std;



//Constructeurs : 

IntegrateurNewmark::IntegrateurNewmark(double e) 
:epsilon(e)
{}



// Méthodes publiques : 

    //implémentation de l'algorithme fournit dans le complément mathématique
    void IntegrateurNewmark::evolue( Masse& masse, double dt) {

        Vecteur3D Position_precedente(masse.position());
        Vecteur3D Vitesse_precedente(masse.vitesse());
        s = masse.acceleration();

        do {

            q = masse.position();
            r = masse.acceleration();
            masse.set_vitesse( Vitesse_precedente + ((dt/2)*(r+s)) );
            masse.set_position(Position_precedente + dt * Vitesse_precedente + ((pow(dt,2)/3)*(0.5 * r + s))); 

        } while((masse.position()-q).norme() >= epsilon);

    }