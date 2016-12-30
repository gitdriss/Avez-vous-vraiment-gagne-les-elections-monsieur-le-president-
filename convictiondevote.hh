#ifndef CONVICT_H
#define CONVICT_H
#include <string>
#include <sstream>
#include <iostream>					
#include "utility.hh"
#include <map>
#include <list>
#include "candidat.hh"

class ConvictiondeVote
{
	private:
		//attributs
		std::map<std::string,int> OrdrePreferenceCandidats_;
		int nbelecteur_;
		
		 // exemple si on a : OrdrePreferenceCandidats_[CANDITAT]=1;OrdrePreferenceCandidats_[CANDITAT2]=2; 
		 // cela  signifie qui il y a nbelecteur_ électeurs qui classe CANDIDAT1 en 1er choix de vote
		 // et CANDIDAT2 en 2eme
	public:
		//constructeur
		ConvictiondeVote(std::list<Candidat*> listeCandidats, std::string s);
		ConvictiondeVote(std::map<std::string,int> OrdrePreferenceCandidats, int nbelecteur);
		//destructeur
		~ConvictiondeVote();
		//methode
		std::map<std::string,int> getOrdrePreferenceCandidats();
		int getNbelecteur();
};

#endif
