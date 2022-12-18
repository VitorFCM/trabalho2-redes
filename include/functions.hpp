#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <vector>

void AplicacaoTransmissora();
void CamadaAplicacaoTransmissora(std::string msg);
void CamadaEnlaceTransmissora(std::vector<int> bits);
void CamadaEnlaceTransmissoraErroBitParidadePar(std::vector<int> *bits);
void CamadaEnlaceTransmissoraErroBitParidadeImpar(std::vector<int> *bits); 

#endif

