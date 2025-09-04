#include <QApplication>
#include "glwidget.h"
#include "TissuCompose.h"
#include "TissuDisque.h"
#include "TissuChaine.h"
#include "TissuRectangle.h"
#include "Systeme.h"
#include "Crochet.h"
using namespace std;
int main(int argc, char* argv[])
{

  TissuDisque t1 (0.1, {0,0,4}, 1, 0.3, 10, {0,0,0});
  TissuRectangle t2 ( 0.1, {4,0,0},{0,4,0}, 0.3, 1, 2, 1, {9,0,0});
  TissuChaine chaine(0.1,0.3,10,1,{{5,0,0},{6,0,0},{7,0,0},{8,0,0}});

  vector<Contrainte*> crochets;

  for (auto masse : t1.get_masses()) {

    crochets.push_back( new Crochet(0.9, masse->position()));

  }

  TissuCompose compose ({&t1, &chaine, &t2}, 1.1, 10);

  compose.raccomode();

  Systeme systeme({&compose}, {crochets});
    
  QApplication a(argc, argv);
  GLWidget w(&systeme);
  w.show();

  return a.exec();
  
  for (auto crochet : crochets) {

    delete crochet;
    crochet = nullptr;

  }
}
