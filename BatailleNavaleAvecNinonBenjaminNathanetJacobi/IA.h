#pragma once

class Grille;
#include <vector>
using namespace std;

class IA
{private:
	int imove;
	int posdernier[2];//derni�re case o� le bateau a �t� touch�
	int postouche[2]; //premi�re case o� le bateau a �t� touch�
	bool cherche; //n'a pas encore touch� de nouveau bateau
	Grille* maGrille;
public:
	
	void jouer();
	IA();
	void setGrille(Grille* g) { maGrille = g; };
	IA(Grille* g);
};

