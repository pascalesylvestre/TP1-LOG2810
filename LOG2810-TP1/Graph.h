/**
* Fichier : Graph.h
* Auteur : Pascale Sylvestre & Coralie Pharand
* Date : 22 fevrier 2018
* Description : entête de la classe Graph
**/

#ifndef GRAPH_H
#define GRAPH_H

#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <limits>

#include "Sommet.h"

using namespace std;

class Graph {
public:
	//remplace la fonction creerGraph
	Graph();
	void setFilePath(string filepath);
	bool getDefault();
	void setDefault(bool b);
	void lireGraph();
	void plusCourtChemin(typeVehicule vehicule, Sommet* origine, Sommet* destination);
	Sommet* getVille(int ville);

private:
	Sommet* prochaineVille();
	vector<Sommet> sommets_;
	bool default_;
};
#endif //GRAPH_H