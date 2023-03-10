#include <iostream>
#include "../../include/functions.hpp"

using namespace std;

vector<int> ReceptorControleErroCRC(vector<int> *bits)
{
	cout << "Controle CRC - Recepcao" << endl;

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

	cout << "Final:" << endl;
	for(int i = 0; i < bits->size(); i++)
		cout << (*bits)[i];
	cout << endl;

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

vector<int> CamadaEnlaceReceptoraErroBitParidadePar(vector<int> *bits) {

	cout << "Pariedade Par - Recepcao" << endl;

	vector<int> msg_original;
	int tamanho_msg = bits->size() - 1;

	msg_original.insert(msg_original.begin(), bits->begin(), bits->begin() + tamanho_msg);

	bool paridade = false;

	for (int i = 0; i < tamanho_msg; i++)
		if ((*bits)[i] == 1)
			paridade = !paridade;

	if ((*bits)[tamanho_msg] != int(paridade))
		cout << "Mensagem corrompida" << endl;
	else
		cout << "Mensagem integra" << endl;

	cout << "Quadro:" << endl;
	for (int i = 0; i <  bits->size(); i++)
		cout << (*bits)[i];
	cout << endl;

	return msg_original;
}

vector<int> CamadaEnlaceReceptoraErroBitParidadeImpar(vector<int> *bits) {

	cout << "Pariedade Impar - Recepcao" << endl;

	vector<int> msg_original;
	int tamanho_msg = bits->size() - 1;

	msg_original.insert(msg_original.begin(), bits->begin(), bits->begin() + tamanho_msg);

	bool paridade = true;

	for (int i = 0; i < tamanho_msg; i++)
		if ((*bits)[i] == 1)
			paridade = !paridade;

	if ((*bits)[tamanho_msg] != int(paridade))
		cout << "Mensagem corrompida" << endl;
	else
		cout << "Mensagem integra" << endl;


	cout << "Quadro:" << endl;
	for (int i = 0; i <  bits->size(); i++)
		cout << (*bits)[i];
	cout << endl;

	return msg_original;
}

void CamadaEnlaceReceptora(vector<int> bits)
{
	// Trocar de acordo com o metodo desejado
	int tipoDeControleDeErro = 2;

	//A mensagem recebida pode estar corrompida ou nao
	vector<int> msg_recebida;

	switch(tipoDeControleDeErro){

		case 0:
			msg_recebida = CamadaEnlaceReceptoraErroBitParidadePar(&bits);
			break;
		case 1:
			msg_recebida = CamadaEnlaceReceptoraErroBitParidadeImpar(&bits);
			break;
		case 2:
			msg_recebida = ReceptorControleErroCRC(&bits);
			break;

	}


	CamadaAplicacaoReceptora(msg_recebida);


}
