#pragma once
#include "SupportADessin.h"
#include "Tissu.h"
#include "Systeme.h"

class TextViewer : public SupportADessin {
	
	private :
	
		std::ostream& flot;
	
	public :

		//constructeurs
			TextViewer (std::ostream& flot)
				:flot(flot)
			{}
			virtual ~TextViewer() = default;
			// on ne copie pas les TextViewer
			TextViewer(TextViewer const&)            = delete; 
			TextViewer& operator=(TextViewer const&) = delete;
			// mais on peut les déplacer
			TextViewer(TextViewer&&)            = default; 
			TextViewer& operator=(TextViewer&&) = default;
		 
		 //methodes publiques: Toutes des methodes heritees de supportADessin.
		 
			virtual void dessine(Tissu const& a_dessiner)  override;
			virtual void dessine(Systeme const& a_dessiner)  override; 
			virtual void dessine(Masse const& a_dessiner)  override;
			virtual void dessine(Ressort const& a_dessiner) override;
};
