#pragma once
class Bateau
{
	int taille;
	int nbShot;
public:
	Bateau(int t);
	void shot();
	int getNbShot();
	int getTaille();
	bool isDead();

};

