#include "pch.h"
#include "Enemy.h"

void Enemy::SetVida(int vida)
{
	_currentvida = vida;
	if (_currentvida <= 0)
	{
		_alive = false;
	}
}

int& Enemy::GetVida()
{
	return _currentvida;
}

Enemy::Enemy()
{
}

Enemy::Enemy(int type, int id)
{
	_id = id;
	_type = type;
	switch (_type)
	{
	case 1:
		_name = "minion";
		_maxvida = 30;
		_currentvida = 30;
		break;
	}
}

int Enemy::attack()
{
	srand(time(0));
	_daño += (rand() % 10);
	return _daño;
}

string Enemy::GetName()
{
	return _name;
}

int Enemy::Getid()
{
	return _id;
}

bool Enemy::isAlive()
{
	return _alive;
}

void Enemy::setAlive(bool alive)
{
	_alive = alive;
}
Enemy::~Enemy()
{
}