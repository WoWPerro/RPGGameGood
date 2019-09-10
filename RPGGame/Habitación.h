#pragma once
#include "Objeto.h"
#include "Enemy.h"
#include "Puerta.h"
#include "Llave.h"

#include <iostream>
#include <string>
#include <set>
#include <list>
#include <forward_list>

using std::string;
using std::list;
using std::set;
using std::forward_list;
using std::list;

class Habitación
{
private:
	int num = 0;
	bool _playerEnters = false;
	bool _read = false;
	string _descripcion;

	std::list <Objeto*>* _objetos;
	std::set <Llave> _llaves;
	std::forward_list <Puerta> _puertas;
	std::list <Enemy> _enemigos;

public:

	Habitación();
	Habitación(int numH, string desc, list<Objeto*>* obj, forward_list<Puerta> pu, list<Enemy> en, set <Llave> Llave) :
	num(numH), _descripcion(desc), _objetos(obj), _puertas(pu), _enemigos(en), _llaves(Llave){};
	/**
	Returns the volume of a sphere with the specified radius.

	@param NULL
	@return string con todos los objetos dentro de la habitación
	*/
	void LeerHabitacion();
	void SetDescription(std::string descripcion);
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

	~Habitación();
};

