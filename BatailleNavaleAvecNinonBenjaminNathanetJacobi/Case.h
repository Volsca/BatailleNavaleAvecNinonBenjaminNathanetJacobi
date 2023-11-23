#pragma once


class Bateau;

class Case
{
	bool hasBateau;
	bool hasBeenShot;
	Bateau* bateau;
public:
	Case();
	bool getHasBateau();
	bool getHasBeenShot();
	void setHasBeenShot(bool a);
	void setHasBateau(bool a);
	int shoot();

};

