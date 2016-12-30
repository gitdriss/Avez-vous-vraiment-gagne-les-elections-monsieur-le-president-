 #include "convictiondevote.hh"
 
ConvictiondeVote::ConvictiondeVote(std::map<std::string,int> OrdrePreferenceCandidats, int nbelecteur){
	OrdrePreferenceCandidats_ = OrdrePreferenceCandidats;
	nbelecteur_ = nbelecteur;
}

ConvictiondeVote::ConvictiondeVote(std::list<Candidat*> listeCandidats, std::string s){
	std::vector<std::string> s2;
	//separation des args
	s2 = split( s,";" );
	//convertion en int
	std::string c = s2[0];
	int d = atoi(c.c_str());
	
	nbelecteur_ = d;
	int i = 1;
	std::list<Candidat*>::const_iterator it;
	for (it = listeCandidats.begin(); it != listeCandidats.end(); it++)
	{
		//convertion en int
		std::string a = s2[i];
		int b = atoi(a.c_str());
		
		OrdrePreferenceCandidats_[(*it)->getname()]=b;
		i++;
	}
}

ConvictiondeVote::~ConvictiondeVote(){}

std::map<std::string,int> ConvictiondeVote::getOrdrePreferenceCandidats(){return OrdrePreferenceCandidats_;}
int ConvictiondeVote::getNbelecteur(){return nbelecteur_;}
