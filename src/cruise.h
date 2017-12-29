#ifndef CRUISE_H_
#define CRUISE_H_

#include <vector>
#include <string>
#include "extras.h"
#include <queue>
#include <unordered_set>
#include "BST.h"



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
	Time data;
	Time ultimaReserva;
	unsigned int preco;
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
	Oferta(std::string nome,std::string barco, std::vector<std::string> destinos, unsigned int distancia, unsigned int lotacao, Time data, unsigned int preco);
	
	void setNome(std::string name) { nome = name; }
	void setBarco(std::string boat) { barco = boat; }
	void setDestinos(std::vector <std::string> destinies) { destinos = destinies; }
	void apagaDestinos() { destinos.erase(destinos.begin(),destinos.end()); }
	void setDistancia(unsigned int distance) { distancia = distance; }
	void setLotacao(unsigned int limit) { lotacao = limit; }
	void setTime(Time novaData) { data = novaData; }
	void setTimeUltimaReserva(Time novaDataReserva) { ultimaReserva = novaDataReserva; };
	void setPreco(unsigned int price) { preco = price; }
	/**
	 * @brief      Gets the name
	 *
	 * @return     The nome.
	 */
	std::string getNome() { return this->nome; }

	/**
	 * @brief      Gets the boat
	 *
	 * @return     The barco.
	 */
	std::string getBarco() { return this->barco; }

	/**
	 * @brief      Gets the date in string format
	 *
	 * @return     The date(string)
	 */
	std::string getData();

	/**
	 * @brief      Gets the date 
	 *
	 * @return     The date
	 */
	Time getDataMesmo() { return this->data; }

	Time  & getUltimaReserva(){ return this->ultimaReserva; }

	/**
	 * @brief      Gets the number of the boat.
	 *
	 * @return     The barco number.
	 */
	int getBarcoNumber();

	/**
	 * @brief      Gets the lotation
	 *
	 * @return     The lotacao.
	 */
	unsigned int getLotacao() { return this->lotacao; }

	/**
	 * @brief      Gets the stops
	 *
	 * @return     The destinos.
	 */

	unsigned int getDistancia() { return this->distancia; }

	/**
	 * @brief      Gets the distance of the trip
	 *
	 * @return     The destinos
	 */
	const std::vector<std::string> & getDestinos();

	/**
	 * @brief      Gets the price
	 *
	 * @return     The preco
	 */
	unsigned int getPreco(){return this->preco;};

	/**
	 * @brief      decreases the lotation
	 *
	 * @param[in]  lotacaoocupada  The lotation reserved
	 */
	void diminuiLotacao(int lotacaoocupada) { lotacao = lotacao - lotacaoocupada; }

	/**
	 * @brief      prints the information of the offers
	 */
	void printOferta();


	
};

/**
 * @brief      Class for fornecedor.
 */
class Fornecedor {
private:
	std::string nome;
	unsigned int nif;
	std::string morada;
	std::vector<Oferta> ofertas;
	std::vector<int> definicoesfornecedor;  //elementos: 0 - multiplicador lotacao; 1 - iate; 2 - barco rebelo; 3 - veleiro;

public:

	/**
	 * @brief      Sets the name
	 *
	 * @param[in]  novoNome  The new nome
	 */
	void setNome(std::string novoNome) { nome = novoNome; }

	/**
	 * @brief      Sets the nif.
	 *
	 * @param[in]  novoNIF  The new nif
	 */
	void setNIF(unsigned int novoNIF) { nif = novoNIF; }

	/**
	 * @brief      Sets the address
	 *
	 * @param[in]  novaMorada  The new morada
	 */
	void setMorada(std::string novaMorada) { morada = novaMorada; }



	/**
	 * @brief      Construct a Fornecedor Object
	 *
	 * @param[in]  nome    The name
	 * @param[in]  nif     The nif
	 * @param[in]  morada  The address
	 */
	Fornecedor(std::string nome, unsigned int nif, std::string morada);

