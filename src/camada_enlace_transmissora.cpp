#include <iostream>
#include "../include/functions.hpp"

using namespace std;

void CamadaEnlaceTransmissora(vector<int> bits) {
	int tipoDeControleDeErro = 0;

	switch(tipoDeControleDeErro){
		case 0:
			cout << "bit pariedade par" << endl;
			break;
		case 1:
			cout << "bit pariedade impar" << endl;
			break;
		case 2:

			cout << "teste CRC" << endl;
			break;

	}
}

