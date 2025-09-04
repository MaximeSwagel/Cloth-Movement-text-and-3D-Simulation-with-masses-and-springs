#include <QApplication>
#include "glwidget.h"
#include "Systeme.h"
#include "Crochet.h"

using namespace std;
int main(int argc, char* argv[])
{

	Masse A(0.33,{0,0,-3},{0,0,0});

	Masse B(1,{-0.5,0,0},{0,0,0});

	Masse C(1,{0.5,0,0},{0,0,0});
	
	vector<Masse*> vect({&A,&B,&C});
	
  Tissu tissu_test(vect);

	tissu_test.connecte(0, 2, 0.6, 2.5);
  tissu_test.connecte(0, 1, 0.6, 2.5);
    
  Crochet crochet (1, {0,0,0});

  Systeme systeme({&tissu_test}, {&crochet});

  QApplication a(argc, argv);
  GLWidget w(&systeme);
  w.show();

  return a.exec();
}