
#include <fstream>
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

void Empresa::save(){
	for(auto &fornecedor: this->_fornecedores){
		fornecedor->save();
	}
	for(auto &cliente: this->_clientes){
		cliente->save();
	}
}

//// Metodos da classe Fornecedor ////

Fornecedor::Fornecedor(string nome, unsigned int nif, string morada):nome(nome), nif(nif), morada(morada){}

void Fornecedor::addOferta(Oferta & oferta){
	this->ofertas.push_back(oferta);
}

const vector<Oferta> & Fornecedor::getOfertas(){
	return this->ofertas;
}


void Fornecedor::save(){
	ofstream file("fornecedores.txt", ofstream::app);
		if(file.is_open()){
			file << this->nome << endl << this->nif << endl << this->morada;
		}
}

//// Metodos da classe Reserva ////

Reserva::Reserva(std::string nome_oferta, Oferta * oferta, string nome_cliente, Cliente * cliente, unsigned int preco, bool cancelada):
		nome_oferta(nome_oferta), oferta(oferta), nome_cliente(nome_cliente),cliente(cliente),preco(preco), cancelada(cancelada) {}


//// Metodos da classe Cliente ////

Cliente::Cliente(string nome): nome(nome){}

void Cliente::save(){
	ofstream file("clientes.txt", ofstream::app);
	if(file.is_open())
		file << this->nome << endl;
}


//// Metodos da classe ClienteRegistado ////

ClienteRegistado::ClienteRegistado(string nome, unsigned int pontos): Cliente(nome),pontos(pontos){}

void ClienteRegistado::addPontos(unsigned int pontos){
	this->pontos += pontos;
}

void ClienteRegistado::save(){
	ofstream file("clientes_registados.txt", ofstream::app);
	if(file.is_open())
		file << this->nome << endl << this->pontos << endl;
}

//// Metodos da classe Oferta ////

const std::vector<std::string> & Oferta::getDestinos(){
	return this->destinos;
}



