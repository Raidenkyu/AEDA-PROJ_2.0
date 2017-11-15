#ifndef CRUISE_H_
#define CRUISE_H_

#include <vector>
#include <string>
#include "extras.h"



                      /////                                          /////
                     /////               CRUISE . H                 /////
                    /////                                          /////


/**
 * @brief      Class for oferta.
 */
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

	/**
	 * @brief      Construct a Oferta object
	 *
	 * @param[in]  nome       The nome
	 * @param[in]  barco      The barco
	 * @param[in]  destinos   The destinos
	 * @param[in]  distancia  The distancia
	 * @param[in]  lotacao    The lotacao
	 * @param[in]  data       The data
	 */
	Oferta(std::string nome,std::string barco, std::vector<std::string> destinos, unsigned int distancia, unsigned int lotacao, std::string data);
	
	/**
	 * @brief      Gets the nome.
	 *
	 * @return     The nome.
	 */
	std::string getNome() { return this->nome; }

	/**
	 * @brief      Gets the barco.
	 *
	 * @return     The barco.
	 */
	std::string getBarco() { return this->barco; }

	/**
	 * @brief      Gets the lotacao.
	 *
	 * @return     The lotacao.
	 */
	unsigned int getLotacao() { return this->lotacao; }

	/**
	 * @brief      Gets the destinos.
	 *
	 * @return     The destinos.
	 */
	const std::vector<std::string> & getDestinos();
};

/**
 * @brief      Class for fornecedor.
 */
class Fornecedor{
private:
	std::string nome;
	unsigned int nif;
	std::string morada;
	std::vector<Oferta> ofertas;
public:

	/**
	 * @brief      Construct a Fornecedor Object
	 *
	 * @param[in]  nome    The nome
	 * @param[in]  nif     The nif
	 * @param[in]  morada  The morada
	 */
	Fornecedor(std::string nome, unsigned int nif, std::string morada);

	/**
	 * @brief      Gets the nome.
	 *
	 * @return     The nome.
	 */
	std::string getNome() { return this->nome; }

	/**
	 * @brief      Gets the nif.
	 *
	 * @return     The nif.
	 */
	unsigned int getNif() { return this->nif; }

	/**
	 * @brief      Gets the morada.
	 *
	 * @return     The morada.
	 */
	std::string getMorada() { return this->morada; }

	/**
	 * @brief      Adds an oferta.
	 *
	 * @param      oferta  The oferta
	 */
	void addOferta(Oferta & oferta);

	/**
	 * @brief      Gets the ofertas.
	 *
	 * @return     The ofertas.
	 */
	std::vector<Oferta> & getOfertas();

	/**
	 * @brief      searchs the oferta which name is equal to the argument
	 *
	 * @param[in]  nome  The nome
	 *
	 * @return     The oferta
	 */
	std::vector<Oferta> & getOfertabyName(std::string nome);

	/**
	 * @brief      remove the oferta of a fornecedor
	 *
	 * @param[in]  name  The name
	 *
	 * @return     the modified fornecedor
	 */
	Fornecedor & deleteOfertas(std::string name);


};

/**
 * @brief      Class for cliente.
 */
class Cliente{
protected:
	std::string nome;
public:

	/**
	 * @brief      Construct a Cliente object
	 *
	 * @param[in]  nome  The nome
	 */
	Cliente(std::string nome);

	/**
	 * @brief      Gets the nome.
	 *
	 * @return     The nome.
	 */
	std::string getNome() { return this->nome; };

	/**
	 * @brief      Gets the pontos.
	 *
	 * @return     The pontos.
	 */
	virtual unsigned int getPontos() { return 0 ;};

	/**
	 * @brief      Determines if registado.
	 *
	 * @return     True if registado, False otherwise.
	 */
	virtual bool isRegistado() { return false;};

};

/**
 * @brief      Class for cliente registado.
 */
class ClienteRegistado: public Cliente{
private:
	unsigned int pontos;
public:

	/**
	 * @brief      Construct ClienteRegistado object
	 *
	 * @param[in]  nome    The nome
	 * @param[in]  pontos  The pontos
	 */
	ClienteRegistado(std::string nome, unsigned int pontos = 0);

