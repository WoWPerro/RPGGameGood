// RPGGame.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "Map.h"
#include "Habitación.h"
#include "Player.h"
#include "Weapon.h"

#include <typeinfo>
#include <iostream>
#include <stdlib.h>
#include <map>
#include <string>
#include <algorithm>
#include <cctype>
#include <fstream>
#include <sstream>
#include <vector>
#include <list>
#include <exception>

using std::pair;
using std::vector;
using std::multimap;
using std::string;
using std::list;
using std::map;
using std::set;
using std::forward_list;
using std::stringstream;
using std::cout;
using std::cin;
using std::endl;


void StringToLower(string &text)
{
	std::transform(text.begin(), text.end(), text.begin(), [](unsigned char c) { return std::tolower(c); });
}

int countWords(string str)
{
	// breaking input into word using string stream 
	stringstream s(str); // Used for breaking words 
	string word; // to store individual words 

	int count = 0;
	while (s >> word)
		count++;
	return count;
}

void printFrequency(string st)
{
	// each word it mapped to it's frequency 
	map<string, int> FW;
	stringstream ss(st); // Used for breaking words 
	string Word; // To store individual words 

	while (ss >> Word)
		FW[Word]++;

	map<string, int>::iterator m;
	for (m = FW.begin(); m != FW.end(); m++)
		cout << m->first << " -> "
		<< m->second << "\n";
}

void searchMinorDoor(list<Habitación> mapa1, Habitación H, int n, Player &hero)
{
	bool found = false;
	Habitación h2;
	int r = 0;
	int m = 0;
	int o = 0;
	int o2 = 0;
	list<Habitación>::iterator mapa1itr;
	std::forward_list <Puerta> puertas;
	std::forward_list <Puerta>::iterator puertasitr;

	puertas = H.Getpuertas();
	for (puertasitr = puertas.begin(); puertasitr != puertas.end(); puertasitr++)
	{
		if (!found)
		{
			if (puertasitr->GetID() == n)
			{
				found = true;
				hero.move(n);
				for (mapa1itr = mapa1.begin(); mapa1itr != mapa1.end(); mapa1itr++)
				{
					if (mapa1itr->GetNumH() == n)
					{
						mapa1itr->LeerHabitacion();
					}
				}
			}
		}
		

		r = puertasitr->GetID() - n;
		if (m > r)
		{
			m = r;
			o2 = o;
		}
		o++;
	}

	if (!found)
	{
		puertasitr = puertas.begin();
		std::advance(puertasitr, o2);
		if (puertasitr->GetAbierta())
		{
			if (puertasitr->GetID() == hero.GetCuartoActual() || puertasitr->GetID() == n)
			{
				hero.move(n);
				for (mapa1itr = mapa1.begin(); mapa1itr != mapa1.end(); mapa1itr++)
				{
					if (mapa1itr->GetNumH() == n)
					{
						mapa1itr->LeerHabitacion();
					}
				}
			}
			else
			{
				for (mapa1itr = mapa1.begin(); mapa1itr != mapa1.end(); mapa1itr++)
				{
					if (puertasitr->GetID() == mapa1itr->GetNumH())
					{
						h2 = *mapa1itr;
					}
				}
				try
				{
					searchMinorDoor(mapa1, h2, n, hero);
				}
				catch (std::exception& e)
				{
					std::cout << "==========EXCEPTION: " << e.what() << '\n';
				}
			}

		}
		else
		{
			cout << "El camino está cerrado, no puedes pasar, hay una puerta bloqueada en la habitación: " << H.GetNumH() << endl;
		}
	}
	
}

