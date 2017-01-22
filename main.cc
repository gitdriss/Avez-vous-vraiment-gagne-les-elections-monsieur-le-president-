/*
N7-IOB LANGAGE OBJET C++-UML
Projet élection piege à con
BRAUNSTEIN BREJON
*/


/*
Avez vous vraiment gagné les élections monsieur le president?
*/


/*
Date: 22/01/2017
 
ALDEBERT Louis
ALOUI Driss 

MAIN 4 Polytech Paris UPMC
*/


/*
Liste des fichiers
candidat.cc          methodeborda.cc      methodeenntour.cc    ProjetC++.xmi
candidat.hh          methodeborda.hh      methodeenntour.hh    README.md
convictiondevote.cc  methode.cc           methodefrancaise.cc  simulateur.cc
convictiondevote.hh  methodecondorcet.cc  methodefrancaise.hh  simulateur.hh
election.txt         methodecondorcet.hh  methode.hh           utility.cc
main.cc              methodeen1tour.cc    methodepartour.cc    utility.hh
Makefile             methodeen1tour.hh    methodepartour.hh
*/


/*
Utilisation
Make
./IloveC++
*/

/*
Aucune bibliothèque particulière n'est utilisé par ce programme en dehors des bibliothèques standards.
*/

	
#include <iostream>
#include "candidat.hh"
#include "simulateur.hh"
#include "methodecondorcet.hh"
#include "methodeborda.hh"
#include "methodeen1tour.hh"
#include "methodeenntour.hh"
#include "methodefrancaise.hh"
#include <fstream>
#include <stdio.h>
#include <unistd.h>




