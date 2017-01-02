#include <iostream>
#include "candidat.hh"
#include "simulateur.hh"
#include "methodecondorcet.hh"
#include "methodeborda.hh"
#include <fstream>
int main()
{
std::cout<<"---------------------------------"<<std::endl;
// creation de la simulation

  Simulateur s1;

  std::ifstream file("election.txt");
  std::string s;
  file >> s;
  std::vector<std::string> s2;
  //separation des args
  s2 = split( s,";" );
  
  std::list<ConvictiondeVote> listeConvictiondeVotes;
  std::list<Candidat> listeCandidats;
  
  for(const auto& iter : s2)
     {
       std::vector<std::string> s3;
       s3 = split( iter,"," );
       listeCandidats.push_back(Candidat(s3[0],s3[1]));
     }
     
      for( auto& iter2 : listeCandidats)
     {
       s1.addCandidat(&iter2);
     }

   s1.clotureInscriptionCandidats();   
	
  while( file >> s)
    {
      listeConvictiondeVotes.push_back(ConvictiondeVote(s1.getListeCandidats(),s));
    }
  file.close();
  int cpt =0;
  for( auto& iter3 : listeConvictiondeVotes)
     {
       if(cpt==0)
         iter3.afficheConvictiondeVoteenTete();
       s1.addConvictiondeVote(&iter3);
       iter3.afficheConvictiondeVote();
       cpt++;
     }

// appel des differentes methodes de vote
std::cout<<"---------------------------------"<<std::endl;
std::cout<<"---------------------------------"<<std::endl;
std::cout<<"Methode de Nicolas de Condorcet"<<std::endl;
  MethodeCondorcet mc(&s1);
  mc.findwinner();
  mc.afficheWinner();
  mc.detailsWin();
std::cout<<"---------------------------------"<<std::endl;
std::cout<<"Methode de Jean Charles de Borda"<<std::endl;
  MethodeBorda mb(&s1);
  mb.findwinner();
  mb.afficheWinner();
  mb.detailsWin();
  return 0;
}
