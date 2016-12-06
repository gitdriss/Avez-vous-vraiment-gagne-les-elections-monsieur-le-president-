#include "methodecondorcet"

MethodeCondorcet::MethodeCondorcet(simulation* s):methode(&s){}
MethodeCondorcet::~MethodeCondorcet(){}
void MethodeCondorcet::scrutin()const{
	std::list<Candidat*>::iterator it;
	std::list<Candidat*>::iterator it2;
	for (it = *(s_)->listeCandidats_.begin(); it != *(s_)->listeCandidats_.end(); it++)
	{
		for (it2 = *(s_)->listeCandidats_.begin(); it2 != *(s_)->listeCandidats_.end(); it2++)
		{
			if((*it)>(*it2)){
				nbDeVictoire_[(*it).getname()]++;
			};
		}
	}
}