//SOUS MENU SIMULATION
void f(){
//debut simulation
	system("clear");
	std::cout<<"Lecture de l'échantillon de test 'election.txt' en cours"<<std::endl;
	std::cout<<"0 / 3"<<std::endl;
	sleep(1);
	system("clear");
	std::cout<<"Lecture de l'échantillon de test 'election.txt' en cours"<<std::endl;
	std::cout<<"1 / 3"<<std::endl;
	sleep(1);
	system("clear");
	std::cout<<"Lecture de l'échantillon de test 'election.txt' en cours"<<std::endl;
	std::cout<<"2 / 3"<<std::endl;
	sleep(1);
	system("clear");
	std::cout<<"Lecture de l'échantillon de test 'election.txt' en cours"<<std::endl;
	std::cout<<"3 / 3"<<std::endl;
 	sleep(1);
	int x;
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
		s1.addConvictiondeVote(&iter3);
		cpt++;
	}
	system("clear");
	std::cout<<"Simulation en cours"<<std::endl;
	std::cout<<"3"<<std::endl;
	sleep(1);
	system("clear");
	std::cout<<"Simulation en cours"<<std::endl;
	std::cout<<"2"<<std::endl;
	sleep(1);
	system("clear");
	std::cout<<"Simulation en cours"<<std::endl;
	std::cout<<"1"<<std::endl;
 	sleep(1);
	system("clear");
	std::cout<<"Simulation en cours"<<std::endl;
	std::cout<<"0"<<std::endl;
	sleep(1);
	system("clear");
	//le sous menu
	int Simu = 0;
	int Erreur = 0;
	while(Simu == 0){
		system("clear");
		std::cout<<"Résultat de la simulation"<<std::endl;
		s1.afficheCandidats();
		std::cout<<"0\tRevenir au menu principal"<<std::endl;
		std::cout<<"1\tHelp"<<std::endl;
		std::cout<<"2\tMéthode simple en un tour"<<std::endl;
		std::cout<<"3\tMéthode en deux tours (système électoral Français)"<<std::endl;
		std::cout<<"4\tMéthode en n tours"<<std::endl;
		std::cout<<"5\tMéthode de Jean-Charles de Borda"<<std::endl;
		std::cout<<"6\tMéthode de Nicolas de Condorcet"<<std::endl;
		std::cout<<"7\tRésultat Général"<<std::endl;
		std::cout<<"8\tAfficher la répartition des votes"<<std::endl;
		if(Erreur == 1){
			std::cout<<"[Erreur] Entrée non valide !"<<std::endl;
			Erreur  =  0;
		}
		std::cout<<"Appuyer sur une touche entre 0 et 8  puis valider avec la touche ENTREE"<<std::endl;
		std::cin>>x;
		switch ( x ){
			case 0: 
				system("clear");
				std::cout<<"Vous avez choisi de quitter la simulation, vous allez etre rediriger vers le menu principal."<<std::endl;
				std::cout<<"Etes vous sur?"<<std::endl;
				std::cout<<"Appuyer sur 1 pour revenir à la simulaion sinon un autre CHIFFRE pour quitter puis valider avec la touche ENTREE"<<std::endl;
				std::cin>>x;
				if(x!=1){
	 				Simu = 1;
 				}
            			break; 
			case 1:  
				system("clear");
 				std::cout<<"1\tHelp"<<std::endl;
 				std::cout<<"Merci d'utiliser exclusivement les CHIFFRES pour les selections dans les menus"<<std::endl;
 				std::cout<<""<<std::endl;
 				std::cout<<""<<std::endl;
 				std::cout<<"Le but du programme est de déterminer le vainqueur d'une élection à partir du résultat de vote suivant différentes méthodes."<<std::endl;
 				std::cout<<""<<std::endl;
 				std::cout<<"Utilisation :"<<std::endl;
 				std::cout<<"- Lancer une simulation à partir du menu principal"<<std::endl;
 				std::cout<<"- Naviguer dans les sous menu pour voir le résultat et le détail de la simulation"<<std::endl;
 				std::cout<<""<<std::endl;
 				std::cout<<"Toutes les données sont extraites du fichier 'election.txt'. Elles peuvent être modifiées dans le fichier en respectant des règles d'écriture définies dans le rapport"<<std::endl;
 				std::cout<<""<<std::endl;
 				std::cout<<""<<std::endl;
				std::cout<<"Description des méthodes"<<std::endl;
				std::cout<<""<<std::endl;
				std::cout<<"Les Méthodes par tour"<<std::endl;
				std::cout<<"- Méthode simple en un tour"<<std::endl;
				std::cout<<"C'est certainement le système électoral le plus basique. En effet c'est le candidat qui a reçu le plus de voix qui est élu en un coup."<<std::endl;
				std::cout<<"- Méthode en deux tours (système électoral Français)"<<std::endl;
				std::cout<<"Dans ce système, il y a deux tours. Au premier tour, les deux meilleurs candidats sont retenus. Ensuite un second tour est organisé avec les deux candidats restant, le vainqueur est celui qui obtient le plus de voix au deuxième tour."<<std::endl;
				std::cout<<"- Méthode en n tours"<<std::endl;
				std::cout<<"Cette méthode se déroule en n tour (n étant le nombre de candidat(s) en liste), un candidat est donc éliminé à chaque tour jusqu'à ce qu'il ne reste plus qu'un seul candidat. Celui ci est alors nommé vainqueur. Ce système se justifie dans la mesure où l'électeur moyen élimine souvent plus qu'il ne choisit."<<std::endl;
				std::cout<<""<<std::endl;
				std::cout<<"Méthode de Jean-Charles de Borda"<<std::endl;
				std::cout<<" Ce système électoral est proposé en 1770 par le mathématicien Jean-Charles de Borda. Dans ce système, chaque électeur attribue un nombre de points à chaque candidat. Par exemple pour une élection à 5 candidats cinq points au premier choix, quatre points au second choix, trois points au troisième, etc."<<std::endl;
				std::cout<<"On multiplie alors le nombres de votants par le nombre de points et le candidat récoltant le plus de points est alors le gagnant."<<std::endl;
				std::cout<<""<<std::endl;
				std::cout<<"Méthode de Nicolas de Condorcet"<<std::endl;
				std::cout<<"Chaque candidat est confronté à tous les autres un par un. Pour chaque confrontation, on note une victoire au candidat ayant obtenue le plus de voix par rapport à l'autre. Au final celui ayant le plus de victoires gagne l'élection."<<std::endl;
 				
 				std::cout<<""<<std::endl;
 				std::cout<<""<<std::endl;
 				
				std::cout<<"Nous avons présenté ici cinq façons différentes de déterminer le gagnant d'une élection, et chacune de ces méthodes, sur base des mêmes résultats, peuvent dans certaines situations donner un vainqueur différent. Le blocage peut donc être total."<<std::endl;
				std::cout<<"Et l'absence de solution à ce problème remet en cause tout le principe d'une élection."<<std::endl;
				std::cout<<"Mais alors que faire ?"<<std::endl;
				std::cout<<"Une possibilité parfois évoquée est de choisir le gagnant au hasard parmi les électeurs."<<std::endl;
				std::cout<<"Bien que l'idée peut sembler absurde, elle n'est pas nouvelle, et possède selon ses défenseurs de nombreux atouts."<<std::endl;
				std::cout<<"Quoi qu'il en soit, ne perdons pas de vue ce qui est essentiel pour notre avenir collectif :"<<std::endl;
				std::cout<<"le maintien d'une société ouverte et libre dans laquelle nous pouvons tous vivre en sécurité, sans être pointé d'un doigt accusateur pour être différent ou penser différemment."<<std::endl;

 				std::cout<<""<<std::endl;
 				std::cout<<""<<std::endl;
 				
 				std::cout<<"Appuyer sur un CHIFFRE pour continuer  puis valider avec la touche ENTREE"<<std::endl;
				std::cin>>x;
            			break;  
         		case 2:  
				{
					system("clear");
					std::cout<<"2\tMéthode simple en un tour"<<std::endl;
				
					MethodeEn1Tour m1(&s1);
					m1.findwinner();
					m1.afficheWinner();
					std::cout<<"Appuyer sur 1 pour afficher les détails du résultat sinon un autre CHIFFRE pour revenir à la simulation puis valider avec la touche ENTREE"<<std::endl;
					std::cin>>x;
					if(x==1){
	 					m1.detailsWin();
 						std::cout<<"Appuyer sur un CHIFFRE pour revenir à la simulation puis valider avec la touche ENTREE"<<std::endl;
						std::cin>>x;
					}
 					
            				break;
            			}
			case 3:  {
					system("clear");
	 				std::cout<<"3\tMéthode en deux tours (système électoral Français)"<<std::endl;
					MethodeFrancaise mf(&s1);
					mf.findwinner();
					mf.afficheWinner();
					std::cout<<"Appuyer sur 1 pour afficher les détails du résultat sinon un autre CHIFFRE pour revenir à la simulation puis valider avec la touche ENTREE"<<std::endl;
					std::cin>>x;
					if(x==1){
						mf.detailsWin();
						std::cout<<"Appuyer sur un CHIFFRE pour revenir à la simulaion  puis valider avec la touche ENTREE"<<std::endl;
						std::cin>>x;
					}
		    			break; 
            			}
			case 4:  {
					system("clear");
	 				std::cout<<"4\tMéthode en n tours"<<std::endl;
	 				MethodeEnNTour mn(&s1);
					mn.findwinner();
					mn.afficheWinner();
					std::cout<<"Appuyer sur 1 pour afficher les détails du résultat sinon un autre CHIFFRE pour revenir à la simulation puis valider avec la touche ENTREE"<<std::endl;
					std::cin>>x;
					if(x==1){
						mn.detailsWin();
						std::cout<<"Appuyer sur un CHIFFRE pour revenir à la simulation  puis valider avec la touche ENTREE"<<std::endl;
						std::cin>>x;
					}
		    			break; 
	    			} 
         		case 5:  {
					system("clear");
					std::cout<<"5\tMéthode de Jean-Charles de Borda"<<std::endl;
					MethodeBorda mb(&s1);
					mb.findwinner();
					mb.afficheWinner();
					std::cout<<"Appuyer sur 1 pour afficher les détails du résultat sinon un autre CHIFFRE pour revenir à la simulation puis valider avec la touche ENTREE"<<std::endl;
					std::cin>>x;
					if(x==1){
						mb.detailsWin();
						std::cout<<"Appuyer sur un CHIFFRE pour revenir à la simulaion puis valider avec la touche ENTREE"<<std::endl;
						std::cin>>x;
					}
		    			break;
            			}
         		case 6:  {
					system("clear");
					std::cout<<"6\tMéthode de Nicolas de Condorcet"<<std::endl;
					MethodeCondorcet mc(&s1);
					mc.findwinner();
					mc.afficheWinner();
					std::cout<<"Appuyer sur 1 pour afficher les détails du résultat sinon un autre CHIFFRE pour revenir à la simulation puis valider avec la touche ENTREE"<<std::endl;
					std::cin>>x;
					if(x==1){
						mc.detailsWin();
						std::cout<<"Appuyer sur un CHIFFRE pour revenir à la simulaion puis valider avec la touche ENTREE"<<std::endl;
						std::cin>>x;
					}
		    			break;
            			}
			case 7:  {
	 				system("clear");
	 				std::cout<<"7\tRésultat Général"<<std::endl;
					std::cout<<"---------------------------------"<<std::endl;
					std::cout<<"---------------------------------"<<std::endl;
					std::cout<<"Methode de Nicolas de Condorcet"<<std::endl;
					MethodeCondorcet mc(&s1);
					mc.findwinner();
					mc.afficheWinner();
					std::cout<<"---------------------------------"<<std::endl;
					std::cout<<"Methode de Jean Charles de Borda"<<std::endl;
					MethodeBorda mb(&s1);
					mb.findwinner();
					mb.afficheWinner();
					std::cout<<"---------------------------------"<<std::endl;
					std::cout<<"Methode en 1 tour"<<std::endl;
					MethodeEn1Tour m1(&s1);
					m1.findwinner();
					m1.afficheWinner();;
					std::cout<<"---------------------------------"<<std::endl;
					std::cout<<"Methode en n tour"<<std::endl;
					MethodeEnNTour mn(&s1);
					mn.findwinner();
					mn.afficheWinner();
					std::cout<<"---------------------------------"<<std::endl;
					std::cout<<"Methode francaise"<<std::endl;
					MethodeFrancaise mf(&s1);
					mf.findwinner();
					mf.afficheWinner();
					
					std::cout<<"Appuyer sur un CHIFFRE pour continuer puis valider avec la touche ENTREE"<<std::endl;
					std::cin>>x;
		    			break; 
            			} 
         		case 8:  {
					system("clear");
					std::cout<<"8\tAfficher la répartition des votes"<<std::endl;
					cpt = 0;
					for( auto& iter3 : listeConvictiondeVotes)
					{
						if(cpt==0)
							iter3.afficheConvictiondeVoteenTete();

						iter3.afficheConvictiondeVote();
						cpt++;
					}
					std::cout<<""<<std::endl;
					std::cout<<"Appuyer sur 1 pour afficher les détails du résultat sinon un autre CHIFFRE pour revenir à la simulation puis valider avec la touche ENTREE"<<std::endl;
					std::cin>>x;
					if(x==1){
						std::cout<<""<<std::endl;
						std::cout<<"Chaque électeur classe les candidats en fonction de leurs préférences. Ici le panel d'électeurs se distingue en "<<cpt<<" conviction(s) de vote differente(s)."<<std::endl;
						std::cout<<"Ce tableau présente le classement associé à chaque candidat par chacune des convictions de vote existantes"<<std::endl;
						std::cout<<"Par exemple X élécteur(s) choisissent de classer Mr B en premiere position puis Mm B ..."<<std::endl;
						std::cout<<"Pour certaines méthodes, on utilise seulement le premier choix des électeurs et donc leur candidat de rang 1"<<std::endl;
						std::cout<<""<<std::endl;
						std::cout<<""<<std::endl;
						std::cout<<"Appuyer sur un CHIFFRE pour continuer puis valider avec la touche ENTREE"<<std::endl;
						std::cin>>x;
					}
		    			break;
            			}
         		default:
 				Erreur = 1;
		} 
	}
}


