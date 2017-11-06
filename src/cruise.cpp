
#include "cruise.h"

using namespace std;


                      /////                                            /////
                     /////               CRUISE . CPP                 /////
                    /////                                            /////

////  Metodos da classe Empresa ////

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


//// Metodos da classe Fornecedor ////


Fornecedor::Fornecedor(string nome, unsigned int nif, string morada):nome(nome), nif(nif), morada(morada){}

void Fornecedor::addOferta(Oferta & oferta){
	this->ofertas.push_back(oferta);
}

const vector<Oferta> & Fornecedor::getOfertas(){
	return this->ofertas;
}

//// Metodos da classe Cliente ////

Cliente::Cliente(string nome): nome(nome), pontos(0){}

void Cliente::addPontos(unsigned int pontos){
	this->pontos += pontos;
}

//// Metodos da classe Oferta ////

const std::vector<std::string> & Oferta::getDestinos(){
	return this->destinos;
}




