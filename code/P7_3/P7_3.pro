QT += core gui opengl widgets
QMAKE_CXXFLAGS += -std=c++11

win32:LIBS += -lopengl32


TARGET = TestIntegrateur3

LIBS += -L../general -lgeneral
PRE_TARGETDEPS += ../general/libgeneral.a

INCLUDEPATH = ../general ../head

SOURCES += \
    TestIntegrateur3.cc

HEADERS += \
    ../head/IntegrateurEulerCromer.h