	/**
	 * @brief      Gets the name
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
	 * @brief      Gets the address
	 *
	 * @return     The morada
	 */
	std::string getMorada() { return this->morada; }

	/**
	 * @brief      Adds an offer
	 *
	 * @param      oferta  The offer
	 */
	void addOferta(Oferta & oferta);

	/**
	 * @brief      Gets the offers
	 *
	 * @return     The ofertas
	 */
	std::vector<Oferta> & getOfertas();
	

	/**
	 * @brief      Sets the definitions of a supplier.
	 */
	void setDefinicoesFornecedor();

	/**
	 * @brief      Gets the definitions of the supplier
	 *
	 * @return     The definitions of the supplier
	 */
	std::vector<int> getDefinicoesFornecedor() { return this->definicoesfornecedor; }

	/**
	 * @brief      Calculates the price of a boat trip
	 *
	 * @param[in]  tipodebarco  The type of boat
	 * @param[in]  lotacao      The lotation
	 *
	 * @return     the value of the price
	 */
	int calculaPreco(int tipodebarco, int lotacao, int distancia);

	/**
	 * @brief      prints all the offers
	 */
	

	void displayOfertas();

	/**
	 * @brief      removes an offer
	 *
	 * @param[in]  name  The name of the offer
	 *
	 * @return     the modified supplier
	 */
	Fornecedor & deleteOfertas(std::string name);

	/**
	 * @brief      Sets the defenicoes.
	 *
	 * @param[in]  def   The definition
	 */
	void setDefenicoes(std::vector<int> def){this->definicoesfornecedor=def;};

};

/**
 * @brief      Class for cliente.
 */
class Cliente{
protected:
	std::string nome;
	std::string morada;
public:

	/**
	 * @brief      Construct a Cliente object
	 *
	 * @param[in]  nome  The name
	 */
	Cliente(std::string nome, std::string morada);

	/**
	 * @brief      Gets the name
	 *
	 * @return     The nome.
	 */
	std::string getNome() { return this->nome; };

	std::string getMorada(){ return this->morada;};

	/**
	 * @brief      Sets the name.
	 *
	 * @param[in]  novoNome  The novo nome
	 */
	void setNome(std::string novoNome) { nome = novoNome; }

	void setMorada(std::string novaMorada){this->morada = novaMorada;};

	/**
	 * @brief      Gets the points
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

	/**
	 * @brief      Sets the points
	 *
	 * @param[in]  pontos  The points
	 */
	virtual void setPontos(unsigned int pontos) {};



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
	 * @param[in]  nome    The name
	 * @param[in]  pontos  The points
	 */
	ClienteRegistado(std::string nome, std::string morada, unsigned int pontos = 0);

	/**
	 * @brief      Gets the points
	 *
	 * @return     The points
	 */
	unsigned int getPontos() { return this->pontos; };

	/**
	 * @brief      Adds points
	 *
	 * @param[in]  pontos  The points
	 */
	void setPontos(unsigned int pontos);

	/**
	 * @brief      Determines if registado.
	 *
	 * @return     True if registado, False otherwise.
	 */
	bool isRegistado(){return true;};

};

class ClienteInativo {
private:
	Cliente * ptr;
public:
	ClienteInativo(Cliente * ptr);
	std::string getNome() const;
	std::string getMorada() const;
	void setMorada(std::string novaMorada);
};


/**
 * @brief      Class for reserva.
 */
class Reserva{
private:
	std::string nome_fornecedor;
	Oferta* oferta;
	std::string nome_cliente;
	Cliente * cliente;
	bool cancelada;
	unsigned int preco;
	Time data;
public:

