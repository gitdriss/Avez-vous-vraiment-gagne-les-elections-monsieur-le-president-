#include "methodefrancaise.hh"
//constructeur
MethodeFrancaise::MethodeFrancaise(Simulateur* s):MethodeParTour(s){}
//destructeur
MethodeFrancaise::~MethodeFrancaise(){}

//methode
void MethodeFrancaise::scrutin(){
	std::list<Candidat*> candidatenliste = (s_)->getListeCandidats();
	std::list<Candidat*> candidatenliste2emetour;
	std::list<Candidat*>::const_iterator it;
	//1er tour
	int tmp1;
	std::string nametmp1;
	int tmp2;
	std::string nametmp2;
	std::map<std::string,int> resultatvote = resutatTour(candidatenliste);
	std::map<std::string,int> resultatvote2 = resutatTour(candidatenliste);
	//1er selectionné
	for(auto& iter : resultatvote){tmp1 = iter.second;nametmp1=iter.first;}
	for(auto& iter2 : resultatvote)
	{
		if(iter2.second>tmp1){
			nametmp1=iter2.first;
			tmp1=iter2.second;
		}
	}
	resultatvote.clear();
	for(auto& iter3 : resultatvote2)
	{
		if(iter3.first != nametmp1){
			resultatvote[iter3.first]=iter3.second;
		}
	}
	//2eme selectionné
	for(auto& iter4 : resultatvote){tmp2 = iter4.second;nametmp2=iter4.first;}
	for(auto& iter5 : resultatvote)
	{
		if(iter5.second>tmp2){
			nametmp2=iter5.first;
			tmp2=iter5.second;
		}
	}
	//2emetour
	for (it = candidatenliste.begin(); it != candidatenliste.end(); it++)
	{
		if((*it)->getname() == nametmp1 || (*it)->getname() == nametmp2 ){
			Candidat* c = *it;
			candidatenliste2emetour.push_back(c);
		}else{
			candidatElimine_[(*it)->getname()] = 1;
		}
	}
	std::map<std::string,int> resultatvote2emetour = resutatTour(candidatenliste2emetour);
	for(auto& iter6 : resultatvote2emetour){tmp1 = iter6.second;nametmp1=iter6.first;}
	for(auto& iter7 : resultatvote2emetour)
	{
		if(iter7.second>tmp1){
			nametmp1=iter7.first;
			tmp1=iter7.second;
		}
	}
	gagnant_=nametmp1;
	for(auto& iter8 : resultatvote2emetour)
	{
		if(iter8.first!=gagnant_){
			candidatElimine_[iter8.first] = 2;
		}
	}
}
void MethodeFrancaise::findwinner(){
	scrutin();
}
void MethodeFrancaise::detailsWin(){
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