int main()
{
//INTRODUCTION
	system("clear");
	std::cout<<"Dans le cadre"<<std::endl;
	std::cout<<""<<std::endl;
	std::cout<<"N7-IOB LANGAGE OBJET C++-UML"<<std::endl;
	std::cout<<"Projet élection piege à con"<<std::endl;
	std::cout<<""<<std::endl;
	std::cout<<"2016 - 2017"<<std::endl;
	sleep(3);
	system("clear");
	std::cout<<"Supervisé par"<<std::endl;
	std::cout<<""<<std::endl;
	std::cout<<"BRAUNSTEIN Cécile"<<std::endl;
	std::cout<<"BREJON Jean-Baptiste"<<std::endl;
	sleep(2);
	system("clear");
	std::cout<<"ALDEBERT Louis"<<std::endl;
	std::cout<<"ALOUI Driss"<<std::endl;
	std::cout<<""<<std::endl;
	std::cout<<"MAIN 4 Polytech Paris UPMC"<<std::endl;
	sleep(2);
	system("clear");
	std::cout<<"Présente"<<std::endl;
	sleep(1);
	system("clear");
	
	std::cout<<"Avez vous vraiment gagné les élections monsieur le president?"<<std::endl;
	sleep(1);
	system("clear");
	
	std::cout<<"Avez vous vraiment gagné les élections monsieur le president?"<<std::endl;
	std::cout<<""<<std::endl;
	std::cout<<""<<std::endl;
	std::cout<<"0"<<std::endl;
	sleep(1);
	system("clear");
	std::cout<<"Avez vous vraiment gagné les élections monsieur le president?"<<std::endl;
	std::cout<<""<<std::endl;
	std::cout<<""<<std::endl;
	std::cout<<"0\t0"<<std::endl;
	sleep(1);
	system("clear");
	std::cout<<"Avez vous vraiment gagné les élections monsieur le president?"<<std::endl;
	std::cout<<""<<std::endl;
	std::cout<<""<<std::endl;
	std::cout<<"0\t0\t0"<<std::endl;
	sleep(1);
	system("clear");
	std::cout<<"Avez vous vraiment gagné les élections monsieur le president?"<<std::endl;
	std::cout<<""<<std::endl;
	std::cout<<""<<std::endl;
	std::cout<<"0\t0\t0\t0"<<std::endl;
	sleep(1);
	
//PRELUDE
	system("clear");
	std::cout<<"Typiquement, "<<std::endl;sleep(1);
	std::cout<<"dans un état démocratique, des élections sont régulièrement organisées."<<std::endl;sleep(3);
	std::cout<<"Plusieurs candidats se présentent, "<<std::endl;sleep(2);
	std::cout<<"la population se rend aux urnes,"<<std::endl;sleep(2);
	std::cout<<"et sur la base des votes le candidat qui reflète au mieux le choix des électeurs est élu, "<<std::endl;sleep(3);
	std::cout<<"finissant à la tête du pays."<<std::endl;sleep(3);
	system("clear"); 
	std::cout<<"Le principe est donc assez simple,"<<std::endl;sleep(2);
	std::cout<<"et il semble que l'organisation d'une élection est avant tout un casse-tête logistique,"<<std::endl;sleep(3);
	std::cout<<"surtout dans des pays comportant des dizaines de millions d'habitants "<<std::endl;sleep(3);
	std::cout<<"et une mauvaise infrastructure."<<std::endl;sleep(3);
	system("clear");
	std::cout<<"Mais si les problèmes logistiques inhérents à une élection peuvent être résolus,"<<std::endl;sleep(4);
	std::cout<<"beaucoup de gens ignorent que déterminer un vainqueur sur base des votes n'est pas toujours possible."<<std::endl;sleep(4);
	system("clear"); 
	std::cout<<"Merci d'utiliser exclusivement les CHIFFRES pour les selections dans les menus"<<std::endl;
	std::cout<<"Appuyer sur un CHIFFRE pour commencer puis valider avec la touche ENTREE"<<std::endl;
	int x;
	std::cin>>x;

//MENU principal
	int Simu = 0;
	int Erreur = 0;
	while(Simu == 0){
		system("clear");
		std::cout<<"Menu principal"<<std::endl;
		std::cout<<"0\tQuitter"<<std::endl;
		std::cout<<"1\tHelp"<<std::endl;
		std::cout<<"2\tCréer un echantillon de test"<<std::endl;
		if(Erreur == 1){
			std::cout<<"[Erreur] Entrée non valide !"<<std::endl;
			Erreur  =  0;
		}
		std::cout<<"Appuyer sur une touche entre 0 et 2  puis valider avec la touche ENTREE"<<std::endl;
		std::cin>>x;
		switch ( x ){
			case 0: 
				system("clear");
				std::cout<<"Vous avez choisi de quitter"<<std::endl;
				std::cout<<"Etes vous sur?"<<std::endl;
				std::cout<<"Appuyer sur 1 pour revenir au Menu principal sinon une touche pour quitter puis valider avec la touche ENTREE"<<std::endl;
				std::cin>>x;
				if(x!=1){
					system("clear");
					std::cout<<"Merci et à bientot"<<std::endl;
	 				sleep(0.6);
					system("clear");
					std::cout<<"Merci et à bientot"<<std::endl;
	 				std::cout<<"3"<<std::endl;
	 				sleep(1);
	 				system("clear");
					std::cout<<"Merci et à bientot"<<std::endl;
	 				std::cout<<"2"<<std::endl;
	 				sleep(1);
	 				system("clear");
					std::cout<<"Merci et à bientot"<<std::endl;
	 				std::cout<<"1"<<std::endl;
 				 	sleep(1);
	 				Simu = 1;
	 				system("clear");
 				}
            			break; 
			case 1:  
				system("clear");
 				std::cout<<"1\tHelp"<<std::endl;
 				std::cout<<"Merci d'utiliser exclusivement les CHIFFRES pour les selections dans les menus"<<std::endl;
 				std::cout<<""<<std::endl;
 				std::cout<<""<<std::endl;
 				std::cout<<"Le but du programme est de déterminer le vainqueur d'une élection à partir du résultat de vote suivant différentes méthodes."<<std::endl;
 				std::cout<<""<<std::endl;
 				std::cout<<"Utilisation :"<<std::endl;
 				std::cout<<"- Lancer une simulation à partir du menu principal"<<std::endl;
 				std::cout<<"- Naviguer dans les sous menu pour voir le résultat et le détail de la simulation"<<std::endl;
 				std::cout<<""<<std::endl;
 				std::cout<<"Toutes les données sont extraites du fichier 'election.txt'. Elles peuvent être modifiées dans le fichier en respectant des règles d'écriture définies dans le rapport"<<std::endl;
 				std::cout<<""<<std::endl;
 				std::cout<<""<<std::endl;
 				std::cout<<"Appuyer sur un CHIFFRE pour continuer puis valider avec la touche ENTREE"<<std::endl;
				std::cin>>x;
            			break;  
         		case 2:  
				// creation de la simulation
				f();

            			break;
         		default:  
 				Erreur = 1;
		} 
	}
	return 0;
}

