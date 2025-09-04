#include "Crochet.h"
#include "IntegrateurEulerCromer.h"
#include "TextViewer.h"
#include "Crochet.h"
#include "Impulsion_sin.h"
#include "TissuRectangle.h"

using namespace std;

int main(){
	
	IntegrateurEulerCromer I;
	
	TextViewer display(cout);
	
	TissuRectangle rectangle(0.3125, {3,0,0}, {0,3,0}, 0.3, 1.0, 1.0, 1.0, {0,0,0});

	if(rectangle.check()) cout<<"Le tissu est conforme aux exigences du projet"<<endl;
    
    else cout<<"Le tissu n'est pas conforme aux exigences du projet"<<endl;
	
	Crochet contrainte1( 0.1, {0,0,0});
	
	Crochet contrainte2(0.1, {0,3,0});
	
	Impulsion_sin impulsion1(0.5, {3,0,0}, 0, 2, {0,0,30}, {&rectangle}, 1.5);
	
	Impulsion_sin impulsion2(0.5, {3,3,0}, 0, 2, {0,0,30}, {&rectangle}, 1.5);
	
	Systeme systeme({&rectangle}, {&contrainte1, &contrainte2, &impulsion1, &impulsion2});
	
	display.dessine(systeme);
	
	for( int i(0); i<25; ++i){
		
		systeme.evolue(I, 0.01);
	
		display.dessine(systeme);
	}
	
	return 0;
}
