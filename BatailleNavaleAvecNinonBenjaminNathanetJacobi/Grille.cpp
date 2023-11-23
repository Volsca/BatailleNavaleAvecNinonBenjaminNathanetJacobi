#include "Grille.h"
#include "Case.h"
#include <iostream>
using namespace std;
Grille::Grille()
{
	shots = 0;
}

bool Grille::addBateau(int taille, int x, int y, string direction)
{
	if (y >= 0 && y < Taille && x >= 0 && x < Taille)
	{
		//Direction vers le haut
		if (direction == "up") {
			if ((x + 1 - taille) >= 0) {
				for (int i = 0; i < taille; i++)
				{
					grille[x - i][y]->setHasBateau(true);
				}
			}
			else {
				cout << "Bateau out of range" << endl;
			}
		}
		//Direction vers le bas
		else if (direction == "down") {
			if ((x +taille-1) < Taille) {
				for (int i = 0; i < taille; i++)
				{
					grille[x + i][y]->setHasBateau(true);
				}
			}
			else {
				cout << "Bateau out of range" << endl;
			}
		}
		//Direction vers la droite
		else if (direction == "right") {
			if ((y + taille - 1) < Taille) {
				for (int i = 0; i < taille; i++)
				{
					grille[x][y+i]->setHasBateau(true);
				}
			}
			else {
				cout << "Bateau out of range" << endl;
			}
		}
		//Direction vers la gauche
		if (direction == "up") {
			if ((y + 1 - taille) >= 0) {
				for (int i = 0; i < taille; i++)
				{
					grille[x ][y-i]->setHasBateau(true);
				}
			}
			else {
				cout << "Bateau out of range" << endl;
			}
		}
	}
	else {
		cout << "Case out of range" << endl;
	}
}

bool Grille::isDead()
{
	return shots >= 17;
}

int Grille::shootCase(int x, int y)
{
	return grille[x][y]->shoot();
}
