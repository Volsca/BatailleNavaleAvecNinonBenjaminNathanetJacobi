#pragma once
class Grille;

class Jeu
{
	Grille* Player1;
	Grille* Player2;

	bool game = false;

public :
 
	// Contructeur
	Jeu();
	Jeu(Grille * one, Grille* two);

	// Getters
	bool getGame();

	// Methodes 
	void Start(); // Le départ du jeu
	bool Tour(); // La gestion d'un tour (return true si le jeu est toujours en cours)
	void End(); // La fin du jeu
	void addBateau(int taille, Grille* g);
};

