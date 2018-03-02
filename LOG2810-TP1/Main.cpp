/**
* Fichier : Main.cpp
* Auteur : Pascale Sylvestre & Coralie Pharand
* Date : 22 fevrier 2018
* Description : fichier main
**/
#include <iostream>
#include "Graph.h"

using namespace std;


int main()
{

	//graph vide
	Graph graphNew;

	//interface();
	enum choix { menu, a, b, c };

	string optionA = "(a) Mettre à jour la carte";
	string optionB = "(b) Determiner le plus court chemin";
	string optionC = "(c) Quitter";


	//Variables option b
	string vehicule = "";
	Sommet* origine = nullptr;
	Sommet* destination = nullptr;

	string optionsV = "Choix de vehicule : ";
	string optionsO = "";
	string optionsD = "";

	choix etat = menu;
	char reponse;
	string fichier;
	for (;;) {
		switch (etat)
		{
		case menu:
			//Affichage de l'interface
			cout << a << endl << b << endl << c << endl;
			cin >> reponse;

			if (reponse == 'a') {
				etat = a;
			}
			else if (reponse == 'b') {
				etat = b;
			}
			else if (reponse == 'c') {
				etat = c;
			}
			else cout << "Faire un choix ente a, b & c." << endl;

			break;

		case a:
			//Mettre à jour la carte
			cout << "Ecrire le nom du nouveau fichier" << endl;
			cin >> fichier;
			graphNew.setFilePath(fichier);
			etat = menu;
			break;


		case b:
			//Determiner le plus court chemin
			if (graphNew.getDefault()) {
				graphNew.setFilePath("ville.txt");
			}

			graphNew.plusCourtChemin(vehicule, origine, destination);

			//plusCourtChemin();

		}
	}

	//carte.plusCourtChemin("", carte.getVille(10), carte.getVille(17));

	system("pause");
	return 0;
}
//{}