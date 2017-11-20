
#include <fstream>
#include "cruise.h"
#include "extras.h"
#include <iostream>

using namespace std;


                      /////                                            /////
                     /////               CRUISE . CPP                 /////
                    /////                                            /////

/// Metodos da classe Empresa ////


/**
 * @brief      Constructs object of type Empresa
 */
Empresa::Empresa(){
	this->load();
	this->menuInicial();
	this->save();
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
	this->_clientes.push_back(&c);
	return *this;
}


Empresa & Empresa::addReservas(Reserva& r){
	this->_reservas.push_back(&r);
	return *this;
}


Empresa & Empresa::deleteClientes(string name){
	int index = BinarySearch(this->_clientes,name);
	if(index != -1){
		_clientes.erase(_clientes.begin() + index);
	}
	else{
		throw ObjetoInexistente<string>(name);
	}
	return *this;
}


Empresa & Empresa::deleteFornecedores(string name) {

	for (unsigned int i = 0; i < _fornecedores.size(); i++)
	{
		if (name == this->_fornecedores.at(i)->getNome())
			_fornecedores.erase(_fornecedores.begin() + i);
	}
	return *this;
}


Empresa & Empresa::deleteReservas(string name) {

	for (unsigned int i = 0; i < _reservas.size(); i++)
	{
		if (name == this->_reservas.at(i)->getNomeCliente())
			_reservas.erase(_reservas.begin() + i);
	}
	return *this;
}

/* Fornecedor & Fornecedor::deleteOfertas(string name) {
	for (unsigned int i = 0; i < ofertas.size(); i++)
	{
		if (name == this->ofertas.at(i).getNome())
			ofertas.erase(ofertas.begin() + i);
	}
	return *this;

}
*/


void Empresa::load(){
	ifstream clientes_file("src/clientes.txt");
	ifstream registados_file("src/clientes_registados.txt");
	ifstream fornecedores_file("src/fornecedores.txt");
	ifstream reservas_file("src/fornecedores.txt");
	string line;
	string s1;
	string s2;
	string s3;
	string morada;
	unsigned int num1;
	unsigned int num2;
	unsigned int p;
	vector<string> destinos;
	Cliente * c;
	Fornecedor * f;
	Oferta * o;
	Reserva * r;
	Time * t;
	vector<Oferta> ofertas;
	//Stores the clients who aren't registered in the data base
	if(clientes_file.is_open())
		while(getline(clientes_file,line)){
			s1 = line;
			c = new Cliente(s1);
			this->addClientes(*c);
		}
	else {
		cout << "O programa falhou a abrir o ficheiro com a informacao de clientes" << endl;
	}
	//Stores the clients who are registered in the data base
	if(registados_file.is_open())
			while(getline(registados_file,line)){
				s1 = line;
				getline(registados_file,line,'\n');
				num1 = stoi(line);
				c = new ClienteRegistado(line,num1);
				this->addClientes(*c);
			}
		else {
			cout << "O programa falhou a abrir o ficheiro com a informacao de clientes registados" << endl;
		}
   //Stores the supplier
	if(fornecedores_file.is_open()){
			while(getline(fornecedores_file,line)){
				s1 = line;
				getline(fornecedores_file,line,'\n');
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
						getline(fornecedores_file,line,'\n');
						num1 = stoi(line);
						getline(fornecedores_file,line,'\n');
						num2 = stoi(line);
						getline(fornecedores_file,line);
						t = new Time(line);
						getline(fornecedores_file,line,'\n');
						p = stoi(line);
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
						o = new Oferta(s1,s2,destinos,num1,num2,*t,p);
						f->addOferta(*o);

					}
				}


				this->addFornecedores(*f);


			}
	}
		else {
			cout << "O programa falhou a abrir o ficheiro com a informacao de fornecedores" << endl;
		}
	bool cancelada;
	if(reservas_file.is_open()){
		while(getline(reservas_file,line)){
			s1 = line;
			getline(reservas_file,line);
			s2 = line;
			getline(reservas_file,line);
			if(line == "true"){
				cancelada = true;
			}
			else cancelada = false;
			getline(reservas_file,line, '\n');
			num1 = stoi(line);
			for(unsigned int i = 0; i < this->_clientes.size();i++){
				if(this->_clientes[i]->getNome() == s2){
					*c = *this->_clientes[i];
				}
			}
			for(unsigned int i = 0; i < this->_fornecedores.size();i++){
							for(unsigned int j = 0;j < this->_fornecedores[i]->getOfertas().size();j++){
								if(this->_fornecedores[i]->getOfertas().at(j).getNome() == s1){
									*o = this->_fornecedores[i]->getOfertas()[j];
								}
							}
						}
			r = new Reserva(s1,o,s2,c,num1,cancelada);
			this->addReservas(*r);
		}
	}
	else{
		cout << "Erro: O programa nao conseguiu abrir o ficheiro das reservas" << endl;
	}
	this->sort();
	clientes_file.close();
	registados_file.close();
	fornecedores_file.close();
	reservas_file.close();
}
void Empresa::save(){
	ofstream clientes_file("src/clientes_.txt");
	ofstream registados_file("src/clientes_registados.txt");
	ofstream fornecedores_file("src/fornecedores.txt");
	ofstream reservas_file("src/fornecedores.txt");
	for(unsigned int i = 0; i < this->_clientes.size(); i++){
		if(this->_clientes[i]->isRegistado())
			registados_file << this->_clientes[i]->getNome() << endl << this->_clientes[i]->getPontos() << endl;
		else
			clientes_file << this->_clientes[i]->getNome() << endl;
	}
	for(unsigned int i = 0; i < this->_fornecedores.size(); i++){
		fornecedores_file << this->_fornecedores[i]->getNome() << endl;
		fornecedores_file << this->_fornecedores[i]->getNif() << endl;
		fornecedores_file << this->_fornecedores[i]->getMorada() << endl;
		for(unsigned int j = 0; j < this->_fornecedores[i]->getOfertas().size(); j++){
			fornecedores_file << this->_fornecedores[i]->getOfertas()[j].getNome() << endl;
			fornecedores_file << this->_fornecedores[i]->getOfertas()[j].getBarco() << endl;
			fornecedores_file << this->_fornecedores[i]->getOfertas()[j].getDistancia() << endl;
			fornecedores_file << this->_fornecedores[i]->getOfertas()[j].getLotacao() << endl;
			fornecedores_file << this->_fornecedores[i]->getOfertas()[j].getData() << endl;
			fornecedores_file << this->_fornecedores[i]->getOfertas()[j].getPreco() << endl;
			for(unsigned int k = 0; k < this->_fornecedores[i]->getOfertas()[j].getDestinos().size(); k++){
				cout << this->_fornecedores[i]->getOfertas()[j].getDestinos()[k] << endl;
			}
			if(this->_fornecedores[i]->getOfertas().size() != 0){
			    cout << "oend" << endl;
			}
			cout << "fend" << endl;

		}
	}
	for(unsigned int i = 0; i < this->_reservas.size(); i++){
		cout << this->_reservas[i]->getNomeFornecedor() << endl;
		cout << this->_reservas[i]->getNomeCliente() << endl;
		if(this->_reservas[i]->isCancelada()){
			cout << "true" << endl;
		}
		else cout << "false" << endl;
		cout << this->_reservas[i]->getPreco() << endl;
	}
}
void Empresa::sort(){
	Sort(this->_clientes);
	Sort(this->_fornecedores);
}

