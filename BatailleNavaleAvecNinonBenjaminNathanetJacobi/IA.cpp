#include "IA.h"
#include "Grille.h"
#include <random>
#include <time.h>


void IA::jouer()
{
    vector<int> resultat;
    int new_x;
    int new_y;
    int restir;

    if (cherche) 
    {
        srand(time(nullptr));
        new_x = rand() % 10;
        new_y = rand() % 10;
        restir=  maGrille->shootCase(new_y, new_x);
        switch (restir)
        {
        case 0:
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
        switch (imove)
        {

        case 0:
            new_x = posdernier[0];
            new_y = posdernier[1] - 1;
            if (new_y < 0) {
                imove = (imove + 2) % 4;
                new_y = postouche[1] + 1;
            }
            break;
        case 1:
            new_x = posdernier[0]+1;
            new_y = posdernier[1];
            if (new_x > 9) {
                imove = (imove + 2) % 4;
                new_x = postouche[0] - 1;
            }
            break;
        case 2:
            new_x = posdernier[0];
            new_y = posdernier[1]+1;
            if (new_y > 9) {
                imove = (imove + 2) % 4;
                new_y = postouche[1] - 1;
            }
            break;
        case 3:
            new_x = posdernier[0]-1;
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
           if (postouche[0] == posdernier[0] && postouche[1] == posdernier[1])
           {
               imove=(imove+1)%4;
               jouer();
           }
           else
           {
               imove = (imove + 2) % 4;
               posdernier[0] = postouche[0];
               posdernier[1] = postouche[1];
               jouer();
           }
           break;
       case 1:
           if (postouche == posdernier)
           {
               imove = (imove + 1) % 4;
           }
           else
           {
               posdernier[0] = postouche[0];
               posdernier[1] = postouche[1];
               imove=(imove + 2)%4;
           }
           break;
       case 2:
           posdernier[0] = new_x;
           posdernier[1] = new_y;
           break;
       case 3:
           cherche = true;
           break;
       }
    }

    

    return ;
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
