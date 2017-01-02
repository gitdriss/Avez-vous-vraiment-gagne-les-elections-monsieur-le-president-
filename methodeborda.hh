#ifndef METHODEB_H
#define METHODEB_H
#include <string>
#include <sstream>
#include <iostream>					
#include "methode.hh"

class MethodeBorda : public Methode
{
	private:
		std::map<std::string,int> nbDePoint_;
	public:
		//constructeur
		MethodeBorda(Simulateur* s);
		//destructeur
		~MethodeBorda();
		//methode
		void scrutin();
		void findwinner();
		void detailsWin();
};
#endif
