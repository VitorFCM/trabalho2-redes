#include <iostream>
#include <string>
#include<bits/stdc++.h>
#include "../include/functions.hpp"

using namespace std;

void CamadaAplicacaoReceptora(vector<int> bits)
{
	string msg ="";
	cout << "Mensagem convertida em string: ";
	for(int i = 0; i < bits.size()/8; i++){
		bitset<8> b;
		for(int j = 0; j < 8; j++)
		{
			b[j]=bits[8*i+j];
			cout << b[j];
		}
		msg= msg + b.to_string();
	}
	
	cout << endl;

	CamadaEnlaceReceptora(msg);

}
