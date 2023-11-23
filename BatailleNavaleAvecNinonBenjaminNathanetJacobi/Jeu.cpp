#include "Jeu.h"
#include "Grille.h"
#include <iostream>
#include <Windows.h>
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
	
	// Setup des bateaux
	cout << "Joueur 2, détournez le regard..." << endl;
}

void Jeu::Affichage(bool p1)
{
	if (p1)
	{

	}
}