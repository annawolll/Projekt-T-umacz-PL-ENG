//Projekt PPK plik projekt.h
//Anna Wo³oszyn

#ifndef PROJEKT_H
#define PROJEKT_H

#include <string>
#include <fstream>
#include <iostream>

using namespace std;

/**Struktura reprezentuj¹ca drzewo binarne */
struct wezel {
	string polSlowko;///< wartosc danego wezla "drzewa polskiego" 
	string angSlowko;///<wartoœæ danego wezla "drzewa angielskiego"
	wezel* lewyAng;///<Lewa ga³¹Ÿ "drzewa angielskiego", wartoœci mniejsze od angSlowko
	wezel* prawyAng;///<Prawa ga³¹Ÿ "drzewa angielskiego", wartoœci wiêksze lub równe angSlowko
	wezel* lewyPol;///<Lewa ga³¹Ÿ "drzewa polskiego", wartoœci mniejsze od polSlowko
	wezel* prawyPol;///<Prawa ga³¹Ÿ "drzewa polskiego", wartoœci wiêksze lub równe polSlowko
};

/**Funkcja dodaj¹ca s³ówka do "polskiej czêœci" drzewa.
Jest typu bool aby zapobiec dwukrotnemu dodaniu tego samego elementu przy dodawaniu do pustego drzewa.
* @param korzen Rozpatrywane drzewo.
* @param doDodania Wêze³ do dodania do tej czêœci drzewa.
*/
bool dodajDoDrzewaPol(wezel*& korzen, wezel* doDodania);

/**Funkcja dodaj¹ca s³ówka do "angielskiej czêœci" drzewa.
* @param korzen Rozpatrywane drzewo.
* @param doDodania Wêze³ do dodania do tej czêœci drzewa.
*/
void dodajDoDrzewaAng(wezel*& korzen, wezel* doDodania);

/**Funkcja dodaj¹ca s³ówka do drzewa z podzieleniem na polsk¹ i angielsk¹ "czêœæ" drzewa.
Jeœli odbywa siê dodanie do pustego drzewa (pierwszy zestaw s³ówek) powstaje element wspólny dla obu drzew.
* @param polskie S³ówko polskie do dodania.
* @param angielskie S³ówko angielskie do dodania.
* @param korzen Rozpatrywane drzewo.
*/
void dodajDoDrzewa(string polskie, string angielskie, wezel*& korzen);

/**Funkcja usuwaj¹ca drzewo.
* @param korzen Rozpatrywane drzewo.
*/
void usunDrzewo(wezel*& korzen);

/**Funkcja wczytuj¹ca z pliku nazwaPliku s³ówko polskie i angielskie
i dodaj¹ca je do drzewa.
* @param korzen Rozpatrywane drzewo.
* @param nazwaPliku Nazwa pliku.
* @return True Poprawne wczytanie pliku, False je¿eli niepoprawne.
*/
bool wczytajZPliku(string nazwaPliku, wezel*& korzen);

/**Funkcja t³umacz¹ca s³ówko angielskie na polskie
przez szukanie w drzewie wêz³a z podanym s³ówkiem angielskim.
* @param doPrzetlumaczenia S³ówko angielskie do przet³umaczenia.
* @korzen Rozpatrywane drzewo.
* @return Przet³umaczenie na s³ówko polskie,
a jeœli nie znaleziono takiego wêz³a w drzewie to podane s³ówko angielskie w nawiasach kwadratowych.
*/
string przetlumaczAng(string doPrzetlumaczenia, wezel* korzen);

/**Funkcja t³umacz¹ca s³ówko polskie na angielskie
przez szukanie w drzewie wêz³a z podanym s³ówkiem polskim.
* @param doPrzetlumaczenia S³ówko polskie do przet³umaczenia.
* @korzen Rozpatrywane drzewo.
* @return Przet³umaczenie na s³ówko angielskie,
a jeœli nie znaleziono takiego wêz³a w drzewie to podane s³ówko polskie w nawiasach kwadratowych.
*/
string przetlumaczPol(string doPrzetlumaczenia, wezel* korzen);

/**Funkcja zapisuj¹ca do pliku o podanej nazwie przet³umaczony tekst.
* @param nazwaPliku Nazwa pliku.
* @param przetlumaczone Przet³umaczony tekst.
* @return True Poprawne otworzenie i zapisanie tekstu do pliku, False jeœli niepoprawne.
*/
bool zapisWyniku(string nazwaPliku, string przetlumaczone);

/**Funkcja wczytuj¹ca tekst w jêz. polskim do przet³umaczenia
i t³umacz¹ca go s³owo po s³owie.
* @param nazwaPliku Nazwa Pliku.
* @param korzen Rozpatrywane drzewo.
* @param przetlumaczone Przet³umaczony tekst w jêzyku angielskim.
* @return Przet³umaczony tekst w jêzyku angielskim.
*/
string wczytajTekstWejsciowyPol(string nazwaPliku, wezel* korzen, string& przetlumaczone);

/**Funkcja wczytuj¹ca tekst w jêz. angielskim do przet³umaczenia
i t³umacz¹ca go s³owo po s³owie.
* @param nazwaPliku Nazwa Pliku.
* @param korzen Rozpatrywane drzewo.
* @param przetlumaczone Przet³umaczony tekst w jêzyku polskim.
* @return Przet³umaczony tekst w jêzyku polskim.
*/
string wczytajTekstWejsciowyAng(string nazwaPliku, wezel* korzen, string& przetlumaczone);

#endif /* PROJEKT_H */