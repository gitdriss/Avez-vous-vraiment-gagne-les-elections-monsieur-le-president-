#ifndef METHODEEN1TOUR_H
#define METHODEEN1TOUR_H
#include <string>
#include <sstream>
#include <iostream>					
#include "methodepartour.hh"

class MethodeEn1Tour : public  MethodeParTour
{
	protected:
		
	public:
		//constructeur
		MethodeEn1Tour(Simulateur* s);
		//destructeur
		~MethodeEn1Tour();
		//methode
		void scrutin();
		void findwinner();
		void detailsWin();
};
#endif
