#include "pch.h"
#include "Habitaci�n.h"

Habitaci�n::Habitaci�n()
{
}

int Habitaci�n::GetNumH()
{
	return num;
}

std::forward_list <Puerta> &Habitaci�n::Getpuertas()
{
	return _puertas;
}

void Habitaci�n::LeerHabitacion()
{
	if (!_read)
	{
		std::cout << "============================================================================" << std::endl;
		std::cout << _descripcion << std::endl;
		if (_objetos) {
			std::list <Objeto*>::iterator objetosit;
			for (objetosit = _objetos->begin(); objetosit != _objetos->end(); objetosit++)
			{
				std::cout << "Ves: " << (*objetosit)->GetName() << std::endl;
			}
		}

		std::set <Llave>::iterator llavesit;
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
				std::cout << "Puerta [" << puertasit->GetID() << "] abierta" << std::endl;
			}
			else if (!puertasit->GetAbierta())
			{
				std::cout << "Puerta [" << puertasit->GetID() << "] cerrada" << std::endl;
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

void Habitaci�n::SetDescription(std::string descripcion)
{
	_descripcion = descripcion;
}

void Habitaci�n::Add(Puerta puerta)
{
	_puertas.push_front(puerta);
}

void Habitaci�n::Add(Objeto *obj)
{
	_objetos->push_back(obj);
}

void Habitaci�n::Add(Llave llave)
{
	//_llaves.insert(llave);
}

void Habitaci�n::Add(Enemy enemy)
{
	_enemigos.push_back(enemy);
}

void Habitaci�n::Remove(Puerta puerta)
{

}

void Habitaci�n::Remove(Objeto *obj)
{

}

void Habitaci�n::Remove(Llave llave)
{

}

void Habitaci�n::Remove(Enemy enemy)
{

}

list <Enemy> &Habitaci�n::GetEnemies()
{
	return _enemigos;
}

Habitaci�n::~Habitaci�n()
{
}
