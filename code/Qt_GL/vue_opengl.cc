#include "vue_opengl.h"
#include "vertex_shader.h"
#include "systeme.h"
#include "Masse.h"
#include "Tissu.h"

#include <QVector>

// ======================================================================
void VueOpenGL::dessine(Systeme const& a_dessiner)
{
    for (auto tissu : a_dessiner.get_tissus()) {
        dessine(*tissu);
    }
}

void VueOpenGL::dessine(Tissu const& a_dessiner)
{
    for (auto masse : a_dessiner.get_masses()) {
        dessine(*masse);
    }

    QMatrix4x4 matrice;
    matrice.setToIdentity();
    dessineAxes(matrice, true);

    for (auto ressort : a_dessiner.get_ressorts()) {
        dessine(*ressort);
    }
}

void VueOpenGL::dessine(Masse const& a_dessiner)
{
    QMatrix4x4 matrice;
    matrice.setToIdentity();
    matrice.translate(a_dessiner.position().get_coord('x'),
                      a_dessiner.position().get_coord('y'),
                      a_dessiner.position().get_coord('z'));
    matrice.scale(0.5);

    prog.bind();
    prog.setUniformValue("vue_modele", matrice_vue * matrice);
    prog.setAttributeValue(CouleurId, 0.0, 1.0, 1.0);
    sphere.draw(prog, SommetId);
    prog.release();
}

void VueOpenGL::dessine(Ressort const& a_dessiner)
{
    QMatrix4x4 matrice;
    prog.bind();
    prog.setUniformValue("vue_modele", matrice_vue * matrice);

    QVector<GLfloat> vertices = {
        (GLfloat)a_dessiner.get_masse(1)->position().get_coord('x'),
        (GLfloat)a_dessiner.get_masse(1)->position().get_coord('y'),
        (GLfloat)a_dessiner.get_masse(1)->position().get_coord('z'),
        (GLfloat)a_dessiner.get_masse(2)->position().get_coord('x'),
        (GLfloat)a_dessiner.get_masse(2)->position().get_coord('y'),
        (GLfloat)a_dessiner.get_masse(2)->position().get_coord('z')
    };

    prog.setAttributeValue(CouleurId, 1.0, 1.0, 1.0);

    GLuint vbo;
    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(GLfloat), vertices.constData(), GL_STATIC_DRAW);

    prog.enableAttributeArray(SommetId);
    prog.setAttributeArray(SommetId, GL_FLOAT, nullptr, 3);
    glDrawArrays(GL_LINES, 0, 2);
    prog.disableAttributeArray(SommetId);

    glDeleteBuffers(1, &vbo);

    prog.release();
}

// ======================================================================
void VueOpenGL::init()
{
    prog.addShaderFromSourceFile(QOpenGLShader::Vertex,   ":/vertex_shader.glsl");
    prog.addShaderFromSourceFile(QOpenGLShader::Fragment, ":/fragment_shader.glsl");

    prog.bindAttributeLocation("sommet",  SommetId);
    prog.bindAttributeLocation("couleur", CouleurId);

    prog.link();
    prog.bind();

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);

    sphere.initialize();
    initializePosition();
    prog.release();
}

// ======================================================================
void VueOpenGL::initializePosition()
{
    matrice_vue.setToIdentity();
    matrice_vue.rotate(90, 0,0,-1);
    matrice_vue.rotate(30, 0,-1,0);
    matrice_vue.rotate(20, 1,0,0);
    matrice_vue.rotate(45, 0,0,-1);
    matrice_vue.translate(-3.0, -4.0, -8.0);
}

// ======================================================================
void VueOpenGL::translate(double x, double y, double z)
{
    QMatrix4x4 translation;
    translation.translate(x, y, z);
    matrice_vue = translation * matrice_vue;
}

void VueOpenGL::rotate(double angle, double dx, double dy, double dz)
{
    QMatrix4x4 rotation;
    rotation.rotate(angle, dx, dy, dz);
    matrice_vue = rotation * matrice_vue;
}

// ======================================================================
void VueOpenGL::dessineAxes(QMatrix4x4 const& point_de_vue, bool en_couleur)
{
    prog.bind();
    prog.setUniformValue("vue_modele", matrice_vue * point_de_vue);

    QVector<GLfloat> vertices = {
        0.0f,0.0f,0.0f, 1.0f,0.0f,0.0f,   // X
        0.0f,0.0f,0.0f, 0.0f,1.0f,0.0f,   // Y
        0.0f,0.0f,0.0f, 0.0f,0.0f,1.0f    // Z
    };

    QVector<GLfloat> colors = {
        1.0f,0.0f,0.0f, 1.0f,0.0f,0.0f,   // red
        0.0f,1.0f,0.0f, 0.0f,1.0f,0.0f,   // green
        0.0f,0.0f,1.0f, 0.0f,0.0f,1.0f    // blue
    };

    GLuint vbo[2];
    glGenBuffers(2, vbo);

    glBindBuffer(GL_ARRAY_BUFFER, vbo[0]);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(GLfloat), vertices.constData(), GL_STATIC_DRAW);
    prog.enableAttributeArray(SommetId);
    prog.setAttributeArray(SommetId, GL_FLOAT, nullptr, 3);

    glBindBuffer(GL_ARRAY_BUFFER, vbo[1]);
    glBufferData(GL_ARRAY_BUFFER, colors.size() * sizeof(GLfloat), colors.constData(), GL_STATIC_DRAW);
    prog.enableAttributeArray(CouleurId);
    prog.setAttributeArray(CouleurId, GL_FLOAT, nullptr, 3);

    glDrawArrays(GL_LINES, 0, 6);

    prog.disableAttributeArray(SommetId);
    prog.disableAttributeArray(CouleurId);

    glDeleteBuffers(2, vbo);

    prog.release();
}

// ======================================================================
void VueOpenGL::dessineSphere(QMatrix4x4 const& point_de_vue,
                              double r, double g, double b)
{
    prog.bind();
    prog.setUniformValue("vue_modele", matrice_vue * point_de_vue);
    prog.setAttributeValue(CouleurId, r, g, b);
    sphere.draw(prog, SommetId);
    prog.release();
}
