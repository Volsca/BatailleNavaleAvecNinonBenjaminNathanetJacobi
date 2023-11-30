#include "Grille.h"
#include "Case.h"
#include "Jeu.h"
#include"Bateau.h"

int main() {
	Jeu* game = new Jeu();
	game->Start();

	// Boucle principale du jeu
	while (game->getGame()) {

	}
}