#pragma once
class Grille;

class Jeu
{
	Grille* Player1;
	Grille* Player2;

public :
 
	// Contructeur
	Jeu(Grille * one, Grille* two);

	// Methodes 
	void Start(); // Le départ du jeu
	void Tour(); // La gestion d'un tour
	void End(); // La fin du jeu
	void Affichage(bool p1); // L'affichage
};

