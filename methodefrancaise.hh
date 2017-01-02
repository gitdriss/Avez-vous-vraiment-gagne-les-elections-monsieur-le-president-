#ifndef METHODEFR_H
#define METHODEFR_H
#include <string>
#include <sstream>
#include <iostream>					
#include "methodepartour.hh"

class MethodeFrancaise : public MethodeParTour
{
	protected:
		
	public:
		//constructeur
		MethodeFrancaise(Simulateur* s);
		//destructeur
		~MethodeFrancaise();
		//methode
		void scrutin();
		void findwinner();
		void detailsWin();
};
#endif