	/**
	 * @brief      Gets the pontos.
	 *
	 * @return     The pontos.
	 */
	unsigned int getPontos() { return this->pontos; };

	/**
	 * @brief      Adds pontos.
	 *
	 * @param[in]  pontos  The pontos
	 */
	void addPontos(unsigned int pontos);

	/**
	 * @brief      Determines if registado.
	 *
	 * @return     True if registado, False otherwise.
	 */
	bool isRegistado(){return true;};

};

/**
 * @brief      Class for reserva.
 */
class Reserva{
private:
	std::string nome_oferta;
	Oferta* oferta;
	std::string nome_cliente;
	Cliente * cliente;
	bool cancelada;
	unsigned int preco;
public:

	/**
	 * @brief      Construct the Reserva Objet
	 *
	 * @param[in]  nome_oferta   The name of the offer
	 * @param      oferta        A pointer to the offer
	 * @param[in]  nome_cliente  The name of the client
	 * @param      cliente       A pointer to the client
	 * @param[in]  preco         The price of the reservation
	 * @param[in]  cancelada     If the reservation was canceled
	 */
	Reserva(std::string nome_oferta, Oferta * oferta, std::string nome_cliente, Cliente * cliente, unsigned int preco, bool cancelada = false);
	
	/**
	 * @brief      Gets the name of the client.
	 *
	 * @return     The nome of cliente.
	 */
	std::string getNomeCliente() { return this->nome_cliente; };
	
	/**
	 * @brief      Gets the name of the offer
	 *
	 * @return     The nome of oferta.
	 */
	std::string getNomeOferta() { return this->nome_oferta; };
	
};

/**
 * @brief      Class for empresa.
 */
class Empresa{
private:
	std::vector<Fornecedor*> _fornecedores;
	std::vector<Cliente*> _clientes;
	std::vector<Reserva*>_reservas;
public:

	/**
	 * @brief      Construct Empresa object
	 */
	Empresa();

	/**
	 * @brief      Adds fornecedores.
	 *
	 * @param      f     Fornecedor
	 *
	 * @return     the modified Empresa
	 */
	Empresa & addFornecedores(Fornecedor& f);

	/**
	 * @brief      Adds clientes.
	 *
	 * @param      c     Cliente
	 *
	 * @return     the modified Empresa
	 */
	Empresa & addClientes(Cliente& c);

	/**
	 * @brief      Adds a reservas.
	 *
	 * @param      r     Reserva
	 *
	 * @return     the modified Empresa
	 */
	Empresa & addReservas(Reserva & r);

	/**
	 * @brief      removes a Fornecedor
	 *
	 * @param[in]  name  The name
	 *
	 * @return     the modified Empresa
	 */
	Empresa & deleteFornecedores(std::string name);

	/**
	 * @brief      removes a Cliente
	 *
	 * @param[in]  name  The name
	 *
	 * @return     the modified Empresa
	 */
	Empresa & deleteClientes(std::string name);

	/**
	 * @brief      removes a Reserva
	 *
	 * @param[in]  name  The name
	 *
	 * @return     the modified Empresa
	 */
	Empresa & deleteReservas(std::string name);


	// menusGerais
	/**
	 * @brief      dislpay the main title of the company
	 */
	void titulo();

	/**
	 * @brief      displays the first menu
	 */
	void menuInicial();

	/**
	 * @brief      Displays a menu that guides the user to all the sub-menus
	 */
	void menuTipodeUtilizador();

	// menuCliente
	/**
	 * @brief      displays the Client Menu
	 */
	void menuCliente();

	/**
	 * @brief      displays the interface to add Clients
	 */
	void adicionaClienteNormal();

	/**
	 * @brief      displays the interface to add Registred Clients
	 */
	void adicionaClienteRegistado();

	/**
	 * @brief      { function_description }
	 */
	void adicionaCliente();

	/**
	 * @brief      Removes a cliente.
	 */
	void removeCliente();

	// menuFornecedor
	/**
	 * @brief      { function_description }
	 */
	void menuFornecedor();

