#pragma once
#include <string>

class Objeto
{
public:
	Objeto(int peso);
	Objeto();
	virtual ~Objeto();
	int GetPeso();
	void SetPeso(int peso);
	std::string GetName();
	void SetName(std::string name);
private:
	int _peso;
	std::string _name;
};

