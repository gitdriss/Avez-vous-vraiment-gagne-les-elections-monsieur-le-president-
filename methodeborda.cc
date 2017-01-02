#include "methodeborda.hh"

MethodeBorda::MethodeBorda(Simulateur* s):Methode(s){}
MethodeBorda::~MethodeBorda(){}
void MethodeBorda::scrutin(){
	std::list<ConvictiondeVote*>::const_iterator it3;
	std::map<std::string,int>::const_iterator it4;
	std::list<ConvictiondeVote*> listeCc = (s_)->getlisteConvictiondeVotes();
	
	
	for(it3 = listeCc.begin(); it3 != listeCc.end(); it3++){
		std::map<std::string,int> OrdrePreferenceCandidats = (*it3)->getOrdrePreferenceCandidats();
		for(it4 = OrdrePreferenceCandidats.begin(); it4 != OrdrePreferenceCandidats.end(); it4++){	
			nbDePoint_[it4->first]+=(1+(s_)->getnbCandidat()-it4->second)*(*it3)->getNbelecteur();
		}	
	}
}

void MethodeBorda::findwinner(){
	scrutin();
	int tmp = nbDePoint_.begin()->second;
	gagnant_=nbDePoint_.begin()->first;
	for(const auto& iter : nbDePoint_)
	{
		if(iter.second>tmp){
			gagnant_=iter.first;
			tmp=iter.second;
		}
	}
}

void MethodeBorda::detailsWin(){
	std::cout<<"Details des resultats"<<std::endl;
	for(const auto& iter : nbDePoint_)
	{
		std::cout<<iter.second<<" pts\t"<<iter.first<<std::endl;
	}
	std::cout<<"---------------------------------"<<std::endl;
}
