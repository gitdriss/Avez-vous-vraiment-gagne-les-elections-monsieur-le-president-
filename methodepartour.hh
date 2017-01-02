#ifndef METHODEPARTOUR_H
#define METHODEPARTOUR_H
#include <string>
#include <sstream>
#include <iostream>					
#include "methode.hh"

class MethodeParTour : public Methode
{
	protected:
		std::map<std::string,int> candidatElimine_;
	public:
		//constructeur
		MethodeParTour(Simulateur* s);
		//destructeur
		~MethodeParTour();
		//methode
		virtual void scrutin() = 0;
		virtual void findwinner() = 0;
		virtual void detailsWin() = 0;
		std::map<std::string,int> resutatTour(std::list<Candidat*>);//list vote resutatTour(list candidat);
		std::string elimineCandidat(std::map<std::string,int> resultatvote);
};
#endif
