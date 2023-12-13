#pragma once
#include <vector>
#include <string>
using namespace std;
class Case;
#define _Taille 10;

/*! \file Grille.h
*	\brief définition de la grille de jeu
*	\author Nacojaminon
*/

/*! Grille.h
*	Represente la grille d'un joueur lors du jeu de bataille navale.
*/

class Grille
{
protected :
	/**
	*  Nombre de fois que la grille a ete touchee.
	*  Si ce nombre depasse le nombre de cases contenant des bateaux, ce joueur perds.
	*/
	int shots; 
	vector<vector<Case*>> grille; ///< Toutes les cases de la grille.
	int Taille = _Taille; ///< Taille de la grille

public :
	Grille();

	/**
	* @brief Fonction d'ajout d'un bateau.
	* Verifie que le placement souhaite n'est pas incompatible avec les bateaux deja places et la taille de la grille
	*/
	bool addBateau(int taille, int x,int y, string direction);

	/**
	* @brief Verifie l'etat du joueur
	*/
	bool isDead();

	/**
	* @brief Enregistre un tir pour ce joueur a une case specifiee
	*/
	int shootCase(int x, int y); // 
	
	/**
	* @brief 
	*/
	void shot();
	void afficheGrille(bool bateau);
};

