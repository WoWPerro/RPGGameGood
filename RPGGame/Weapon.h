#pragma once
#include "Objeto.h"
#include <time.h>
#include <iostream>

using std::cout;
using std::endl;

class Weapon : public Objeto
{
private:
	std::string _weaponName = "NONAME";
	int _damage = 0;
	bool _effect = false;
	bool _sharp = false;
	bool _fire = false;
	bool _poison = false;
	bool _freeze = false;
	int _typeEffect = 0;
	int _type;
public:
	void setDamage(int damage);
	int getDamage();
	void setWName(std::string name);
	std::string getWName();
	void setEffect();
	bool EffectActive();
	int getEffectType();
	void showStats();
	Weapon();
	Weapon(int type);
	~Weapon();
};

