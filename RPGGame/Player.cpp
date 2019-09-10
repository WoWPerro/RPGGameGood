#include "pch.h"
#include "Player.h"

Player::Player()
{
	_cargaActual = 0;
}

Player::Player(std::string name)
{
	_name = name;
}

int Player::GetCuartoActual()
{
	return _cuartoActual;
}

void Player::SetCuartoActual(int cuarto)
{
	_cuartoActual = cuarto;
}

void Player::move(int cuarto)
{
	SetCuartoActual(cuarto);
}

void Player::drop(Objeto *)
{

}

void Player::take(Objeto * objeto)
{
	_objetos.push_back(objeto);
}

void Player::takeDamage(int damage)
{
	_vida -= damage;
}

int Player::makeDamage()
{
	int Result = 0;
	if (_currentweapon.EffectActive())
	{
		if (_currentweapon.getEffectType() == 1)
		{
			srand(time(0));
			Result += (rand() % 10);
			std::cout << "Suma " << Result << " Porque tu " << _currentweapon.GetName() << " contiene SHARPNESS";
		}
	}

	else 
	{
		Result += _currentweapon.getDamage();
	}
	Result *= _fuerza;
	return Result;
}

int Player::getVida()
{
	return _vida;
}

void Player::setVida(int vida)
{
	_vida = vida;
}

void Player::SetWeapon(Weapon &weapon)
{
	_currentweapon = weapon;
}

list <Objeto*> Player::GetObjects()
{
	return _objetos;
}

void Player::showInventory()
{
	list <Weapon*> weaponlist;
	list <Weapon*>::iterator weaponlistitr = weaponlist.begin();
	for (Objeto* objeto : _objetos)
	{
		if (objeto == dynamic_cast<Weapon*>(objeto))
		{
			weaponlist.insert(weaponlistitr, dynamic_cast<Weapon*>(objeto));
			if (weaponlistitr != weaponlist.end())
			{
				weaponlistitr++;
			}
		}
	}

	int weaponN = 0;
	cout << "Armas------------------------------------------------" << endl;
	for (weaponlistitr = weaponlist.begin(); weaponlistitr != weaponlist.end(); weaponlistitr++)
	{
		cout << "Arma [" << weaponN << "]------------" << endl;
		(**weaponlistitr).showStats();
		weaponN++;
	}
	cout << "-----------------------------------------------------" << endl;
}

Player::~Player()
{

}
