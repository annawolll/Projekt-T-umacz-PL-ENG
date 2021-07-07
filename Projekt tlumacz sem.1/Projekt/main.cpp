// Projekt PPK plik main.cpp
//Anna Wołoszyn

#include <iostream>
#include <string.h>
#include <fstream>
#include "projekt.h"

using namespace std;


int main(int argc, char** argv) {
	wezel* pKorzen = nullptr;

	string nazwaPlikuWe = "";
	string nazwaPlikuDoTlumaczenia = "";
	string nazwaPlikuWy = "";
	bool plen = false;
	bool enpl = false;

	//Sprawdzenie które przełączniki wystąpiły.
	for (int i = 0; i < argc; i++) {
		if (strcmp(argv[i], "-s") == 0 && i + 1 < argc) {//Funkcja strcmp porównuje napisy, zwraca 0 gdy są takie same.
			nazwaPlikuWe = argv[i + 1];
			i++;//Pominięcie następnego
		}

		if (strcmp(argv[i], "-k") == 0 && i + 1 < argc) {
			if (strcmp(argv[i + 1],"plen")==0) {
				plen = true;
			}
			else if (strcmp(argv[i + 1],"enpl")==0) {
				enpl = true;
			}
			i++;//Pominięcie następnego
		}

		if (strcmp(argv[i], "-i") == 0 && i + 1 < argc) {
			nazwaPlikuDoTlumaczenia = argv[i + 1];
			i++;//Pominięcie następnego
		}

		if (strcmp(argv[i], "-o") == 0 && i + 1 < argc) {
			nazwaPlikuWy = argv[i + 1];
			i++;//Pominięcie następnego
		}
	}

	wczytajZPliku(nazwaPlikuWe, pKorzen); //Wczytanie słówek z pliku tekstowego i dodanie ich do drzewa.
	string y, x;
	if (plen == true) { //Jeżeli w drugim przełączniku podano "plen" to odbywa się wczytanie tekstu w języku polskim 
		x = wczytajTekstWejsciowyPol(nazwaPlikuDoTlumaczenia, pKorzen, y);//do przetłumaczenia na język angielski
	}
	else if (enpl == true) {//Jeżeli w drugim przełączniku podano "enpl" to odbywa się wczytanie tekstu w języku angielskim
		x = wczytajTekstWejsciowyAng(nazwaPlikuDoTlumaczenia, pKorzen, y);//do przetłumaczenia na język polski
	}
	zapisWyniku(nazwaPlikuWy, x);//Przetłumaczony tekst zapisywany jest do pliku.

	usunDrzewo(pKorzen);//Usuwanie drzewa w celu zapobiegania wycieków.
}