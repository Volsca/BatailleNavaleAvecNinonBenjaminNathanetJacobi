#include "Jeu.h"
#include "IA.h"
#include "Grille.h"
#include <Windows.h>
#include <iostream>
#include <string>
#include <random>

using namespace std;

Jeu::Jeu()
{
	Player1 = nullptr;
	Player2 = nullptr;

}
Jeu::Jeu(IA* a)
{
	Player1 = nullptr;
	Player2 = nullptr;
	adversaire = a;
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
	// Initialisation première du jeu
	string seul = "";
	cout << "Jouer seul ? (oui ou non)" << endl;
	cin >> seul;
	solo = (seul == "oui");
	// Creation des grille
	Grille* p1 = new Grille();
	Grille* p2 = new Grille();
	Player1 = p1;
	Player2 = p2;
	adversaire->setGrille(p1);
	string ready = "";
	
	// Affichage initial
	Player1->afficheGrille(true); 
	std::cout << endl << endl;

	// Placer les bateaux //
	if (!solo)
	{
		std::cout << "Joueur 2, détournez le regard..." << endl;
	}
	addBateau(5, Player1);
	addBateau(4, Player1);
	addBateau(3, Player1);
	addBateau(3, Player1);
	addBateau(2, Player1);

	// Clear hadoc du terminal
	std::cout << endl << endl << endl << endl << endl 
		 << endl << endl << endl << endl << endl 
		 << endl << endl << endl << endl << endl 
		 << endl << endl << endl << endl << endl 
		 << endl << endl << endl << endl << endl 
		 << endl << endl << endl << endl;

	if (solo) {
		addBateau_IA(5, Player2);
		addBateau_IA(4, Player2);
		addBateau_IA(3, Player2);
		addBateau_IA(3, Player2);
		addBateau_IA(2, Player2);
	}
	else
	{
		std::cout << "Player 2, êtes vous prèt ? ";
		std::cin >> ready;
		if (std::cin.fail()) { ready = "non"; std::cin.clear(); }
		std::cout << "Joueur 1, détournez le regard..." << endl;
		Player2->afficheGrille(true);
		addBateau(5, Player2);
		addBateau(4, Player2);
		addBateau(3, Player2);
		addBateau(3, Player2);
		addBateau(2, Player2);
	}


	// Affichage test
	Player1->afficheGrille(true); 
	Player2->afficheGrille(true);
	std::cout << endl << endl
		<< endl << endl;

	// Le jeu est en cours
	game = true;

}


