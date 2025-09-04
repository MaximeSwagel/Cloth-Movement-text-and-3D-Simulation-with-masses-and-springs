QT += core gui opengl widgets
QMAKE_CXXFLAGS += -std=c++11

win32:LIBS += -lopengl32

TARGET = TestContrainte1_text

LIBS += -L../general -lgeneral
PRE_TARGETDEPS += ../general/libgeneral.a

INCLUDEPATH = ../general ../head ../source ../text

SOURCES += \
    ../text/TextViewer.cc \
    TestContrainte1.cc \
    ../source/Crochet.cc \
    ../source/IntegrateurEulerCromer.cc

HEADERS += \
    ../text/TextViewer.h \
    ../head/Crochet.h \
    ../head/IntegrateurEulerCromer.h

RESOURCES += \
    ../Qt_GL/resource.qrc