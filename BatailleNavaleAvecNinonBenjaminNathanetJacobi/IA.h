#pragma once

class Grille;
#include <vector>
using namespace std;

class IA
{private:
	int imove;//Permet de d�cider la direction dans laquelle tirer lorsque l'on a trouv� un bateau
	int posdernier[2];//derni�re case o� le bateau a �t� touch�
	int postouche[2]; //premi�re case o� le bateau a �t� touch�
	bool cherche; //n'a pas encore touch� de nouveau bateau
	Grille* maGrille;
	int nbtry;//nombre d'essai sans pouvoir tirer
public:
	//Constructeurs
	IA();
	IA(Grille* g);

	void jouer(); //Tour de jeu d'IA
	void setGrille(Grille* g) { maGrille = g; };
	
};

