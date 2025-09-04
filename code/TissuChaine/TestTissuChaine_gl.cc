#include <QApplication>
#include "glwidget.h"
#include "TissuChaine.h"
#include "Systeme.h"
#include "Crochet.h"
#include "Impulsion_sin.h"

int main(int argc, char* argv[])
{
	TissuChaine tissu ( 1, 1, 5, 0.5, {{0,0,0},{1,0,0},{2,0,0},{3,0,0},{4,0,0}} );
  Crochet crochet1(0.5, {0,0,0});
  Systeme systeme({&tissu}, {&crochet1});
    
  QApplication a(argc, argv);
  GLWidget w(&systeme);
  w.show();

  return a.exec();
}