	/**
	 * @brief      { function_description }
	 */
	void adicionaFornecedor();

	/**
	 * @brief      Removes a fornecedor.
	 */
	void removeFornecedor();

	//menuReservas
	/**
	 * @brief      { function_description }
	 */
	void menuReservas();

	/**
	 * @brief      { function_description }
	 */
	void adicionaReserva();

	/**
	 * @brief      Removes a reservas.
	 */
	void removeReservas();

	//menuOfertas
	/**
	 * @brief      { function_description }
	 */
	void menuOfertas();

	/**
	 * @brief      { function_description }
	 */
	void adicionaOferta();

	/**
	 * @brief      Removes an oferta.
	 */
	void removeOferta();


	//metodos Empresa
	/**
	 * @brief      Gets the suppliers.
	 *
	 * @return     The fornecedores.
	 */
	const std::vector<Fornecedor*> & getFornecedores();

	/**
	 * @brief      Gets the clientes.
	 *
	 * @return     The clientes.
	 */
	const std::vector<Cliente*> & getClientes();

	/**
	 * @brief      stores in a text file all the information generated by the program execution
	 */
	void save();

	/**
	 * @brief      loads the information generated in previous executions
	 */
	void load();

	/**
	 * @brief      sorts the vectors of the class
	 */
	void sort();



};

//Exceptions


/**
 * @brief      Class for invalid input exception.
 *
 * @tparam     T     the type of the input
 */
template <class T>
class InputInvalido{
private:
  T input;
public:

  /**
   * @brief      Construct the InputInvalido Exception
   *
   * @param[in]  input  The input
   */
  InputInvalido(T input):input(input){};

  /**
   * @brief      Gets the input.
   *
   * @return     The input.
   */
  T getInput(){return this->input;};


};



/**
 * @brief      Class for objeto repetido Exception
 *
 * @tparam     T     type of the repeated object
 */
template <class T>
class ObjetoRepetido{
private:
  T obj;
public:

  /**
   * @brief      Constructs the ObjetoRepetido Exception
   *
   * @param[in]  obj   The repeated object
   */
  ObjetoRepetido(T obj):obj(obj){};

  /**
   * @brief      Gets the object.
   *
   * @return     The object.
   */
  T getObj(){return this->obj;};

};


/**
 * @brief      Class for objeto inexistente Exception.
 *
 * @tparam     T     type of the not found object
 */
template<class T>
class ObjetoInexistente{
private:
  T obj;
public:

  /**
   * @brief      Constructs the ObjetoInexistente Exception.
   *
   * @param[in]  obj   The not found object
   */
  ObjetoInexistente(T obj):obj(obj){};

  /**
   * @brief      Gets the object.
   *
   * @return     The object.
   */
  T getObj(){return this->obj;};

};

//Overload do operador << para as exceptions


/**
 * @brief      overload to << operator to display InvalidInput Exception
 *
 * @param      os    ostream
 * @param      ex    Invalid Input Exception
 *
 * @tparam     T     the type of the invalid input
 *
 * @return     ostream that reads InputInvalid object
 */
template <class T>
std::ostream & operator<<(std::ostream & os,InputInvalido<T> & ex){
  os << ex.getInput();
  return os;
};

/**
 * @brief      overload to << operator to display ObjetoRepetido Exception
 *
 * @param      os    ostream
 * @param      ex    Repeated Object Exception
 *
 * @tparam     T     the type of the repeated obhect
 *
 * @return     ostream that reads ObjetoRepetido object
 */
template <class T>
std::ostream & operator<<(std::ostream & os,ObjetoRepetido<T> & ex){
  os << ex.getObj();
  return os;
};

/**
 * @brief      overload to << operator to display ObjetoInexistente Exception
 *
 * @param      os    ostream
 * @param      ex    Not found Object Exception
 *
 * @tparam     T     the type of the not found obhect
 *
 * @return     ostream that reads ObjetoInexistente object
 */
template <class T>
std::ostream & operator<<(std::ostream & os,ObjetoInexistente<T> & ex){
  os << ex.getObj();
  return os;
}

#endif /* CRUISE_H_ */
