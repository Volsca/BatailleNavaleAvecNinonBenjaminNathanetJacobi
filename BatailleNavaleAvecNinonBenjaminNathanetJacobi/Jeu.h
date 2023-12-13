#pragma once
class Grille;
class IA;
class Jeu
{
	Grille* Player1;
	Grille* Player2;
	bool solo = false;
	bool game = true;
	IA* adversaire;

public :
 
	// Contructeur
	Jeu();
	Jeu(IA* a);
	Jeu(Grille * one, Grille* two);

	// Getters
	bool getGame();

	// Methodes 
	void Start(); // Le départ du jeu
	bool Tour(); // La gestion d'un tour (return true si le jeu est toujours en cours)
	void End(); // La fin du jeu
	void addBateau(int taille, Grille* g);
	void addBateau_IA(int taille, Grille* g);
};

