 #include <iostream>
#include "menu.h"
#include "extras.h"
#include "cruise.h"
#include <climits>
#include "BST.h"

using namespace std;

/**
 * @brief      Displays the company title
 */
void Empresa::titulo() {


	clearScreen();

	cout << "__________              __           __________.__                               \n";
	cout << "\\______   \\____________/  |_  ____   \\______   \\__|__  __ ___________  ______      \n";
	cout << " |     ___/  _ \\_  __ \\   __\\/  _ \\   |       _/  \\  \\/ // __ \\_  __ \\/  ___/    \n";
	cout << " |    |  (  <_> )  | \\/|  | (  <_> )  |    |   \\  |\\   /\\  ___/|  | \\/\\___ \\   \n";
	cout << " |____|   \\____/|__|   |__|  \\____/   |____|_  /__| \\_/  \\_____>__|  /_____ >\n";
	cout << "                                             \\/                            \\/       \n";
	cout << "\n";

}


/**
 * @brief      displays the client menu
 */
void Empresa::menuCliente() {


	int opcaocliente;
	while (true) {
		titulo();
		cout << "+----------------------------------------------------------+\n";
		cout << "| Escolha o que pretende fazer com os clientes             |\n";
		cout << "+----------------------------------------------------------+\n";
		cout << "| Selecione a sua opcao (insira apenas o numero):          |\n";
		cout << "+----------------------------------------------------------+ \n";
		cout << "| 1 - Adicionar Cliente                                    |\n";
		cout << "| 2 - Modificar Cliente                                    |\n";
		cout << "| 3 - Apagar Cliente                                       |\n";
		cout << "| 4 - Ver todos os Clientes                                |\n";
		cout << "| 0 - Sair                                                 |\n";
		cout << "+----------------------------------------------------------+\n";

		cin >> opcaocliente;

		if (cin.fail()){
			cin.clear();
			cin.ignore(INT_MAX,'\n');
			clearScreen();
			cout << "Erro: Introduziu um input invalido. So pode usar numeros inteiros." << endl;
			cout << "Pressione Enter para voltar ao menu" << endl;
			cin.get();
		}
		switch (opcaocliente) {

		case 0:
			return;
			break;

		case 1:
			adicionaCliente();
			break;
		case 2:
			modificaCliente();
			break;
		case 3:
			removeCliente();
			break;
		
		case 4:
			displayClientes();
			cin.get();
			cin.get();
			break;
			
		default:
			cout << "Lamento, mas a opcao que inseriu nao e valida. Sera redirecionado/a para o inicio do menu. \n";


		}
		
	}
}

void Empresa::adicionaCliente() {


	titulo();

	int opcaoRegisto;
	bool clientechoice = true;
	while (clientechoice) {

		cout << "+----------------------------------------------------------+\n";
		cout << "| Pretende tornar-se um cliente registado?                 |\n";
		cout << "+----------------------------------------------------------+\n";
		cout << "| Selecione a sua opcao (insira apenas o numero):          |\n";
		cout << "+----------------------------------------------------------+\n";
		cout << "| 1 - Sim (tera conta registada e acumulara pontos)        |\n";
		cout << "| 2 - Nao (continuara como cliente normal)                 |\n";
		cout << "| 0 - Sair                                                 |\n";
		cout << "+----------------------------------------------------------+\n";
		cin >> opcaoRegisto;
		if (cin.fail()){
			cin.clear();
			cin.ignore(INT_MAX,'\n');
			clearScreen();
			cout << "Erro: Introduziu um input invalido. So pode usar numeros inteiros." << endl;
			cout << "Pressione Enter para voltar ao menu" << endl;
			cin.get();
		}
		switch (opcaoRegisto) {
		case 0:
			return;
			break;
		case 1:
			adicionaClienteRegistado();
			clientechoice = false;
			break;
		case 2:
			adicionaClienteNormal();
			clientechoice = false;
			break;
		default:
			cout << "Lamento, mas a opcao que inseriu nao e valida. Sera redirecionado/a para o inicio do menu. \n";
		}

	}


}

void Empresa::adicionaClienteNormal() {

	titulo();
	string nomeCliente;
	string morada;

	cout << "+----------------------------------------------------------+\n";
	cout << "| Qual e o seu nome?                                       |\n";
	cout << "+----------------------------------------------------------+\n";

	cin.ignore (INT_MAX,'\n');
	getline(cin,nomeCliente);

	cout << "+----------------------------------------------------------+\n";
	cout << "| Qual a sua morada?                                       |\n";
	cout << "+----------------------------------------------------------+\n";

	Cliente * novocliente = new Cliente(nomeCliente, morada);
	addClientes(*novocliente);
	this->sort();
	return;

}

void Empresa::adicionaClienteRegistado() {

	titulo();
	string nomeClienteRegistado;

	cout << "+----------------------------------------------------------+\n";
	cout << "| Com que nome pretende ficar registado?                   |\n";
	cout << "+----------------------------------------------------------+\n";

	cin.ignore(INT_MAX, '\n');
	getline(cin,nomeClienteRegistado);
	Cliente * novoClienteRegistado = new ClienteRegistado(nomeClienteRegistado, 0);
	addClientes(*novoClienteRegistado);
	this->sort();
	cout << "Pressione Enter para regressar\n";
	cin.get();
	return;

}