	/**
	 * @brief      Construct the Reserva Objet
	 *
	 * @param[in]  nome_fornecedor	The name of the supplier
	 * @param      oferta			A pointer to the offer
	 * @param[in]  nome_cliente		The name of the client
	 * @param      cliente			A pointer to the client
	 * @param[in]  preco			The price of the reservation
	 * @param[in]  cancelada		If the reservation was canceled
	 */
	Reserva(std::string nome_fornecedor, Oferta * oferta, std::string nome_cliente, Cliente * cliente, unsigned int preco, bool cancelada = false);
	
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
	std::string getNomeFornecedor() { return this->nome_fornecedor; };

	/**
	 * @brief      Determines if the reservation was cancelled.
	 *
	 * @return     True if cancelled, False otherwise.
	 */

	Oferta*  getOferta() { return this-> oferta; }

	/**
	 * @brief      Gets the cliente.
	 *
	 * @return     The cliente.
	 */
	Cliente*  getCliente() { return this->cliente; }

	/**
	 * @brief      Determines if cancelada.
	 *
	 * @return     True if cancelada, False otherwise.
	 */
	bool isCancelada(){return this->cancelada;};

	/**
	 * @brief      { function_description }
	 */
	void cancelamento() { cancelada = true; }

	/**
	 * @brief      Gets the price
	 *
	 * @return     The price
	 */
	unsigned int getPreco(){return this->preco;};

	/**
	 * @brief      Sets the preco.
	 *
	 * @param[in]  novoPreco  The new price
	 */
	void setPreco(int novoPreco) { preco = novoPreco; }

	Time getData() {return data;}

};


struct comparaOfertas
{
	bool operator() (Oferta oferta1, Oferta oferta2)  const{
		return oferta1.getUltimaReserva() < oferta2.getUltimaReserva();
	}
};

struct comparaClientesInativos
{
	int operator() (const ClienteInativo & c) const {
		return 0;
	}
	bool operator() (const ClienteInativo & c1, const ClienteInativo & c2)  const{
		return c1.getNome() < c2.getNome();
	}
};

typedef std::priority_queue<Oferta, std::vector<Oferta>,comparaOfertas> pq_ofertas;
typedef std::unordered_set<ClienteInativo, comparaClientesInativos,comparaClientesInativos> tabHInativos;


class Fatura{
private:
	Reserva * reserva;
public:
	Fatura(Reserva *r);
	Reserva *getReserva();
	std::string getNomeCliente() const;
	Time getData() const;
	Time getData();
	string getFornecedor();
	bool operator< (const Fatura &f1) const;
	bool operator== (const Fatura &f1) const;
};



/**
 * @brief      Class for empresa.
 */
class Empresa{
private:
	std::vector<Fornecedor*> _fornecedores;
	std::vector<Cliente*> _clientes;
	std::vector<Reserva*>_reservas;
	BST<Fatura> _faturas;
	pq_ofertas queueOfertasOrdenadas;
	tabHInativos _clientesInativos;

public:

	/**
	 * @brief      Construct Empresa object
	 */
	Empresa();

	/**
	 * @brief      Adds suppliers
	 *
	 * @param      f     Fornecedor
	 *
	 * @return     the modified Empresa
	 */
	Empresa & addFornecedores(Fornecedor& f);

	/**
	 * @brief      Adds clients
	 *
	 * @param      c     Cliente
	 *
	 * @return     the modified Empresa
	 */
	Empresa & addClientes(Cliente& c);

	/**
	 * @brief      Adds a reservations
	 *
	 * @param      r     Reserva
	 *
	 * @return     the modified Empresa
	 */
	Empresa & addReservas(Reserva & r);

	Empresa & addFaturas(Fatura & r);


	/**
	 * @brief      removes a supplier
	 *
	 * @param[in]  name  The name
	 *
	 * @return     the modified Empresa
	 */
	Empresa & deleteFornecedores(std::string name);

	/**
	 * @brief      removes a Client
	 *
	 * @param[in]  name  The name
	 *
	 * @return     the modified Empresa
	 */
	Empresa & deleteClientes(std::string name);

