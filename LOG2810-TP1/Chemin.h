/**
* Fichier : Chemin.h
* Auteur : Pascale Sylvestre & Coralie Pharand
* Date : 22 fevrier 2018
* Description : entête de la classe Chemin
**/

#ifndef CHEMIN_H
#define CHEMIN_H

#include "Vehicule.h"
#include "Sommet.h"

using namespace std;

class Chemin {
public:
	Chemin();
	vector<Sommet*> getChemin();
	void setChemin(Chemin chemin);
	void ajouterVilleAuChemin(Sommet*);
	void afficherChemin();
	
private:
	vector<Sommet*> cheminSommet_;
	int niveauEssence_;
};
#endif //SOMMET_H






