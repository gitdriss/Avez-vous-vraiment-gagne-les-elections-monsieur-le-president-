#ifndef METHODE_H
#define METHODE_H
#include <string>
#include <sstream>
#include <iostream>					
#include "simulateur.hh"

class Methode
{
	protected:
		std::string gagnant_;
		const Simulateur *s_;
	public:
		//constructeur
		Methode(Simulateur* s);
		//destructeur
		~Methode();
		//methode
		virtual void scrutin() = 0;
		virtual void findwinner() = 0;
		virtual void detailsWin() = 0;
		void afficheWinner();
};
#endif
