
#pragma once
#include <vector>
#include "Vecteur3D.h"
#include "constantes.h"
#include "Ressort.h"
#include "SupportADessin.h"
#include "Dessinable.h"

class Masse : public Dessinable{

public:

//Constructeurs :

    Masse() = delete; // Il faut toujours donne la masse d'une instance de la classe Masse lors de sa construction

    Masse(double masse, double lambda = 0.3);

    Masse(double masse, Vecteur3D position = {0,0,0}, double lambda = 0.3, Vecteur3D vitesse = {0,0,0}, Vecteur3D F = {0,0,0});

    Masse(double masse, Vecteur3D position = {0,0,0} , Vecteur3D vitesse = {0,0,0}, Vecteur3D F = {0,0,0}, double lambda = 0.3);

    Masse(Masse const&);

//Méthodes publiques :

    // Cette méthode ajoute un vecteur force à la résultante de toutes les forces sur une masse
    void ajoute_force(Vecteur3D const&); 

    //Cette méthode retourne l'accélération d'une masse.
    //Ce n'est pas un getter car l'accélération n'est pas un attribut, mais est calculée
    Vecteur3D acceleration(); 

    //Cette méthode met à jour les forces de la masse.
    void maj_forces();

    //Cette méthode permet d'afficher une masse (avec toutes ses caractéristiques)
    std::ostream& affiche (std::ostream&) const;

    //Cette méthode permet d'afficher une avec un indice lui étant associé,
    //par exemple sa position dans un vector de pointeurs sur des masses.
    std::ostream& affiche (std::ostream&, size_t&) const;

    //Cette méthode permet d'ajouter un ressort au vector de pointeur sur des ressor "ressorts_"
    void add_ressort(Ressort*);

    //Permet de vider le vector "ressorts_"
    void clear_ressorts() {ressorts_.clear();}

    //Cette méthode permet de vérifier si une masse est connectée à un ressort
    bool check_connectee() const;

    //Cette méthode permet de vérifier si un ressort particulier est dans le vector "ressort_"
    bool check_ressort_connecte(Ressort*) const;

    //Cette méthode vérifie si l'instance courante de la class Masse est connectée à une autre masse.
    bool is_connected_to(Masse*) const;

    //Cette méthode est héritée de dessinable
    //elle pemet de représenter l'instance courante de Masse sur le support à dessin voulu 
    virtual void dessine_sur(SupportADessin&) override;

    //Permet de faire bouger une masse grâce à un intégrateur
    void evolue(Integrateur& I, double dt) override;

// getters

    Vecteur3D position() const;

    Vecteur3D vitesse() const;

    Vecteur3D force() const;

    std::vector<Ressort*> get_ressorts() const;

    double masse() const;

//setters :

    void set_position(Vecteur3D);

    void set_vitesse(Vecteur3D);

    void set_force(Vecteur3D);

private:

//Attributs privés :

    /*const*/ double masse_;

    Vecteur3D position_;

    Vecteur3D vitesse_;

    Vecteur3D F_; //résulatante de toutes les forces

    double lambda_; //coefficient de frottements fluide

    std::vector<Ressort*> ressorts_;

};

std::ostream& operator<<(std::ostream& out, Masse const& m);