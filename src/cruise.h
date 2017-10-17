#ifndef CRUISE_H_
#define CRUISE_H_


                      /////                                          /////
                     /////               CRUISE . H                 /////
                    /////                                          /////


#include <vector>
#include <string>

using namespace std;

class Oferta{
private:
	string nome;
	string barco;
	vector<std::string> destinos;
	unsigned int distancia;
	unsigned int lotacao;
	string data;
	string hora;
public:
	string getNome() { return this->nome; }
	string getBarco() { return this->barco; }
	unsigned int getLotacao() { return this->lotacao; }

};

class Fornecedor{
private:
	string nome;
	unsigned int nif;
	string morada;
	vector<Oferta> ofertas;
public:
	string getNome() { return this->nome; }
	unsigned int getNif() { return this->nif; }
	string getMorada() { return this->morada; }

};

class Cliente{
private:
	string nome;
	unsigned int pontos;
public:
	string getNome() { return this->nome; }
	unsigned int getPontos() { return this->pontos; }
};


class Empresa{
private:
	vector<Fornecedor*> _fornecedores;
	vector<Cliente*> _clientes;
};



#endif /* CRUISE_H_ */
