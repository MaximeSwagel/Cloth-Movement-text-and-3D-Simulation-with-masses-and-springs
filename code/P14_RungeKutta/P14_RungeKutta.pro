QT += core gui opengl widgets
QMAKE_CXXFLAGS += -std=c++11

win32:LIBS += -lopengl32


TARGET = TestIntegrateurRungeKutta_text

LIBS += -L../general -lgeneral
PRE_TARGETDEPS += ../general/libgeneral.a

INCLUDEPATH = ../general ../head ../source ../text

SOURCES += \
    TestIntegrateurRungeKutta.cc \
    ../source/IntegrateurRungeKutta.cc \
    ../text/TextViewer.cc

HEADERS += \
	../head/IntegrateurRungeKutta.cc \
	../text/TextViewer.h
