#include "IA.h"
#include "Grille.h"
#include <random>
#include <time.h>


void IA::jouer() //tour de jeu
{
    //Coordonn�es du tir
    int new_x;
    int new_y;

    int restir;//r�sultat du tir : 0 si la case avait d�j� �t� vis�e, 1 s'il n'y a pas de bateau, 2 si un bateau est touch�, 3 si le bateau est coul�

    if (cherche) 
    {
        srand(time(nullptr));
        new_x = rand() % 10;
        new_y = rand() % 10;
        restir=  maGrille->shootCase(new_y, new_x);
        switch (restir)
        {
        case 0: //si la case avait d�j� �t� vis�e, on rejoue
            jouer();
            break;
        case 2:
            cherche = false;
            posdernier[0] = new_x;
            posdernier[1] = new_y;
            postouche[0] = new_x;
            postouche[1] = new_y;
            break;
        }
       
    }
    else
    {
        switch (imove) //on choisit la prochaine direction, 0 vers le haut, 1 vers la droite, 2 vers le bas et 3 vers la gauche
        {

        case 0:
            if (nbtry >= 4)
            {
                new_y = posdernier[1] - 2;
            }
            else
            {
                new_y = posdernier[1] - 1;
            }
            new_x = posdernier[0];
            if (new_y < 0) {
                imove = (imove + 2) % 4;
                new_y = postouche[1] + 1;
            }
            break;
        case 1:
            if (nbtry >= 4)
            {
                new_x = posdernier[0] + 2;
            }
            else
            {
                new_x = posdernier[0] + 1;
            }
            new_y = posdernier[1];
            if (new_x > 9) {
                imove = (imove + 2) % 4;
                new_x = postouche[0] - 1;
            }
            break;
        case 2:
            if (nbtry >= 4)
            {
                new_y = posdernier[1] + 2;
            }
            else
            {
                new_y = posdernier[1] + 1;
            }
            new_x = posdernier[0];
            if (new_y > 9) {
                imove = (imove + 2) % 4;
                new_y = postouche[1] - 1;
            }
            break;
        case 3:
            if (nbtry >= 4) 
            {
                new_x = posdernier[0] - 2;
            }
            else
            {
                new_x = posdernier[0] - 1;
            }
            
            new_y = posdernier[1];
            if (new_x <0) {
                imove = (imove + 2) % 4;
                new_x = postouche[0] + 1;
            }
            break;
        }
       
       restir= maGrille->shootCase(new_y, new_x);
       switch (restir)
       {
       case 0:
           if (postouche[0] == posdernier[0] && postouche[1] == posdernier[1]) //si on n'a touch� qu'une seule fois, on teste toutes les directions
           {
              imove=(imove+1)%4;
              nbtry++;
              jouer();
           }
           else //sinon on repart dans la direction oppos�e
           {
               imove = (imove + 2) % 4;
               posdernier[0] = postouche[0];
               posdernier[1] = postouche[1];
               nbtry++;
               jouer();
           }
           break;
       case 1:
           if (postouche[0] == posdernier[0] && postouche[1] == posdernier[1]) //si on n'a touch� qu'une seule fois, on teste toutes les directions
           {
               imove = (imove + 1) % 4;
               nbtry = 0;
           }
           else //sinon on repart dans la direction oppos�e
           {
               posdernier[0] = postouche[0];
               posdernier[1] = postouche[1];
               imove=(imove + 2)%4;
               nbtry = 0;
           }
           break;
       case 2: //si on a touch� on continue dans cette direction
           posdernier[0] = new_x;
           posdernier[1] = new_y;
           nbtry = 0;
           break;
       case 3: // on coule un bateau, on repasse en al�atoire
           cherche = true;
           nbtry = 0;
           break;
       }
    }
}

IA::IA()
{
    cherche = true;
    imove = 0;
    maGrille = nullptr;
    posdernier[0] =  0;
    postouche[0] = 0;
    posdernier[1] = 0;
    postouche[1] = 0;
}

IA::IA(Grille* g)
{
    maGrille = g;
    cherche = true;
    imove = 0;
}
