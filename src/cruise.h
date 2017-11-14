#ifndef CRUISE_H_
#define CRUISE_H_

#include <vector>
#include <string>
#include "extras.h"



                      /////                                          /////
                     /////               CRUISE . H                 /////
                    /////                                          /////


class Oferta{
private:
	std::string nome;
	std::string barco;
	std::vector<std::string> destinos;
	unsigned int distancia;
	unsigned int lotacao;
	std::string data;
	Time hora;
public:
	Oferta(std::string nome,std::string barco, std::vector<std::string> destinos, unsigned int distancia, unsigned int lotacao, std::string data);
	std::string getNome() { return this->nome; }
	std::string getBarco() { return this->barco; }
	unsigned int getLotacao() { return this->lotacao; }
	const std::vector<std::string> & getDestinos();
};

class Fornecedor{
private:
	std::string nome;
	unsigned int nif;
	std::string morada;
	std::vector<Oferta> ofertas;
public:
	Fornecedor(std::string nome, unsigned int nif, std::string morada);
	std::string getNome() { return this->nome; }
	unsigned int getNif() { return this->nif; }
	std::string getMorada() { return this->morada; }
	void addOferta(Oferta & oferta);
	std::vector<Oferta> & getOfertas();
	std::vector<Oferta> & getOfertabyName(std::string nome);
	Fornecedor & deleteOfertas(std::string name);

};

class Cliente{
protected:
	std::string nome;
public:
	Cliente(std::string nome);
	std::string getNome() { return this->nome; };
	virtual unsigned int getPontos() { return 0 ;};
	virtual bool isRegistado() { return false;};
};

class ClienteRegistado: public Cliente{
private:
	unsigned int pontos;
public:
	ClienteRegistado(std::string nome, unsigned int pontos = 0);
	unsigned int getPontos() { return this->pontos; };
	void addPontos(unsigned int pontos);
	bool isRegistado(){return true;};
};

class Reserva{
private:
	std::string nome_oferta;
	Oferta* oferta;
	std::string nome_cliente;
	Cliente * cliente;
	bool cancelada;
	unsigned int preco;
public:
	Reserva(std::string nome_oferta, Oferta * oferta, std::string nome_cliente, Cliente * cliente, unsigned int preco, bool cancelada = false);
	std::string getNomeCliente() { return this->nome_cliente; };
	std::string getNomeOferta() { return this->nome_oferta; };
	
};

class Empresa{
private:
	std::vector<Fornecedor*> _fornecedores;
	std::vector<Cliente*> _clientes;
	std::vector<Reserva*>_reservas;
public:
	Empresa();
	Empresa & addFornecedores(Fornecedor& f);
	Empresa & addClientes(Cliente& c);
	Empresa & addReservas(Reserva & r);
	Empresa & deleteFornecedores(std::string name);
	Empresa & deleteClientes(std::string name);
	Empresa & deleteReservas(std::string name);

	//menusGerais
	void titulo();
	void menuInicial();
	void menuTipodeUtilizador();
	//menuCliente
	void menuCliente();
	void adicionaClienteNormal();
	void adicionaClienteRegistado();
	void adicionaCliente();
	void removeCliente();
	//menuFornecedor
	void menuFornecedor();
	void adicionaFornecedor();
	void removeFornecedor();
	//menuReservas
	void menuReservas();
	void adicionaReserva();
	void removeReservas();
	//menuOfertas
	void menuOfertas();
	void adicionaOferta();
	void removeOferta();

	//metodos Empresa
	const std::vector<Fornecedor*> & getFornecedores();
	const std::vector<Cliente*> & getClientes();
	void save();
	void load();

};

//Exceptions

template <class T>
class InputInvalido{
private:
  T input;
public:
  InputInvalido(T input):input(input){};
  T getInput(){return this->input;};

};

template <class T>
class ObjetoRepetido{
private:
  T obj;
public:
  ObjetoRepetido(T obj):obj(obj){};
  T getObj(){return this->obj;};
};

template<class T>
class ObjetoInexistente{
private:
  T obj;
public:
  ObjetoInexistente(T obj):obj(obj){};
  T getObj(){return this->obj;};
};

//Overload do operador << para as exceptions

template <class T>
std::ostream & operator<<(std::ostream & os,InputInvalido<T> & ex){
  os << ex.getInput();
  return os;
};

template <class T>
std::ostream & operator<<(std::ostream & os,ObjetoRepetido<T> & ex){
  os << ex.getObj();
  return os;
};

template <class T>
std::ostream & operator<<(std::ostream & os,ObjetoInexistente<T> & ex){
  os << ex.getObj();
  return os;
}

#endif /* CRUISE_H_ */
