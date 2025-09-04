#pragma once
#include <iostream>
#include "Dessinable.h"

class Masse;
class Vecteur3D;
class SupportADessin;

class Ressort : public Dessinable{

    public :

//Constructeurs : 

    Ressort() = delete; // Il faut toujours qu'un ressort soit lié à des masses

    Ressort(Masse* m1, Masse* m2, double r = 0 , double l = 0); 

// Méthodes publiques : 

    //Retourne la force de rappel qu'exerce un ressort sur une masse
    Vecteur3D force_rappel(Masse* m) const;

    //Affiche un ressort et toutes ses caractéristiques.
    std::ostream& affiche (std::ostream&) const;

    //Permet d'afficher des ressorts en les indiçant
    std::ostream& affiche (std::ostream&, size_t&) const;  //size_t const&  

    //Renvoie une masse liée au ressort selon le paramètre
    Masse* get_masse(int) const;

    //Permet de vérifier si un ressort est lié à deux masses différentes
    bool check_masses();        // Checker si ces trois fonctions peuvent être const

    //Permet de vérifier si la masse pointée en paramètre est liée à ce ressort
    bool check_masse_connectee(Masse*);

    //Cette méthode est héritée de dessinable
    //elle pemet de représenter l'instance courante de la classe Ressort sur le support à dessin voulu 
    void dessine_sur(SupportADessin&) override;
    
    //Un ressort n'evoluant que selon ses masses : cette methode héritée de dessinable n'agit pas sur les ressorts (ne fait rien).
    void evolue(Integrateur&, double) override {}

    private :

// Attributs privés : 

    Masse* m1; //masse de départ
    Masse* m2; //masse d'arrivée
    const double k; //raideur
    const double l; // longueur de repos

//Méthodes privées : 

    //Cette méthode renvoie la direction d'un ressort 
    // et modifie son paramètre pour y stocké la longueur du ressort (distance entre les deux masses qu'elle lie)
    Vecteur3D direction (double&) const;
};

//fonctions externes à la classe :

    std::ostream& operator<<(std::ostream& out , Ressort r);
