QT += core gui opengl widgets openglwidgets
QMAKE_CXXFLAGS += -std=c++11

win32:LIBS += -lopengl32


TARGET = TestTissuRectangle_gl

LIBS += -L../general -lgeneral
PRE_TARGETDEPS += ../general/libgeneral.a

INCLUDEPATH = ../general ../head ../Qt_GL

SOURCES += \
    TestTissuRectangle_gl.cc \
    ../Qt_GL/glwidget.cc \
    ../Qt_GL/glsphere.cc \
    ../Qt_GL/vue_opengl.cc

HEADERS += \
    ../Qt_GL/glwidget.h \
    ../Qt_GL/vertex_shader.h \
    ../Qt_GL/vue_opengl.h \
    ../Qt_GL/glsphere.h \
    ../head/Dessinable.h \
    ../head/SupportADessin.h \
    ../head/Systeme.h \
    ../head/Masse.h \
    ../head/Tissu.h \
    ../head/Vecteur3D.h

RESOURCES += \
    ../Qt_GL/resource.qrc
