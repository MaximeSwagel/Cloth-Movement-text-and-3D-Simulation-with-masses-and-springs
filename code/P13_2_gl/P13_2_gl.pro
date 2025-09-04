QT += core gui widgets opengl openglwidgets

# OpenGL module varies by Qt version
greaterThan(QT_MAJOR_VERSION, 5) {
    QT += openglwidgets   # Qt 6: QOpenGLWidget is here
} else {
    QT += opengl          # Qt 5: QOpenGLWidget is here
}

# Prefer CONFIG over raw flags
CONFIG += c++11

TARGET = TestContrainte2_gl

LIBS += -L../general -lgeneral
PRE_TARGETDEPS += ../general/libgeneral.a

# Append (don't overwrite!) custom include paths
INCLUDEPATH += ../general ../head ../source ../Qt_GL

SOURCES += \
    TestContrainte2_gl.cc \
    ../source/Impulsion_sin.cc \
    ../source/Crochet.cc \
    ../source/TissuRectangle.cc \
    ../source/IntegrateurEulerCromer.cc \
    ../source/Systeme.cc \
    ../Qt_GL/glwidget.cc \
    ../Qt_GL/glsphere.cc \
    ../Qt_GL/vue_opengl.cc

HEADERS += \
    ../Qt_GL/glwidget.h \
    ../Qt_GL/vertex_shader.h \
    ../Qt_GL/vue_opengl.h \
    ../Qt_GL/glsphere.h \
    ../head/Systeme.h \
    ../head/Impulsion_sin.h \
    ../head/Crochet.h \
    ../head/TissuRectangle.h \
    ../head/IntegrateurEulerCromer.h

RESOURCES += \
    ../Qt_GL/resource.qrc