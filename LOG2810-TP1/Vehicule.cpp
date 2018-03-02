/**
* Fichier : Vehicule.cpp
* Auteur : Pascale Sylvestre & Coralie Pharand
* Date : 22 fevrier 2018
* Description : implementation de la classe Vehicule
**/

#include "Vehicule.h"

Vehicule::Vehicule(typeVehicule type, compagnieVehicule compagnie = cheapCar)
{
	type_ = type;
	compagnie_ = compagnie;
}

void Vehicule::setCompagnie(compagnieVehicule compagnie)
{
	compagnie_ = compagnie;
}

//retourne la consommation en pourcentage par heure
int Vehicule::getConsommation()
{
	switch (compagnie_)
	{
	case cheapCar:
		switch (type_)
		{
		case voiture:
			return 5;
			break;
		case pickup:
			return 7;
			break;
		case fourgon:
			return 8;
			break;
		}
	case superCar:
		switch (type_)
		{
		case voiture:
			return 3;
			break;
		case pickup:
			return 4;
			break;
		case fourgon:
			return 6;
			break;
		}
	}
}

int Vehicule::getEssence()
{
	return essence_;
}

void Vehicule::fullEssence()
{
	essence_ = 100;
}

void Vehicule::setEssence(int duree)
{
	essence_ -= duree*getConsommation();
}