void cambiarcuarto(int n, Player& hero, list<Habitación> mapa1)
{
	int r = 0;
	int m = 0;
	int o = 0;
	int o2 = 0;
	std::forward_list <Puerta> puertas;
	std::forward_list <Puerta>::iterator puertasitr;
	hero.GetCuartoActual();
	list<Habitación>::iterator mapa1itr = mapa1.begin();
	list<Habitación>::iterator mapa1itr2 = mapa1.begin();

	for (mapa1itr = mapa1.begin(); mapa1itr != mapa1.end(); mapa1itr++)
	{
		//if (mapa1itr->GetNumH() == hero.GetCuartoActual())
		if (mapa1itr->GetNumH() == 1)
		{
			mapa1itr2 = mapa1itr;
		}
	}

	//for (mapa1itr = mapa1.begin(); mapa1itr != mapa1.end(); mapa1itr++)
	//{
		//if (n == mapa1itr->GetNumH())
		//if (n == hero.GetCuartoActual())
	try
	{
		searchMinorDoor(mapa1, *mapa1itr2, n, hero);
	}		
	catch(std::exception& e)
	{
		std::cout << "==========EXCEPTION: " << e.what() << '\n';
	}
}

void nextRoom(list<Habitación> &mapa1, int n, Player &hero)
{
	int maxH = 0;
	bool aprove = false;
	bool open = false;
	std::forward_list <Puerta> puertas;
	std::forward_list <Puerta>::iterator puertasitr;
	list<Habitación>::iterator mapa1itr = mapa1.begin();
	for (mapa1itr = mapa1.begin(); mapa1itr != mapa1.end(); mapa1itr++)
	{
		maxH++;
		if (mapa1itr->GetNumH() == hero.GetCuartoActual())
		{
			puertas = mapa1itr->Getpuertas();
		}
	}

	for (puertasitr = puertas.begin(); puertasitr != puertas.end(); puertasitr++)
	{
		if (puertasitr->GetID() == n)
		{
			aprove = true;
		}
	}

	if (aprove)
	{
		for (puertasitr = puertas.begin(); puertasitr != puertas.end(); puertasitr++)
		{
			if (puertasitr->GetID() == n && puertasitr->GetAbierta())
			{
				open = true;
				hero.move(n);
			}
		}

		if (open)
		{
			for (mapa1itr = mapa1.begin(); mapa1itr != mapa1.end(); mapa1itr++)
			{
				if (mapa1itr->GetNumH() == n)
				{
					mapa1itr->LeerHabitacion();
				}
			}
		}
		else
		{
			cout << "La puerta esta cerrada, busca la llave, o si la tienes, abre la puerta" << endl;
		}
	}

	else
	{
		if (n == hero.GetCuartoActual())
		{
			cout << "Estas en a habitacion " << n  << endl;
		}else if (n > maxH){
			cout << "La habitacion " << n << " no existe" << endl;
		}else{
			cout << "La habitacion " << n << " esta muy lejos para que llegues a ella" << endl;
		}
		
	}
}

