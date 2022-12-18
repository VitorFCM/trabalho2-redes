#include <iostream>
#include "../../include/functions.hpp"

using namespace std;

void TransmissorControleErroCRC(vector<int>* bits) {

	//CRC-32

	int polinomio[32] = {0, 0, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 1};

	vector<int> zeros(31, 0);

	vector<int> msg_original = *bits;

	bits->insert(bits->end(), zeros.begin(), zeros.end());

	for (int i = 0; i < msg_original.size(); i++){
		if ((*bits)[i] == 1)
		{
			for (int j = 0; j < 32; j++)
			{
				(*bits)[j + i] ^= polinomio[j];
			}
		}
	}
	/*
	   for(int i = 0; i < msg_original.size(); i++){
	   cout << msg_original[i];
	   (*bits)[i] = msg_original[i];
	   }

	   cout << endl;
	   */
}

void CamadaEnlaceTransmissora(vector<int> bits)
{

	//Controle de erro
	int tipoDeControleDeErro = 2;


	switch(tipoDeControleDeErro){

		case 0:
			cout << "bit pariedade par" << endl;
			break;
		case 1:
			cout << "bit pariedade impar" << endl;
			break;
		case 2:

			cout << "teste CRC" << endl;
			TransmissorControleErroCRC(&bits);
			break;

	}


	MeioComunicacao(bits);
	//Fim do controle de erro

	/*
	   for(int i = 0; i < bits.size(); i++)
	   {
	   cout << bits[i];
	   }*/
}

