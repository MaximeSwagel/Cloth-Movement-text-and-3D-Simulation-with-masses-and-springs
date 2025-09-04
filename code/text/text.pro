QMAKE_CXXFLAGS += -std=c++11

CONFIG += console

TARGET = exerciceP11_text

LIBS += -L../general -lgeneral
PRE_TARGETDEPS += ../general/libgeneral.a

INCLUDEPATH = ../general ../head

SOURCES += \
    exerciceP11_text.cc \
    TextViewer.cc

HEADERS += \
    TextViewer.h

