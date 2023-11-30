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


// Tour principal du jeu
bool Jeu::Tour()
{
	int x, y; // Les coordon�es de tir
	int etat = 0;

	// Joueur 1 d'abord
	cout << "Joueur 1 vous �tes pr�t ?" << endl;
	
	while (etat == 0) {
		cout << "Player 1" << endl;
		Player1->afficheGrille(true);
		cout << "Player 2" << endl;
		Player2->afficheGrille(true);
		cout << "Veuillez tirer sur votre ennemi. x : ";
		cin >> x;
		cout << endl << "Et en y :";
		cin >> y;
		etat = Player2->shootCase(y, x);

		if (etat == 0) { cout << "Case d�j� touch�e, r�essayez" << endl; }
	}
	
	if (etat == 1) {
		cout << "Vous ne savez pas viser..." << endl;
	}
	else {
		cout << "Fort..." << endl;
		Player2->shot();

		if (Player2->isDead()) {
			cout << "Vous avez tout d�truit... Victoire." << endl;
			return false;
		}
	}


	// Joueur 2
	cout << "Joueur 2 vous �tes pr�t ?" << endl;

	while (etat == 0) {
		cout << "Player 1" << endl;
		Player1->afficheGrille(true);
		cout << "Player 2" << endl;
		Player2->afficheGrille(true);
		cout << "Veuillez tirer sur votre ennemi. x : ";
		cin >> x;
		cout << endl << "Et en y :";
		cin >> y;
		etat = Player1->shootCase(y, x);

		if (etat == 0) { cout << "Case d�j� touch�e, r�essayez" << endl; }
	}

	if (etat == 1) {
		cout << "Miss ! Vous ne savez pas viser..." << endl;
	}
	else {
		cout << "Touch� !!! Fort..." << endl;
		Player1->shot();

		if (Player1->isDead()) {
			cout << "Vous avez tout d�truit... Victoire." << endl;
			return false;
		}
	}
	;
}

void Jeu::End()
{
	if (Player1->isDead())
	{
		cout << "Joueur 2 a gagn�!" << endl;
	}
	else
	{
		cout << "Joueur 1 a gagn�!" << endl;
	}
		
}

// Placement des bateaux en d�but de jeu
void Jeu::addBateau(int taille, Grille* g)
{
	string dir;
	int x, y;
	cout << "Joueur, placez v�tre bateau de taille " << taille;
	bool place = false;

	// Placement du bateau avec v�rification de d�passement et de collisions
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
		place = g->addBateau(taille, x, y, dir); // Add bateau dans Grille.h/.cpp
		if (!place) { cout << " Placement �chou�e" << endl << endl; }
		g->afficheGrille(true); // Visualiser le changement
	}
}
