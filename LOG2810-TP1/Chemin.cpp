/**
* Fichier : Chemin.cpp
* Auteur : Pascale Sylvestre & Coralie Pharand
* Date : 22 fevrier 2018
* Description : implementation de la classe Chemin
**/

#include "Chemin.h"

Chemin::Chemin() {}

vector<Sommet*> Chemin::getChemin()
{
	return cheminSommet_;
}

void Chemin::setChemin(Chemin chemin)
{
	cheminSommet_ = chemin.getChemin();
	niveauEssence_ = chemin.niveauEssence_;
}

void Chemin::ajouterVilleAuChemin(Sommet* ville)
{
	cheminSommet_.push_back(ville);
	// niveau essence
}

void Chemin::afficherChemin()
{
	for (int i = 0; i < cheminSommet_.size() - 1; i++)
	{
		cout << cheminSommet_[i]->getVille() << " --> ";
	}
	cout << cheminSommet_[cheminSommet_.size() - 1]->getVille() << endl;
}