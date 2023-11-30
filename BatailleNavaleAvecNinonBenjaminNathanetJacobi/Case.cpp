#include "Case.h"
#include "Bateau.h"
#include <iostream>
#include <Windows.h>
using namespace std;

Case::Case()
{
	hasBateau = false;
	hasBeenShot = false;
	bateau = nullptr;
}

bool Case::getHasBateau()
{
	return hasBateau;
}

bool Case::getHasBeenShot()
{
	return hasBeenShot;
}

void Case::setHasBeenShot(bool a)
{
	hasBeenShot = a;
}

void Case::setHasBateau(bool a)
{
	hasBateau = a;
}

void Case::setBateau(Bateau* b)
{
	bateau = b;
}

int Case::shoot() //retourne 0 si la case avait déjà été visée, 1 s'il n'y a pas de bateau, 2 si un bateau est touché
{
	if (hasBeenShot)
	{	
		return 0;
	}
	else 
	{
		setHasBeenShot(true);
		if (hasBateau)
		{
			bateau->shot();
			cout << "Touché !" << endl;
			if (bateau->isDead())
			{
				cout << "Coulé !" << endl;
			}
			return 2;
		}
		else {
			cout << "A l'eau !" << endl;
			return 1;
		}
	}
}
