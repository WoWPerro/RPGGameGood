#include "pch.h"
#include "Llave.h"


Llave::Llave()
{
}

Llave::Llave(int ID)
{
	_ID = ID;
}

int Llave::GetID()
{
	return _ID;
}

Llave::~Llave()
{
}
