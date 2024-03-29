#include "pch.h"
#include "Habitación.h"

Habitación::Habitación()
{
}

int Habitación::GetNumH()
{
	return num;
}

std::forward_list <Puerta> &Habitación::Getpuertas()
{
	return _puertas;
}

void Habitación::LeerHabitacion()
{
	if (!_read)
	{
		int counter = 0;
		std::cout << "============================================================================" << std::endl;
		std::cout << _descripcion << std::endl;
		if (_objetos) {
			std::list <Objeto*>::iterator objetosit;
			for (objetosit = _objetos->begin(); objetosit != _objetos->end(); objetosit++)
			{
				std::cout << "Ves: " << (*objetosit)->GetName() << " ["<< counter << "]"<< std::endl;
				counter++;
			}
		}

		std::vector <Llave>::iterator llavesit;
		int counterLlaves = 0;
		for (llavesit = _llaves.begin(); llavesit != _llaves.end(); llavesit++)
		{
			counterLlaves++;
			std::cout << "Ves: " << counterLlaves << " LLaves" << std::endl;
		}

		std::forward_list <Puerta>::iterator puertasit;
		int counterPuertasA = 0;
		int counterPuertasC = 0;
		for (puertasit = _puertas.begin(); puertasit != _puertas.end(); puertasit++)
		{
			if (puertasit->GetAbierta())
			{
				std::cout << "Puerta [Que lleva al cuarto " << puertasit->GetID() << "] abierta" << std::endl;
			}
			else if (!puertasit->GetAbierta())
			{
				std::cout << "Puerta [Que lleva al cuarto (" << puertasit->GetID() << ")] cerrada" << std::endl;
			}			
		}

		std::list <Enemy>::iterator enemigosit;
		std::cout << "Ves Enemigos" << std::endl;
		for (enemigosit = _enemigos.begin(); enemigosit != _enemigos.end(); enemigosit++)
		{		
			std::cout << "El " << enemigosit->GetName() << "(Enemigo [" << enemigosit->Getid() << "], HP[" << enemigosit->GetVida() << "])" << std::endl;
		}
		_read = true;
		std::cout << "============================================================================" << std::endl;
	}
}

void Habitación::SetDescription(std::string descripcion)
{
	_descripcion = descripcion;
}

void Habitación::Add(Puerta puerta)
{
	_puertas.push_front(puerta);
}

void Habitación::Add(Objeto *obj)
{
	_objetos->push_back(obj);
}

void Habitación::Add(Llave llave)
{
	//_llaves.insert(llave);
}

void Habitación::Add(Enemy enemy)
{
	_enemigos.push_back(enemy);
}

void Habitación::Remove(Puerta puerta)
{

}

void Habitación::Remove(Objeto *obj)
{
	_objetos->remove(obj);
}

void Habitación::Remove(Llave llave)
{

}

void Habitación::Remove(Enemy enemy)
{

}

list <Enemy> &Habitación::GetEnemies()
{
	return _enemigos;
}

vector <Llave> &Habitación::GetLlaves()
{
	return _llaves;
}

std::list <Objeto*> *Habitación::GetObjetos()
{
	return _objetos;
}

std::list <Weapon*> Habitación::GetWeapons()
{
	list <Objeto*>::iterator Objectsitr;
	list <Weapon*> weaponlist;
	list <Weapon*>::iterator weaponlistitr = weaponlist.begin();
	for (Objeto* objeto : *_objetos)
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
	return weaponlist;
}

void Habitación::setRead(bool read)
{
	_read = read;
}

Habitación::~Habitación()
{
}
