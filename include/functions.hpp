#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <vector>

//Transmissor
void AplicacaoTransmissora();
void CamadaAplicacaoTransmissora(std::string msg);
void CamadaEnlaceTransmissora(std::vector<int> bits);
void CamadaEnlaceTransmissoraErroBitParidadePar(std::vector<int> *bits);
void CamadaEnlaceTransmissoraErroBitParidadeImpar(std::vector<int> *bits);

//Meio de Comunicacao
void MeioComunicacao(std::vector<int>);

//Receptor
void CamadaEnlaceReceptora(std::vector<int> bits);

#endif

