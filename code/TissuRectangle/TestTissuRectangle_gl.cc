#include <QApplication>
#include "glwidget.h"
#include "TissuRectangle.h"
#include "Systeme.h"
#include "Crochet.h"

int main(int argc, char* argv[])
{
	TissuRectangle tissu ( 1, {0,8,0}, {0,0,8}, 0.5, 0.3, 0.5, 0.5, {0,0,0} );
	Crochet crochet(20, {0,0,0});
  Systeme systeme({&tissu}, {&crochet});
    
  QApplication a(argc, argv);
  GLWidget w(&systeme);
  w.show();

  return a.exec();
}
