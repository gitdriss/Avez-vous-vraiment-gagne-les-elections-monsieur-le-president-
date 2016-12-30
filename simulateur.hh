#ifndef SIMULATEUR_H
#define SIMULATEUR_H
#include <string>
#include <sstream>
#include <iostream>					
#include <list>
//#include "Method.hh"
#include "candidat.hh"
#include "convictiondevote.hh"
 
class Simulateur
{
	private:
		std::list<Candidat*> listeCandidats_;
		std::list<ConvictiondeVote*> listeConvictiondeVotes_;
		int nbCandidat_;
		int droitInscriptionCandidat_; // 0 inscription auorisé, 1 inscription pus autorisé
		//std::list<Method*> liste_methode;
	public:
		//constructeur
		Simulateur();
		//destructeur
		~Simulateur();
		//methode
		void addCandidat(Candidat*);
		void addConvictiondeVote(ConvictiondeVote* ConvictiondeVote);
		void afficheCandidats();
		void clotureInscriptionCandidats();
		void run();
		int getnbCandidat() const;
		std::list<Candidat*> getListeCandidats() const;
		std::list<ConvictiondeVote*> getlisteConvictiondeVotes() const;
};
#endif