	/**
	 * @brief      removes a Reservation
	 *
	 * @param[in]  name  The name
	 *
	 * @return     the modified Empresa
	 */
	Empresa & deleteReservas(std::string name);


	// menusGerais
	/**
	 * @brief      displays the main title of the company
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
	 * @brief      adds Clients
	 */
	void adicionaCliente();

	/**
	 * @brief      Modifies a cliente.
	 */

	void modificaCliente();

	/**
	 * @brief      Removes a cliente.
	 */
	void removeCliente();

	// menuFornecedor
	/**
	 * @brief      displays the Supplier Menu
	 */

	void menuFornecedor();

	/**
	 * @brief      displays the interface to add suppliers
	 */
	void adicionaFornecedor();

	/**
	 * @brief      Modifies a supplier
	 */

	void modificaFornecedor();

	/**
	 * @brief      Removes a supplier
	 */
	void removeFornecedor();

	//menuReservas
	/**
	 * @brief      displays the Reservations Menu
	 */
	void menuReservas();

	/**
	 * @brief      displays the interface to add reservations
	 */
	void adicionaReserva();

	/**
	 * @brief      displays the interface to modify reservations
	 */

	void modificaReserva();

	/**
	 * @brief      displays the interface to cancel reservations
	 */
	void cancelaReservas();

	//menuOfertas
	/**
	 * @brief      displays the interface to remove reservations
	 */

	void removeReservas();

	void menuFaturas();

	void listaFaturas();

	/**
	 * @brief      displays the offers Menu
	 */
	void menuOfertas();

	/**
	 * @brief      displays the interface to adds offers
	 */
	void adicionaOferta();

	/**
	 * @brief      displays the interface to modify offers
	 */
	void modificaOferta();
	/**
	 * @brief      displays the interface to remove offers
	 */
	void removeOferta();

	/**
	 * @brief      displays all the information about the Clients
	 */

	void addOfertasQueue();
	
	void displayOfertasemOrdem();

	void displayClientes();

	/**
	 * @brief      displays all the information about the suppliers;
	 */
	void displayFornecedores();

	/**
	 * @brief      displays all the information about the suppliers all their
	 *             respective offers
	 */
	void displayFornecedorescomOfertas();

	/**
	 * @brief      displays all the information about the reservations
	 */
	void displayReservas();

	//metodos Empresa
	/**
	 * @brief      Gets the suppliers.
	 *
	 * @return     The fornecedores.
	 */
	const std::vector<Fornecedor*> & getFornecedores();

	/**
	 * @brief      Gets the clients.
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


	Empresa & desativaCliente(Cliente * c);

	Empresa & atualizaInatividade();

	Empresa & reativaCliente(Cliente * c);

	void displayClientesInativos();

};



//Exceptions

/**
 * @brief      Class for objeto repetido Exception
 *
 * @tparam     T     type of the repeated object
 */
template <class T>
class ObjetoRepetido{
private:
  std::string obj;
public:

  /**
   * @brief      Constructs the ObjetoRepetido Exception
   *
   * @param[in]  obj   The repeated object
   */
  ObjetoRepetido(std::string obj):obj(obj){};

  /**
   * @brief      Gets the object.
   *
   * @return     The object.
   */
  std::string getObj(){return this->obj;};

};


/**
 * @brief      Class for objeto inexistente Exception.
 *
 * @tparam     T     type of the not found object
 */
template<class T>
class ObjetoInexistente{
private:
  string obj;
public:

  /**
   * @brief      Constructs the ObjetoInexistente Exception.
   *
   * @param[in]  obj   The not found object
   */
  ObjetoInexistente(std::string obj):obj(obj){};

  /**
   * @brief      Gets the object.
   *
   * @return     The object.
   */
  std::string getObj(){return this->obj;};

};

//Overload do operador << para as exceptions


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
