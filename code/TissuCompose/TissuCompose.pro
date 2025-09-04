QT += core gui opengl widgets openglwidgets
QMAKE_CXXFLAGS += -std=c++11

win32:LIBS += -lopengl32


TARGET = TestTissuCompose_gl

LIBS += -L../general -lgeneral
PRE_TARGETDEPS += ../general/libgeneral.a

INCLUDEPATH = ../general ../head ../Qt_GL ../source

SOURCES += \
    TestTissuCompose_gl.cc \
    ../Qt_GL/glwidget.cc \
    ../Qt_GL/glsphere.cc \
    ../Qt_GL/vue_opengl.cc \
    ../source/TissuRectangle.cc

HEADERS += \
    ../Qt_GL/glwidget.h \
    ../Qt_GL/vertex_shader.h \
    ../Qt_GL/vue_opengl.h \
    ../Qt_GL/glsphere.h \
    ../head/SupportADessin.h \
    ../head/Systeme.h \
    ../head/TissuCompose.h \
    ../head/TissuDisque.h \
    ../head/Crochet.h \
    ../head/TissuRectangle.h


RESOURCES += \
    ../Qt_GL/resource.qrc
