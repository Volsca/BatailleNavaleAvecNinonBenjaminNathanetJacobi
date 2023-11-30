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

int Case::shoot() //retourne 0 si la case avait d�j� �t� vis�e, 1 s'il n'y a pas de bateau, 2 si un bateau est touch�, 3 si le bateau est coul�
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
			cout << "Touch� !" << endl;
			if (bateau->isDead())
			{
				cout << "Coul� !" << endl;
				return 3;
			}
			return 2;
		}
		else {
			cout << "A l'eau !" << endl;
			return 1;
		}
	}
}
