#include "IntegrateurEulerCromer.h"
using namespace std;

//implémentation des formules fournies dans le complément mathématique
void IntegrateurEulerCromer::evolue(Masse& masse, double dt) {
						
	masse.set_vitesse(masse.vitesse() + dt * masse.acceleration());
			
	masse.set_position(masse.position() + dt * masse.vitesse());
}

