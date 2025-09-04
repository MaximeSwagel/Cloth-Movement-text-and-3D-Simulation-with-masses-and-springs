#pragma once

class Integrateur;
class SupportADessin;

class Dessinable {
	
	public :

		virtual void dessine_sur(SupportADessin&) = 0;
		
		virtual ~Dessinable(){}
		
		virtual void evolue( Integrateur& I, double dt) = 0;

};