void DictionarySearch2(string text, multimap <int, string> Diccionario, Player &hero, list<Habitación> &mapa1, bool battle)
{
	bool foundTheWord = false;
	//cout << text << endl;
	StringToLower(text);
	//cout << "N of words is: " << countWords(text) << endl;
	//printFrequency(text);

	vector <string> StringList;
	string key;
	string::iterator it;
	it = key.begin();
	stringstream ss(text); // Used for breaking words 
	string Word; // To store individual words 

	while (ss >> Word)
		StringList.push_back(Word);
	//FW[Word]++;

	vector<string>::iterator i;
	multimap <int, string>::iterator j;
	key = key + " ";
	for (i = StringList.begin(); i != StringList.end(); i++)
	{
		for (j = Diccionario.begin(); j != Diccionario.end(); j++)
		{
			if (i->compare(j->second) == 0)
			{
				key = key + std::to_string(j->first) + " ";				
			}
		}
	}
	key = key + " ";
	//cout << "Keywords in key are: " << key << endl;

	string keys; // To store individual words 

	std::size_t found = key.find('1');
	if (found != string::npos)
	{
		foundTheWord = true;
		if (!battle)
		{
			cout << "Cambiando de cuarto" << '\n';			
			bool foundNumber = false;
			for (i = StringList.begin(); i != StringList.end(); i++)
			{				
				if (i->find_first_of("0123456789") == 0)
				{
					foundNumber = true;
					//hero.move(std::stoi(*i));
					try
					{
						//cambiarcuarto(stoi(*i), hero, mapa1);
						nextRoom(mapa1, stoi(*i), hero);
					}
					catch (std::exception& e)
					{
						std::cout << "==========EXCEPTION: " << e.what() << '\n';
					}

				}
			}
			if (!foundNumber)
			{
				cout << "Por favor especifique un numero de habitacion con numero [ej(1) no(uno)]" << endl;
			}
		}
		else
		{
			cout << "No puedes cambiar de cuarto durante una batalla" << endl;
		}
	}

	found = key.find(" 2 3 ");
	if (found != string::npos)
	{
		foundTheWord = true;
		if (!battle)
		{
			cout << "Abriendo puerta" << '\n';
			/*for (i = StringList.begin(); i != StringList.end(); i++)
			{
				if (i->find_first_of("0123456789") == 0)
				{

				}
			}*/	
		}
		
	}

	found = key.find(" 5 ");
	if (found != string::npos)
	{
		foundTheWord = true;
			cout << "Atacar" << '\n';
			for (i = StringList.begin(); i != StringList.end(); i++)
			{
				if (i->find_first_of("0123456789") == 0)
				{
					list<Habitación>::iterator mapa1itr;
					list<Enemy> *enemigosActuales = NULL;
					
					for (mapa1itr = mapa1.begin(); mapa1itr != mapa1.end(); mapa1itr++)
					{
						if (mapa1itr->GetNumH() == hero.GetCuartoActual())
						{
							enemigosActuales = (&(mapa1itr->GetEnemies()));
						}
					}

					list<Enemy>::iterator enemigosActualesitr;
					for (enemigosActualesitr = (*enemigosActuales).begin(); enemigosActualesitr != (*enemigosActuales).end(); enemigosActualesitr++)
					{
						if (enemigosActualesitr->Getid() == stoi(*i))
						{
							int finalhealth = enemigosActualesitr->GetVida() - hero.makeDamage();
							enemigosActualesitr->SetVida(finalhealth);
							if (enemigosActualesitr->GetVida() <= 0)
							{
								enemigosActualesitr->setAlive(false);
							}
						}
					}
				}
			}
	}

	found = key.find(" 6 ");
	if (found != string::npos)
	{
		foundTheWord = true;
		bool foundTheNumber = false;
		cout << "Equipar" << '\n';
		for (i = StringList.begin(); i != StringList.end(); i++)
		{
			if (i->find_first_of("0123456789") == 0)
			{
				foundTheNumber = true;
				bool foundWeapon = false;
				list <Objeto*> heroObjects = hero.GetObjects();
				list <Objeto*>::iterator heroObjectsitr;
				list <Weapon*> weaponlist;
				list <Weapon*>::iterator weaponlistitr = weaponlist.begin();
				for (Objeto* objeto : heroObjects)
				{
					if (objeto == dynamic_cast<Weapon*>(objeto))
					{
						weaponlist.insert(weaponlistitr, dynamic_cast<Weapon*>(objeto));
						if (weaponlistitr != weaponlist.end())
						{
							weaponlistitr++;
						}

						int weaponN = 0;
						for (weaponlistitr = weaponlist.begin(); weaponlistitr != weaponlist.end(); weaponlistitr++)
						{
							if (stoi(*i) == weaponN)
							{
								hero.SetWeapon(**weaponlistitr);
								foundWeapon = true;
								cout << "Euipaste el arma: " << endl;
								(**weaponlistitr).showStats();
							}
							weaponN++;
						}
						if (!foundWeapon)
						{
							cout << "No encontre tu arma numero [" << *i << "] En tu inventario, puedes desplegar el inventario para averiguar qué tienes" << endl;
						}
					}
				}
			}		
		}
		if (!foundTheNumber)
		{
			cout << "Por favor especifica un numero Ej. (Equipar 5)" << endl;
		}
	}

	found = key.find(" 7 ");
	if (found != string::npos)
	{
		foundTheWord = true;
		cout << "Mostrando inventario" << '\n';
		hero.showInventory();
	}


	if (!foundTheWord)
	{
		cout << "No se encontro el comando, intenta de nuevo o ingresa Help para ver mas opciones" << '\n';
	}
}

