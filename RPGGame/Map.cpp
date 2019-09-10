#include "pch.h"
#include "Map.h"


GameMap::GameMap()
{
}

void GameMap::Add(Habitación habitación)
{
	_habitaciones++;
	_mapa.insert(std::pair<int, Habitación>(_habitaciones, habitación));
}

void GameMap::Remove(Habitación habitación)
{

}

void GameMap::SetPlayerPos(int pos)
{
	_playerpos = &pos;
}

int GameMap::GetPlayerPos()
{
	return *_playerpos;
}



GameMap::~GameMap()
{
}
