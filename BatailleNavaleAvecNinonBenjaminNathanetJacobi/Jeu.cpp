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

void Jeu::Start()
{
	// Initialisation première du jeu
	// Creation des grille
	Grille* p1 = new Grille();
	Grille* p2 = new Grille();
	Player1 = p1;
	Player2 = p2;
	
	// Placer les bateaux //
	cout << "Joueur 2, détournez le regard..." << endl;
	addBateau(5, Player1);
	addBateau(4, Player1);
	addBateau(3, Player1);
	addBateau(3, Player1);
	addBateau(2, Player1);

	cout << "Joueur 1, détournez le regard..." << endl;
	addBateau(5, Player2);
	addBateau(4, Player2);
	addBateau(3, Player2);
	addBateau(3, Player2);
	addBateau(2, Player2);

	// Affichage test
	Player1->afficheGrille(true); 
	Player2->afficheGrille(true);
}

void Jeu::Affichage(bool p1)
{
	if (p1)
	{

	}
}

void Jeu::addBateau(int taille, Grille* g)
{
	string dir;
	int x, y;
	cout << "Joueur 1, placez vôtre bateau de " << taille << " cases, direction : (up, down, left, right) ";
	cin >> dir;
	cout << endl << "et son emplacement ? ";
	bool place = false;

	while (!place)
	{
		cout << "Grille :" << endl << endl;
		g->afficheGrille(true);
		cout << "x : ";
		cin >> x;
		cout << " y :";
		cin >> y;
		cout << endl;
		place = g->addBateau(taille, x, y, dir);
		if (!place) { cout << " Placement échouée" << endl << endl; }
	}
}
