#include "Bateau.h"

Bateau::Bateau(int t)
{
    taille = t;
    nbShot = 0;
}

void Bateau::shot()
{
    nbShot += 1;
}

int Bateau::getNbShot()
{
    return nbShot;
}

int Bateau::getTaille()
{
    return taille;
}

bool Bateau::isDead()
{
    return taille==nbShot;
}