void Empresa::modificaCliente() {

	titulo();
	string nome_cliente, novonome,novaMorada;
	int modifica, pontos;
	ClienteRegistado *cliente = NULL;


	cout << "+----------------------------------------------------------+\n";
	cout << "| Qual e o nome do cliente?                                |\n";
	cout << "+----------------------------------------------------------+\n";

	cin.ignore(INT_MAX, '\n');
	getline(cin, nome_cliente);


	int index = BinarySearch(_clientes, nome_cliente);
	try{
	if (index == -1) { throw ObjetoInexistente<string>(nome_cliente); }
	}
	catch(ObjetoInexistente<string> & ex){
		clearScreen();
		cout << "O cliente " << ex << " nao existe. " << endl;
		cout << "Pressione enter para regressar ao menu" << endl;
		cin.get();
		return;
	}


	cout << "+----------------------------------------------------------+\n";
	cout << "| Que propriedade do cliente pretende modificar?           |\n";
	cout << "+----------------------------------------------------------+\n";
	cout << "| 1 - Nome                                                 |\n";
	cout << "| 2 - Pontos                                               |\n";
	cout << "| 3 - Estatuto de Registado                                |\n";
	cout << "| 0 - Sair                                                 |\n";
	cout << "+----------------------------------------------------------+\n";

	cin >> modifica;

	switch (modifica) {
	case 0:
		return;
		break;
	case 1:
		cout << "+----------------------------------------------------------+\n";
		cout << "| Indique o novo nome:                                     |\n";
		cout << "+----------------------------------------------------------+\n";

		cin.ignore(INT_MAX, '\n');
		getline(cin, novonome);
		_clientes.at(index)->setNome(novonome);
		break;

	case 2:

		if (_clientes.at(index)->isRegistado()) {
			cout << "+----------------------------------------------------------+\n";
			cout << "| Indique os pontos:                                       |\n";
			cout << "+----------------------------------------------------------+\n";

			cin >> pontos;
			_clientes.at(index)->setPontos(pontos);
		}
		else cout << "Esse cliente nao esta registado, logo nao tem pontos. Registe-o antes de utilizar os pontos. \n";

		break;

	case 3:
		if(this->_clientes.at(index)->isRegistado()){
			cout << "O cliente ja se encontra registado" << endl;
			cout << "Pressione Enter para regressar ao menu" << endl;
			cin.get();
		}
		else{
		novonome = _clientes.at(index)->getNome();
		novaMorada = _clientes.at(index)->getMorada();
		_clientes.at(index) = new ClienteRegistado(novonome, novaMorada,0);
		}
		break;

	
	default:
		cout << "Essa opcao nao e viavel. Pressione Enter para voltar ao menu anterior.";

	}
	cin.get();
	return;

}

void Empresa::removeCliente() {
	titulo();

	displayClientes();
	string clienteremover;
	int quickmaths;

	cout << "+----------------------------------------------------------+\n";
	cout << "| Qual e o cliente a remover?	                            |\n";
	cout << "+----------------------------------------------------------+\n";

	cin.ignore(INT_MAX, '\n');
	getline(cin, clienteremover);
	

	try {
		int index = BinarySearch(_clientes, clienteremover);
		if (index == -1) { throw ObjetoInexistente<string>(clienteremover); }
	}
	catch (ObjetoInexistente<string> & ex) {
		cout << "Cliente nao encontrado: " << clienteremover << endl;
		cout << "Pressione Enter para voltar ao menu";
		cin.get();
		return;
	}

	deleteClientes(clienteremover);
	cout << endl << "O cliente foi removido com sucesso" << endl;
	cout << "Pressione Enter para regressar" << endl;
	cin.get();
	return;
	

}


void Empresa::menuFornecedor() {

	int opcaofornecedor;

	while(true){
	titulo();
	cout << "+----------------------------------------------------------+\n";
	cout << "| Escolha o que pretende fazer com os fornecedores         |\n";
	cout << "+----------------------------------------------------------+\n";
	cout << "| Selecione a sua opcao (insira apenas o numero):          |\n";
	cout << "+----------------------------------------------------------+ \n";
	cout << "| 1 - Adicionar Fornecedor                                 |\n";
	cout << "| 2 - Modificar Fornecedor                                 |\n";
	cout << "| 3 - Apagar Fornecedor                                    |\n";
	cout << "| 4 - Ver Fornecedores (sem ofertas)                      |\n";
	cout << "| 5 - Ver Fornecedores (com ofertas)                      |\n";
	cout << "| 0 - Sair                                                 |\n";
	cout << "+----------------------------------------------------------+\n";

	cin >> opcaofornecedor;
	if (cin.fail()) {
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		clearScreen();
		cout << "Erro: Introduziu um input invalido. So pode usar numeros inteiros." << endl;
		cout << "Pressione Enter para voltar ao menu" << endl;
		cin.get();
	}
	switch (opcaofornecedor) {

	case 0:
		cout << "\n" << "Agradecemos a utilizacao do nosso servico, a aplicacao ira agora fechar.";
		return;
		break;

	case 1:
		adicionaFornecedor();
		break;
	case 2:
		modificaFornecedor();
		break;
	case 3:
		removeFornecedor();
		break;
	case 4:
		displayFornecedores();
		cin.get();
		cin.get();
		break;
	case 5:
		displayFornecedorescomOfertas();
		cin.get();
		cin.get();

	default:
		cout << "Lamento, mas a opcao que inseriu nao e valida. Sera redirecionado/a para o inicio do menu. \n";


	}

}
}

