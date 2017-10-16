#ifndef CRUISE_H_
#define CRUISE_H_

#include <vector>
#include <string>

class oferta{
private:
	std::string nome;
	std::string barco;
	std::vector<std::string> destinos;
	unsigned int distancia;
	unsigned int lotacao;
	std::string data;
	std::string hora;
};

class fornecedor{
private:
	std::string nome;
	unsigned int NIF;
	std::string morada;
	std::vector<oferta> ofertas;
};

class cliente{
private:
	std::string nome;
	unsigned int pontos;
};


class empresa{
private:
	std::vector<fornecedor*> _fornecedores;
	std::vector<cliente*> _clientes;
};



#endif /* CRUISE_H_ */
