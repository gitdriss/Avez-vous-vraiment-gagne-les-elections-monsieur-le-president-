#include "simulateur.hh"

Simulateur::Simulateur(){nbCandidat_=0;droitInscriptionCandidat_=0;}

Simulateur::~Simulateur(){}


void Simulateur::addCandidat(Candidat* candidat)
{
	if(droitInscriptionCandidat_==0){
		nbCandidat_++;
		listeCandidats_.push_back(candidat);
	}else{
		std::cout<<"la cloture des inscriptions est dépassée!"<<std::endl;
	}
	
}

void Simulateur::addConvictiondeVote(ConvictiondeVote* ConvictiondeVote)
{
	if(droitInscriptionCandidat_==1){
		listeConvictiondeVotes_.push_back(ConvictiondeVote);
	}else{
		std::cout<<"la cloture des inscriptions n'est pas dépassée encore!"<<std::endl;
	}
	
}

/*
void simulateur::add_methode(Method methode)
{
		liste_methode.push_back[methode];
	
}*/

void Simulateur::afficheCandidats()
{
	std::cout<<"---------------------------------"<<std::endl;
	std::cout<<"Les candidats en liste sont :"<<std::endl<<std::endl;	
	std::list<Candidat*>::iterator it;
	for (it = listeCandidats_.begin(); it != listeCandidats_.end(); it++)
	{
		(*it)->affiche() ;
	}
	std::cout<<"---------------------------------"<<std::endl;	
}

void Simulateur::clotureInscriptionCandidats(){
	droitInscriptionCandidat_=1;
	std::cout<<"les inscriptions sont maintenant terminées !"<<std::endl;
	afficheCandidats();
}

std::list<Candidat*> Simulateur::getListeCandidats() const{
	return listeCandidats_;
}

std::list<ConvictiondeVote*> Simulateur::getlisteConvictiondeVotes() const{
	return listeConvictiondeVotes_;
}

int Simulateur::getnbCandidat() const{
	return nbCandidat_;
}
