#include <iostream>
#include <string>
#include <vector>
#include "functions.h"

using namespace std;

int main()
{
	string msg = AplicacaoTransmissora();
	cout << msg << endl;
	vector<int> v = CamadaAplicacaoTransmissora(msg);

	for(int i = 0; i < v.size(); i++)
		cout << v[i];
}

