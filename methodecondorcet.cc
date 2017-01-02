#include "methodecondorcet.hh"

MethodeCondorcet::MethodeCondorcet(Simulateur* s):Methode(s){}
MethodeCondorcet::~MethodeCondorcet(){}
void MethodeCondorcet::scrutin(){
	std::list<Candidat*>::const_iterator it;
	std::list<Candidat*>::const_iterator it2;
	std::list<ConvictiondeVote*>::const_iterator it3;
	std::list<Candidat*> listeC = (s_)->getListeCandidats();
	std::list<ConvictiondeVote*> listeCc = (s_)->getlisteConvictiondeVotes();
	
	int s1;
	int s2;
	for (it = listeC.begin(); it != listeC.end(); it++)
	{
		for (it2 = listeC.begin(); it2 != listeC.end(); it2++)
		{
			s1=0;
			s2=0;
			for(it3 = listeCc.begin(); it3 != listeCc.end(); it3++){
				if((*it3)->getOrdrePreferenceCandidats()[(*it)->getname()] < (*it3)->getOrdrePreferenceCandidats()[(*it2)->getname()]){
					s1+=(*it3)->getNbelecteur();
				}else{
					s2+=(*it3)->getNbelecteur();
				}
			}
			if(s1>s2){
				nbDeVictoire_[(*it)->getname()]++;
			}
		}
	}
}

void MethodeCondorcet::findwinner(){
	scrutin();
	int tmp = nbDeVictoire_.begin()->second;
	gagnant_=nbDeVictoire_.begin()->first;
	for(const auto& iter : nbDeVictoire_)
	{
		if(iter.second>tmp){
			gagnant_=iter.first;
			tmp=iter.second;
		}
	}
}

void MethodeCondorcet::detailsWin(){
	std::cout<<"Details des resultats"<<std::endl;
	for(const auto& iter : nbDeVictoire_)
	{
		std::cout<<iter.second<<" victoire(s)\t"<<iter.first<<std::endl;
	}
	std::cout<<"---------------------------------"<<std::endl;
}
