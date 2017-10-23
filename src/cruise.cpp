/*
 * cruise.cpp
 *
 *  Created on: 18/10/2017
 *      Author: joao
 */

#include "cruise.h"

using namespace std;

////  Métodos da classe Empresa ////

const std::vector<Fornecedor*> & Empresa::getFornecedores(){
	return this->_fornecedores;
}

const std::vector<Cliente*> & Empresa::getClientes(){
	return this->_clientes;
}

Empresa & Empresa::addFornecedores(Fornecedor& f){
	this->_fornecedores.push_back(&f);
	return *this;
}

Empresa & Empresa::addClientes(Cliente& c){

	return *this;
}


//// Métodos da classe Fornecedor ////
//ola


Fornecedor::Fornecedor(string nome, unsigned int nif, string morada):nome(nome), nif(nif), morada(morada){}

void Fornecedor::addOferta(Oferta & oferta){
	this->ofertas.push_back(oferta);
}

const vector<Oferta> & Fornecedor::getOfertas(){
	return this->ofertas;
}

//// Métodos da classe Cliente ////

Cliente::Cliente(string nome): nome(nome), pontos(0){}

void Cliente::addPontos(unsigned int pontos){
	this->pontos += pontos;
}

//// Métodos da classe Oferta ////

const std::vector<std::string> & Oferta::getDestinos(){
	return this->destinos;
}




