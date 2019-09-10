#pragma once
#include "Habitación.h"
#include <list>
#include <set>
#include <map>

class GameMap
{
public:
	GameMap();
	std::map <int, Habitación> _mapa;
	std::set <Llave> _llaves;
	std::set <Puerta> _puertas;
	int _habitaciones = 0;
	//int _playerpos = 0;
	int *_playerpos;
	//_playerpos = new int 

	void Add(Habitación habitación);
	void Remove(Habitación habitación);
	int GetPlayerPos();
	void SetPlayerPos(int pos);
	~GameMap();
};

