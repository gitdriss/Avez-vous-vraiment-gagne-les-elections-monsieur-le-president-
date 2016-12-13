#include <iostream>
#include "candidat.hh"
#include "simulateur.hh"
#include "methodecondorcet.hh"
int main()
{
  Candidat c1("ALOUI","Driss");
  Candidat c2("ALDEBERT","Louis");
  Candidat c3("CHASSETUILLIER","Jules");
  Candidat c4("LELAPIN","Jojo");
  Simulateur s1;
  c1.ajouteDeVote(1, 50);
  c1.ajouteDeVote(2, 20);
  c1.ajouteDeVote(3, 20);
  c1.ajouteDeVote(4, 20);
  c2.ajouteDeVote(1, 52);
  c2.ajouteDeVote(2, 20);
  c2.ajouteDeVote(3, 30);
  c2.ajouteDeVote(4, 10);
  c3.ajouteDeVote(1, 500);
  c3.ajouteDeVote(2, 60);
  c3.ajouteDeVote(3, 20);
  c3.ajouteDeVote(4, 24);
  c4.ajouteDeVote(1, 58);
  c4.ajouteDeVote(2, 8);
  c4.ajouteDeVote(3, 2);
  c4.ajouteDeVote(4, 21);
  s1.addCandidat(&c1);
  s1.addCandidat(&c2);
  s1.addCandidat(&c3);
  s1.addCandidat(&c4);
  s1.afficheCandidats();
  c2.afficheDetail();

  MethodeCondorcet mc(&s1);
  mc.findwinner();
  mc.afficheWinner();
  return 0;
}
