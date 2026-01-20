// tic_tac_toe.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.


/////////////////////////////////////////////////////////////////////////////
//librairies nécessaires
//iostream: entrées-sorties à l'aide de cout et cin
//string: pour la manipulation des chaines de caractères
#include <iostream>
#include <string>
//évite d'écrire std:: devant les cin, cout, ...
using namespace std;

/////////////////////////////////////////////////////////////////////////////
// Constantes et prototypes des fonctions

//le mot const s'applique à ce qui se trouve immédiatement à sa gauche
//sinon, il s'applique à ce qui se trouve à sa droite
int const NOMBRE_JOUEUR = 2;

//en C++, un caractère (type char) est entouré d'apostrophe: '
//et une chaine de caractères (type string) est entourée de guillemets: "

char const JOUEURS[NOMBRE_JOUEUR] = { 'O', 'X' };

void EntrerUnNombre(int& nombre);
void EntrerUnCaractere(char& caractere);
bool ValiderNombre(int nombre, int borneInferieure, int borneSuperieure);
void AfficherBienvenue();
void Afficher(char const jeu[3][3]);
bool Jouer(char jeu[3][3], int position, char joueur);
bool VerifierTicTacToe(char const jeu[3][3], char joueur);

/////////////////////////////////////////////////////////////////////////////
// Point d'entrée de l'exécution
// La fonction main() retourne toujours 0

//Un programme en mode console constitue de la programmation de type procédurale (non événementielle)
//Les instructions se déroulent les unes après les autres
//La fonction main() comporte souvent une boucle servant à controler le déroulement de l'application

//***************STANDARD ******************
//la fonction main() doit être la première fonction dans le code
int main()
{
    int nombreTours = 0;
    int joueurCourant = 0;
    int position = -1;
    bool finJeu = false;
    bool positionValide = false;

    char jeuTicTacToe[3][3] =
    {
        { '1', '2', '3' },
        { '4', '5', '6' },
        { '7', '8', '9' },
    };

    AfficherBienvenue();

    Afficher(jeuTicTacToe);
    while (!finJeu && nombreTours < 9)
    {
        cout << "Joueur " << JOUEURS[joueurCourant] << " entrez une position: ";

        positionValide = false;
        while (!positionValide)
        {
            EntrerUnNombre(position);
            positionValide = ValiderNombre(position, 1, 9);
            if (!positionValide)
            {
                cout << "Erreur...entrez une position valide (1-9)\n";
            }
        }
        if (Jouer(jeuTicTacToe, position, JOUEURS[joueurCourant]))
        {
            Afficher(jeuTicTacToe);
            finJeu = VerifierTicTacToe(jeuTicTacToe, JOUEURS[joueurCourant]);
            if (!finJeu)
            {
                joueurCourant = (joueurCourant + 1) % NOMBRE_JOUEUR;
            }
            nombreTours++;
        }
    }

    if (finJeu)
    {
        cout << "Joueur " << JOUEURS[joueurCourant] << " vous etes le gagnant\n";
    }
    else
    {
        cout << "Il n'y a pas de gagnant\n";
    }
    return 0;
}

/////////////////////////////////////////////////////////////////////////////
// Autres fonctions

void AfficherBienvenue()
{
    //cout (console out) sert à faire afficher du texte ou des variables à l'écran
    //les caractères accentués ne sont pas affichés
    //cin (console in) permet à l'usager d'entrer une valeur au clavier

    cout << "\n\nBienvenue dans notre jeu de tic-tac-toe " << endl; //endl (end line) fait la même chose que "\n"

    //pour faire afficher des guillemets ou un '\'
    //le '\' constitue un caractère d'échappement qui fait ignorer la signification du caractère qui suit
    //cout << "Voici des guillemets \"" << endl;
    //cout << "Voici un \\" << endl;
}

// Paramètre par RÉFÉRENCE:
//      & indique qu'il s'agit d'une référence
//      C'est l'ADRESSE de la variable qui est reçue en paramètre
//      La valeur de la variable sera donc modifiée au retour de la fonction
void EntrerUnNombre(int& nombre)
{
    //cin (console in) permet à l'usager d'entrer une valeur au clavier
    //cin peut échouer si l'usager n'inscrit pas le bon type de donnée
    //il faut prendre l'habitude de sécuriser le tout
    while (!(cin >> nombre))
    {
        cin.clear(); // On remet std::cin dans un état fonctionnel.
        cin.ignore(255, '\n'); // On vide les caractères mémorisés.
        cout << "Erreur...\n";
    }
    cin.ignore();

    //if std::cin.fail() existe aussi
}

void EntrerUnCaractere(char& caractere)
{
    //un caractère peut être n'importe quoi: lettre, chiffre, autre, ...
    //lorsque l'usager entre plusieurs caractères:
    //  - le 1er caractère va dans la variable
    //  - les autres restent en mémoire et seront utilisés lors du prochain cin
    //  - il faut donc vider la mémoire du cin
    cin >> caractere;
    cin.ignore(255, '\n'); // On vide les caractères mémorisés.
}

// Paramètre par VALEUR:
//      une COPIE du contenu de la variable est effectuée
//      le paramètre est en fait une variable LOCALE à la fonction
//      toute modification faite au paramètre ne sera pas effective au retour de la fonction
//
//retourne true si le nombre se trouve dans les bornes, les bornes étant acceptées
bool ValiderNombre(int nombre, int borneInferieure, int borneSuperieure)
{
    bool nombreValide = false;
    if (nombre >= borneInferieure && nombre <= borneSuperieure)
    {
        nombreValide = true;
    }
    return nombreValide;
}

// un tableau est TOUJOURS un paramètre par RÉFÉRENCE
// Paramètre par REFERENCE CONSTANT:
//      le mot const empêche la modification du paramètre même s'il est par référence

// lorsqu'un tableau à plusieurs dimensions est passé en paramètres il faut préciser les dimensions
// par contre, il ne faut pas préciser les dimensions lorsqu'il s'agit d'un tableau à 1 dimension ex: char tableau[]
void Afficher(char const jeu[3][3])
{
    for (unsigned int ligne = 0; ligne < 3; ligne++)
    {
        for (unsigned int col = 0; col < 3; col++)
        {
            cout << " " << jeu[ligne][col];
            if (col != 2)
            {
                cout << " |";
            }
        }
        cout << "\n";
        if (ligne != 2)
        {
            cout << "--- --- ---\n";
        }
    }
    cout << endl;
}

// Retourne true si le coup est joué
bool Jouer(char jeu[3][3], int position, char joueur)
{
    bool coupValide = false;
    int ligne = (position - 1) / 3;
    int colonne = (position - 1) % 3;
    //pour obtenir le caractère correspondant au chiffre
    //car le code ascii du caractère '0' est 48, '1' est 49, ...
    if (jeu[ligne][colonne] == (position + 48))
    {
        jeu[ligne][colonne] = joueur;
        coupValide = true;
    }
    return coupValide;
}

// Retourne true si le joueur courant a reussi à faire un tic-tac-toe
bool VerifierTicTacToe(char const jeu[3][3], char joueur)
{
    bool ticTacToe = false;
    
    return ticTacToe;
}

