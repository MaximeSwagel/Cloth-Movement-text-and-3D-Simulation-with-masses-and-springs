#include <QApplication>
#include "glwidget.h"
#include "TissuDisque.h"
#include "Crochet.h"
#include "Systeme.h"

using namespace std;
int main(int argc, char* argv[])
{

  TissuDisque t1 (1, {0,0,10}, 1, 1, 10, {0,0,0});
  Crochet crochet(0.1,{0,0,0});

  Systeme systeme({&t1}, {&crochet});
    
  QApplication a(argc, argv);
  GLWidget w(&systeme);
  w.show();

  return a.exec();
}
