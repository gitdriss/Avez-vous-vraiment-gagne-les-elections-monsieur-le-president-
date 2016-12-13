#include "methode.hh"

Methode::Methode(Simulateur* s):s_(s){}
Methode::~Methode(){}
void Methode::afficheWinner(){
	std::cout<<"---------------------------------"<<std::endl;	
	std::cout<<"Le vainqueur est "<<gagnant_<<std::endl;
	std::cout<<"---------------------------------"<<std::endl;	
}