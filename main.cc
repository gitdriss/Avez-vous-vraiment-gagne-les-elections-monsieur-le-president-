#include <iostream>
#include "candidat.hh"

int main()
{
  Candidat c1("ALOUI","Driss");
  c1.affiche();
  c1.ajouteDeVote(1, 11);
  c1.ajouteDeVote(2, 200);
  c1.affiche();
}
