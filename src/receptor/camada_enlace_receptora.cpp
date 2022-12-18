#include <iostream>
#include "../../include/functions.hpp"

using namespace std;

void ReceptorControleErroCRC(vector<int> *bits)
{
	//CRC-32

	int polinomio[32] = {0, 0, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 1};


	for (int i = 0; i < bits->size() - 31; i++){
		if ((*bits)[i] == 1)
		{
			for (int j = 0; j < 32; j++)
			{
				(*bits)[j + i] ^= polinomio[j];
			}
		}
	}

	for(int i = 0; i < bits->size(); i++)
		cout << (*bits)[i];


	for(int i = bits->size() - 31; i < bits->size(); i++)
	{
		if((*bits)[i] == 1)
		{
			cout << "Mensagem corrompida" << endl;
			return;

		}
	}

	cout << "Mensagem integra" << endl;
}

void CamadaEnlaceReceptora(vector<int> bits)
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
			ReceptorControleErroCRC(&bits);
			break;

	}
	//Fim do controle de erro

	/*
	   for(int i = 0; i < bits.size(); i++)
	   {
	   cout << bits[i];
	   }*/
}


