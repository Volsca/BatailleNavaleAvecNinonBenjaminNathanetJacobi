#pragma once


class Bateau;
/*! \file Case.h
*	\brief Definition de la classe Case
*	\author Nacojaminon
*/

/*! Case.h
*	Definition d'une case de notre grille. 
*	Contient des informationss sur les bateaux presents ou non sur cette case, et si elle a deja ete tire dessus.
*/
class Case
{
	bool hasBateau; ///< True si cette case possède un bateau.
	bool hasBeenShot; ///< True si cette case a deja ete tire dessus
	Bateau* bateau; ///< Reference au bateau sur cette case. Null si aucun bateau est present
public:
	/**
	* @brief Constructeur par defaut de Case.
	*  Tout est a false par default, et le pointeur du bateau est null.
	*/
	Case();
	/**
	* @brief Getter de hasBateau.
	*  Permet de savoir si une case possède un bateau
	*/
	bool getHasBateau();
	/**
	* @brief Getter de hasBeenShot.
	*  Permet de savoir si une case a deja ete tire dessus
	*/
	bool getHasBeenShot();
	/**
	* @brief Setter de hasBeenShot.
	*  Permet de changer la valeur de hasBeenShot
	*/
	void setHasBeenShot(bool a);
	/**
	* @brief Setter de hasBateau.
	*  Permet de changer la valeur de hasBateau
	*/
	void setHasBateau(bool a);
	/**
	* @brief Setter de bateau.
	*  Permet de changer la valeur de bateau avec un pointeur
	*/
	void setBateau(Bateau* b);
	/**
	* @brief Tir sur une case
	* Permet de tirer sur une case. Renvoie : 
	* 0 si la case avait deja ete visee. 
	* 1 s'il n'y a pas de bateau.
	* 2 si un bateau est touche.
	* 3 si le bateau est coule.
	* Appel de la methode shot() de la classe Bateau pour mettre a jour son etat

	*/
	int shoot();
};

