
#include <fstream>
#include "cruise.h"
#include <iostream>

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
	ifstream clientes_file("src/clientes_.txt");
	ifstream registados_file("src/clientes_registados.txt");
	ifstream fornecedores_file("src/fornecedores.txt");
	string line;
	unsigned int pontos;
	Cliente * c;
	//Stores the clients who aren't registred in the data base
	if(clientes_file.is_open())
		while(getline(clientes_file,line)){
			c = new Cliente(line);
			this->addClientes(*c);
		}
	else {
		cout << "The program failed to open the file with the information of the clients" << endl;
	}
	//Stores the clients who are registred in the data base
	if(registados_file.is_open())
			while(getline(clientes_file,line)){
				c = new Cliente(line);
				this->addClientes(*c);
			}
		else {
			cout << "The program failed to open the file with the information of the clients" << endl;
		}
   //Stores the supplier
	if(fornecedores_file.is_open())
			while(getline(clientes_file,line)){
				c = new Cliente(line);
				this->addClientes(*c);
			}
		else {
			cout << "The program failed to open the file with the information of the clients" << endl;
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



//// Metodos da classe Reserva ////

Reserva::Reserva(std::string nome_oferta, Oferta * oferta, string nome_cliente, Cliente * cliente, unsigned int preco, bool cancelada):
		nome_oferta(nome_oferta), oferta(oferta), nome_cliente(nome_cliente),cliente(cliente),preco(preco), cancelada(cancelada) {}


//// Metodos da classe Cliente ////

Cliente::Cliente(string nome): nome(nome){}


//// Metodos da classe ClienteRegistado ////

ClienteRegistado::ClienteRegistado(string nome, unsigned int pontos): Cliente(nome),pontos(pontos){}

void ClienteRegistado::addPontos(unsigned int pontos){
	this->pontos += pontos;
}


//// Metodos da classe Oferta ////

const std::vector<std::string> & Oferta::getDestinos(){
	return this->destinos;
}



