//Projekt PPK plik projekt.h
//Anna Wo�oszyn

#ifndef PROJEKT_H
#define PROJEKT_H

#include <string>
#include <fstream>
#include <iostream>

using namespace std;

/**Struktura reprezentuj�ca drzewo binarne */
struct wezel {
	string polSlowko;///< wartosc danego wezla "drzewa polskiego" 
	string angSlowko;///<warto�� danego wezla "drzewa angielskiego"
	wezel* lewyAng;///<Lewa ga��� "drzewa angielskiego", warto�ci mniejsze od angSlowko
	wezel* prawyAng;///<Prawa ga��� "drzewa angielskiego", warto�ci wi�ksze lub r�wne angSlowko
	wezel* lewyPol;///<Lewa ga��� "drzewa polskiego", warto�ci mniejsze od polSlowko
	wezel* prawyPol;///<Prawa ga��� "drzewa polskiego", warto�ci wi�ksze lub r�wne polSlowko
};

/**Funkcja dodaj�ca s��wka do "polskiej cz�ci" drzewa.
Jest typu bool aby zapobiec dwukrotnemu dodaniu tego samego elementu przy dodawaniu do pustego drzewa.
* @param korzen Rozpatrywane drzewo.
* @param doDodania W�ze� do dodania do tej cz�ci drzewa.
*/
bool dodajDoDrzewaPol(wezel*& korzen, wezel* doDodania);

/**Funkcja dodaj�ca s��wka do "angielskiej cz�ci" drzewa.
* @param korzen Rozpatrywane drzewo.
* @param doDodania W�ze� do dodania do tej cz�ci drzewa.
*/
void dodajDoDrzewaAng(wezel*& korzen, wezel* doDodania);

/**Funkcja dodaj�ca s��wka do drzewa z podzieleniem na polsk� i angielsk� "cz��" drzewa.
Je�li odbywa si� dodanie do pustego drzewa (pierwszy zestaw s��wek) powstaje element wsp�lny dla obu drzew.
* @param polskie S��wko polskie do dodania.
* @param angielskie S��wko angielskie do dodania.
* @param korzen Rozpatrywane drzewo.
*/
void dodajDoDrzewa(string polskie, string angielskie, wezel*& korzen);

/**Funkcja usuwaj�ca drzewo.
* @param korzen Rozpatrywane drzewo.
*/
void usunDrzewo(wezel*& korzen);

/**Funkcja wczytuj�ca z pliku nazwaPliku s��wko polskie i angielskie
i dodaj�ca je do drzewa.
* @param korzen Rozpatrywane drzewo.
* @param nazwaPliku Nazwa pliku.
* @return True Poprawne wczytanie pliku, False je�eli niepoprawne.
*/
bool wczytajZPliku(string nazwaPliku, wezel*& korzen);

/**Funkcja t�umacz�ca s��wko angielskie na polskie
przez szukanie w drzewie w�z�a z podanym s��wkiem angielskim.
* @param doPrzetlumaczenia S��wko angielskie do przet�umaczenia.
* @korzen Rozpatrywane drzewo.
* @return Przet�umaczenie na s��wko polskie,
a je�li nie znaleziono takiego w�z�a w drzewie to podane s��wko angielskie w nawiasach kwadratowych.
*/
string przetlumaczAng(string doPrzetlumaczenia, wezel* korzen);

/**Funkcja t�umacz�ca s��wko polskie na angielskie
przez szukanie w drzewie w�z�a z podanym s��wkiem polskim.
* @param doPrzetlumaczenia S��wko polskie do przet�umaczenia.
* @korzen Rozpatrywane drzewo.
* @return Przet�umaczenie na s��wko angielskie,
a je�li nie znaleziono takiego w�z�a w drzewie to podane s��wko polskie w nawiasach kwadratowych.
*/
string przetlumaczPol(string doPrzetlumaczenia, wezel* korzen);

/**Funkcja zapisuj�ca do pliku o podanej nazwie przet�umaczony tekst.
* @param nazwaPliku Nazwa pliku.
* @param przetlumaczone Przet�umaczony tekst.
* @return True Poprawne otworzenie i zapisanie tekstu do pliku, False je�li niepoprawne.
*/
bool zapisWyniku(string nazwaPliku, string przetlumaczone);

/**Funkcja wczytuj�ca tekst w j�z. polskim do przet�umaczenia
i t�umacz�ca go s�owo po s�owie.
* @param nazwaPliku Nazwa Pliku.
* @param korzen Rozpatrywane drzewo.
* @param przetlumaczone Przet�umaczony tekst w j�zyku angielskim.
* @return Przet�umaczony tekst w j�zyku angielskim.
*/
string wczytajTekstWejsciowyPol(string nazwaPliku, wezel* korzen, string& przetlumaczone);

/**Funkcja wczytuj�ca tekst w j�z. angielskim do przet�umaczenia
i t�umacz�ca go s�owo po s�owie.
* @param nazwaPliku Nazwa Pliku.
* @param korzen Rozpatrywane drzewo.
* @param przetlumaczone Przet�umaczony tekst w j�zyku polskim.
* @return Przet�umaczony tekst w j�zyku polskim.
*/
string wczytajTekstWejsciowyAng(string nazwaPliku, wezel* korzen, string& przetlumaczone);

#endif /* PROJEKT_H */