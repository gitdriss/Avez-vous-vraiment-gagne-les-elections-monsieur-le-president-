#include "methodepartour.hh"

MethodeParTour::MethodeParTour(Simulateur* s):Methode(s){}
MethodeParTour::~MethodeParTour(){}

std::map<std::string,int> MethodeParTour::resutatTour(std::list<Candidat*> candidatenliste){
	std::map<std::string,int> resultatvote;
	std::list<ConvictiondeVote*>::const_iterator it3;
	std::list<ConvictiondeVote*> listeCc = (s_)->getlisteConvictiondeVotes();
	std::list<Candidat*>::const_iterator it;
	
	int tmp;
	std::string nametmp;
	for (it = candidatenliste.begin(); it != candidatenliste.end(); it++)
	{
		resultatvote[(*it)->getname()]=0;		
	}
	for(it3 = listeCc.begin(); it3 != listeCc.end(); it3++){
		tmp = (s_)->getnbCandidat();
		nametmp ="";
		for (it = candidatenliste.begin(); it != candidatenliste.end(); it++)
		{
			if((*it3)->getOrdrePreferenceCandidats()[(*it)->getname()] < tmp){
				nametmp=(*it)->getname();
				tmp=(*it3)->getOrdrePreferenceCandidats()[(*it)->getname()];
			}			
		}
		
		resultatvote[nametmp]+=(*it3)->getNbelecteur();
	}
	return resultatvote;
}

std::string MethodeParTour::elimineCandidat(std::map<std::string,int> resultatvote){
	int tmp;
	std::string nametmp;
	for(auto& iter : resultatvote){tmp = iter.second;nametmp=iter.first;}
	for(auto& iter2 : resultatvote)
	{
		if(iter2.second>tmp){
			nametmp=iter2.first;
			tmp=iter2.second;
		}
	}
	return nametmp;
}
