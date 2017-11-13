
#include <fstream>
#include "cruise.h"
#include <iostream>

using namespace std;


                      /////                                            /////
                     /////               CRUISE . CPP                 /////
                    /////                                            /////

////  Metodos da classe Empresa ////

Empresa::Empresa(){
	this->load();
	cout << this->_clientes[0]->getNome() << endl;
}

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

void Empresa::load(){
	ifstream clientes_file("src/clientes_.txt");
	ifstream registados_file("src/clientes_registados.txt");
	ifstream fornecedores_file("src/fornecedores.txt");
	string line;
	string s1;
	string s2;
	string s3;
	string morada;
	unsigned int num1;
	unsigned int num2;
	vector<string> destinos;
	Cliente * c;
	Fornecedor * f;
	Oferta * o;
	vector<Oferta> ofertas;
	//Stores the clients who aren't registred in the data base
	if(clientes_file.is_open())
		while(getline(clientes_file,line)){
			s1 = line;
			c = new Cliente(s1);
			this->addClientes(*c);
		}
	else {
		cout << "The program failed to open the file with the information of the clients" << endl;
	}
	//Stores the clients who are registred in the data base
	if(registados_file.is_open())
			while(getline(registados_file,line)){
				s1 = line;
				getline(registados_file,line);
				num1 = stoi(line);
				c = new ClienteRegistado(line,num1);
				this->addClientes(*c);
			}
		else {
			cout << "The program failed to open the file with the information of the registred clients" << endl;
		}
   //Stores the supplier
	if(fornecedores_file.is_open())
			while(getline(fornecedores_file,line)){
				s1 = line;
				getline(fornecedores_file,line);
				num1 = stoi(line);
				getline(fornecedores_file,line);
				s2 = line;
				f = new Fornecedor(s1,num1,s2);
				getline(fornecedores_file,line);
				while(true){
					if(line == "fend")
						break;
					else{
						s1 = line;
						getline(fornecedores_file,line);
						s2 = line;
						getline(fornecedores_file,line);
						num1 = stoi(line);
						getline(fornecedores_file,line);
						num2 = stoi(line);
						getline(fornecedores_file,line);
						s3 = line;
						getline(fornecedores_file,line);
						if(line == "oend"){
							break;
						}
						else{
							do{
								destinos.push_back(line);
								getline(fornecedores_file,line);
							} while(line != "oend");
						}
						o = new Oferta(s1,s2,destinos,num1,num2,s3);
						f->addOferta(*o);

					}
				}
				this->addFornecedores(*f);
			}
		else {
			cout << "The program failed to open the file with the information of the suppliers" << endl;
		}
}
void Empresa::save(){

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

Oferta::Oferta(string name,string boat, vector<string> dest, unsigned int dist, unsigned int lot, string date): nome(name),barco(boat),destinos(dest),distancia(dist),lotacao(lot),data(date){};

const std::vector<std::string> & Oferta::getDestinos(){
	return this->destinos;
}



