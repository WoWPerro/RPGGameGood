#pragma once
#include <iostream>

class Puerta
{
private:
	bool _abierta;
	std::string _estadopuerta;
	int _ID;
	int _key = 0;
public:
	Puerta();
	Puerta(bool abierta, int Id, int key);
	//Puerta(const Puerta& p);

	bool GetAbierta();
	void SetAbierta(bool abierta);
	int GetID();
	int GetKey();

	//friend std::ostream& operator << (std::ostream &o, const Puerta &p);
	~Puerta();
};

