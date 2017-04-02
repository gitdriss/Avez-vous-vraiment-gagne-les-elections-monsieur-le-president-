Avez-vous-vraiment-gagne-les-elections-monsieur-le-president-
===
Projet élection piege à con N7-IOB LANGAGE OBJET C++-UML - BRAUNSTEIN Cécile, BREJON Jean-Baptiste

    N7-IOB LANGAGE OBJET C++-UML
    Projet élection piege à con
    BRAUNSTEIN BREJON

Date: 22/01/2017
 
    ALDEBERT Louis
    ALOUI Driss 

MAIN 4 Polytech Paris UPMC


Liste des fichiers
------------
    candidat.cc          methodeborda.cc      methodeenntour.cc    ProjetC++.xmi
    candidat.hh          methodeborda.hh      methodeenntour.hh    README.md
    convictiondevote.cc  methode.cc           methodefrancaise.cc  simulateur.cc
    convictiondevote.hh  methodecondorcet.cc  methodefrancaise.hh  simulateur.hh
    election.txt         methodecondorcet.hh  methode.hh           utility.cc
    main.cc              methodeen1tour.cc    methodepartour.cc    utility.hh
    Makefile             methodeen1tour.hh    methodepartour.hh


Utilisation
------------
    Make
    ./IloveC++
    Make clean


Aucune bibliothèque particulière n'est utilisé par ce programme en dehors des bibliothèques standards.


Merci d'utiliser exclusivement les CHIFFRES pour les selections dans les menus


Le but du programme est de déterminer le vainqueur d'une élection à partir du résultat de vote suivant différentes méthodes.


Navigation
------------
- Lancer une simulation à partir du menu principal
- Naviguer dans les sous menu pour voir le résultat et le détail de la simulation


Toutes les données sont extraites du fichier 'election.txt'. Elles peuvent être modifiées dans le fichier en respectant des règles d'écriture définies dans le rapport




Description des méthodes
------------
Les Méthodes par tour
- Méthode simple en un tour
C'est certainement le système électoral le plus basique. En effet c'est le candidat qui a reçu le plus de voix qui est élu en un coup.
- Méthode en deux tours (système électoral Français)
Dans ce système, il y a deux tours. Au premier tour, les deux meilleurs candidats sont retenus. Ensuite un second tour est organisé avec les deux candidats restant, le vainqueur est celui qui obtient le plus de voix au deuxième tour.
- Méthode en n tours
Cette méthode se déroule en n tour (n étant le nombre de candidat(s) en liste), un candidat est donc éliminé à chaque tour jusqu'à ce qu'il ne reste plus qu'un seul candidat. Celui ci est alors nommé vainqueur. Ce système se justifie dans la mesure où l'électeur moyen élimine souvent plus qu'il ne choisit.

Méthode de Jean-Charles de Borda
 Ce système électoral est proposé en 1770 par le mathématicien Jean-Charles de Borda. Dans ce système, chaque électeur attribue un nombre de points à chaque candidat. Par exemple pour une élection à 5 candidats cinq points au premier choix, quatre points au second choix, trois points au troisième, etc.
On multiplie alors le nombres de votants par le nombre de points et le candidat récoltant le plus de points est alors le gagnant.

Méthode de Nicolas de Condorcet
Chaque candidat est confronté à tous les autres un par un. Pour chaque confrontation, on note une victoire au candidat ayant obtenue le plus de voix par rapport à l'autre. Au final celui ayant le plus de victoires gagne l'élection.


Nous avons présenté ici cinq façons différentes de déterminer le gagnant d'une élection, et chacune de ces méthodes, sur base des mêmes résultats, peuvent dans certaines situations donner un vainqueur différent. Le blocage peut donc être total.
Et l'absence de solution à ce problème remet en cause tout le principe d'une élection.
Mais alors que faire ?
Une possibilité parfois évoquée est de choisir le gagnant au hasard parmi les électeurs.
Bien que l'idée peut sembler absurde, elle n'est pas nouvelle, et possède selon ses défenseurs de nombreux atouts.
Quoi qu'il en soit, ne perdons pas de vue ce qui est essentiel pour notre avenir collectif :
le maintien d'une société ouverte et libre dans laquelle nous pouvons tous vivre en sécurité, sans être pointé d'un doigt accusateur pour être différent ou penser différemment.
