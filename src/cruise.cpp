/*
 * cruise.cpp
 *
 *  Created on: 18/10/2017
 *      Author: joao
 */

#include "cruise.h"

using namespace std;

Fornecedor::Fornecedor(string nome, unsigned int nif, string morada):nome(nome), nif(nif), morada(morada){}

void Fornecedor::addOferta(Oferta & oferta){
	this->ofertas.push_back(oferta);
}


Cliente::Cliente(string nome): nome(nome), pontos(0){}

void Cliente::addPontos(unsigned int pontos){
	this->pontos += pontos;
}






