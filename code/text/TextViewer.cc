#include "TextViewer.h" 
 using namespace std;

//Methodes publiques

//chacune des methodes suivante affiche un dessinable dans une supportADessin textuel selon le format choisi.

	void TextViewer::dessine(Systeme const& a_dessiner){
	
	cout<<"========================================"<< endl;
	cout<<" t = "<< a_dessiner.get_t() << endl;
	for (auto element : a_dessiner.get_tissus()){
		this->dessine(*element);
	}
	}

	void TextViewer::dessine(Tissu const& a_dessiner){
		
	for(auto masse : a_dessiner.get_masses()){

		this->dessine(*masse);

	}
	}

	void TextViewer::dessine(Masse const& a_dessiner){
		
		flot << a_dessiner << endl;

	}

	void TextViewer::dessine(Ressort const& a_dessiner){

		flot << a_dessiner << endl;

	}
