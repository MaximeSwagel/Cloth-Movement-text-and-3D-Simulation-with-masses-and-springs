#include "Vecteur3D.h"
using namespace std;


// Constructeur :

	Vecteur3D :: Vecteur3D (double x, double y , double z)
	:coord_({x , y , z})
	{}

//Méthodes publiques :

	array<double,3> Vecteur3D::get_coord () const{
		
		return coord_;
		
	}

	double Vecteur3D::get_coord(char c) const {

		switch (c) {

			case 'x' :
			return coord_[0];
			break;

			case 'y' :
			return coord_[1];
			break;

			case 'z' : 
			return coord_[2];
			break;

			//valeur par défaut retournée si le char est incohérent
			default :
			return 0;
		}
		
	}

	ostream& Vecteur3D::affiche(ostream& sortie) const{
		
		sortie<<coord_[0]<<" "<<coord_[1]<<" "<<coord_[2];

		return sortie;
		
	}

	bool Vecteur3D::operator== (Vecteur3D const& v) const{
		
		for (size_t i(0); i<3 ; ++i ) {

			//Comme les coordonnées sont des doubles, on tolère une marge d'erreur sur chaque composante (margin_ est définie dans le fichier constantes.cc)
			
			if (abs(v.coord_[i]-coord_[i])> margin_) return false;
			
		}
		
		return true;
	}
	
	void Vecteur3D::operator+=(Vecteur3D const& v){

		for (size_t i (0) ; i<3 ; ++i) {

			coord_[i] += v.coord_[i];

		}
	}
	
	void Vecteur3D::operator *= (double const& s) {
		
		for (size_t i(0); i<3 ; ++i) {
			
			coord_[i] = s * coord_[i];
		}
		
	}
	
	double Vecteur3D::operator*(Vecteur3D const& v2) const {

		double ps(0);
		 
		for (size_t i(0); i<3; ++i) {
			 
			ps+= coord_[i]*v2.coord_[i];
			 
			}
		 
		return ps;

	}
	
	void Vecteur3D::operator-=(Vecteur3D const& v) {

			*this += (-v);

	}
		
	Vecteur3D Vecteur3D::oppose() const {

		Vecteur3D retour(0,0,0);

		for (size_t i (0) ; i<3 ; ++i) {

			retour.coord_[i] -= coord_[i];

		}

		return retour;
	}
	
	Vecteur3D Vecteur3D::operator -() const{
		return this->oppose();
	}

	double Vecteur3D::norme2 () const {
		
		return ((*this)*(*this));
		
	}

	double Vecteur3D::norme() const {
		
		return sqrt (norme2());
		
		}
	
	Vecteur3D Vecteur3D::operator^(Vecteur3D const& v2) const{
		
		Vecteur3D retour;

		retour.set_x (coord_[1]*v2.coord_[2] - coord_[2]*v2.coord_[1]);
		retour.set_y (coord_[2]*v2.coord_[0] - coord_[0]*v2.coord_[2]);
		retour.set_z (coord_[0]*v2.coord_[1] - coord_[1]*v2.coord_[0]);
		
		return retour;

    }

//Méthodes privées :

	void Vecteur3D::set_coord(size_t n , double c ) { coord_[n] = c;}

//Surcharge externes des opérateurs :

	ostream& operator<<(ostream& out, Vecteur3D v) {

		v.affiche(out);

		return out;
	}

    bool operator!=(Vecteur3D const& v1 , Vecteur3D const& v2){

		if( not (v1 == v2) ) return true;

		else return false;

	}

	Vecteur3D operator+ (Vecteur3D v1, Vecteur3D const& v2){

		v1+=v2;

		return v1;

	}

	Vecteur3D operator*( Vecteur3D v, double const& s) {

		v *= s;
		
		return v;
	}

	Vecteur3D operator* (double const& s, Vecteur3D v){

		return v*s;

	}


	Vecteur3D operator-(Vecteur3D v1 , Vecteur3D const& v2){
		
		v1-=v2;

		return v1;

	}

	Vecteur3D operator~(Vecteur3D v) {

		if (v == Vecteur3D{0,0,0}) return {0,0,0}; // On retourne exceptionnellement un veceur non unitaire si le vecteur entré est nulle

		v*= 1/v.norme();

		return v;
	}
