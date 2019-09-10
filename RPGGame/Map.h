#pragma once
#include "Habitaci�n.h"
#include <list>
#include <set>
#include <map>

class GameMap
{
public:
	GameMap();
	std::map <int, Habitaci�n> _mapa;
	std::set <Llave> _llaves;
	std::set <Puerta> _puertas;
	int _habitaciones = 0;
	//int _playerpos = 0;
	int *_playerpos;
	//_playerpos = new int 

	void Add(Habitaci�n habitaci�n);
	void Remove(Habitaci�n habitaci�n);
	int GetPlayerPos();
	void SetPlayerPos(int pos);
	~GameMap();
};

