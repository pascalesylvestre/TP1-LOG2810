/**
* Fichier : Graph.cpp
* Auteur : Pascale Sylvestre & Coralie Pharand
* Date : 22 fevrier 2018
* Description : implementation de la classe Graph
**/

#include "Graph.h"

template<typename Out>
void split(const string &s, char delim, Out result) {
	stringstream ss(s);
	string item;
	while (getline(ss, item, delim)) {
		*(result++) = item;
	}
}

//split un string au charactere delim et retourne les nouveau string dans un vecteur
vector<string> split(const string &s, char delim) {
	vector<string> elems;
	split(s, delim, back_inserter(elems));
	return elems;
}

Graph::Graph() : default_(true) {}// si true, il n'y a pas eu d'ajout d'une nouvelle carte

void Graph::setFilePath(string filepath)
{
	sommets_.clear(); //vide le vecteur de sommet pour y mettre les nouvelles informations

	ifstream fichier(filepath, ios::in); 

	if (fichier) // si l'ouverture a fonctionne
	{
		setDefault(false);
		string ligne;
		vector<string> splitString;
		getline(fichier, ligne); // lire la premiere ligne
		//creer les sommets
		while (ligne.size() > 1) // lire les ligne jusqu'a la premiere ligne vide
		{
			//separe la string en deux : la premiere est le numero de la ville et la deuxieme indique s'il y a une station
			splitString = split(ligne, ',');
			int ville = stoi(splitString[0]);
			bool station = bool(stoi(splitString[1]));
			
			Sommet sommet(ville, station, numeric_limits<double>::max()); // std::numeric_limits<double>::max() est la valeur max qu'un double peut prendre cela equivaut a un gain infini
			sommets_.push_back(sommet);
			getline(fichier, ligne); //lire la ligne suivante
		} 

		//ajouter les arcs entre les sommets
		while (getline(fichier, ligne))  // jusqu'a la fin du fichier
		{
			splitString = split(ligne, ',');
			int ville1 = stoi(splitString[0]);
			int ville2 = stoi(splitString[1]);
			int cout = stoi(splitString[2]);

			//ajoute la ville2 comme voisin de la ville1 et la ville1 comme voisin de la ville2
			sommets_[ville1 - 1].ajouterVoisin(&sommets_[ville2 - 1], cout);
			sommets_[ville2 - 1].ajouterVoisin(&sommets_[ville1 - 1], cout);
		}

	}
	else cout << "Le nom du fichier est invalide, la carte n'a pas ete creee." << endl; 
}

//Affichage du graphe
void Graph::lireGraph()
{
	for (int i = 0; i < sommets_.size(); i++)
	{
		cout << "(" << sommets_[i].getVille() << ", (";
		vector<pair<Sommet*, int>> voisins = sommets_[i].getSommetsVoisins();
		for (int j = 0; j < voisins.size(); j++)
		{
			cout << "(" << voisins[j].first->getVille() << ", " << voisins[j].second << ")";
			if (j < voisins.size() - 1)
			{
				cout << ", ";
			}
		}
		cout << "))" << endl;
	}
}

//Affiche le plus court chemin entre deux ville
void Graph::plusCourtChemin(typeVehicule vehiculeType, Sommet* origine, Sommet* destination)
{
	origine->setGain(0);
	origine->setVisite(true);
	origine->ajouterVilleAuChemin(origine);
	Sommet* sommetCourant = origine;
	Vehicule vehicule(vehiculeType);

	while (sommetCourant->getVille() != destination->getVille())
	{
		vector<pair<Sommet*, int>> voisins = sommetCourant->getSommetsVoisins();
		for (int i = 0; i < voisins.size(); i++)
		{
			double newGain = sommetCourant->getGain() + voisins[i].second;
			if (newGain < voisins[i].first->getGain())
			{
				voisins[i].first->setGain(newGain);
				voisins[i].first->setChemin(sommetCourant->getChemin());
				voisins[i].first->ajouterVilleAuChemin(voisins[i].first);
			}
		}
		sommetCourant = prochaineVille();
		sommetCourant->setVisite(true);
	}
	destination->afficherChemin();
}

Sommet* Graph::prochaineVille()
{
	Sommet* prochaineVille = nullptr;
	double gainMin = numeric_limits<double>::max();
	for (int i = 0; i < sommets_.size(); i++)
	{
		if (sommets_[i].getGain() < gainMin && !(sommets_[i].getVisite()))
		{
			gainMin = sommets_[i].getGain();
			prochaineVille = &sommets_[i];
		}
	}
	return prochaineVille;
}

Sommet* Graph::getVille(int ville)
{
	return &sommets_[ville - 1];
}

void Graph::setDefault(bool b) { 
	default_ = b;
}

bool Graph::getDefault() { 
	return default_;
}