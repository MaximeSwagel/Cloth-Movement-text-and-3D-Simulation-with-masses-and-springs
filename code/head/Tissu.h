#pragma once
#include "Masse.h"
#include "IntegrateurEulerCromer.h"

typedef std::vector<Masse*> liste_masses;
typedef std::vector<Ressort*> liste_ressorts;


class Tissu : public Dessinable{


    public:

//Méthodes publiques :

        Tissu(liste_masses const&);

        Tissu(double, double, std::vector<Vecteur3D> const&);
        
        Tissu() = default; // le tissu vide est aussi un tissu et respecte toutes les contraintes

        Tissu(Tissu const&) = delete;

//Destructeur :

        virtual ~Tissu();

//Méthodes publiques : 

        //Permet de connecter deux masses du tissu (référencée dans "masses_")
        void connecte(size_t , size_t , double k = 0, double l = 0);

        //permet de s'assurer que les masses du tissu sont bien connectées
        void connecte_masses();

        //Permet de vérifier si un tissu est conforme aux exigences du projet
        bool check() const;

        //Permet de faire bouge un tissu grâce à un intégrateur
        void evolue(Integrateur& I, double dt) override;

        //Met à jour les forces sur un tissu
        void maj_forces();

        //renvoie le pointeur sur un Ressort indicé par le paramètre dans "ressorts_"
        Ressort* get_ressort(size_t) const;

        //renvoie le pointeur sur une masse indicé par le paramètre dans "masses_"
        Masse* get_masse(size_t) const;

        //renvoie "masses_"
        liste_masses get_masses() const;

        //renvoie "ressorts_"
        liste_ressorts get_ressorts() const;
        
        virtual void dessine_sur(SupportADessin& support) override;

        //renvoie le nombre de masses qu'il y a dans le tissu
        size_t nbr_masses () const;

        //renvoie le nombre de masses qu'il y a dans le tisu
        size_t nbr_ressorts() const;

        //permet d'afficher les masses du tissu
        std::ostream& affiche_masses(std::ostream&, size_t&) const ;
        
        //permet d'afficher les ressorts du tissu
        std::ostream& affiche_ressorts(std::ostream&, size_t&) const;

        //permet de vide le vecteur de masses du tissu
        void vider_masses();

        //permet de vider le vecteur de ressorts du tissu
        void vider_ressorts();

    protected:

        liste_masses masses_;
        liste_ressorts ressorts_;

};
