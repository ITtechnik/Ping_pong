#include <iostream>
#include <string>
#include <algorithm>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//#include <math.h>

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

/***********************inicializacia funkcii******************************/

int nacitanie_hracov(int argc, char const *argv[], TStruct &params);
int podanie(int &kto_podava, char bod[1], TStruct params);
int change_podanie(int &vymena_podania, int &kto_podava);

/***********************koniec inicializacie funkcii***********************/

/********************************* main ***********************************/
int main(int argc, char const *argv[]) {

	TStruct params;
	// TStruct_hrac array[5];
	// array[0].meno = "kokoti";
	// array[0].body = 5;

	// cout << array[0].meno << endl;
	// cout << array[0].body << endl;


	nacitanie_hracov(argc, argv, params);
	cout << "----------------------------------------------------------" << endl;
	cout << "START GAME" << endl;
	cout << endl;
	cout << params.hraci_array[0] << " VS " << params.hraci_array[1] << endl;
	char bod[1];
	int count_hrac1 = 0;
	int count_hrac2 = 0;
	int kto_podava = 2;
	int vymena_podania = 0;
	cout << "Hra o podanie" << endl;
	podanie(kto_podava, bod, params);

	for (int i = 0; i < 70; ++i) {
		scanf ("%s",bod);
		if (strcmp(bod, "o") == 0) {
			count_hrac1++;
			change_podanie(vymena_podania, kto_podava);
			cout << count_hrac1 << " : " << count_hrac2 << " podava: "<< params.hraci_array[kto_podava] << endl;
		}
		else if (strcmp(bod, "p") == 0) {
			count_hrac2++;
			change_podanie(vymena_podania, kto_podava);
			cout << count_hrac1 << " : " << count_hrac2 << " podava: "<< params.hraci_array[kto_podava] << endl;
		}
		
		if (count_hrac2 == 11 || count_hrac1 == 11) {
			if (abs(count_hrac2 - count_hrac1) >= 2) {
				if (count_hrac1 > count_hrac2) {
					cout << "Vyhral " << params.hraci_array[0] <<endl;
					break;
				}
				else{
					cout << "Vyhral " << params.hraci_array[1] << endl;
					break;
				}
			}
		}
	}

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
  		//cout << params.hraci_array[i] << endl;
	}
	if (params.pocet_hracov > 2) {
		cerr << "Privela hracov pre tuto verziu programu" << endl; //chybove hlasenie
		exit(1);//ukoncenie programu s navratovou hodnotou 1
	}
	return 0;
}
int podanie(int &kto_podava, char bod[1], TStruct params) {

	scanf ("%s",bod);
	if (strcmp(bod, "o") == 0) {
		kto_podava = 0;
	cout << "0 : 0" << " podava: "<< params.hraci_array[0] <<  endl;
	}
	else if (strcmp(bod, "p") == 0) {
		kto_podava = 1;
		cout << "0 : 0" << " podava: "<< params.hraci_array[1] << endl;
	}
	// else
	// 	cout << "Stlacil si nieco zle" << endl;
	return 0;
}
int change_podanie(int &vymena_podania, int &kto_podava){
	
	vymena_podania++;
	if (vymena_podania == 2) {
		if (kto_podava == 0) {
			kto_podava = 1;
		}
		else {
			kto_podava = 0;
		}
			vymena_podania = 0;
	}
	return 0;
}

	// string meno;
	// cin >> meno;
	// cout << meno << endl;