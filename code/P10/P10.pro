QT += core gui opengl widgets
QMAKE_CXXFLAGS += -std=c++11

win32:LIBS += -lopengl32


TARGET = exerciceP10_text

LIBS += -L../general -lgeneral
PRE_TARGETDEPS += ../general/libgeneral.a

INCLUDEPATH = ../general ../head ../text ../source

SOURCES += \
    exerciceP10.cc \
    ../text/TextViewer.cc \
    ../source/Crochet.cc

HEADERS += \
    ../text/TextViewer.h \
    ../head/SupportADessin.h \
    ../head/Crochet.h
