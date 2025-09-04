#pragma once
#include <array>
#include <iostream>
#include "constantes.h"
#include <cmath>

class Vecteur3D {
	
	public :

	//Constructeurs :

		Vecteur3D (double x = 0, double y = 0 , double z = 0);
	
	//Setters :
	
		void set_x (double c) {set_coord( 0, c );} //set_coord() la fonction private <-> Cela nous permet de gerer les eurreurs sur le size_t de la fonction set_coord() [et la lisibilite]
		void set_y (double c) {set_coord( 1, c );}
		void set_z (double c) {set_coord( 2, c );}

	//getters :
		
		std::array<double,3> get_coord () const;

		double get_coord (char) const; //le char indique si on veut 'x', 'y' ou 'z'

	//surchage interne des operateurs
		
		std::ostream& affiche(std::ostream&) const;
		
		bool operator==(Vecteur3D const&) const;
		
		void operator+=(Vecteur3D const&);
		
		void operator*= (double const&);

		double operator*(Vecteur3D const& v2) const; // Il s'agit du produit scalaire standard entre deux vecteurs

		Vecteur3D operator^ (Vecteur3D const& v2) const; // Il s'agit du produit vectoriel entre deux vecteur

		void operator-=(Vecteur3D const& v);
		
		Vecteur3D oppose() const;
		
		Vecteur3D operator -() const;

		double norme2 () const; //renvoie le carré de la norme d'une vecteur
		
		double norme() const;
		
	private :
	
		void set_coord(size_t, double);
		
		std::array<double,3> coord_; // la methode privee utilisee set_x, set_y et set_z
		
	};

//surchage externe des operateurs

	std::ostream& operator<<(std::ostream& out, Vecteur3D v);
	
	bool operator!=(Vecteur3D const& v1 , Vecteur3D const& v2);

	Vecteur3D operator+ (Vecteur3D, Vecteur3D const&);
	
	Vecteur3D operator*( Vecteur3D v, double const& s);

	Vecteur3D operator* (double const& s, Vecteur3D v);

	Vecteur3D operator-(Vecteur3D v1 , Vecteur3D const& v2);

	Vecteur3D operator~(Vecteur3D v); //renvoie un vecteur unitaire dans la même direction et le même sens
