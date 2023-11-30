#pragma once
#include <vector>
#include <string>
using namespace std;
class Case;
#define _Taille 10;

class Grille
{
	int shots;
	vector<vector<Case*>> grille;
	int Taille = _Taille;

public :
	Grille();
	bool addBateau(int taille, int x,int y, string direction);
	bool isDead();
	int shootCase(int x, int y); // 
	void shot();
	void afficheGrille(bool bateau);
};

