#include "methodeborda.hh"

MethodeBorda::MethodeBorda(Simulateur* s):Methode(s){}
MethodeBorda::~MethodeBorda(){}
void MethodeBorda::scrutin(){
	std::list<Candidat*>::const_iterator it;
	std::list<Candidat*> listeC = (s_)->getListeCandidats();
	std::map<int,int>::iterator it2;
	for (it = listeC.begin(); it != listeC.end(); it++)
	{
		for(it2=(*it)->getrepartitionVote().begin();it2!=(*it)->getrepartitionVote().end();it2++) {
			this->nbDePoint_[(*it)->getname()]=(listeC.size() + 1 - it2->first )*it2->second;
		}
		
	}
	gagnant_=nbDePoint_.begin()->first;
}

void MethodeBorda::findwinner(){
	scrutin();
	gagnant_ = nbDePoint_.begin()->first;
}