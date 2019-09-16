#pragma once
#include <list>
#include <vector>
#include "Objeto.h"
#include "Llave.h"
#include "Habitación.h"
#include "Map.h"
#include "Weapon.h"
#include <time.h>

class Player
{
public:
	Player();
	Player(std::string name);

private:
	std::string _name;
	int _cuartoActual = 1;
	std::list <Objeto *> _objetos;
	std::vector <Llave> _llaves;
	int _fuerzaCarga = 100;
	int _cargaActual = 0;
	float _fuerza = 1;
	int _currentMana = 10;
	int _maxMana = 10;
	int _exp = 0;
	int _maxExp = 100;
	int _vida = 100;
	int _maxVida = 100;
	Weapon _currentweapon;

public:
	void move(int cuarto);
	void SetCuartoActual(int cuarto);
	int GetCuartoActual();
	void drop(Objeto *);
	void take(Objeto *);
	void takeKey(Llave Llave);
	vector <Llave> GetKey();
	void takeDamage(int damage);
	int makeDamage();
	int getVida();
	void setVida(int vida);
	void SetWeapon(Weapon &weapon);
	void showInventory();
	bool SetCargactual(int carga);
	list <Objeto*> GetObjects();
	
	~Player();
};

