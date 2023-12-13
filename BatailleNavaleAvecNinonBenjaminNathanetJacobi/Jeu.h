#pragma once
class Grille;
class IA;

/*! \file Jeu.h
*	\brief definition de l'outil de gestion du jeu
*	\author Nacojaminon
*/

/*! Jeu.h
*	Objet contenant les grilles joueurs ainsi que l'IA 
*/

class Jeu
{
	Grille* Player1; ///< La grille du joueur 1
	Grille* Player2; ///< La grille du joueur 2
	bool solo = false; ///< Etat multijoueur du jeu
	bool game = true; ///< Etat du jeu (si false alors le jeu est terminee)
	IA* adversaire; ///< L'IA qui jouerait si solo = true

public :
 
	/**
	* @brief Constructeur par defaut de Jeu
	*/
	Jeu();

	/**
	* @brief Constructeur que l'on utilise le plus
	*/
	Jeu(IA* a);

	/**
	* @brief Constructeur qui prends en parametre des grilles crees a l'avance
	*/
	Jeu(Grille * one, Grille* two);

	// Getters
	/**
	* @brief Verifie l'etat du jeu
	*/
	bool getGame();

	// Methodes 
	/**
	* @brief Fonction d'initialisation du jeu.
	* Cree les joueurs et lance la phase de placement des bateaux.
	*/
	void Start();

	/**
	* @brief Parcours un tour a l'appel de cette fonction
	*/
	bool Tour();

	/**
	* @brief Fin du jeu
	* Affiche le message de fin une fois le jeu fini
	*/
	void End();

	/**
	* @brief Gestion de l'ajout d'un bateau de taille donnee
	* Cette fonction est appelee durant start() pour placer tout les bateaux necessaires
	*/
	void addBateau(int taille, Grille* g);

	/**
	* @brief addBateau() pour l'IA
	* Remplace le choix de l'uilisateur par un choix au hasard de l'IA
	*/
	void addBateau_IA(int taille, Grille* g);
};