//// Metodos da classe Fornecedor ////

Fornecedor::Fornecedor(string nome, unsigned int nif, string morada):nome(nome), nif(nif), morada(morada){}

void Fornecedor::addOferta(Oferta & oferta){
	this->ofertas.push_back(oferta);
}

vector<Oferta> & Fornecedor::getOfertas(){
	return this->ofertas;
}


int Fornecedor::calculaPreco(int tipodebarco, int lotacao) {


	return definicoesfornecedor.at(tipodebarco) + definicoesfornecedor.at(0) * lotacao; //1 - iate; 2 - barco rabelo; 3 - veleiro;

}

void Fornecedor::displayOfertas() {
	

	for (unsigned int i = 0; i < ofertas.size(); i++)
	{
		cout << "Nome: " << ofertas.at(i).getNome() << endl;
		cout << "Barco: " << ofertas.at(i).getBarco() << endl;

		for (unsigned int j = 0; j < ofertas.at(i).getDestinos().size(); j++) {
		cout << "Destinos:" << endl;
		cout << "	Destino nº" << j << " : "<< ofertas.at(i).getDestinos().at(j) << endl;
	}
		cout << "Distancia: " << ofertas.at(i).getDistancia() << "/n";
		cout << "Lotacao: " << ofertas.at(i).getLotacao() << endl;
		cout << "Data: " << ofertas.at(i).getData() << endl;
		cout << "Preco: " << calculaPreco(ofertas.at(i).getBarcoNumber(), ofertas.at(i).getLotacao()) << endl;

	}
}




//// Metodos da classe Reserva ////

Reserva::Reserva(string nome_fornecedor, Oferta * oferta, string nome_cliente, Cliente * cliente, unsigned int preco, bool cancelada):
		nome_fornecedor(nome_fornecedor), oferta(oferta), nome_cliente(nome_cliente),cliente(cliente),preco(preco), cancelada(cancelada) {}



//// Metodos da classe Cliente ////

Cliente::Cliente(string nome): nome(nome){}


//// Metodos da classe ClienteRegistado ////

ClienteRegistado::ClienteRegistado(string nome, unsigned int pontos): Cliente(nome),pontos(pontos){}

void ClienteRegistado::addPontos(unsigned int pontos){
	this->pontos += pontos;
}


//// Metodos da classe Oferta ////

Oferta::Oferta(string name,string boat, vector<string> dest, unsigned int dist, unsigned int lot, Time date, unsigned int preco): nome(name),barco(boat),destinos(dest),distancia(dist),lotacao(lot),data(date), preco(preco){};

const std::vector<std::string> & Oferta::getDestinos(){
	return this->destinos;
}

int Oferta::getBarcoNumber()
{
	if (barco == "iate")
		return 1;
	else if (barco == "barco rabelo" || barco == "barco_rabelo")
		return 2;
	else if (barco == "veleiro")
		return 3;
	else return -1;
	
}

string Oferta::getData() {
	
	return to_string(data.getYear()) + "/" + to_string(data.getMonth()) + "/" + to_string(data.getDay());
}
