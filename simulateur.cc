#include "simulateur.hh"

Simulateur::Simulateur(){nbCandidat_=0;}

Simulateur::~Simulateur(){}


void Simulateur::addCandidat(Candidat* candidat)
{
	nbCandidat_++;
	listeCandidats_.push_back(candidat);
	
}
/*
void simulateur::add_methode(Method methode)
{
		liste_methode.push_back[methode];
	
}*/

void Simulateur::afficheCandidats()
{
	std::cout<<"---------------------------------"<<std::endl;	
	std::list<Candidat*>::iterator it;
	for (it = listeCandidats_.begin(); it != listeCandidats_.end(); it++)
	{
		(*it)->affiche() ;
	}
	std::cout<<"---------------------------------"<<std::endl;	
}

std::list<Candidat*> Simulateur::getListeCandidats() const{
	return listeCandidats_;
}