void Empresa::adicionaFornecedor() {

	titulo();
	string nome_fornecedor, morada;
	int NIF;

	cout << "+----------------------------------------------------------+\n";
	cout << "| Qual e o nome do fornecedor?                             |\n";
	cout << "+----------------------------------------------------------+\n";

	cin.ignore(INT_MAX,'\n');
	getline(cin,nome_fornecedor);

	cout << "+----------------------------------------------------------+\n";
	cout << "| Indique o NIF:                                           |\n";
	cout << "+----------------------------------------------------------+\n";

	cin >> NIF;

	cout << "+----------------------------------------------------------+\n";
	cout << "| Indique a morada:                                        |\n";
	cout << "+----------------------------------------------------------+\n";

	cin.ignore(INT_MAX,'\n');
	getline(cin,morada);
	Fornecedor * novoFornecedor = new Fornecedor(nome_fornecedor, NIF, morada);
	novoFornecedor->setDefinicoesFornecedor();
	addFornecedores(*novoFornecedor);
	this->sort();
}


void Empresa::modificaFornecedor() {

	titulo();
	string nome_fornecedor, novonome,novamorada;
	int modifica;
	unsigned int novoNIF;


	cout << "+----------------------------------------------------------+\n";
	cout << "| Estes sao os fornecedores:                               |\n";
	cout << "+----------------------------------------------------------+\n";

	displayFornecedores();


	cout << "+----------------------------------------------------------+\n";
	cout << "| Qual e o nome do fornecedor?                             |\n";
	cout << "+----------------------------------------------------------+\n";

	cin.ignore(INT_MAX, '\n');
	getline(cin, nome_fornecedor);
	

	int index = BinarySearch(_fornecedores, nome_fornecedor);
	if (index == -1) { throw ObjetoInexistente<string>(nome_fornecedor); }


	cout << "+----------------------------------------------------------+\n";
	cout << "| Que propriedade do fornecedor pretende modificar?        |\n";
	cout << "+----------------------------------------------------------+\n";
	cout << "| 1 - Nome                                                 |\n";
	cout << "| 2 - NIF                                                  |\n";
	cout << "| 3 - Morada                                               |\n";
	cout << "| 4 - Definicoes de Fornecedor                             |\n";
	cout << "| 0 - Sair                                                 |\n";
	cout << "+----------------------------------------------------------+\n";

	cin >> modifica;
	
	switch (modifica) {
	case 0:
		return;
		break;
	case 1:
		cout << "+----------------------------------------------------------+\n";
		cout << "| Indique o novo nome:                                     |\n";
		cout << "+----------------------------------------------------------+\n";

		cin.ignore(INT_MAX, '\n');
		getline(cin, novonome);
		_fornecedores.at(index)->setNome(novonome);
		break;

	case 2:
		cout << "+----------------------------------------------------------+\n";
		cout << "| Indique o novo NIF:                                      |\n";
		cout << "+----------------------------------------------------------+\n";

		cin >> novoNIF;
		_fornecedores.at(index)->setNIF(novoNIF);
		break;

	case 3:
		cout << "+----------------------------------------------------------+\n";
		cout << "| Indique a nova morada:                                   |\n";
		cout << "+----------------------------------------------------------+\n";

		cin.ignore(INT_MAX, '\n');
		getline(cin, novamorada);
		_fornecedores.at(index)->setMorada(novamorada);
		break;
	
	case 4: _fornecedores.at(index)->setDefinicoesFornecedor();

	default:
		cout << "Essa opcao nao e viavel. Pressione Enter para voltar ao menu anterior.";

	}
	cin.get();
	return;

}
void Empresa::removeFornecedor() {
	titulo();

	string fornecedorremover;

	cout << "+----------------------------------------------------------+\n";
	cout << "| Estes sao os fornecedores:                               |\n";
	cout << "+----------------------------------------------------------+\n";

	displayFornecedores();
	
	
	cout << "+----------------------------------------------------------+\n";
	cout << "| Qual e o fornecedor a remover?                           |\n";
	cout << "+----------------------------------------------------------+\n";

	cin.ignore(INT_MAX, '\n');
	getline(cin, fornecedorremover);
	for (unsigned int i = 0; i < _fornecedores.size(); i++)
	{
		if (_fornecedores.at(i)->getNome() == fornecedorremover)
		{
			deleteFornecedores(fornecedorremover);
			cout << endl << "O fornecedor foi removido com sucesso" << endl;
			cout << "Pressione Enter para regressar" << endl;
			cin.get();
			return;
		}
	}

	cout << endl << "O fornecedor com esse nome nao foi encontrado" << endl;
	cout << "Pressione Enter para regressar" << endl;

	cin.get();
	return;
}

