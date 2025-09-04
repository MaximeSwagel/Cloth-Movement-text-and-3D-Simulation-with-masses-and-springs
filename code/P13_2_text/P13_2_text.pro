QT += core gui opengl widgets
QMAKE_CXXFLAGS += -std=c++11

win32:LIBS += -lopengl32

TARGET = TestContrainte2_text

LIBS += -L../general -lgeneral
PRE_TARGETDEPS += ../general/libgeneral.a

INCLUDEPATH = ../general ../head ../source ../text

SOURCES += \
    ../text/TextViewer.cc \
    TestContrainte2.cc \
    ../source/Impulsion_sin.cc \
    ../source/Crochet.cc \
    ../source/TissuRectangle.cc \
    ../source/IntegrateurEulerCromer.cc

HEADERS += \
    ../text/TextViewer.h \
    ../head/Impulsion_sin.h \
    ../head/Crochet.h \
    ../head/TissuRectangle.h \
    ../head/IntegrateurEulerCromer.h
