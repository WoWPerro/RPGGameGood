#pragma once
#include "Objeto.h"
#include "Enemy.h"
#include "Puerta.h"
#include "Llave.h"
#include "Weapon.h"

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <forward_list>

using std::string;
using std::list;
using std::forward_list;
using std::list;
using std::vector;

class Habitación
{
private:
	int num = 0;
	bool _playerEnters = false;
	bool _read = false;
	string _descripcion;

	std::list <Objeto*>* _objetos;
	std::vector <Llave> _llaves;
	std::forward_list <Puerta> _puertas;
	std::list <Enemy> _enemigos;

public:

	Habitación();
	Habitación(int numH, string desc, list<Objeto*>* obj, forward_list<Puerta> pu, list<Enemy> en, vector <Llave> Llave) :
	num(numH), _descripcion(desc), _objetos(obj), _puertas(pu), _enemigos(en), _llaves(Llave){};
	/**
	Returns the volume of a sphere with the specified radius.

	@param NULL
	@return string con todos los objetos dentro de la habitación
	*/
	void LeerHabitacion();
	void SetDescription(std::string descripcion);
	void setRead(bool read);
	int GetNumH();
	void Add(Puerta puerta);
	void Remove(Puerta puerta);
	void Add(Objeto *obj);
	void Remove(Objeto *obj);
	void Add(Llave llave);
	void Remove(Llave llave);
	void Add(Enemy enemy);
	void Remove(Enemy enemy);
	std::forward_list <Puerta> &Getpuertas();
	list <Enemy> &GetEnemies();
	vector <Llave> &GetLlaves();
	std::list <Objeto*> *GetObjetos();
	std::list <Weapon*> GetWeapons();

	~Habitación();
};

