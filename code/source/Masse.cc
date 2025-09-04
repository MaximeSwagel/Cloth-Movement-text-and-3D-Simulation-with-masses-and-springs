#include "Integrateur.h"
using namespace std;

//Constructeurs :

    Masse::Masse(double masse, double lambda)
    : masse_(masse), F_(masse*g), lambda_(lambda)
    { if (masse <= 0) throw 0; }

    Masse::Masse (double masse, Vecteur3D position, double lambda, Vecteur3D vitesse, Vecteur3D F) // la valeur par défaut qui est conseillée // il faut bien mentionner la convention que la position vient avant la vitesse etc..
    : masse_(masse), position_(position), vitesse_(vitesse), F_(F), lambda_(lambda)
    {

        if (masse <= 0) throw 0;
        if (F_ == Vecteur3D(0,0,0)) F_ = masse*g;

    }


    Masse::Masse(double masse, Vecteur3D position, Vecteur3D vitesse, Vecteur3D F, double lambda) 
    : masse_(masse), position_(position), vitesse_(vitesse), F_(F), lambda_(lambda)
    {

        if (masse <= 0) throw 0;
        if (F_ == Vecteur3D(0,0,0)) F_ = masse*g;

    }

    //on définit le constructeur de copie par soucie de copie profonde. On utilise pour celà l'operateur "=" qu'on a surchargé

    Masse::Masse(Masse const& masse)
    :masse_(masse.masse_), position_(masse.position_), vitesse_(masse.vitesse_), F_(masse.F_), lambda_(masse.lambda_)
    {} 

// il n'y a pas besoin de destructeurs car on alloue pas de mémoire dynamiquement, on pointe sur de la mémoire déjà allouée

//Méthodes publiques : 

    void Masse::ajoute_force(Vecteur3D const& df) {

        F_ += df;

    }

    Vecteur3D Masse::acceleration() {

        return (1/masse_)*F_;

    }

    void Masse::maj_forces() {

        F_ = masse_*g;


        for (auto ressort : ressorts_) {

            //On ajoute les forces induites par tous les ressorts dans cette boucles

            F_ += (*ressort).force_rappel (this);

        }

        //On ajoute la force induite par les frottements

        F_ -= lambda_*vitesse_;

    }

    ostream& Masse::affiche(ostream& out) const{

        out<<"Masse "<<this<<" :"<<endl

        <<masse_<<" # masse"<<endl

        <<lambda_<<" # lambda"<<endl

        <<position_<<" # position"<<endl

        <<vitesse_<<" # vitesse"<<endl

        <<F_<<" # force"<<endl

        <<ressorts_.size()<<" ressorts"<<endl;


        for(auto elt : ressorts_) {

            out<<elt<<endl;

        }

        return out;

    }

    ostream& Masse::affiche(ostream& out, size_t& i) const {

        out<<"Masse "<<i<<" :"<<endl;

        ++i;

        return affiche(out);

    }

    void Masse::add_ressort(Ressort* r) { //attention il faut que le ressort soit celui de la masse

        ressorts_.push_back(r);

    }

    bool Masse::check_connectee() const {

        if(ressorts_.size() > 0) return true;

        else return false;

    }

    bool Masse::check_ressort_connecte(Ressort* r) const {

        for( auto ressort : ressorts_ ) {

            if (ressort == r) return true;


        }

        return false;

    }

    bool Masse::is_connected_to(Masse* m) const {

        for (auto const& ressort : m->get_ressorts()) {

            //Dans cette boucle on vérifie si un ressort de m est lié à la masse qui appelle cette méthode

            if (check_ressort_connecte(ressort)) return true;

        }

        return false;

    }

    void Masse::dessine_sur(SupportADessin& support) { 

        support.dessine(*this); 

    }


    void Masse::evolue(Integrateur& I, double dt){

        I.evolue(*this, dt);

    }


//getters

    Vecteur3D Masse::position() const {return position_;}

    Vecteur3D Masse::vitesse() const {return vitesse_;}

    Vecteur3D Masse::force() const {return F_;}

    double Masse::masse() const {return masse_;}

    vector<Ressort*> Masse::get_ressorts() const {

        return ressorts_;

    }

//setters :

    void Masse::set_position(Vecteur3D v) {

        position_ = v;

    }

    void Masse::set_vitesse(Vecteur3D v) {

        vitesse_ = v;

    }

    void Masse::set_force(Vecteur3D v) {

        F_= v;

    }

// Surcharge externe des opérateurs :

    ostream& operator<<(ostream& out, Masse const& m) {

        m.affiche(out);

    return out;

    }
