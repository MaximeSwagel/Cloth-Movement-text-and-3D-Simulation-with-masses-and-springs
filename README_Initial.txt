Nous rendons l'intégralité des exercices nécessaires du projet et un intégrateur en plus.

Nous avons réalisé une version graphique du projet avec Qt.
Version de Qt utilisée : 5.12.8 / Bibliothèque graphique : Qt / OpenGl

Nous avons passé en moyenne 6 heures par personne et par semaine sur le projet.

Organisation du projet :
 
Dans notre dossier "code" se trouvent :

- Un dossier "head" avec les headers
- Un dossier "source" avec les fichers sources
- Un dossier pour chaque test à compiler ( exemple : P1 )
- Deux dossiers, "Qt_GL" et "text", calqués sur le modèle du tutoriel qui contiennent respectivement l'exercice P11 graphique et textuel
- D'autres dossiers/fichiers servant la simplification de la compilation du projet (dossier "general", fichiers .pro)

Guide Compilation :

- Ouvrir le terminal dans le dossier "code"
- Taper "qmake" puis "make"
- Taper une de ces lignes pour ouvrir le test associé :

[ Note1: Avant la P10 Tout test est un test textuel par défaut. (Nous n’avions pas encore les classes SupportAdessin, TextViewer et Qt-GL). Après l’exercie P10, les tests textuels sont dénotés par le suffixe “_text” et les test Qt-GL par le suffixe “_gl”]

[ Note2 : TestIntegrateur3, TestTissuSimple2 et exerciceP9 sont les mêmes situations mais sous différentes formes (masses ; tissus ; systemes) ]

[ Note3 : exerciceP10_text et exerciceP11_text sont les mêmes mais nous avons décidé de rendre les tests tels qu’ils sont demandés dans les exercices. ]

[ Note4 : L’exercice P12 n’ayant pas explicitement demandé des tests pour les  Tissus Complexes, nous proposons 4 tests (un par sous classe), d’où les 4 commandes. ]

Exercice : Test			//===============// 	Commande
P1 : TestVecteur3D 		//===============// 	./P1/TestVecteur3D
P5 : TestMasse       		//===============// 	./P5/TestMasse
P6 : TestRessort     		//===============// 	./P6/TestRessort
P7_1 : TestIntegrateur1  	//===============// 	./P7_1/TestIntegrateur1
P7_2 : TestIntegrateur2		//===============// 	./P7_2/TestIntegrateur2
P7_3 : TestIntegrateur3		//===============//	./P7_3/TestIntegrateur3
P8_1 : TestTissuSimple1 	//===============//	./P8_1/TestTissuSimple1
P8_2 : TestTissuSimple2 	//===============// 	./P8_2/TestTissuSimple2
P9 : exerciceP9 		//===============// 	./P9/exerciceP9
P10 : exerciceP10_text		//===============// 	./P10/exerciceP10_text
P11_text : exerciceP11_text	//===============// 	./text/exerciceP11_text
P11_gl : exerciceP11_gl		//===============// 	./Qt_GL/exerciceP11_gl
P12 : TissusComposes 		//===============//     ./TissuChaine/TestTissuChaine_gl
							./TissuDisque/TestTissuDisque_gl
							./TissuRectangle/TestTissuRectangle_gl
							./TissuCompose/TestTissuCompose_gl
P13_1 : TestContrainte_1	//===============//	./P13_1/TestContrainte1_text
P13_2 : TestContrainte_2	//===============//     ./P13_2_text/TestContrainte2_text
							./P13_2_gl/TestContrainte2_gl
P14_Newmark :Newmark    	//==========//    ./P14_Newmark/TestIntegrateurNewmark_text
P14_RungeKutta :RungeKutta 	//=====//  ./P14_RungeKutta/TestIntegrateurRungeKutta_text


Commandes Graphiques Principales :

[Clic Gauche + mouvement de la souris] : rotation de l'observateur
[W] : zoom in
[S] : zoom out
[espace] : pause

Mention bug : On a remarqué que le “t” d’un systeme peut buguer dans l’affichage (particulièrement dans TestContrainte 1). Nous n’avons pas réussi à trouver l’erreur. Cela pourrait expliquer quelques écarts dans les valeurs de nos tests lorsque nous utilisons une contrainte Impulsion_sin.



