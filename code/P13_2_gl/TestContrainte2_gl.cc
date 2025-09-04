#include <QApplication>
#include "glwidget.h"
#include "Crochet.h"
#include "IntegrateurEulerCromer.h"
#include "Impulsion_sin.h"
#include "TissuRectangle.h"
#include "Systeme.h"

using namespace std;

int main(int argc, char* argv[])
{

	
	TissuRectangle rectangle(0.3125, {3,0,0}, {0,3,0}, 0.3, 1.0, 1.0, 1.0, {0,0,0});
	
	Crochet contrainte1( 0.1, {0,0,0});
	
	Crochet contrainte2(0.1, {0,3,0});
	
	Impulsion_sin impulsion1(0.5, {3,0,0}, 0, 2, {0,0,30}, {&rectangle}, 1.5);
	
	Impulsion_sin impulsion2(0.5, {3,3,0}, 0, 2, {0,0,30}, {&rectangle}, 1.5);
	
	Systeme systeme({&rectangle}, {&contrainte1, &contrainte2, &impulsion1, &impulsion2});
	

  QApplication a(argc, argv);
  GLWidget w(&systeme);
  w.show();

  return a.exec();
}
