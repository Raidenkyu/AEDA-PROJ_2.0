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
	const std::vector<Oferta> & getOfertas();

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
	const std::vector<Fornecedor*> & getFornecedores();
	const std::vector<Cliente*> & getClientes();
	void save();
	void load();

};













#endif /* CRUISE_H_ */
