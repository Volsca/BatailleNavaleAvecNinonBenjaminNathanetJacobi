#include "Grille.h"
#include "Case.h"
#include <iostream>
#include <Windows.h>
#include "Bateau.h"
using namespace std;

/**
* @brief Constructeur
* Cree la grille vide contenant aucun bateau.
*/
Grille::Grille()
{
	for (int jacobi = 0; jacobi < Taille; jacobi++)
	{
		
		vector<Case*> temp;
		for (int i = 0; i < Taille; i++)
		{
			Case* empty = new Case();
			temp.push_back(empty);
		}
		grille.push_back(temp);
	}

	shots = 0;
}


bool Grille::addBateau(int taille, int x, int y, string direction)
{
	if (y >= 0 && y < Taille && x >= 0 && x < Taille)
	{
		if (direction == "up" || direction == "right" || direction == "left" || direction == "down")
		{
			//Direction vers le haut
			if (direction == "up") {
				if ((x + 1 - taille) >= 0) {
					for (int i = 0; i < taille; i++)
					{
						if (grille[x - i][y]->getHasBateau())
						{
							cout << "chevauchement de bateau" << endl;
							return false;
						}
					}
					Bateau* temp_b = new Bateau(taille);
					for (int i = 0; i < taille; i++)
					{

						grille[x - i][y]->setHasBateau(true);
						grille[x - i][y]->setBateau(temp_b);
					}
				}
				else {
					cout << "Bateau out of range" << endl;
					return false;
				}
			}
			//Direction vers le bas
			else if (direction == "down") {
				if ((x + taille - 1) < Taille) {
					for (int i = 0; i < taille; i++)
					{
						if (grille[x + i][y]->getHasBateau())
						{
							cout << "chevauchement de bateau" << endl;
							return false;
						}
					}
					Bateau* temp_b = new Bateau(taille);
					for (int i = 0; i < taille; i++)
					{
						grille[x + i][y]->setHasBateau(true);
						grille[x + i][y]->setBateau(temp_b);
					}
				}
				else {
					cout << "Bateau out of range" << endl;
					return false;
				}
			}
			//Direction vers la droite
			else if (direction == "right") {
				if ((y + taille - 1) < Taille) {
					for (int i = 0; i < taille; i++)
					{
						if (grille[x][y + i]->getHasBateau())
						{
							cout << "chevauchement de bateau" << endl;
							return false;
						}
					}
					Bateau* temp_b = new Bateau(taille);
					for (int i = 0; i < taille; i++)
					{
						grille[x][y + i]->setHasBateau(true);
						grille[x][y + i]->setBateau(temp_b);
					}
				}
				else {
					cout << "Bateau out of range" << endl;
					return false;
				}
			}
			//Direction vers la gauche
			if (direction == "left") {
				if ((y + 1 - taille) >= 0) {
					for (int i = 0; i < taille; i++)
					{
						if (grille[x][y - i]->getHasBateau())
						{
							cout << "chevauchement de bateau" << endl;
							return false;
						}
					}
					Bateau* temp_b = new Bateau(taille);
					for (int i = 0; i < taille; i++)
					{
						grille[x][y - i]->setHasBateau(true);
						grille[x][y - i]->setBateau(temp_b);
					}
				}
				else {
					cout << "Bateau out of range" << endl;
					return false;
				}
			}
		}
		else {
		
		cout << "Wrong direction" << endl;
		return false;
		}	
	}
	else {
		cout << "Case out of range" << endl;
		return false;
	}
	return true;
}

bool Grille::isDead()
{
	return shots >= 17;
}

int Grille::shootCase(int x, int y)
{

	return grille[x][y]->shoot();
}

void Grille::afficheGrille(bool bateau)
{
	int i;
	cout << "  ";
	for (i=0; i <  Taille  ;i++)
	{cout << i <<" "; }
	cout<< endl;
	i = 0;
	for (vector<Case*> l : grille)
	{

			cout << i<< " ";
		
		
		for(Case* c : l)
		{
			if (c->getHasBateau()) {
				if (c->getHasBeenShot()) {
					cout << "X ";
				}
				else {
					if (bateau) {
						cout << "B ";
					}
					else {
						cout << "~ ";
					}
				}
			}
			else {
				if (c->getHasBeenShot()) {
					cout << "O ";
				}
				else {
					cout << "~ ";
				}
			}
		}
		cout << endl;
		i++;
	}
}

void Grille::shot()
{
	shots += 1;
}
