#pragma once

class Masse;
class Tissu;
class Systeme;
class Ressort;

class SupportADessin {

	private :

	public :
	
	virtual ~SupportADessin() = default;
	
	virtual void dessine(Tissu const&) = 0;
	virtual void dessine(Systeme const&) = 0;
	virtual void dessine(Masse const&) = 0;
	virtual void dessine(Ressort const&) =0;
};
