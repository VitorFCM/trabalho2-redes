#include <iostream>
#include <time.h>
#include "../include/functions.hpp"

using namespace std;

void MeioComunicacao(vector<int> bits)
{
	srand (time(NULL));

	int probabilidadeDeErro = 0;
	//Deve ser alterado entre 0 e 100
	//Caso seja 100 todos os bits serao invertidos
	//Caso seja 0 nenhum bit sera invertido

	vector<int> bits_corrompidos;

	for(int i = 0; i < bits.size(); i++)
	{
		if(rand()%100 < probabilidadeDeErro){
			int bit = (bits[i] == 0) ? 1 : 0;
			bits_corrompidos.push_back(bit);

		}else{
			bits_corrompidos.push_back(bits[i]);
		}
	}

	CamadaEnlaceReceptora(bits_corrompidos);
}

