#include <iostream>
#include "../../include/functions.hpp"

using namespace std;

void TransmissoraControleErroCRC(vector<int>* bits) {

	//Os zeros do inicio do polinomio CRC-32 foram removidos
	int polinomio[27] = {1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 1};

	//Realiza uma copia da mensagem original antes da divisao
	vector<int> msg_original = *bits;

	//Criando vetor com 32 - 1 zeros
	vector<int> zeros(31, 0);

	//Adicionando 31 zeros no final da cadeia de bits da mensagem
	bits->insert(bits->end(), zeros.begin(), zeros.end());

	//Divisao da mensagem original pelo polinomio CRC-23
	for (int i = 0; i < msg_original.size(); i++){
		if ((*bits)[i] == 1)
		{
			for (int j = 0; j < 27; j++)
			{
				(*bits)[j + i] ^= polinomio[j];
			}
		}
	}

	//A mensagem original eh copiada para o inicio do vetor bits
	for(int i = 0; i < msg_original.size(); i++)
		(*bits)[i] = msg_original[i];

}

void CamadaEnlaceTransmissoraErroBitParidadePar(vector<int> *bits) {

	cout << endl
		<< "---- CONTROLE PARIDADE PAR ----" << endl;

	int tamanho_msg = bits->size() + 1;
	bool paridade = false;

	cout << endl
		<< ">> QUADRO: ";

	for (int i = 0; i < bits->size(); i++)
		if ((*bits)[i] == 1)
			paridade = !paridade;

	bits->push_back(paridade);

	for (int i = 0; i < tamanho_msg; i++)
		cout << (*bits)[i];

	cout << endl;
}

void CamadaEnlaceTransmissoraErroBitParidadeImpar(vector<int> *bits) {

	cout << endl
		<< "---- CONTROLE PARIDADE IMPAR ----" << endl;

	int tamanho_msg = bits->size() + 1;
	bool paridade = true;

	cout << endl
		<< ">> QUADRO: ";

	for (int i = 0; i < bits->size(); i++)
		if ((*bits)[i] == 1)
			paridade = !paridade;

	bits->push_back(paridade);

	for (int i = 0; i < tamanho_msg; i++)
		cout << (*bits)[i];

	cout << endl;
}

void CamadaEnlaceTransmissora(vector<int> bits) {
	int tipoDeControleDeErro = 0;
	switch(tipoDeControleDeErro) {

		case 0:
			cout << "bit pariedade par" << endl;
			CamadaEnlaceTransmissoraErroBitParidadePar(&bits);
			break;
		case 1:
			cout << "bit pariedade impar" << endl;
			CamadaEnlaceTransmissoraErroBitParidadeImpar(&bits);
			break;
		case 2:
			cout << "teste CRC" << endl;
			TransmissoraControleErroCRC(&bits);
			break;

	}

	MeioComunicacao(bits);


}
