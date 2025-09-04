#pragma once

#include <QOpenGLShaderProgram>
#include <QMatrix4x4>
#include "SupportADessin.h"
#include "glsphere.h"
#include "Ressort.h"

class VueOpenGL : public SupportADessin {
 public:
  virtual void dessine(Systeme const& a_dessiner) override;
  virtual void dessine(Tissu const& a_dessiner) override;
  virtual void dessine(Masse const& a_dessiner) override;
  virtual void dessine(Ressort const& a_dessiner) override;
  
  void init();
  void initializePosition();

  void setProjection(QMatrix4x4 const& projection) {
    prog.bind();
    prog.setUniformValue("projection", projection);
    prog.release();
  }

  void translate(double x, double y, double z);
  void rotate(double angle, double dir_x, double dir_y, double dir_z);
  
  void dessineAxes(QMatrix4x4 const& point_de_vue, bool en_couleur = true);
  void dessineCube(QMatrix4x4 const& point_de_vue = QMatrix4x4());
  void dessineSphere(QMatrix4x4 const& point_de_vue,
                     double rouge = 1.0, double vert = 1.0, double bleu = 1.0);
  void dessineLigne(QMatrix4x4 const& point_de_vue, Vecteur3D debut, Vecteur3D fin);

 private:
  QOpenGLShaderProgram prog;
  GLSphere sphere;
  QMatrix4x4 matrice_vue;
};
