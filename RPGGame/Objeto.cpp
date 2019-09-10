#include "pch.h"
#include "Objeto.h"


Objeto::Objeto(int peso)
{
	_peso = peso;
}

Objeto::Objeto()
{
}

int Objeto::GetPeso()
{
	return _peso;
}

void Objeto::SetPeso(int peso)
{
	_peso = peso;
}

std::string Objeto::GetName()
{
	return _name;
}

void Objeto::SetName(std::string name)
{
	_name = name;
}

Objeto::~Objeto()
{
}
