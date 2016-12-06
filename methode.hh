#ifndef METHODE_H
#define METHODE_H
#include <string>
#include <sstream>
#include <iostream>					
#include "simulation.hh"

class Methode
{
	protected:
		std::string gagnant_;
		const simulation *s_;
	public:
		//constructeur
		Methode(simulation* s);
		//destructeur
		~Methode();
		//methode
		virtual void scrutin()const = 0;
};
#endif