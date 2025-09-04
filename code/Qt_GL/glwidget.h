#pragma once

#include <QOpenGLWidget>
#include <QOpenGLBuffer>        // for VBO/IBO
#include <QElapsedTimer>        // replaces QTime in Qt6
#include "vue_opengl.h"
#include "Dessinable.h"
#include "Masse.h"
#include "Tissu.h"

class GLWidget : public QOpenGLWidget
/* La fenêtre hérite de QOpenGLWidget ;
 * les événements (clavier, souris, temps) sont des méthodes virtuelles à redéfinir.
 */
{
    Q_OBJECT
public:
    GLWidget(Dessinable* dessinable, QWidget* parent = nullptr)
        : QOpenGLWidget(parent), dessinable(dessinable)
    {}
    virtual ~GLWidget() = default;

private:
    // Les 3 méthodes clés de QOpenGLWidget
    void initializeGL() override;
    void resizeGL(int width, int height) override;
    void paintGL() override;

    // Événements
    void keyPressEvent(QKeyEvent* event) override;
    void timerEvent(QTimerEvent* event) override;
    void mouseMoveEvent(QMouseEvent* event) override;
    void mousePressEvent(QMouseEvent* event) override;

    void pause();

    // Vue
    VueOpenGL vue;

    // Buffers (moved inside class)
    QOpenGLBuffer vbo{QOpenGLBuffer::VertexBuffer};
    QOpenGLBuffer ibo{QOpenGLBuffer::IndexBuffer};

    // Timer
    int timerId;
    QElapsedTimer chronometre;   // was QTime

    // Objet à dessiner
    Dessinable* dessinable;

    // Position souris
    QPoint lastMousePosition;
};