bool CheckEnemy(list<Habitación> &mapa1, int n)
{
	std::list <Enemy> _enemigos;
	std::list <Enemy>::iterator enemigositr;
	list<Habitación>::iterator mapa1itr;
	for (mapa1itr = mapa1.begin(); mapa1itr != mapa1.end(); mapa1itr++)
	{
		if (mapa1itr->GetNumH() == n)
		{
			_enemigos = mapa1itr->GetEnemies();
			if (_enemigos.size() != 0)
			{
				for (enemigositr = _enemigos.begin(); enemigositr != _enemigos.end(); enemigositr++)
				{
					if (enemigositr->isAlive())
					{
						return true;
					}
				}
				return false;
			}
		}
	}
	return false;
}

int main()
{
	//------------------------------Dictionary-----------------------------------
	multimap <int, string> Diccionario;
	//MovePlayer
	Diccionario.insert(pair <int, string>(1, "cambiar"));
	Diccionario.insert(pair <int, string>(1, "cambiarme"));
	Diccionario.insert(pair <int, string>(1, "mover"));
	Diccionario.insert(pair <int, string>(1, "moverme"));
	Diccionario.insert(pair <int, string>(1, "ir"));
	Diccionario.insert(pair <int, string>(1, "caminar"));
	Diccionario.insert(pair <int, string>(1, "transladarse"));
	Diccionario.insert(pair <int, string>(1, "transladar"));

	//Abrir
	Diccionario.insert(pair <int, string>(2, "abrir"));
	Diccionario.insert(pair <int, string>(3, "puerta"));
	Diccionario.insert(pair <int, string>(4, "cofre"));

	//Atacar
	Diccionario.insert(pair <int, string>(5, "atacar"));
	Diccionario.insert(pair <int, string>(5, "matar"));
	Diccionario.insert(pair <int, string>(5, "pegarle"));

	//Equipar
	Diccionario.insert(pair <int, string>(6, "equipar"));

	//Mostrar Inventario
	Diccionario.insert(pair <int, string>(7, "mostrar"));
	Diccionario.insert(pair <int, string>(7, "enseñar"));
	Diccionario.insert(pair <int, string>(7, "inventario"));
	Diccionario.insert(pair <int, string>(7, "objetos"));

	//curarse	

	//Tomar

	//Dropear

	//Hechizo

	//Mostrar
	//Inventario
	//Experiencia
	//Vida
	//Stats
	//Mapa

	//Help
	Diccionario.insert(pair <int, string>(5, "atacar"));

	//Ver Inventario
	//---------------------------------------------------------------------------
	{
		//---------------------------------------------------------------------------
		//Referencias: 
		//https://cadiz.nueva-acropolis.es/cadiz-articulos/civilizaciones-antiguas/14779-el-increible-viaje-del-sol-el-libro-de-la-duat-3267
		//https://www.historiarum.es/news/el-egipcio-libro-de-los-muertos-por-talia-lizandra-sierra-/
		//https://es.wikipedia.org/wiki/Libro_del_Amduat
		//https://es.wikipedia.org/wiki/Libro_de_los_muertos
		//https://es.wikipedia.org/wiki/Libro_de_las_Puertas
		//https://es.wikipedia.org/wiki/Duat
		//---------------------------------------------------------------------------
	}

	/*
	De ley:
	Funciones en la Clase Player
		1.- Cambiarse de Habitación
		1.1.- Abrir la puerta
		1.2.- Desbloquear la puerta (si está cerrada)
		2.- Recoger Objetos
		2.1.- Recoger Escudo
		2.2.- Recoger Espada
		2.3.- Recoger Llave
		2.4.- Intercambio de Escudo
		2.5.- Intercambio de Espada
		2.6.- Intercambio de Llave
		3.- Atacar
		3.1.- Enemigo minion
		3.2.- Enemigo Chido
		3.3.- Enemigo Boss
		4.- Defensa automática
		5.- Consultar su Inventario
		6.- Tirar objetos
		7.- Información de la habitación
		8.- Lootear enemigos
		8.1.- Ver una lista de objetos que dropeó
		8.2.- Tomar los objetos que quiera
		8.3.- Agregar una lista en la clase enemigo que almacene una
		lista de strings, donde están especificados los elementos
		que dropea para craftear
		9.- Curarse (agregar el item de poti, la subclase, pues)
		10.- Craftear pociones y alimentos para curarse
		11.- Recetario de cosas que puede craftear, y qué necesita.
		12.- Bestiario
	Mecánicas:
	-Spells
	->Peso para cargar
	-Crear Personaje
	-Elegir mejoras
	Narrativa:
	-Sublime
	-Fantasía
	-Viaje al inframundo Egipcio
	-24 hrs, día y noche, dividir las sesiones en tiempo
	Enemigos:
	-Sirvientes de APAP (Dios Griego del caos y el desánimo)
	Programacion
	Mostrar el Dictionary
	*/

	//GameMap *mapa1;
	//mapa1 = new GameMap;
	list<Habitación> mapa1
	{
		Habitación
		(1,
		string("Holi, vas a morir 1"),
		new list<Objeto*>{new Weapon(1), new Weapon(1)},
		forward_list<Puerta>{Puerta(true, 2, 0)},
		list<Enemy>{},
		set<Llave>{}),

		Habitación
		(2,
		string("Holi, vas a morir 2"),
		new list<Objeto*>{new Weapon(1), new Weapon(1)},
		forward_list<Puerta>{Puerta(true, 1, 0), Puerta(true, 3, 1), Puerta(true, 4, 2)},
		list<Enemy>{Enemy(1,1), Enemy(1,2)},
		set<Llave>{}),

		Habitación
		(3,
		string("Holi, vas a morir 3"),
		new list<Objeto*>{new Weapon(1), new Weapon(1)},
		forward_list<Puerta>{Puerta(true, 2, 1), Puerta(true, 5, 3)},
		list<Enemy>{Enemy(1,1)},
		set<Llave>{}),

		Habitación
		(4,
		string("Holi, vas a morir 4"),
		new list<Objeto*>{new Weapon(1), new Weapon(1)},
		forward_list<Puerta>{Puerta(true, 2, 2), Puerta(true, 6, 2), Puerta(true, 7, 2)},
		list<Enemy>{Enemy()},
		set<Llave>{}),

		Habitación
		(5,
		string("Holi, vas a morir 5"),
		new list<Objeto*>{new Weapon(1), new Weapon(1)},
		forward_list<Puerta>{Puerta(true, 3, 3), Puerta(true, 8, 3)},
		list<Enemy>{Enemy()},
		set<Llave>{}),

		Habitación
		(6,
		string("Holi, vas a morir 6"),
		new list<Objeto*>{new Weapon(1), new Weapon(1)},
		forward_list<Puerta>{Puerta(true, 4, 3), Puerta(true, 9, 3)},
		list<Enemy>{Enemy()},
		set<Llave>{}),

		Habitación
		(7,
		string("Holi, vas a morir 7"),
		new list<Objeto*>{new Weapon(1), new Weapon(1)},
		forward_list<Puerta>{Puerta(true, 4, 3), Puerta(true, 10, 3)},
		list<Enemy>{Enemy()},
		set<Llave>{}),

		Habitación
		(8,
		string("Holi, vas a morir 8"),
		new list<Objeto*>{new Weapon(1), new Weapon(1)},
		forward_list<Puerta>{Puerta(true, 5, 3), Puerta(true, 11, 3), Puerta(true, 12, 3)},
		list<Enemy>{Enemy()},
		set<Llave>{}),

		Habitación
		(9,
		string("Holi, vas a morir 9"),
		new list<Objeto*>{new Weapon(1), new Weapon(1)},
		forward_list<Puerta>{Puerta(true, 6, 3), Puerta(true, 17, 3)},
		list<Enemy>{Enemy()},
		set<Llave>{}),

		Habitación
		(10,
		string("Holi, vas a morir 10"),
		new list<Objeto*>{new Weapon(1), new Weapon(1)},
		forward_list<Puerta>{Puerta(true, 7, 3), Puerta(true, 13, 3)},
		list<Enemy>{Enemy()},
		set<Llave>{}),

		Habitación
		(11,
		string("Holi, vas a morir 11"),
		new list<Objeto*>{new Weapon(1), new Weapon(1)},
		forward_list<Puerta>{Puerta(true, 8, 3)},
		list<Enemy>{Enemy()},
		set<Llave>{}),

		Habitación
		(12,
		string("Holi, vas a morir 12"),
		new list<Objeto*>{new Weapon(1), new Weapon(1)},
		forward_list<Puerta>{Puerta(true, 8, 3)},
		list<Enemy>{Enemy()},
		set<Llave>{}),

		Habitación
		(13,
		string("Holi, vas a morir 13"),
		new list<Objeto*>{new Weapon(1), new Weapon(1)},
		forward_list<Puerta>{Puerta(true, 10, 3), Puerta(true, 14, 3)},
		list<Enemy>{Enemy()},
		set<Llave>{}),

		Habitación
		(14,
		string("Holi, vas a morir 14"),
		new list<Objeto*>{new Weapon(1), new Weapon(1)},
		forward_list<Puerta>{Puerta(true, 13, 3)},
		list<Enemy>{Enemy()},
		set<Llave>{}),

		Habitación
		(15,
		string("Holi, vas a morir 15"),
		new list<Objeto*>{new Weapon(1), new Weapon(1)},
		forward_list<Puerta>{Puerta(true, 14, 3), Puerta(true, 16, 3)},
		list<Enemy>{Enemy()},
		set<Llave>{}),

		Habitación
		(16,
		string("Holi, vas a morir 16"),
		new list<Objeto*>{ new Weapon(1), new Weapon(1) },
		forward_list<Puerta>{Puerta(true, 15, 3), Puerta(true, 17, 3)},
		list<Enemy>{Enemy()},
		set<Llave>{}),

		Habitación
		(17,
		string("Holi, vas a morir 17"),
		new list<Objeto*>{ new Weapon(1), new Weapon(1) },
		forward_list<Puerta>{Puerta(true, 9, 3), Puerta(true, 16, 3)},
		list<Enemy>{Enemy()},
		set<Llave>{}),

		Habitación
		(18,
		string("Holi, vas a morir 18"),
		new list<Objeto*>{ new Weapon(1), new Weapon(1) },
		forward_list<Puerta>{Puerta(true, 9, 3), Puerta(true, 16, 3)},
		list<Enemy>{Enemy()},
		set<Llave>{}),

		Habitación
		(19,
		string("Holi, vas a morir 19"),
		new list<Objeto*>{ new Weapon(1), new Weapon(1) },
		forward_list<Puerta>{Puerta(true, 9, 3), Puerta(true, 16, 3)},
		list<Enemy>{Enemy()},
		set<Llave>{}),

		Habitación
		(20,
		string("Holi, vas a morir 20"),
		new list<Objeto*>{ new Weapon(1), new Weapon(1) },
		forward_list<Puerta>{Puerta(true, 9, 3), Puerta(true, 16, 3)},
		list<Enemy>{Enemy()},
		set<Llave>{}),

		Habitación
		(21,
		string("Holi, vas a morir 21"),
		new list<Objeto*>{ new Weapon(1), new Weapon(1) },
		forward_list<Puerta>{Puerta(true, 9, 3), Puerta(true, 16, 3)},
		list<Enemy>{Enemy()},
		set<Llave>{}),

		Habitación
		(22,
		string("Holi, vas a morir 22"),
		new list<Objeto*>{ new Weapon(1), new Weapon(1) },
		forward_list<Puerta>{Puerta(true, 9, 3), Puerta(true, 16, 3)},
		list<Enemy>{Enemy()},
		set<Llave>{}),

		Habitación
		(23,
		string("Holi, vas a morir 23"),
		new list<Objeto*>{ new Weapon(1), new Weapon(1) },
		forward_list<Puerta>{Puerta(true, 9, 3), Puerta(true, 16, 3)},
		list<Enemy>{Enemy()},
		set<Llave>{}),
	};
	//-----------------------------Niveles--------------------------------

	//Habitación R1;
	//R1.SetDescription("Prueba");
	//Puerta P1(true);
	//R1.Add(P1);
	//Khopesh *khopesh1 = new Khopesh();
	//R1.Add(khopesh1);
	//mapa1->Add(R1);

	//Habitación R2;
	//R2.SetDescription("Prueba 2");
	//Puerta P2(true);
	//R2.Add(P2);
	//mapa1->Add(R2);

	//-----------------------------Player----------------------------------
	Player hero("name");
	cout << hero.GetCuartoActual() << "\n";
	//hero.move(2);
	cout << hero.GetCuartoActual() << "\n";
	//------------------------------GAME-----------------------------------
	list<Habitación>::iterator mapa1itr = mapa1.begin();
	bool win = false;
	bool combat = false;
	string name, dummy;
	cout << "Pon el nombre de tu heroe: " << endl;
	cin >> name;
	getline(cin, dummy);
	cout << "Bienvenido " << name << endl;
	mapa1itr->LeerHabitacion();
	
	//hero.take(new Weapon(1));
	//hero.take(new Weapon(1));
	//hero.take(new Weapon(1));
	//hero.SetWeapon(Weapon(1));
	string text;
	//cout << "hero.GetCuartoActual(): " << hero.GetCuartoActual() << "\n";
	while (win == false)
	{
		combat = CheckEnemy(mapa1, hero.GetCuartoActual());

		while (combat == false && win == false)
		{
			getline(std::cin, text);
			try
			{
				DictionarySearch2(text, Diccionario, hero, mapa1, false);
			}
			catch (std::exception& e)
			{
				std::cout << "==========EXCEPTION: " << e.what() << '\n';
			}

			combat = CheckEnemy(mapa1, hero.GetCuartoActual());
			//cout << "hero.GetCuartoActual(): " << hero.GetCuartoActual() << "\n";
		}

		while (combat == true)
		{
			list<Enemy> enemigosActuales;
			list<Enemy>::iterator enemigosActualesitr;
			list<Habitación>::iterator mapa1itr;
			for (mapa1itr = mapa1.begin(); mapa1itr != mapa1.end(); mapa1itr++)
			{
				if (mapa1itr->GetNumH() == hero.GetCuartoActual())
				{
					enemigosActuales = mapa1itr->GetEnemies();
				}
			}

			getline(std::cin, text);
			try
			{
				DictionarySearch2(text, Diccionario, hero, mapa1, true);
			}
			catch (std::exception& e)
			{
				std::cout << "==========EXCEPTION: " << e.what() << '\n';
			}
			
			for (enemigosActualesitr = enemigosActuales.begin(); enemigosActualesitr != enemigosActuales.end(); enemigosActualesitr++)
			{
				if (enemigosActualesitr->isAlive())
				{
					hero.takeDamage(enemigosActualesitr->attack());
				}
				
				cout << "El " << enemigosActualesitr->GetName() << "(Enemigo [" << enemigosActualesitr->Getid() << "], HP[" << enemigosActualesitr->GetVida() << "])" << " te ataco" << endl;
				cout << "Vida actual [" << hero.getVida() << "]" << endl;
			}




			combat = CheckEnemy(mapa1, hero.GetCuartoActual());
		}
	}
	
	//R1.LeerHabitacion();
	//cout << text;
}
