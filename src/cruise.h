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
	std::string getNome() { return this->nome; }
	std::string getBarco() { return this->barco; }
	unsigned int getLotacao() { return this->lotacao; }
};

class Fornecedor{
private:
	std::string nome;
	unsigned int nif;
	std::string morada;
	vector<Oferta> ofertas;
public:
	Fornecedor(string nome, unsigned int nif, string morada);
	std::string getNome() { return this->nome; }
	unsigned int getNif() { return this->nif; }
	std::string getMorada() { return this->morada; }


};

class Cliente{
private:
	std::string nome;
	unsigned int pontos;
public:
	Cliente(string nome);
	std::string getNome() { return this->nome; }
	unsigned int getPontos() { return this->pontos; }
	addPontos(unsigned int pontos);
};


class Empresa{
private:
	std::vector<Fornecedor*> _fornecedores;
	std::vector<Cliente*> _clientes;
public:
	Empresa();
	Empresa addFornecedores(Fornecedor& f);
	Empresa addClientes(Cliente& c);
};













#endif /* CRUISE_H_ */
