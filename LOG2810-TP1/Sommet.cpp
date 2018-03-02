/**
* Fichier : Sommet.cpp
* Auteur : Pascale Sylvestre & Coralie Pharand
* Date : 22 fevrier 2018
* Description : implementation de la classe Sommet
**/

#include "Sommet.h"

Sommet::Sommet(int ville, bool station, double gain)
{
	ville_ = ville;
	station_ = station;
	gain_ = gain;
}

void Sommet::ajouterVoisin(Sommet* voisin, int cout)
{
	sommetsVoisins_.push_back(make_pair(voisin, cout));
}

int Sommet::getVille()
{
	return ville_;
}

bool Sommet::getStation()
{
	return station_;
}

double Sommet::getGain()
{
	return gain_;
}

void Sommet::setGain(double gain)
{
	gain_ = gain;
}

bool Sommet::getVisite()
{
	return visite_;
}

void Sommet::setVisite(bool visite)
{
	visite_ = visite;
}

vector<pair<Sommet*, int>> Sommet::getSommetsVoisins()
{
	return sommetsVoisins_;
}

vector<Sommet*> Sommet::getChemin()
{
	return chemin_.getChemin();
}

void Sommet::setChemin(Chemin chemin)
{
	chemin_.setChemin(chemin);
}

void Sommet::ajouterVilleAuChemin(Sommet* ville)
{
	chemin_.ajouterVilleAuChemin(ville);
}

void Sommet::afficherChemin()
{
	chemin_.afficherChemin();
}