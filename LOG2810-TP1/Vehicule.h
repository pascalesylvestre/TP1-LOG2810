/**
* Fichier : Vehicule.h
* Auteur : Pascale Sylvestre & Coralie Pharand
* Date : 22 fevrier 2018
* Description : entête de la classe Vehicule
**/

#ifndef VEHICULE_H
#define VEHICULE_H

#include <string>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

enum typeVehicule { voiture, pickup, fourgon };
enum compagnieVehicule { cheapCar, superCar };

class Vehicule {
public:
	Vehicule(typeVehicule type, compagnieVehicule compagnie = cheapCar);
	void setCompagnie(compagnieVehicule compagnie);
	int getConsommation();
	int getEssence();
	void fullEssence();
	void setEssence(int duree);

private:
	typeVehicule type_;
	compagnieVehicule compagnie_;
	int essence_;
};
#endif //VEHICULE_H






