#include <iostream>
#include <string>
#include <bits/stdc++.h>
#include "../../include/functions.hpp"

using namespace std;

void CamadaAplicacaoReceptora(vector<int> bits)
{
	string msg ="";
	char ch;
	unsigned long ich;
	cout << "Mensagem convertida em string: ";
	for(int i = 0; i < bits.size()/8; i++){
		bitset<8> b;
		for(int j = 0; j < 8; j++)
		{
			b[j]=bits[8*i+j];
			cout << b[j];
		}
		ich = b.to_ulong(); 
		ch = static_cast<char>( ich );
		msg = msg + (char) ch;
	}

	cout << endl;

	AplicacaoReceptora(msg);

}
