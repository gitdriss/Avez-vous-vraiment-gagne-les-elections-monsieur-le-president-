#ifndef SIMULATEUR_H
#define SIMULATEUR_H
#include <string>
#include <sstream>
#include <iostream>					
#include <list>
//#include "Method.hh"
#include "candidat.hh"

class Simulateur
{
	private:
		std::list<Candidat*> listeCandidats_;
		int nbCandidat_;
		//std::list<Method*> liste_methode;
	public:
		//constructeur
		Simulateur();
		//destructeur
		~Simulateur();
		//methode
		void addCandidat(Candidat*);
		void afficheCandidats();
		void run();
		std::list<Candidat*> getListeCandidats() const;
};
#endif