void Fornecedor::setDefinicoesFornecedor() {


	int porpessoa, iate, barco_rabelo, veleiro;

	definicoesfornecedor.erase(definicoesfornecedor.begin(), definicoesfornecedor.end()); //limpa_o_vetor, caso tivesse definicoes prévias


	cout << "+----------------------------------------------------------+\n";
	cout << "| Quanto pretende que custe, por pessoa, a reserva?        |\n";
	cout << "+----------------------------------------------------------+\n";

	cin >> porpessoa;


	cout << "+----------------------------------------------------------+\n";
	cout << "| Indique o preco base para a reserva de um iate:          |\n";
	cout << "+----------------------------------------------------------+\n";

	cin >> iate;

	cout << "+----------------------------------------------------------+\n";
	cout << "| Indique o preco base para a reserva de um barco rabelo:  |\n";
	cout << "+----------------------------------------------------------+\n";

	cin >> barco_rabelo;

	cout << "+----------------------------------------------------------+\n";
	cout << "| Indique o preco base para a reserva de um veleiro:       |\n";
	cout << "+----------------------------------------------------------+\n";

	cin >> veleiro;
	
	definicoesfornecedor.push_back(porpessoa);
	definicoesfornecedor.push_back(iate);
	definicoesfornecedor.push_back(barco_rabelo);
	definicoesfornecedor.push_back(veleiro);

	cout << "+----------------------------------------------------------+\n";
	cout << "| As definicoes de fornecedor foram registadas com sucesso.|\n";
	cout << "| Pressione a tecla Enter para sair                        |\n";
	cout << "+----------------------------------------------------------+\n";


	return;
}

void Empresa::menuReservas() {


	int opcaoreservas;
	while (true) {
		titulo();
		cout << "+----------------------------------------------------------+\n";
		cout << "| Escolha o que pretende fazer com as reservas             |\n";
		cout << "+----------------------------------------------------------+\n";
		cout << "| Selecione a sua opcao (insira apenas o numero):          |\n";
		cout << "+----------------------------------------------------------+ \n";
		cout << "| 1 - Adicionar Reserva                                    |\n";
		cout << "| 2 - Modificar Reserva                                    |\n";
		cout << "| 3 - Cancelar Reserva                                     |\n";
		cout << "| 4 - Apagar Reserva                                       |\n";
		cout << "| 5 - Ver Reservas                                         |\n";
		cout << "| 0 - Sair                                                 |\n";
		cout << "+----------------------------------------------------------+\n";

		cin >> opcaoreservas;

		if (cin.fail()){
			cin.clear();
			cin.ignore(INT_MAX,'\n');
			clearScreen();
			cout << "Erro: Introduziu um input invalido. So pode usar numeros inteiros." << endl;
			cout << "Pressione Enter para voltar ao menu" << endl;
			cin.get();
			return;
		}
		switch (opcaoreservas) {

		

		case 1:
			adicionaReserva();
			break;
		case 2:
			modificaReserva();
			break;
		case 3:
			cancelaReservas();
			break;
		case 4:
			removeReservas();
			break;
		case 5:
			displayReservas();
			cin.get();
			cin.get();
			break;

		case 0:
			return;

		default:
			cout << "Lamento, mas a opcao que inseriu nao e valida. Sera redirecionado/a para o inicio do menu. \n";
			return;
			

		}

	}
	return;
}

void Empresa::adicionaReserva() {

	titulo();
	string nome_fornecedor, nomeCliente, nomeOferta;
	unsigned int  preco,lotacao;
	bool cancelada = false;
	bool erroNome = false;
	vector<Oferta*> ofertas;

	
	cout << "+----------------------------------------------------------+\n";
	cout << "| Estes sao os clientes:                                   |\n";
	cout << "+----------------------------------------------------------+\n";

	displayClientes();

	cout << "+----------------------------------------------------------+\n";
	cout << "| Indique o nome do cliente:                               |\n";
	cout << "+----------------------------------------------------------+\n";
	cin.ignore(INT_MAX,'\n');
	getline(cin, nomeCliente);

	int indexCliente = BinarySearch(_clientes, nomeCliente);
	try{
	if (indexCliente == -1) { throw ObjetoInexistente<string>(nomeCliente); }
	}
	catch(ObjetoInexistente<string> & ex){
		cout << "O cliente " << ex << " nao existe" << endl;
		cout << "Pressione Enter para regressar ao menu anterior" << endl;
		cin.get();
		return;
	}
	
	cout << "+----------------------------------------------------------+\n";
	cout << "| Estes sao todos os fornecedores e respetivas ofertas     |\n";
	cout << "+----------------------------------------------------------+\n";
	
	displayFornecedorescomOfertas();

	cout << "+----------------------------------------------------------+\n";
	cout << "| Indique o nome do fornecedor:                            |\n";
	cout << "+----------------------------------------------------------+\n";


	getline(cin, nome_fornecedor);
	int index = BinarySearch(_fornecedores, nome_fornecedor);
	try{
	if (index == -1) { throw ObjetoInexistente<string>(nome_fornecedor); }
	}
	catch(ObjetoInexistente<string> & ex){
		cout << "O fornecedor " << ex << " nao existe" << endl;
		cout << "Pressione Enter para regressar ao menu anterior" << endl;
		cin.get();
		return;
	}

	cout << "+----------------------------------------------------------+\n";
	cout << "| Estas sao as suas ofertas:                               |\n";
	cout << "+----------------------------------------------------------+\n";

	_fornecedores.at(index)->displayOfertas();

	cout << "+----------------------------------------------------------+\n";
	cout << "| Indique o nome da oferta que pretende reservar:          |\n";
	cout << "+----------------------------------------------------------+\n";
	
	getline(cin, nomeOferta);

	for (unsigned int k = 0; k < _fornecedores.at(index)->getOfertas().size(); k++)
	{
		if (_fornecedores.at(index)->getOfertas().at(k).getNome() == nomeOferta)
		{
			ofertas.push_back(&_fornecedores.at(index)->getOfertas()[k]);

		}
		else
			erroNome = true;

	}

	if (erroNome)
	{
		cout << "Esse nome de oferta nao existe. Pressione Enter para tentar novamente.";
		cin.get();
		return;
	}

	cout << "+----------------------------------------------------------+\n";
	cout << "| Indique para quantas pessoas quer efetuar a reserva:     |\n";
	cout << "+----------------------------------------------------------+\n";

	cin >> lotacao;

	if (lotacao <= ofertas[0]->getLotacao())
		ofertas[0]->diminuiLotacao(lotacao);
	else {
		cout << "Esse numero de pessoas excede o limite na oferta. Pressione Enter regressar.";
		cin.get();
		return;
	}

	cin.get();


	preco = _fornecedores.at(index)->calculaPreco(ofertas[0]->getBarcoNumber(),  lotacao, ofertas[0]->getDistancia());
	Reserva * novaReserva = new Reserva(nome_fornecedor, ofertas[0], nomeCliente, _clientes.at(indexCliente), preco, cancelada);
	addReservas(*novaReserva);  
	Fatura * novaFatura = new Fatura(*novaReserva);
	BTNode<Fatura*> * no = new BTNode<Fatura*>(novaFatura);
	this->_faturas.addNode(no, this->_faturas.getRoot());
	RealTime tempoReserva;
	for (unsigned int l = 0; l < _fornecedores.at(index)->getOfertas().size(); l++)
	{
		if (_fornecedores.at(index)->getOfertas().at(l).getNome() == nomeOferta)
		{
			_fornecedores.at(index)->getOfertas().at(l).setTimeUltimaReserva(tempoReserva);

		}
		else
			erroNome = true;
	}
	
	cout << "+----------------------------------------------------------+\n";
	cout << "| A oferta foi reservada com sucesso.                      |\n";
	cout << "+----------------------------------------------------------+\n";
	this->sort();

}

