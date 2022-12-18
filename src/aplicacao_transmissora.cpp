#include <iostream>
#include <string>
#include "../include/functions.hpp"

using namespace std;

void AplicacaoTransmissora()
{
	string msg;
	cout << "Digite uma mensagem: ";
	cin >> msg;

	CamadaAplicacaoTransmissora(msg);
}

