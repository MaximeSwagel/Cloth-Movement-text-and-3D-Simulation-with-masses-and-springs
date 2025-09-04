#include "Systeme.h"
using namespace std;

int main() {

    Masse A(0.33,{0,0,-3},{0,0,0});

    Masse B(1,{-0.5,0,0},{0,0,0});

    Masse C(1,{0.5,0,0},{0,0,0});

    vector<Masse*> vect({&A,&B,&C});

    Tissu tissu_test(vect);

    tissu_test.connecte(0, 1, 0.6, 2.5);
    tissu_test.connecte(0, 2, 0.6, 2.5);
    
    if(tissu_test.check()) cout<<"Le tissu est conforme aux exigences du projet"<<endl;
    
    else cout<<"Le tissu n'est pas conforme aux exigences du projet"<<endl;

    Systeme test({&tissu_test});

    cout<<test;

    return 0;
}