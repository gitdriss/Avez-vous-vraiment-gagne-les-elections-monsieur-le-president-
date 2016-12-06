#ifndef CANDIDAT_H
#define CANDIDAT_H
#include <iostream>
#include <vector>
#include <string>
#include <map>

class Candidat
{
	public:
		//Constructeur
		Candidat(std::string nom,std::string prenom);
		//Destucteur
		~Candidat();
		//Methode
		void affiche(); //affiche les caracteristique d un candidat
		void ajouteDeVote(int rang, int nbDeVote); //pour affecter le scorre d un candidat
		//Operateur
		//comparaison des votes

	private:
		//Attributs
		const std::string nom_;
		const std::string prenom_;
		std::map<int,int> repartitionVote_; //vote[i] indique le nombre de personne qui a choisi le candidat en ieme position
};

#endif