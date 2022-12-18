#include <iostream>
#include "../../include/functions.hpp"

using namespace std;

void TransmissoraControleErroCRC(vector<int>* bits) {

	//CRC-32

	int polinomio[27] = {1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 1};

	vector<int> final_mensagem(31, 0);

	int tamanho_msg = bits->size();

	bits->insert(bits->end(), final_mensagem.begin(), final_mensagem.end());

	for (int i = 0; i < tamanho_msg; i++){
		if ((*bits)[i] == 1)
		{
			//Faz o XOR com todos os elementos do polinomio
			for (int j = 0; j < 27; j++)
			{
				(*bits)[j + i] ^= polinomio[j];
			}
		}
	}

}

void CamadaEnlaceTransmissoraErroBitParidadePar(vector<int> *bits) {

	  int tamanho_msg = bits->size() + 1; 
	  bool paridade = false;

	  // Paridade do dado 
	  for (int i = 0; i < bits->size(); i++) 
		    if ((*bits)[i] == 1) 
		    	paridade = !paridade;

	  bits->push_back(paridade);

	  for (int i = 0; i < tamanho_msg; i++)
	  	cout << (*bits)[i];

	  cout << endl;
}

void CamadaEnlaceTransmissoraErroBitParidadeImpar(vector<int> *bits) {

	  int tamanho_msg = bits->size() + 1; 
	  bool paridade = true;

	  // Paridade do dado 
	  for (int i = 0; i < bits->size(); i++) 
		    if ((*bits)[i] == 1) 
		    	paridade = !paridade;

	  bits->push_back(paridade);

	  for (int i = 0; i < tamanho_msg; i++)
	  	cout << (*bits)[i];

	  cout << endl;
}

void CamadaEnlaceTransmissora(vector<int> bits) {
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
			TransmissoraControleErroCRC(&bits);
			break;

	}

	for(int i = 0; i < bits.size(); i++)
	{
		cout << bits[i];
	}
}

