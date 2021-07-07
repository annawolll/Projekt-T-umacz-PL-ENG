//Projekt PPK plik projekt.cpp
//Anna Wo³oszyn

#include "projekt.h"

//#include <iostream>
//#include <fstream>

using namespace std;

bool dodajDoDrzewaPol(wezel*& korzen, wezel* doDodania) {
	if (korzen == nullptr) {
		korzen = doDodania;
		return true;
	}
	else if (doDodania->polSlowko < korzen->polSlowko)
		dodajDoDrzewaPol(korzen->lewyPol, doDodania);
	else
		dodajDoDrzewaPol(korzen->prawyPol, doDodania);

	return false;
}

void dodajDoDrzewaAng(wezel*& korzen, wezel* doDodania) {
	if (korzen == nullptr)
		korzen = doDodania;
	else if (doDodania->angSlowko < korzen->angSlowko)
		dodajDoDrzewaAng(korzen->lewyAng, doDodania);
	else
		dodajDoDrzewaAng(korzen->prawyAng, doDodania);
}

void dodajDoDrzewa(string polskie, string angielskie, wezel*& korzen) {
	wezel* doDodania = new wezel{ polskie, angielskie, nullptr, nullptr, nullptr, nullptr };
	if (!dodajDoDrzewaPol(korzen, doDodania)) //Je¿eli jest dodanie do pustego drzewa, bêdzie to element wspólny, nie dodawany jest dwukrotnie. 

		dodajDoDrzewaAng(korzen, doDodania);
}

void usunDrzewo(wezel*& korzen) {
	if (korzen) {
		usunDrzewo(korzen->lewyPol);
		usunDrzewo(korzen->prawyPol);
		delete korzen;
		korzen = nullptr;
	}
}


bool wczytajZPliku(string nazwaPliku, wezel*& korzen) {

	ifstream plik(nazwaPliku);
	if (!plik)//Je¿eli nie znaleziono pliku zwrócenie false.
		return false;

	string slowkoPolskie, slowkoAngielskie;
	while (plik >> slowkoPolskie >> slowkoAngielskie) {//Wczytanie pierwszego s³ówka linijki do "slowkoPolskie", a drugiego do "slowkoAngielskie".
		dodajDoDrzewa(slowkoPolskie, slowkoAngielskie, korzen);//Dodanie s³ówek do drzewa.
	}
	return true;
}

string przetlumaczAng(string doPrzetlumaczenia, wezel* korzen) {
	if (korzen) {
		if (korzen->angSlowko == doPrzetlumaczenia)
			return korzen->polSlowko;
		else {
			if (doPrzetlumaczenia < korzen->angSlowko)
				return przetlumaczAng(doPrzetlumaczenia, korzen->lewyAng);
			else
				return przetlumaczAng(doPrzetlumaczenia, korzen->prawyAng);
		}
	}
	else
		return "[" + doPrzetlumaczenia + "]";
}

string przetlumaczPol(string doPrzetlumaczenia, wezel* korzen) {
	if (korzen) {
		if (korzen->polSlowko == doPrzetlumaczenia)
			return korzen->angSlowko;
		else {
			if (doPrzetlumaczenia < korzen->polSlowko)
				return przetlumaczPol(doPrzetlumaczenia, korzen->lewyPol);
			else
				return przetlumaczPol(doPrzetlumaczenia, korzen->prawyPol);
		}
	}
	else
		return "[" + doPrzetlumaczenia + "]";

}

bool zapisWyniku(string nazwaPliku, string przetlumaczone) {

	ofstream plik;
	plik.open(nazwaPliku);
	if (plik) {//Je¿eli plik otwarty pomyœlnie, zapisanie do niego przet³umaczonego tekstu.
		plik << przetlumaczone;
		plik.close();
		return true;
	}
	else
		cout << "Plik nie utworzyl sie";
	return false;
}



string wczytajTekstWejsciowyPol(string nazwaPliku, wezel* korzen, string& przetlumaczone) {
	string PLdotlumaczenia = "";
	string buffer;
	ifstream plik(nazwaPliku);
	while (plik >> buffer) {
		
		bool wystapilaKropka = 0;
		bool zmianaWielkosciLit = 0;
		PLdotlumaczenia += buffer + " ";
		for (int i = 0; i < buffer.length(); i++) {
			if (buffer[i] >='A' && buffer[i] < 91) {//sprawdzenie czy s¹ wielkie litery, jeœli tak to zamiana ich na ma³e korzystaj¹c z wartoœci w tablicy ASCII
				buffer[i] = (buffer[i] + 32);
				zmianaWielkosciLit = 1;
			}
			if (buffer[i] == 46) {//sprawdzenie czy s¹ kropki, jeœli tak to usuniêcie ich
				buffer.erase(i, 1);
				wystapilaKropka = 1;
			}
		}

		if (zmianaWielkosciLit) {//Jeœli wyst¹pi³a zmiana du¿ej litery na ma³¹, z powrotem zamieniana jest na du¿¹.
			string temp = przetlumaczPol(buffer, korzen);
			temp[0] = (temp[0] - 32);
			przetlumaczone += temp + " ";
		}
		else {
			if (wystapilaKropka)//Jeœli wyst¹pi³a kropka (by³a ona usuwana),to jest przywrócona.
				przetlumaczone += przetlumaczPol(buffer, korzen) + ". ";
			else
				przetlumaczone += przetlumaczPol(buffer, korzen) + " ";
		}
	}
	return przetlumaczone;

}
string wczytajTekstWejsciowyAng(string nazwaPliku, wezel* korzen, string& przetlumaczone) {
	string Angdotlumaczenia = "";
	string buffer;
	ifstream plik(nazwaPliku);
	while (plik >> buffer) {
		bool zmianaWielkosciLit = 0;
		bool wystapilaKropka = 0;
		Angdotlumaczenia += buffer + " ";
		for (int i = 0; i < buffer.length(); i++) {//sprawdzenie czy s¹ wielkie litery, jeœli tak to zamiana ich na ma³e korzystaj¹c z wartosci w tablicy ASCII.
			if (buffer[i] > 64 && buffer[i] < 91) {
				buffer[i] = (buffer[i] + 32);
				zmianaWielkosciLit = 1;
			}
			if (buffer[i] == 46) {//sprawdzenie czy s¹ kropki, jeœli tak to usuniêcie ich.
				buffer.erase(i, 1);
				wystapilaKropka = 1;
			}
		}
		if (zmianaWielkosciLit) {//Jeœli wyst¹pi³a zmiana du¿ej litery na ma³¹, z powrotem zamieniana jest na du¿¹.
			string temp = przetlumaczAng(buffer, korzen);
			temp[0] = (temp[0] - 32);
			przetlumaczone += temp + " ";
		}
		else {
			if (wystapilaKropka)//Jeœli wyst¹pi³a kropka (by³a ona usuwana),to jest przywrócona.
				przetlumaczone += przetlumaczAng(buffer, korzen) + ". ";
			else
				przetlumaczone += przetlumaczAng(buffer, korzen) + " ";
		}

	}
	return przetlumaczone;
}