void Empresa::modificaReserva()
{
	titulo();
	string nome_fornecedor, novonome, novamorada;
	int modifica;
	unsigned int novoNIF;


	cout << "+----------------------------------------------------------+\n";
	cout << "| Qual e o nome do fornecedor?                             |\n";
	cout << "+----------------------------------------------------------+\n";

	cin.ignore(INT_MAX, '\n');
	getline(cin, nome_fornecedor);


	int index = BinarySearch(_fornecedores, nome_fornecedor);
	if (index == -1) { throw ObjetoInexistente<string>(nome_fornecedor); }


	cout << "+----------------------------------------------------------+\n";
	cout << "| Que propriedade do fornecedor pretende modificar?        |\n";
	cout << "+----------------------------------------------------------+\n";
	cout << "| 1 - Nome                                                 |\n";
	cout << "| 2 - NIF                                                  |\n";
	cout << "| 3 - Morada                                               |\n";
	cout << "| 4 - Definicoes de Fornecedor                             |\n";
	cout << "| 0 - Sair                                                 |\n";
	cout << "+----------------------------------------------------------+\n";

	cin >> modifica;

	switch (modifica) {
	case 0:
		return;
		break;
	case 1:
		cout << "+----------------------------------------------------------+\n";
		cout << "| Indique o novo nome:                                     |\n";
		cout << "+----------------------------------------------------------+\n";

		cin.ignore(INT_MAX, '\n');
		getline(cin, novonome);
		_fornecedores.at(index)->setNome(novonome);
		break;

	case 2:
		cout << "+----------------------------------------------------------+\n";
		cout << "| Indique o novo NIF:                                      |\n";
		cout << "+----------------------------------------------------------+\n";

		cin >> novoNIF;
		_fornecedores.at(index)->setNIF(novoNIF);
		break;

	case 3:
		cout << "+----------------------------------------------------------+\n";
		cout << "| Indique a nova morada:                                   |\n";
		cout << "+----------------------------------------------------------+\n";

		cin.ignore(INT_MAX, '\n');
		getline(cin, novamorada);
		_fornecedores.at(index)->setMorada(novamorada);
		break;

	case 4: _fornecedores.at(index)->setDefinicoesFornecedor();

	default:
		cout << "Essa opcao nao e viavel. Pressione Enter para voltar ao menu anterior.";

	}
	cin.get();
	return;

}



void Empresa::removeReservas() {
	titulo();

	cout << "+----------------------------------------------------------+\n";
	cout << "| Estas sao as reservas disponiveis para remover:          |\n";
	cout << "+----------------------------------------------------------+\n";

	displayReservas();

	string reservaremoveOferta, reservaremoveCliente;
	cout << "+----------------------------------------------------------+\n";
	cout << "| Indique o nome do cliente cuja oferta quer remover:      |\n";
	cout << "+----------------------------------------------------------+\n";

	cin.ignore(INT_MAX, '\n');
	getline(cin, reservaremoveCliente);

	cout << "+----------------------------------------------------------+\n";
	cout << "| Indique o nome da oferta reservada pelo cliente:         |\n";
	cout << "+----------------------------------------------------------+\n";


	getline(cin, reservaremoveOferta);

	for (unsigned int i = 0; i < _reservas.size(); i++)
	{
		if (_reservas.at(i)->getOferta()->getNome() == reservaremoveOferta && _reservas.at(i)->getCliente()->getNome() == reservaremoveCliente)
		{
			deleteReservas(reservaremoveOferta);
		}
	}

	cout << "+----------------------------------------------------------+\n";
	cout << "| Reserva apagada com sucesso!                             |\n";
	cout << "| Pressione a tecla Enter para sair                        |\n";
	cout << "+----------------------------------------------------------+\n";

	cin.get();
	return;
}

