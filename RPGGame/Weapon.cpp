#include "pch.h"
#include "Weapon.h"

Weapon::Weapon():Objeto()
{
}

void Weapon::setEffect()
{
	srand(time(0));
	int r = (rand() % 10) + 1;
	if (r == 5)
	{ 
		_effect = true;
		_typeEffect = (rand() % 3) + 1;
		switch(_typeEffect)
		{
		case 1:
			_sharp = true;
			break;

		case 2:
			_fire = true;
			break;

		case 3:
			_poison = true;
			break;

		case 4:
			_freeze = true;
			break;
		}
	}
}

Weapon::Weapon(int type):Objeto()
{
	_type = type;
	switch (_type)
	{
		case 1:
			_weaponName = "Khopesh";
			srand(time(0));
			setDamage(rand() % 20);
			setEffect();
			SetPeso(10);
			SetName(getWName());
			break;
	}
}

void Weapon::setDamage(int damage)
{
	_damage = damage;
}

int Weapon::getDamage()
{
	return _damage;
}

void Weapon::setWName(std::string name)
{
	_weaponName = name;
}

std::string Weapon::getWName()
{
	return _weaponName;
}

int Weapon::getEffectType()
{
	return _typeEffect;
}

bool Weapon::EffectActive()
{
	return _effect;
}

void Weapon::showStats()
{
	cout << "Nombre: " << _weaponName << endl;
	cout << "Danio: " << _damage << endl;
	cout << "Efecto: " << _effect << endl;
	if (_effect)
	{
		switch (_typeEffect)
		{
		case 1:			
			cout << "Efecto: Sharpness (Filo) " << endl;
			break;

		case 2:
			cout << "Efecto: Fire (Fuego) " << endl;
			break;

		case 3:
			cout << "Efecto: Poison (Veneno) " << endl;
			break;

		case 4:
			cout << "Efecto: Freeze (Hielo) " << endl;
			break;
		}
	}
	cout << "Peso: " << Objeto::GetPeso() << endl;
}

Weapon::~Weapon()
{
}