#ifndef METHODEENNTOUR_H
#define METHODEENNTOUR_H
#include <string>
#include <sstream>
#include <iostream>					
#include "methodepartour.hh"

class MethodeEnNTour : public MethodeParTour
{
	protected:
		
	public:
		//constructeur
		MethodeEnNTour(Simulateur* s);
		//destructeur
		~MethodeEnNTour();
		//methode
		void scrutin();
		void findwinner();
		void detailsWin();
};
#endif
