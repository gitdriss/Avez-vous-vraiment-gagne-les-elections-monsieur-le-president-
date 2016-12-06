 #include "candidat.hh"
Candidat::Candidat(std::string nom,std::string prenom):nom_(nom),prenom_(prenom){
	
}
Candidat::~Candidat(){}
void Candidat::affiche(){//affiche les caracteristique d un candidat
	std::cout<<"---------------------------------"<<std::endl;
	std::cout<< prenom_<<"\t"<< nom_<<std::endl;
	std::map<int,int>::iterator it;
	for(it=repartitionVote_.begin();it!=repartitionVote_.end();it++) {
		std::cout<< it->second<<" votant de rang "<< it->first <<std::endl;
	}
	std::cout<<"---------------------------------"<<std::endl;	
}
void Candidat::ajouteDeVote(int rang, int nbDeVote){ //pour affecter le scorre d un candidat
	repartitionVote_[rang]=nbDeVote;
}