void Empresa::cancelaReservas() {
	titulo();
	int novoPreco;

	cout << "+----------------------------------------------------------+\n";
	cout << "| Estas sao as reservas disponíveis:                       |\n";
	cout << "+----------------------------------------------------------+\n";

	displayReservas();

	string reservaremoveOferta,reservaremoveCliente;
	cout << "+----------------------------------------------------------+\n";
	cout << "| Indique o nome do cliente cuja oferta quer cancelar      |\n";
	cout << "+----------------------------------------------------------+\n";

    cin.ignore(INT_MAX,'\n');
	getline(cin,reservaremoveCliente);
	
	cout << "+----------------------------------------------------------+\n";
	cout << "| Indique o nome da oferta reservada pelo cliente:         |\n";
	cout << "+----------------------------------------------------------+\n";

	
	getline(cin, reservaremoveOferta);

	for (unsigned int i = 0; i < _reservas.size(); i++)
	{
		if (_reservas.at(i)->getOferta()->getNome() == reservaremoveOferta && _reservas.at(i)->getCliente()->getNome() == reservaremoveCliente)
		{
			if (_reservas.at(i)->getOferta()->getDataMesmo().diferencaDias() >= 7)
			{
				_reservas.at(i)->cancelamento();
				_reservas.at(i)->setPreco(0);
				break;
			}
			else if (_reservas.at(i)->getOferta()->getDataMesmo().diferencaDias() >= 2)
			{
				_reservas.at(i)->cancelamento();
				novoPreco = _reservas.at(i)->getPreco() / 2;
				_reservas.at(i)->setPreco(novoPreco);
				break;
			}
			else
				_reservas.at(i)->cancelamento();

		}
	}

	cout << "+----------------------------------------------------------+\n";
	cout << "| Reserva cancelada com sucesso!                           |\n";
	cout << "| Pressione a tecla Enter para sair                        |\n";
	cout << "+----------------------------------------------------------+\n";

	cin.get();
	return;


}

void Empresa::menuOfertas() {



	int opcaoOfertas;
	while (true) {
		titulo();
		cout << "+----------------------------------------------------------+\n";
		cout << "| Escolha o que pretende fazer com as Ofertas              |\n";
		cout << "+----------------------------------------------------------+\n";
		cout << "| Selecione a sua opcao (insira apenas o numero):          |\n";
		cout << "+----------------------------------------------------------+\n";
		cout << "| 1 - Adicionar Oferta                                     |\n";
		cout << "| 2 - Modificar Oferta                                     |\n";
		cout << "| 3 - Apagar Oferta                                        |\n";
		cout << "| 4 - Ver Ofertas                                          |\n";
		cout << "| 0 - Sair                                                 |\n";
		cout << "+----------------------------------------------------------+\n";
		cin >> opcaoOfertas;
		if (cin.fail()){
			cin.clear();
			cin.ignore(INT_MAX,'\n');
			clearScreen();
			cout << "Erro: Introduziu um input invalido. So pode usar numeros inteiros." << endl;
			cout << "Pressione Enter para voltar ao menu" << endl;
			cin.get();
		}
		switch (opcaoOfertas) {

		case 1:
			adicionaOferta();
			break;
		case 2:
			modificaOferta();
			break;
		case 3:
			removeOferta();
			break;
		case 4:
			displayFornecedorescomOfertas();
			cin.get();
			cin.get();
			break;

		case 0:
			return;
			break;

		default:
			cout << "Lamento, mas a opcao que inseriu nao e valida. Tente outra vez" << endl;
			cout << "Pressione Enter para repetir" << endl;
			cin.get();
			clearScreen();

		}

	}
} 

