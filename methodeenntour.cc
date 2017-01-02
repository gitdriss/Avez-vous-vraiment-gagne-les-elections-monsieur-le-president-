#include "methodeenntour.hh"
//constructeur
MethodeEnNTour::MethodeEnNTour(Simulateur* s):MethodeParTour(s){}
//destructeur
MethodeEnNTour::~MethodeEnNTour(){}

//methode
void MethodeEnNTour::scrutin(){
	std::list<Candidat*> candidatenliste = (s_)->getListeCandidats();
	std::list<Candidat*> candidatencoreliste = (s_)->getListeCandidats();
	int n =1;
	std::string nametmp;
	std::list<Candidat*>::const_iterator it;
	int cpt = candidatenliste.size();
	while(cpt > 1){
		nametmp = elimineCandidat(resutatTour(candidatenliste));
		candidatElimine_[nametmp] = n;
		n++;
		candidatenliste.clear();
		for (it = candidatencoreliste.begin(); it != candidatencoreliste.end(); it++)
		{
			if((*it)->getname() != nametmp ){
				Candidat* c = *it;
				candidatenliste.push_back(c);
			}
		}
		candidatencoreliste = candidatenliste;
		cpt--;
	}
	for (it = candidatenliste.begin(); it != candidatenliste.end(); it++)
	{
		gagnant_=(*it)->getname();
	}
}
void MethodeEnNTour::findwinner(){
	scrutin();
}
void MethodeEnNTour::detailsWin(){
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
