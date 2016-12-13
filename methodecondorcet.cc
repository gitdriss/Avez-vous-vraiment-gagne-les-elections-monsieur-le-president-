#include "methodecondorcet.hh"

MethodeCondorcet::MethodeCondorcet(Simulateur* s):Methode(s){}
MethodeCondorcet::~MethodeCondorcet(){}
void MethodeCondorcet::scrutin(){
	std::list<Candidat*>::const_iterator it;
	std::list<Candidat*>::const_iterator it2;
	std::list<Candidat*> listeC = (s_)->getListeCandidats();
	for (it = listeC.begin(); it != listeC.end(); it++)
	{
		for (it2 = listeC.begin(); it2 != listeC.end(); it2++)
		{
			if((*it)>(*it2)){
				nbDeVictoire_[(*it)->getname()]++;
			}
		}
	}
	gagnant_=nbDeVictoire_.begin()->first;
}

void MethodeCondorcet::findwinner(){
	scrutin();
	gagnant_ = nbDeVictoire_.begin()->first;
}