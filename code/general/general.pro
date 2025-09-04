TEMPLATE = lib

CONFIG = staticlib 
//QMAKE_CXXFLAGS += -std=c++11

INCLUDEPATH += ../head ../source

HEADERS += \
    ../head/Dessinable.h \
    ../head/Systeme.h \
    ../head/Masse.h \
	../head/Vecteur3D.h \
	../head/Ressort.h \
	../head/Tissu.h \
	../head/IntegrateurEulerCromer.h \
	../head/constantes.h \
	../head/Integrateur.h \
    ../head/SupportADessin.h \
    ../head/Contrainte.h \
    ../head/Crochet.h \
    ../head/Impulsion.h \
    ../head/Impulsion_sin.h \
    ../head/TissuChaine.h \
	../head/TissuCompose.h \
	../head/TissuDisque.h \
	../head/TissuRectangle.h \
    ../head/IntegrateurNewmark.h \
    ../head/IntegrateurRungeKutta.h
    
SOURCES += \
    ../source/Systeme.cc \
    ../source/Masse.cc \
    ../source/Vecteur3D.cc \
    ../source/Ressort.cc \
    ../source/Tissu.cc \
    ../source/IntegrateurEulerCromer.cc \
    ../source/constantes.cc \
    ../source/Crochet.cc \
    ../source/Impulsion.cc \
    ../source/Impulsion_sin.cc \
    ../source/TissuChaine.cc \
    ../source/TissuCompose.cc \
    ../source/TissuDisque.cc \
    ../source/TissuRectangle.cc \
    ../source/IntegrateurNewmark.cc \
    ../source/IntegrateurRungeKutta.cc