void Empresa::adicionaOferta() {

	titulo();
	std::string nome;
	std::string barco;
	int numeroBarco;
	std::string temp;
	std::vector<std::string> destinos;
	Oferta * novaOferta;
	unsigned int distancia;
	unsigned int preco;
	int lotacao;
	std::string data;
	Time * tempo;
	int index;

	displayFornecedores();

	cout << "+----------------------------------------------------------+\n";
	cout << "| Qual e o nome do fornecedor?                             |\n";
	cout << "+----------------------------------------------------------+\n";

	cin.ignore(INT_MAX,'\n');
	getline(cin,nome);
	index = BinarySearch(this->_fornecedores,nome);
	if(index == -1){
		throw ObjetoInexistente<string>(nome);
	}
	

	cout << "+----------------------------------------------------------+\n";
	cout << "| Qual e o nome da oferta?                                 |\n";
	cout << "+----------------------------------------------------------+\n";

	getline(cin,nome);

	cout << "+----------------------------------------------------------+\n";
	cout << "| Escolha o tipo de barco:                                 |\n";
	cout << "+----------------------------------------------------------+\n";
	cout << "| 1 - Iate                                                 |\n";
	cout << "| 2 - Barco rabelo                                         |\n";
	cout << "| 3 - Veleiro                                              |\n";
	cout << "+----------------------------------------------------------+\n";

	cin >> numeroBarco;
	switch (numeroBarco) {
	case 1: 
		barco = "iate";
		break;
	case 2:
		barco = "barco rabelo";
		break;
	case 3:
		barco = "veleiro";
		break;
	default:
		cout << "Esse número nao é reconhecido como barco.";
		

	}



	cout << "+----------------------------------------------------------+\n";
	cout << "| Indique os destinos (escreva FIM quando terminar):       |\n";
	cout << "+----------------------------------------------------------+\n";
	cin.ignore(INT_MAX,'\n');
	while (temp != "FIM")
	{
		getline(cin,temp);
		if(temp != "FIM"){
		 destinos.push_back(temp);
		}
		cout << "\n";
	}

	cout << "+----------------------------------------------------------+\n";
	cout << "| Indique a distancia total percorrida:                    |\n";
	cout << "+----------------------------------------------------------+\n";

	cin >> distancia;

	cout << "+----------------------------------------------------------+\n";
	cout << "| Indique a lotacao total do barco:                        |\n";
	cout << "+----------------------------------------------------------+\n";

	cin >> lotacao;

	cout << "+----------------------------------------------------------+\n";
	cout << "| Indique a data da viagem (YY/MM/DD H:M):                 |\n";
	cout << "+----------------------------------------------------------+\n";

	cin.ignore(INT_MAX,'\n');
	getline(cin,data);
	tempo = new Time(data);

	preco = _fornecedores.at(index)->calculaPreco(numeroBarco, lotacao, distancia);
	
	
	novaOferta = new Oferta(nome, barco, destinos, distancia, lotacao, *tempo, preco);
	this->_fornecedores[index]->addOferta(*novaOferta);

}

void Empresa::modificaOferta()
{

	titulo();
	int modifica, indexOferta;
	string nomeCliente, nomeOferta, novonome, novobarco, novahora, novodestino, temp;
	unsigned int novopreco, novalotacao, novadistancia;
	std::vector<std::string> novosdestinos;
	Time *tempo;






	cout << "+----------------------------------------------------------+\n";
	cout << "| Indique o nome do cliente cuja oferta quer remover:      |\n";
	cout << "+----------------------------------------------------------+\n";

	cin.ignore(INT_MAX, '\n');
	getline(cin, nomeCliente);

	int index = BinarySearch(_clientes, nomeCliente);
	if (index == -1) { throw ObjetoInexistente<string>(nomeCliente); }

	cout << "+----------------------------------------------------------+\n";
	cout << "| Indique o nome da oferta reservada pelo cliente:         |\n";
	cout << "+----------------------------------------------------------+\n";

	getline(cin, nomeOferta);

	for (unsigned int i = 0; i < _reservas.size(); i++)
	{
		if (_reservas.at(i)->getOferta()->getNome() == nomeOferta && _reservas.at(i)->getCliente()->getNome() == nomeCliente)
		{
			indexOferta = i;
		}
	}


	cout << "+----------------------------------------------------------+\n";
	cout << "| Que propriedade da oferta é que pretende modificar?      |\n";
	cout << "+----------------------------------------------------------+\n";
	cout << "| 1 - Nome                                                 |\n";
	cout << "| 2 - Tipo de Barco                                        |\n";
	cout << "| 3 - Destinos                                             |\n";
	cout << "| 4 - Distancia                                            |\n";
	cout << "| 5 - Lotacao                                              |\n";
	cout << "| 6 - Data e Hora                                          |\n";
	cout << "| 7 - Preco                                                |\n";
	cout << "| 0 - Sair                                                 |\n";
	cout << "+----------------------------------------------------------+\n";

	cin >> modifica;

	switch (modifica) {
	case 0:
		return;
		break;
	case 1:
		cout << "+----------------------------------------------------------+\n";
		cout << "| Indique o novo nome:                                     |\n";
		cout << "+----------------------------------------------------------+\n";

		cin.ignore(INT_MAX, '\n');
		getline(cin, novonome);
		_reservas.at(indexOferta)->getOferta()->setNome(novonome);
		break;

	case 2:

		cout << "+----------------------------------------------------------+\n";
		cout << "| Escolha o tipo de barco:                                 |\n";
		cout << "+----------------------------------------------------------+\n";
		cout << "| 1 - Iate                                                 |\n";
		cout << "| 2 - Barco Rabelo                                         |\n";
		cout << "| 3 - Veleiro                                              |\n";
		cout << "+----------------------------------------------------------+\n";

		int numeroBarco;
		cin >> numeroBarco;
		if (numeroBarco == 1) {
			novobarco = "iate";
			_reservas.at(indexOferta)->getOferta()->setBarco(novobarco);
		}
		else if (numeroBarco == 2) {
			novobarco = "barco rabelo";
			_reservas.at(indexOferta)->getOferta()->setBarco(novobarco);
		}
		else if (numeroBarco == 3) {
			novobarco = "veleiro";
			_reservas.at(indexOferta)->getOferta()->setBarco(novobarco);
		}
		else
			cout << "Esse número nao é reconhecido como barco.";
		break;
		return;



	case 3:
		cout << "+----------------------------------------------------------+\n";
		cout << "| Indique os novos destinos (os anteriores serao apagados):|\n";
		cout << "| Para terminar, escreva FIM                               |\n";
		cout << "+----------------------------------------------------------+\n";
		_reservas.at(indexOferta)->getOferta()->apagaDestinos();
		cin.ignore(INT_MAX, '\n');

		while (temp != "FIM")
		{
			getline(cin, temp);
			if (temp != "FIM") {
				novosdestinos.push_back(temp);
			}
			cout << "\n";
		}
		_reservas.at(indexOferta)->getOferta()->setDestinos(novosdestinos);
		break;

	case 4:
		cout << "+----------------------------------------------------------+\n";
		cout << "| Indique a nova distancia:                                |\n";
		cout << "+----------------------------------------------------------+\n";
		cin >> novadistancia;
		_reservas.at(indexOferta)->getOferta()->setDistancia(novadistancia);
		break;

	case 5:
		cout << "+----------------------------------------------------------+\n";
		cout << "| Indique a nova lotacao total:                            |\n";
		cout << "+----------------------------------------------------------+\n";
		cin >> novalotacao;
		_reservas.at(indexOferta)->getOferta()->setLotacao(novalotacao);
		break;

	case 6:

		cout << "+----------------------------------------------------------+\n";
		cout << "| Indique a data da viagem (YY/MM/DD H:M):                 |\n";
		cout << "+----------------------------------------------------------+\n";

		cin.ignore(INT_MAX, '\n');
		getline(cin, novahora);
		tempo = new Time(novahora);
		_reservas.at(indexOferta)->getOferta()->setTime(*tempo);
		break;



	case 7:
		cout << "+----------------------------------------------------------+\n";
		cout << "| Indique o novo preco total:                              |\n";
		cout << "+----------------------------------------------------------+\n";
		cin >> novopreco;
		_reservas.at(indexOferta)->getOferta()->setPreco(novopreco);
		break;


	default:
		cout << "Essa opcao nao é viável. Pressione Enter para voltar ao menu anterior.";

	}
	cin.get();
	return;
}

