#include "Grille.h"
#include "Case.h"
#include "Jeu.h"
#include "IA.h"
#include"Bateau.h"

/*! \file main.cpp
*   \brief main file
*   \author Nacojaminon
*	\version 0.5.2.6.7
*/
int main() {
	IA* adv = new IA();
	Jeu* game = new Jeu(adv);
	game->Start();

	// Boucle principale du jeu
	while (game->getGame()) {
		
		game->Tour();
	}
	game->End();
}