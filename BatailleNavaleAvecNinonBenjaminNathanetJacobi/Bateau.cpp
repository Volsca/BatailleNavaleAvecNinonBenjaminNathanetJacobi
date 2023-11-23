#include "Bateau.h"

Bateau::Bateau(int t)
{
    taille = t;
    nbShot = 0;
}

void Bateau::isShot()
{
    nbShot += 1;
}

int Bateau::getNbShot()
{
    return nbShot;
}
