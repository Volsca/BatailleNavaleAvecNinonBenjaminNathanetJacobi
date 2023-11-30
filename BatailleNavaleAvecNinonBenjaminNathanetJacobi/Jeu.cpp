#include "Jeu.h"
#include "Grille.h"
#include <Windows.h>
#include <iostream>
#include <string>

using namespace std;

Jeu::Jeu()
{
	Player1 = nullptr;
	Player2 = nullptr;
}

Jeu::Jeu(Grille* one, Grille* two)
{
	Player1 = one;
	Player2 = two;
}

bool Jeu::getGame()
{
	return game;
}

void Jeu::Start()
{
	// Initialisation premi�re du jeu
	// Creation des grille
	Grille* p1 = new Grille();
	Grille* p2 = new Grille();
	Player1 = p1;
	Player2 = p2;
	
	// Affichage initial
	Player1->afficheGrille(true); 
	cout << endl << endl;

	// Placer les bateaux //
	cout << "Joueur 2, d�tournez le regard..." << endl;
	addBateau(5, Player1);
	addBateau(4, Player1);
	addBateau(3, Player1);
	addBateau(3, Player1);
	addBateau(2, Player1);

	cout << "Joueur 1, d�tournez le regard..." << endl;
	addBateau(5, Player2);
	addBateau(4, Player2);
	addBateau(3, Player2);
	addBateau(3, Player2);
	addBateau(2, Player2);

	// Affichage test
	Player1->afficheGrille(true); 
	Player2->afficheGrille(true);

	// Le jeu est en cours
	game = true;
}

void Jeu::addBateau(int taille, Grille* g)
{
	string dir;
	int x, y;
	cout << "Joueur, placez v�tre bateau de taille " << taille;
	bool place = false;

	while (!place)
	{
		cout << endl << "Son emplacement ? ";
		cout << "x : ";
		cin >> y;
		cout << " y :";
		cin >> x;
		cout << endl;
		cout << " direction : (up, down, left, right) ";
		cin >> dir;
		place = g->addBateau(taille, x, y, dir);
		if (!place) { cout << " Placement �chou�e" << endl << endl; }
		g->afficheGrille(true);
	}
}
