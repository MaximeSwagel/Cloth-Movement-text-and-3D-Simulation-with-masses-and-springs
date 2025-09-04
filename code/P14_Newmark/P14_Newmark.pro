QT += core gui opengl widgets
QMAKE_CXXFLAGS += -std=c++11

win32:LIBS += -lopengl32


TARGET = TestIntegrateurNewmark_text

LIBS += -L../general -lgeneral
PRE_TARGETDEPS += ../general/libgeneral.a

INCLUDEPATH = ../general ../head ../source ../text

SOURCES += \
    TestIntegrateurNewmark.cc \
    ../source/IntegrateurNewmark.cc \
    ../text/TextViewer.cc

HEADERS += \
	../head/IntegrateurNewmark.cc \
	../text/TextViewer.h
