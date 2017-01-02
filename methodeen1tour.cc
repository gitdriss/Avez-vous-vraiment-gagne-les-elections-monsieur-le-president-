#include "methodeen1tour.hh"
//constructeur
MethodeEn1Tour::MethodeEn1Tour(Simulateur* s):MethodeParTour(s){}
//destructeur
MethodeEn1Tour::~MethodeEn1Tour(){}

//methode
void MethodeEn1Tour::scrutin(){
	std::map<std::string,int> resultatvote;
	resultatvote = resutatTour((s_)->getListeCandidats());
	int tmp = 0;
	for(auto& iter : resultatvote)
	{
		if(iter.second>tmp){
			gagnant_=iter.first;
			tmp=iter.second;
		}
	}
	for(auto& iter2 : resultatvote)
	{
		if(iter2.first!=gagnant_){
			candidatElimine_[iter2.first]  =  1;
		}
	}
}
void MethodeEn1Tour::findwinner(){
	scrutin();
}
void MethodeEn1Tour::detailsWin(){
	std::cout<<"Details des resultats"<<std::endl;
	for(auto& iter : candidatElimine_)
	{
		
		if(iter.second==1){
			std::cout<<iter.first<<" a ete éliminé au "<<iter.second<<"er tour"<<std::endl;
		}else{
			std::cout<<iter.first<<" a ete éliminé au "<<iter.second<<"eme tour"<<std::endl;
		}
	}
	std::cout<<"---------------------------------"<<std::endl;
}
