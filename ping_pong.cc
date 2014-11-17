#include <iostream>
#include <string>
#include <algorithm>
// #include <stdlib.h>
// #include <stdio.h>

using namespace std;

typedef struct {
	string hraci;
	string *hraci_array;
	int pocet_hracov;
}TStruct;

typedef struct {
	string meno;
	int body;
}TStruct_hrac;

int nacitanie_hracov(int argc, char const *argv[], TStruct &params);

int main(int argc, char const *argv[]) {

	TStruct params;
	TStruct_hrac hrac;

	nacitanie_hracov(argc, argv, params);

	return 0;
}

/******************************FUNKCIE*********************************/

// spracovanie argumentu mena hracov
int nacitanie_hracov(int argc, char const *argv[], TStruct &params) {
	//zistim ci je zadany len jeden argument 
	if (argc > 2) {
		cerr << "Bad arguments" << endl; //chybove hlasenie
		cout << "Zadaj mena hracov oddelenych ciarkou" << endl;
		cout << "Example: ./ping_pong hrac1,hrac2,hrac3" << endl;
		exit(1);//ukoncenie programu s navratovou hodnotou 1
	}
	if (argc < 1) {
		cerr << "Neboli zadane ziadne mena hracov" << endl; //chybove hlasenie
		cout << "Zadaj mena hracov oddelenych ciarkou" << endl;
		cout << "Example: ./ping_pong hrac1,hrac2,hrac3" << endl;
		exit(1);//ukoncenie programu s navratovou hodnotou 1
	}

	params.hraci = argv[1];
	params.pocet_hracov = (count(params.hraci.begin(), params.hraci.end(), ',')) + 1;
	//vytvorenie pola o velkosti pocet_hracov
	params.hraci_array = new string[params.pocet_hracov];
	//cyklus pre naplnenie pola s menami hracov
	for (int i = 0; i < params.pocet_hracov; ++i) {
		int index = params.hraci.find_first_of(","); // najde index prvej ciarky
		params.hraci_array[i] = params.hraci.substr(0, index); // naplni pole menom hraca po prvu ciarku
  		params.hraci.erase(0, index+1); // zmensi argument o hraca ,ktroy uz je v poli
  		cout << params.hraci_array[i] << endl;
	}
	if (params.pocet_hracov > 5) {
		cerr << "Privela hracov pre tuto verziu programu" << endl; //chybove hlasenie
		exit(1);//ukoncenie programu s navratovou hodnotou 1
	}
	return 0;
}
	



	// string meno;
	// cin >> meno;
	// cout << meno << endl;