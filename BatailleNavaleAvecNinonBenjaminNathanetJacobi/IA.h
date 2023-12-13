#pragma once

class Grille;
#include <vector>
using namespace std;

class IA
{private:
	int imove;//Permet de décider la direction dans laquelle tirer lorsque l'on a trouvé un bateau
	int posdernier[2];//dernière case où le bateau a été touché
	int postouche[2]; //première case où le bateau a été touché
	bool cherche; //n'a pas encore touché de nouveau bateau
	Grille* maGrille;
	int nbtry;//nombre d'essai sans pouvoir tirer
public:
	//Constructeurs
	IA();
	IA(Grille* g);

	void jouer(); //Tour de jeu d'IA
	void setGrille(Grille* g) { maGrille = g; };
	
};

