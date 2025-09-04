Projet Simulation Physique — README (adapté macOS)

Nous rendons l’intégralité des exercices nécessaires du projet et un intégrateur en plus.
Nous avons réalisé une version graphique du projet avec Qt.
Version de Qt utilisée : 5.12.8 / Bibliothèque graphique : Qt / OpenGL

Nous avons passé en moyenne 6 heures par personne et par semaine sur le projet.

Organisation du projet :
- Dossier "head" avec les headers
- Dossier "source" avec les fichiers sources
- Un dossier pour chaque test à compiler (exemple : P1)
- Dossiers "Qt_GL" et "text" contenant respectivement l'exercice P11 graphique et textuel
- D'autres dossiers/fichiers (.pro, "general") pour la compilation

Guide Compilation et Exécution (macOS) :
1. Ouvrir le terminal dans le dossier "code"
1.5 Vérifier que vous utilisez le bon Qt (celui qui contient "openglwidgets").
   - Sur macOS avec Homebrew (Intel) :
     /usr/local/opt/qt/bin/qmake
   - Sur macOS avec Homebrew (Apple Silicon) :
     /opt/homebrew/opt/qt/bin/qmake
   - Vérifier la version utilisée :
     qmake -v
   - Changer la version utilisée si nécessaire :
     (Intel) : export PATH="/usr/local/opt/qt/bin:$PATH"
     (Apple Silicon) : export PATH="/opt/homebrew/opt/qt/bin:$PATH"
2. Compiler :
   qmake
   make clean
   make
3. Chaque test produit une application macOS (.app).
   - Depuis Finder : double-cliquer sur le fichier .app
   - Depuis Terminal : lancer le binaire interne, ex. :
     ./P6/TestRessort.app/Contents/MacOS/TestRessort

Commandes d’exécution (exemples) :
P5 : TestMasse            ./P5/TestMasse.app/Contents/MacOS/TestMasse
P6 : TestRessort          ./P6/TestRessort.app/Contents/MacOS/TestRessort
P7_1 : TestIntegrateur1   ./P7_1/TestIntegrateur1.app/Contents/MacOS/TestIntegrateur1
P7_2 : TestIntegrateur2   ./P7_2/TestIntegrateur2.app/Contents/MacOS/TestIntegrateur2
P7_3 : TestIntegrateur3   ./P7_3/TestIntegrateur3.app/Contents/MacOS/TestIntegrateur3
P8_1 : TestTissuSimple1   ./P8_1/TestTissuSimple1.app/Contents/MacOS/TestTissuSimple1
P8_2 : TestTissuSimple2   ./P8_2/TestTissuSimple2.app/Contents/MacOS/TestTissuSimple2
P9 : exerciceP9           ./P9/exerciceP9.app/Contents/MacOS/exerciceP9
P10 : exerciceP10_text    ./P10/exerciceP10_text.app/Contents/MacOS/exerciceP10_text
P11_text : exerciceP11_text   ./text/exerciceP11_text.app/Contents/MacOS/exerciceP11_text
P11_gl : exerciceP11_gl       ./Qt_GL/exerciceP11_gl.app/Contents/MacOS/exerciceP11_gl
P12 : TissusComposes
   ./TissuChaine/TestTissuChaine_gl.app/Contents/MacOS/TestTissuChaine_gl
   ./TissuDisque/TestTissuDisque_gl.app/Contents/MacOS/TestTissuDisque_gl
   ./TissuRectangle/TestTissuRectangle_gl.app/Contents/MacOS/TestTissuRectangle_gl
   ./TissuCompose/TestTissuCompose_gl.app/Contents/MacOS/TestTissuCompose_gl
P13_1 : TestContrainte1_text  ./P13_1/TestContrainte1_text.app/Contents/MacOS/TestContrainte1_text
P13_2 : TestContrainte2_text  ./P13_2_text/TestContrainte2_text.app/Contents/MacOS/TestContrainte2_text
        TestContrainte2_gl    ./P13_2_gl/TestContrainte2_gl.app/Contents/MacOS/TestContrainte2_gl
P14_Newmark : Newmark         ./P14_Newmark/TestIntegrateurNewmark_text.app/Contents/MacOS/TestIntegrateurNewmark_text
P14_RungeKutta : RungeKutta   ./P14_RungeKutta/TestIntegrateurRungeKutta_text.app/Contents/MacOS/TestIntegrateurRungeKutta_text

Commandes Graphiques :
[Clic gauche + mouvement] : rotation de l’observateur
[W] : zoom in
[S] : zoom out
[Espace] : pause

Mention bug :
Le “t” d’un système peut buguer dans l’affichage (particulièrement dans TestContrainte 1). Nous n’avons pas trouvé l’erreur, ce qui peut expliquer quelques écarts dans certains tests avec contrainte Impulsion_sin.
