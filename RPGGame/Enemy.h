#pragma once
#include <string>
#include <time.h>
using std::string;

class Enemy
{
private:
	string _name = "NULL";
	int _id = 0;
	int _type = 0;
	int _maxvida = 1;
	int _currentvida = 10;
	int _daño = 0;
	bool _badEffect = false;
	int _badEffectType = 0;
	bool _alive = true;
public:
	void SetVida(int vida);
	int& GetVida();
	int attack();
	string GetName();
	int Getid();
	bool isAlive();
	void setAlive(bool alive);
	Enemy();
	Enemy(int type, int id);
	~Enemy();
};

