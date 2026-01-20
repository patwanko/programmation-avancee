# Exercice 1

## Buts :
*	S’introduire à la syntaxe du C++
*	S’introduire à la structure d’un programme C++
*	Apprendre à bien utiliser Git et Github Classroom

## Contexte :
Le code d’une application en ligne de commande vous est fourni. Vous devez créer un projet, intégrer le code à l’intérieur, l’ajouter au repo Git qui vous a été attribué, le compléter puis le formater selon les bonnes normes du C++

## À faire :

Utiliser votre repo Github Classroom
1.	Vous connecter sur Github Classroom
2.	Ajouter le repo qui vous a été associé sur votre poste grâce à Github Desktop
3.	Configurer un fichier «.gitignore » omettant les fichiers autogénérés de Visual Studio
   1. Le dossier caché .vs
   2. Les dossiers bin et debug
   3. Les dossiers x64 et x86
   4. Les .exe
4. S’assurer qu’aucun fichier inutile ne se présente lors du commit initial ou des subséquents. Si cela vient à arriver, ajouter les filtres nécessaires dans le «.gitignore » **<ins>avant de pousser le commit</ins>**

## Créer un nouveau projet dans votre repo
1.	Doit se nommer tic_tac_toe
2.	Être de type « ligne de commande » et en langage C++
3.	Remplacer le fichier tic_tac_toe.cpp par celui fourni pour l’exercice
4.	Faire un commit initial

## Lire et analyser le code
1.	Essayer de comprendre chaque ligne de code et de commentaire
2.	Exécuter le code pour expérimenter le résultat (la partie ne peut se terminer car il manque du code pour l’instant)

## Organiser les fonctions
1.	Déplacer les déclarations de fonctions dans un fichier en-tête nommé « Fonctions.h »
2.	Tenter de compiler et remarquer ce qui se passe
3.	Déplacer les fonctions complètes dans un fichier nommé « Fonctions.cpp »
     1. Ajouter un « include » de « Fonctions.cpp » vers « Fonctions.h »
     2. Réaliser que les références nécessaires n’ont pas suivies
     3. Ajouter les « includes » et « using namespace » nécessaires dans « Fonction.h » (Puisque c’est inclus dans le .h et que le .h est inclus dans le .cpp, tout le monde a ce qu’il faut!)
4.	Faire un commit avec un nom significatif

## Documenter le code
1.	Ajouter un commentaire au-dessus d’une fonction du « .h »
2.	Aller dans tic_tac_toe.cpp et laisser le curseur sur le nom de la fonction en question
3.	Remarquer que le nouveau commentaire s’affiche dans la description de la fonction, à la place de celui de « Fonctions.cpp »
4.	Donner une description significative et juste à chaque fonction de « Fonctions.h »
5.	Faire un commit avec un nom significatif

## Compléter le code
C’est le temps de s’amuser!
1.	Compléter le code de la fonction « VerifierTicTacToe » afin qu’elle retourne vrai si le joueur passé en paramètre gagne et faux sinon
  * Petit rappel des règles, on gagne si :
    * Nous formons une ligne complète
    * Nous formons une colonne complète
    * Nous formons une diagonale complète
2.	Faire un commit avec un nom significatif

## Remise dans LÉA
Malgré le fait que j’ai accès à votre code dans git, veuillez toujours remettre une version finale dans LÉA lorsqu’un énoncé de travail vous le permet.
1.	Nettoyer la solution
  * Enlever tous les éléments indésirables (.vs, bin, debug, x64, x86…)
2.	Compresser la solution (en .zip)
3.	Remettre via Léa

# Bon travail!

