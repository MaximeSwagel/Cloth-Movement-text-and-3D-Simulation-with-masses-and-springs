#include "Tissu.h"
using namespace std;


//Constructeurs et destructeurs : 

   Tissu::Tissu(vector<Masse*>const& masses)
   {
    
    for (auto const& masse : masses) {

        masses_.push_back(new Masse(*masse));
        
    }

   }

   Tissu::Tissu(double m, double lambda, vector<Vecteur3D> const& positions) {

    for ( auto const& position : positions) {

        masses_.push_back(new Masse (m, position, lambda));

    }

   }

   Tissu::~Tissu() {

    for (auto const& masse : masses_) delete masse;

    for (auto const& ressort : ressorts_) delete ressort;

   }

//Méthodes internes :

    void Tissu::connecte(size_t i , size_t j, double k, double l) {

        ressorts_.push_back(new Ressort(masses_[i], masses_[j], k, l));
        
        this->connecte_masses();
    }

    void Tissu::connecte_masses() {

        for (auto masse : masses_) {

            masse->clear_ressorts();
        }

        for(auto const& ressort : ressorts_) {

            //On modifie les listes de ressorts des masses afin qu'elle correspondent à la liste de masses et de ressorts du tissu
            
            ressort -> get_masse(1) -> add_ressort(ressort); 
            ressort -> get_masse(2) -> add_ressort(ressort);
            
        }

    }

   bool Tissu::check() const{

        for( auto masse : masses_) {

            if( not masse->check_connectee()) //On vérifie si toutes les masses sont liées à au moins un ressort
            {

                cerr<<"Une masse est isolée"<<endl;

                return false;
            }

            for (auto ressort : masse->get_ressorts()) {

                if (not ressort->check_masse_connectee(masse)) { //On vérifie que chaque ressort dans la liste de ressorts d'une masse est bien lié à cette masse

                    return false;

                }

            }
        }

        for (auto ressort : ressorts_) {

        if (not ressort->check_masses()) return false; //On vérifie que les masses que lient chaque ressort respectent les contraintes de l'exercice P8

        else if ( not ressort->get_masse(1)->check_ressort_connecte(ressort)) //On vérifie que les masses que lient chaque ressort possèdent bien ledit ressort dans leur liste de ressorts
         {

            return false;
        }

        else if ( not ressort->get_masse(2)->check_ressort_connecte(ressort)) //Pareil que le dernier commentaire (étape complémentaire)
         {

            return false;
        }

        }

        return true;
        
    }


   void Tissu::evolue(Integrateur& I, double dt){

        for (auto masse : masses_) {
        
        //Fait bouger toutes les masses du tissu une par une
        I.evolue (*masse, dt);
 
         }
    }

    void Tissu::maj_forces() {

        for (auto masse : masses_) {

            masse->maj_forces();

        }
    }

    Ressort* Tissu::get_ressort(size_t t) const {

        if (t < ressorts_.size()) return ressorts_[t];

        else return nullptr; // Si l'indice est incohérent, on renvoit un pointeur nul

    }

    Masse* Tissu::get_masse(size_t t) const {

        if (t < masses_.size()) return masses_[t];

        else return nullptr; // Si l'indice est incohérent, on renvoit un pointeur nul

    }

    vector<Masse*> Tissu::get_masses() const {

        return masses_;

    }

    vector<Ressort*> Tissu::get_ressorts() const {

        return ressorts_;

    }
    
     void Tissu::dessine_sur(SupportADessin& support) {
        
         support.dessine(*this); 
         
         }
    
    size_t Tissu::nbr_masses() const{

        return masses_.size();

    }

    size_t Tissu::nbr_ressorts() const {

        return ressorts_.size();

    }
    
    ostream& Tissu::affiche_masses(ostream& out, size_t& i) const {

        for (auto const& m : masses_) {

            m->affiche(out, i);
            out<<endl;
        }

        return out;
    }

    ostream& Tissu::affiche_ressorts(ostream& out, size_t& i) const {

        for (auto const& r : ressorts_) {

            r->affiche(out, i);
            out<<endl;
        }

        return out;

    }

    void Tissu::vider_masses() {masses_.clear();}

    void Tissu::vider_ressorts() {ressorts_.clear();}
    
