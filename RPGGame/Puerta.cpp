#include "pch.h"
#include "Puerta.h"


Puerta::Puerta()
{
	_abierta = true;
	_estadopuerta = "Abierta";
}

Puerta::Puerta(bool abierta, int id, int key)
{
	_abierta = abierta;
	if (_abierta)
	{
		_estadopuerta = "Abierta";
	}
	else
	{
		_estadopuerta = "Cerrada";
	}
	_ID = id;
	_key = key;
}

int Puerta::GetID()
{
	return _ID;
}

//Puerta::Puerta(const Puerta& p)
//{
//	*this = p;
//}

bool Puerta::GetAbierta()
{
	return _abierta;
}

void Puerta::SetAbierta(bool abierta)
{
	_abierta = abierta;
	if (_abierta)
	{
		_estadopuerta = "Abierta";
	}
	else
	{
		_estadopuerta = "Cerrada";
	}
}

int Puerta::GetKey()
{
	return _key;
}

//std::ostream& operator << (std::ostream &o, const Puerta &p)
//{
//	o << "Puerta: " << p._estadopuerta;
//	return o;
//}

Puerta::~Puerta()
{
}