void Empresa::removeOferta() {


	titulo();

	string ofertaremover, nomeFornecedor;


	cout << "+----------------------------------------------------------+\n";
	cout << "| Qual e o fornecedor com a oferta a remover?	            |\n";
	cout << "+----------------------------------------------------------+\n";

	displayFornecedorescomOfertas();

	cin.ignore(INT_MAX, '\n');
	getline(cin, nomeFornecedor);


	int index = BinarySearch(_fornecedores, nomeFornecedor);
	if (index == -1) { throw ObjetoInexistente<string>(nomeFornecedor); }


	cout << "+----------------------------------------------------------+\n";
	cout << "| Estas sao as ofertas desse fornecedor:                   |\n";
	cout << "+----------------------------------------------------------+\n";
	_fornecedores.at(index)->displayOfertas();

	cout << "+----------------------------------------------------------+\n";
	cout << "| Qual e a oferta a remover?	                            |\n";
	cout << "+----------------------------------------------------------+\n";


	cin.ignore(INT_MAX,'\n');

	getline(cin,ofertaremover);
	for (unsigned int i = 0; i < _fornecedores.at(index)->getOfertas().size(); i++)
	{
		if (ofertaremover == _fornecedores.at(index)->getOfertas().at(i).getNome())
			_fornecedores.at(index)->getOfertas().erase(_fornecedores.at(index)->getOfertas().begin() + i);
	}

	cout << "Oferta removida com sucesso" << endl;
	cout << "Pressione Enter para regressar" << endl;

}

void Empresa::menuTipodeUtilizador()
{
	
	
	int tipodeutilizador;
	while (true){
		titulo();
		
		cout << "+----------------------------------------------------------+\n";
		cout << "| Escolha o tipo de opcao sobre o qual quer trabalhar      |\n";
		cout << "+----------------------------------------------------------+\n";
		cout << "| Selecione a sua opcao (insira apenas o numero):          |\n";
		cout << "+----------------------------------------------------------+\n";
		cout << "| 1 - Gestao de Clientes                                   |\n";
		cout << "| 2 - Gestao de Fornecedores                               |\n";
		cout << "| 3 - Gestao de Reservas                                   |\n";
		cout << "| 4 - Gestao de Ofertas                                    |\n";
		cout << "| 0 - Sair                                                 |\n";
		cout << "+----------------------------------------------------------+\n";

		cin >> tipodeutilizador;

		if (cin.fail()){
			cin.clear();
			cin.ignore(INT_MAX,'\n');
			clearScreen();
			cout << "Erro: Introduziu um input invalido. So pode usar numeros inteiros." << endl;
			cout << "Pressione Enter para voltar ao menu" << endl;
			cin.get();
		}

		switch (tipodeutilizador) {

		case 0:
			cout << "\n" << "Agradecemos a utilizacao do nosso servico, a aplicacao ira agora fechar.\n";
			return;
			break;
		case 1:
			menuCliente();
			break;
		case 2:
			menuFornecedor();
			break;

		case 3:
			menuReservas();
			break;

		case 4:
			menuOfertas();
			break;
		default:
			clearScreen();
			cout << "Lamento, mas a opcao que inseriu nao e valida. Tente outra vez. \n";
			cin.get();
			clearScreen();
		}
	}
}

void Empresa::menuInicial()
{
	cout << "\n" << endl;
	titulo();
	cout << "\n";
	cout << "\n";
	cout << "Seja bem vindo ao gestor da Porto Rivers, aqui podera controlar todas as vertentes da sua empresa e visualizar toda a informacao de que necessita. \n";
	cout <<  "Pressione qualquer tecla para continuar" << endl;
	cin.get();
	menuTipodeUtilizador();
	clearScreen();

}
