/**
* Fichier : Sommet.h
* Auteur : Pascale Sylvestre & Coralie Pharand
* Date : 22 fevrier 2018
* Description : entête de la classe Sommet
**/

#ifndef SOMMET_H
#define SOMMET_H

#include "Chemin.h"

class Sommet {
public:	
	Sommet(int ville, bool station, double gain);
	void ajouterVoisin(Sommet* voisin, int cout);
	int getVille();
	bool getStation();
	double getGain();
	void setGain(double gain);
	bool getVisite();
	void setVisite(bool visite);
	vector<pair<Sommet*, int>> getSommetsVoisins();
	vector<Sommet*> getChemin();
	void setChemin(Chemin chemin);
	void ajouterVilleAuChemin(Sommet*);
	void afficherChemin();

private:
	int ville_;
	bool station_;
	double gain_;
	//si visite est false le sommet n'a pas deja ete visite
	bool visite_ = false;
	//Liste des sommets voisins avec leur cout associe
	vector<pair<Sommet*, int>> sommetsVoisins_;
	//Chemin pour se rendre à ce point
	Chemin chemin_;
};
#endif //SOMMET_H






