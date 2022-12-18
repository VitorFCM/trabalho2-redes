#include <iostream>
#include "../../include/functions.hpp"

using namespace std;

vector<int> ReceptorControleErroCRC(vector<int> *bits)
{
	//Os zeros do inicio do polinomio CRC-32 foram removidos
	int polinomio[27] = {1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 1};

	//A mensagem original, estando ela corrompida ou nao, esta antes da insercao dos zeros
	vector<int> msg_original;
	msg_original.insert(msg_original.begin(), bits->begin(), bits->end() - 31);
	//copia do comeco do vetor bits ate o final menos os 31 bits que foram inseridos na enlace
	//do transmissor

	//Realiza a divisao do que foi recebido no vetor bits pelo polinomio CRC-32
	for (int i = 0; i < bits->size() - 31; i++){
		if ((*bits)[i] == 1)
		{
			for (int j = 0; j < 27; j++)
			{
				(*bits)[j + i] ^= polinomio[j];
			}
		}
	}

	//Se algum dos ultimos 31 bits for diferente de zero, significa que a mensagem esta corrompida
	for(int i = bits->size() - 31; i < bits->size(); i++)
	{
		if((*bits)[i] == 1)
		{
			cout << "Mensagem corrompida" << endl;
			//Mesmo com a mensagem estando corrompida ainda sera mostrado ao usuario o que chegou
			return msg_original;

		}
	}

	cout << "Mensagem integra" << endl;
	return msg_original;
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
}


