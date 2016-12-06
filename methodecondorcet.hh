#ifndef METHODEC_H
#define METHODEC_H
#include <string>
#include <sstream>
#include <iostream>					
#include "methode.hh"

class MethodeCondorcet : public Methode
{
	private:
		std::map<std::string,int> nbDeVictoire_;
	public:
		//constructeur
		MethodeCondorcet(simulation* s);
		//destructeur
		~MethodeCondorcet();
		//methode
		void scrutin()const;
};
#endif