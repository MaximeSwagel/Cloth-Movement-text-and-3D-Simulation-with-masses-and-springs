#include "Ressort.h"
#include "Masse.h"
using namespace std;

// Constructeurs : 

    Ressort::Ressort(Masse* a, Masse* b, double k , double l)
    : m1(a), m2(b), k(k), l(l)
    {
        if(l<0) l = 0;
        if(k<0) k = 0;

        m1->add_ressort(this);
        m2->add_ressort(this);
    }

// Méthodes publiques :

    Vecteur3D Ressort::force_rappel(Masse* m) const {

        Vecteur3D L;
        double d;

        if (m == m1) { 
            
            L = direction(d); 
            
            return (k*(d-l))*L;
            }

        else if (m == m2) { 
            
            L = direction(d).oppose();
            
            return (k*(d-l))*L;
            }

        else return Vecteur3D(0,0,0); 
        // Si le ressort n'est pas lié à la masse en argument, elle n'exerce pas de force sur elle.
    }

     ostream& Ressort::affiche (ostream& out) const {

        out<<"Ressort "<<this<<" :"<<endl
           <<k<<" #cst raideur"<<endl
           <<l<<" #longueur au repos"<<endl
           <<"# masse depart : Masse "<<m1<<" :"<<endl;

             (*m1).affiche(out);
           
        out<<"# masse arrivee : Masse "<<m2<<" :"<<endl;

             (*m2).affiche(out);

        return out;
    }

ostream& Ressort::affiche (ostream& out, size_t& i) const {

        out<<"Ressort "<<i<<" :"<<endl;
        ++i;

        return affiche(out);

    }

    Masse* Ressort::get_masse(int n) const{

        switch(n) {

            case 1 :
            return m1;
            break;

            case 2 :
            return m2;
            break;

            default :
            return nullptr;
            //Si le paramètre est incohérent on renvoie un pointeur nul
        }

    }

    bool Ressort::check_masses() {

        if (m1 == nullptr or m2 == nullptr) return false;

        else if( m1 == m2 ) return false;

        else return true;

    }

    bool Ressort::check_masse_connectee(Masse* m) {

        if (m1 == m or m2 == m) return true;

        else return false;

    }

    void Ressort::dessine_sur(SupportADessin& support){

        support.dessine(*this); 
    }


// Méthodes privées : 

    Vecteur3D Ressort::direction(double& x) const {

        Vecteur3D v = (*m2).position() - (*m1).position();

        x = v.norme();

        return ~v;

    }


    ostream& operator<<(ostream& out , Ressort r) {

        r.affiche(out);

        return out;

    }
