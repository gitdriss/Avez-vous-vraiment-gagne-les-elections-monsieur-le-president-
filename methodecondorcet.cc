#include "methodecondorcet.hh"

MethodeCondorcet::MethodeCondorcet(Simulateur* s):Methode(s){}
MethodeCondorcet::~MethodeCondorcet(){}
void MethodeCondorcet::scrutin(){
	std::list<Candidat*>::const_iterator it;
	std::list<Candidat*>::const_iterator it2;
	for (it = (s_)->getListeCandidats().begin(); it != (s_)->getListeCandidats().end(); it++)
	{
		for (it2 = (s_)->getListeCandidats().begin(); it2 != (s_)->getListeCandidats().end(); it2++)
		{
			if((*it)>(*it2)){
				nbDeVictoire_[(*it)->getname()]++;
			};
		}
	}
	gagnant_=nbDeVictoire_[0];
}