// Tour principal du jeu
bool Jeu::Tour()
{
	int x, y; // Les coordonées de tir
	int etat = 0;
	string ready = "";

	// Joueur 1 d'abord
	// Clear hadoc du terminal
	std::cout << endl << endl << endl << endl << endl
		 << endl << endl << endl << endl << endl 
		 << endl << endl << endl << endl << endl 
		 << endl << endl << endl << endl << endl 
		 << endl << endl << endl << endl << endl 
		 << endl;

	std::cout << "Joueur 1 vous êtes prèt ?" << endl;
	std::cin >> ready;
	if (std::cin.fail()) { std::cin.clear(); ready = "non";  }
	
		
	while (etat == 0) {
		std::cout << "Player 1" << endl;
		Player1->afficheGrille(true);
		std::cout << "Player 2" << endl;
		Player2->afficheGrille(false);
		
		// Vérification de non dépassement de taille
		bool place = false;
		while (!place) {
			std::cout << "Veuillez tirer sur votre ennemi. x : ";
			std::cin >> x;
			if (std::cin.fail()) { x = -1; std::cin.clear(); }
			std::cout << endl << "Et en y :";
			std::cin >> y;
			if (std::cin.fail()) { y = -1; std::cin.clear(); }
			if (y >= 0 && y < 10 && x >= 0 && x < 10) {
				place = true;
			}
		}
		etat = Player2->shootCase(y, x);

		if (etat == 0) { std::cout << "Case déjà touchée, réessayez" << endl; }
	}
	
	if (etat == 1) {
		std::cout << "Vous ne savez pas viser..." << endl;
	}
	else {
		std::cout << "Fort..." << endl;
		Player2->shot();

		if (Player2->isDead()) {
			std::cout << "Vous avez tout détruit... Victoire." << endl;
			game = false;
			return false;
		}
	}

	etat = 0;
	// Joueur 2
	if (solo)
	{
		adversaire->jouer();
		if (Player1->isDead()) {
			std::cout << "Vous êtes éliminé... Défaite." << endl;
			game = false;
			return false;
		}
		return true;
	}
	else 
	{
		ready = "";
		// Clear hadoc du terminal
		std::cout << endl << endl << endl << endl << endl
			<< endl << endl << endl << endl << endl
			<< endl << endl << endl << endl << endl
			<< endl << endl << endl << endl << endl
			<< endl << endl << endl << endl << endl
			<< endl;
		std::cout << "Joueur 2 vous êtes prèt ?" << endl;
		std::cin >> ready;
		if (std::cin.fail()) { ready = "non"; std::cin.clear(); }

		while (etat == 0) {
			std::cout << "Player 1" << endl;
			Player1->afficheGrille(false);
			std::cout << "Player 2" << endl;
			Player2->afficheGrille(true);

			// Vérification de non dépassement de taille
			bool place = false;
			while (!place) {
				std::cout << "Veuillez tirer sur votre ennemi. x : ";
				std::cin >> x;
				if (std::cin.fail()) { x = -1; std::cin.clear(); }
				std::cout << endl << "Et en y :";
				std::cin >> y;
				if (std::cin.fail()) { y = -1; std::cin.clear(); }
				if (y >= 0 && y < 10 && x >= 0 && x < 10) {
					place = true;
				}
			}
			etat = Player1->shootCase(y, x);

			if (etat == 0) { std::cout << "Case déjà touchée, réessayez" << endl; }
		}

		if (etat == 1) {
			std::cout << "Miss ! Vous ne savez pas viser..." << endl;
		}
		else {
			std::cout << "Touché !!! Fort..." << endl;
			Player1->shot();

			if (Player1->isDead()) {
				std::cout << "Vous avez tout détruit... Victoire." << endl;
				game = false;
				return false;
			}
		}
		return true;
	}
}

void Jeu::End()
{
	if (Player1->isDead())
	{
		std::cout << "Joueur 2 a gagné!" << endl;
	}
	else
	{
		std::cout << "Joueur 1 a gagné!" << endl;
	}
		
}

// Placement des bateaux en début de jeu
void Jeu::addBateau(int taille, Grille* g)
{
	string dir;
	int x, y;
	std::cout << "Joueur, placez vôtre bateau de taille " << taille;
	bool place = false;

	// Placement du bateau avec vérification de dépassement et de collisions
	while (!place)
	{
		std::cout << endl << "Son emplacement ? ";
		std::cout << "x : ";
		std::cin >> y;
		if (std::cin.fail()) { y = -1; std::cin.clear(); }
		std::cout << " y :";
		std::cin >> x;
		if (std::cin.fail()) { x = -1; std::cin.clear(); }
		std::cout << endl;
		std::cout << " direction : (up, down, left, right) ";
		std::cin >> dir;
		if (std::cin.fail()) { dir = "non"; std::cin.clear(); }
		place = g->addBateau(taille, x, y, dir);
 // Add bateau dans Grille.h/.cpp
		if (!place) { std::cout << " Placement échouée" << endl << endl; }
		g->afficheGrille(true); // Visualiser le changement
	}
}

// Placement des bateaux par l'IA en début de jeu
void Jeu::addBateau_IA(int taille, Grille* g)
{
	vector<string> directions = { "up","down","left","right"};
	bool place = false;
	srand(time(nullptr));
	// Placement du bateau avec vérification de dépassement et de collisions
	while (!place)
	{
		place = g->addBateau(taille, rand() % 10, rand() % 10, directions[rand() % 4]);
		// Add bateau dans Grille.h/.cpp
	}
}