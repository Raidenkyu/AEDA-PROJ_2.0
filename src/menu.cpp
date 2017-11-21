 #include <iostream>
#include "menu.h"
#include "extras.h"
#include "cruise.h"
#include <climits>

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
	cout << " |____|   \\____/|__|   |__|  \\____/   |____|_  /__| \\_/  \\_____>__|  /____  >\n";
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

		try{
		if (cin.fail()){
			cin.clear();
			cin.ignore(INT_MAX,'\n');
			throw InputInvalido<char>(opcaocliente);
		}
		}
		catch(InputInvalido<char> & ex){
			clearScreen();
			cout << "Erro: Introduziu um input invalido. So pode usar numeros inteiros. O seu input foi: " << ex << endl;
			cout << "Pressione Enter para voltar ao menu" << endl;
			cin.get();

		}

		switch (opcaocliente) {

		case 0:
			cout << "\n" << "Agradecemos a utilizacao do nosso servico, a aplicacao ira agora fechar.";
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
		try{
		cin >> opcaoRegisto;
		if (cin.fail()){
					cin.clear();
					cin.ignore(INT_MAX,'\n');
					throw InputInvalido<char>(opcaoRegisto);
				}
		}
		catch(InputInvalido<char> & ex){
					clearScreen();
					cout << "Erro: Introduziu um input invalido. So pode usar numeros inteiros. O seu input foi: " << ex << endl;
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

	cout << "+----------------------------------------------------------+\n";
	cout << "| Qual e o seu nome?                                       |\n";
	cout << "+----------------------------------------------------------+\n";

	cin.ignore (INT_MAX,'\n');
	getline(cin,nomeCliente);
	Cliente * novocliente = new Cliente(nomeCliente);
	addClientes(*novocliente);
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
	cout << "Pressione Enter para regressar\n";
	cin.get();
	return;

}

void Empresa::modificaCliente() {

	titulo();
	string nome_cliente, novonome;
	int modifica, pontos;
	ClienteRegistado *cliente = NULL;


	cout << "+----------------------------------------------------------+\n";
	cout << "| Qual e o nome do cliente?                                |\n";
	cout << "+----------------------------------------------------------+\n";

	cin.ignore(INT_MAX, '\n');
	getline(cin, nome_cliente);


	int index = BinarySearch(_clientes, nome_cliente);
	if (index = -1) { throw ObjetoInexistente<string>(nome_cliente); }


	cout << "+----------------------------------------------------------+\n";
	cout << "| Que propriedade do cliente é que pretende modificar?     |\n";
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
		else cout << "Esse cliente não é registado, logo não tem pontos. Registe-o antes de utilizar os pontos. \n";

		break;

	case 3:
		
		novonome = _clientes.at(index)->getNome();
		cliente = new ClienteRegistado(novonome, 0);
		_clientes.at(index) = cliente;
		break;

	
	default:
		cout << "Essa opção não é viável. Pressione Enter para voltar ao menu anterior.";

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

	getline(cin, clienteremover);
	

	try {
		int index = BinarySearch(_clientes, clienteremover);
		if (index == -1) { throw ObjetoInexistente<string>(clienteremover); }
	}
	catch (ObjetoInexistente<string> & ex) {
		cout << "Cliente não encontrado: " << clienteremover << endl;
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
	cout << "| 4 - Ver Fornecedores (sem reservas)                      |\n";
	cout << "| 5 - Ver Fornecedores (com reservas)                      |\n";
	cout << "| 0 - Sair                                                 |\n";
	cout << "+----------------------------------------------------------+\n";

	cin >> opcaofornecedor;
	try {
		if (cin.fail()) {
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			throw InputInvalido<char>(opcaofornecedor);
		}
	}
	catch (InputInvalido<char> & ex) {
		clearScreen();
		cout << "Erro: Introduziu um input invalido. So pode usar numeros inteiros. O seu input foi: " << ex << endl;
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
		//ModificaFornecedor();
		break;
	case 3:
		removeFornecedor();
		break;
	case 4:
		displayFornecedores();
		break;
	case 5:
		displayFornecedorescomOfertas();

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
	addFornecedores(*novoFornecedor);
	novoFornecedor->setDefinicoesFornecedor();
}


void Empresa::modificaFornecedor() {

	titulo();
	string nome_fornecedor, novonome,novamorada;
	int modifica;
	unsigned int novoNIF;


	cout << "+----------------------------------------------------------+\n";
	cout << "| Qual e o nome do fornecedor?                             |\n";
	cout << "+----------------------------------------------------------+\n";

	cin.ignore(INT_MAX, '\n');
	getline(cin, nome_fornecedor);
	

	int index = BinarySearch(_fornecedores, nome_fornecedor);
	if (index = -1) { throw ObjetoInexistente<string>(nome_fornecedor); }


	cout << "+----------------------------------------------------------+\n";
	cout << "| Que propriedade do fornecedor é que pretende modificar?  |\n";
	cout << "+----------------------------------------------------------+\n";
	cout << "| 1 - Nome                                                 |\n";
	cout << "| 2 - NIF                                                  |\n";
	cout << "| 3 - Morada                                               |\n";
	cout << "| 4 - Definições de Fornecedor                             |\n";
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

		getline(cin, novamorada);
		_fornecedores.at(index)->setMorada(novamorada);
		break;
	
	case 4: _fornecedores.at(index)->setDefinicoesFornecedor();

	default:
		cout << "Essa opção não é viável. Pressione Enter para voltar ao menu anterior.";

	}
	cin.get();
	return;

}
void Empresa::removeFornecedor() {
	titulo();

	string fornecedorremover;

	cout << "+----------------------------------------------------------+\n";
	cout << "| Estes são os fornecedores:                               |\n";
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

	cout << endl << "O fornecedor com esse nome não foi encontrado" << endl;
	cout << "Pressione Enter para regressar" << endl;

	cin.get();
	return;
}

void Fornecedor::setDefinicoesFornecedor() {


	int porpessoa, iate, barco_rebelo, veleiro;

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
	cout << "| Indique o preco base para a reserva de um barco rebelo:  |\n";
	cout << "+----------------------------------------------------------+\n";

	cin >> barco_rebelo;

	cout << "+----------------------------------------------------------+\n";
	cout << "| Indique o preco base para a reserva de um veleiro:       |\n";
	cout << "+----------------------------------------------------------+\n";

	cin >> veleiro;
	
	definicoesfornecedor.push_back(porpessoa);
	definicoesfornecedor.push_back(iate);
	definicoesfornecedor.push_back(barco_rebelo);
	definicoesfornecedor.push_back(veleiro);

	cout << "+----------------------------------------------------------+\n";
	cout << "| As definicoes de fornecedor foram registadas com sucesso.|\n";
	cout << "| Pressione a tecla Enter para sair                        |\n";
	cout << "+----------------------------------------------------------+\n";


	return;
}

void Empresa::menuReservas() {


	titulo();
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
		try{
		cin >> opcaoreservas;

		if (cin.fail())
			menuReservas();
		}
		catch(InputInvalido<char> & ex){
		clearScreen();
		cout << "Erro: Introduziu um input invalido. So pode usar numeros inteiros. O seu input foi: " << ex << endl;
		cout << "Pressione Enter para voltar ao menu" << endl;
		cin.get();
		}
		switch (opcaoreservas) {

		

		case 1:
			adicionaReserva();
			break;
		case 2:
			//ModificaReservas();
			break;
		case 3:
			cancelaReservas();
			break;
		case 4:
			removeReservas();
			break;
		case 5:
			displayReservas();
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
	int  preco,lotacao;
	bool cancelada = false;
	bool erroNome = false;
	vector<Oferta> vectorOfertasDisponiveis;
	Oferta * oferta = NULL;
	Cliente * cliente;

	
	cout << "+----------------------------------------------------------+\n";
	cout << "| Estes sao os clientes:                                   |\n";
	cout << "+----------------------------------------------------------+\n";

	displayClientes();

	cout << "+----------------------------------------------------------+\n";
	cout << "| Indique o nome do cliente:                               |\n";
	cout << "+----------------------------------------------------------+\n";

	getline(cin, nomeCliente);

	int indexCliente = BinarySearch(_clientes, nomeCliente);
	if (indexCliente == -1) { throw ObjetoInexistente<string>(nomeCliente); }
	
	cout << "+----------------------------------------------------------+\n";
	cout << "| Estes são todos os fornecedores e respetivas ofertas     |\n";
	cout << "+----------------------------------------------------------+\n";
	
	displayFornecedorescomOfertas();

	cout << "+----------------------------------------------------------+\n";
	cout << "| Indique o nome do fornecedor:                            |\n";
	cout << "+----------------------------------------------------------+\n";

	getline(cin, nome_fornecedor);
	int index = BinarySearch(_fornecedores, nome_fornecedor);
	if (index = -1) { throw ObjetoInexistente<string>(nome_fornecedor); }


	cout << "+----------------------------------------------------------+\n";
	cout << "| Estas são as suas ofertas:                               |\n";
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
			*oferta = _fornecedores.at(index)->getOfertas().at(k);

		}
		else
			erroNome = true;

	}

	if (erroNome)
	{
		cout << "Esse nome de oferta não existe. Pressione Enter para tentar novamente.";
		cin.get();
		return;
	}

	cout << "+----------------------------------------------------------+\n";
	cout << "| Indique para quantas pessoas quer efetuar a reserva:     |\n";
	cout << "+----------------------------------------------------------+\n";

	cin >> lotacao;

	if (lotacao <= oferta->getLotacao())
		oferta->diminuiLotacao(lotacao);
	else {
		cout << "Esse número de pessoas excede o limite na oferta. Pressione Enter para tentar novamente.";
		cin.get();
		return;
	}




	preco = _fornecedores.at(index)->calculaPreco(oferta->getBarcoNumber(),  lotacao);
	
	Reserva * novaReserva = new Reserva(nome_fornecedor, oferta, nomeCliente, _clientes.at(indexCliente), preco, cancelada);
	addReservas(*novaReserva);  

	cout << "+----------------------------------------------------------+\n";
	cout << "| A oferta foi reservada com sucesso.                      |\n";
	cout << "+----------------------------------------------------------+\n";

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
	if (index = -1) { throw ObjetoInexistente<string>(nome_fornecedor); }


	cout << "+----------------------------------------------------------+\n";
	cout << "| Que propriedade do fornecedor é que pretende modificar?  |\n";
	cout << "+----------------------------------------------------------+\n";
	cout << "| 1 - Nome                                                 |\n";
	cout << "| 2 - NIF                                                  |\n";
	cout << "| 3 - Morada                                               |\n";
	cout << "| 4 - Definições de Fornecedor                             |\n";
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

		getline(cin, novamorada);
		_fornecedores.at(index)->setMorada(novamorada);
		break;

	case 4: _fornecedores.at(index)->setDefinicoesFornecedor();

	default:
		cout << "Essa opção não é viável. Pressione Enter para voltar ao menu anterior.";

	}
	cin.get();
	return;
}

void Empresa::removeReservas() {
	titulo();

	cout << "+----------------------------------------------------------+\n";
	cout << "| Estas são as reservas disponíveis para remover:          |\n";
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
	cout << "| Estas são as reservas disponíveis:                       |\n";
	cout << "+----------------------------------------------------------+\n";

	displayReservas();

	string reservaremoveOferta,reservaremoveCliente;
	cout << "+----------------------------------------------------------+\n";
	cout << "| Indique o nome do cliente cuja oferta quer remover:      |\n";
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


	titulo();
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
		try{
		cin >> opcaoOfertas;
		if (cin.fail()){
			cin.clear();
			cin.ignore(INT_MAX,'\n');
			throw InputInvalido<char>(opcaoOfertas);
		}
		}
		catch(InputInvalido<char> & ex){
			clearScreen();
			cout << "Erro: Introduziu um input invalido. So pode usar numeros inteiros. O seu input foi: " << ex << endl;
			cout << "Pressione Enter para voltar ao menu" << endl;
			cin.get();

		}

		switch (opcaoOfertas) {

		case 1:
			adicionaOferta();
			break;
		case 2:
			//ModificaOfertas();
			break;
		case 3:
			//removeOfertas();
			break;
		case 4:
			displayFornecedorescomOfertas();
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
	std::string temp = "";
	std::vector<std::string> destinos;
	Oferta * novaOferta;
	unsigned int distancia;
	unsigned int preco;
	int lotacao;
	std::string data;
	Time * tempo;
	int index;

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
	cout << "| Escolha o tipo de barco:                                 |\n";
	cout << "+----------------------------------------------------------+\n";
	cout << "| 1 - Iate                                                 |\n";
	cout << "| 2 - Barco Rebelo                                         |\n";
	cout << "| 3 - Veleiro                                              |\n";
	cout << "+----------------------------------------------------------+\n";

	cin >> numeroBarco;
	switch (numeroBarco) {
	case 1: 
		barco = "iate";
		break;
	case 2:
		barco = "barco rebelo";
		break;
	case 3:
		barco = "veleiro";
		break;
	default:
		cout << "Esse número não é reconhecido como barco.";
		

	}



	cout << "+----------------------------------------------------------+\n";
	cout << "| Indique os destinos (escreva FIM quando terminar):       |\n";
	cout << "+----------------------------------------------------------+\n";

	while (temp != "FIM")
	{
		getline(cin,temp);
		if(temp != "FIM"){
		 destinos.push_back(temp);
		}
		cout << "\n";
	}

	cout << "+----------------------------------------------------------+\n";
	cout << "| Indique a distancia total percorrida:			        |\n";
	cout << "+----------------------------------------------------------+\n";

	cin >> distancia;

	cout << "+----------------------------------------------------------+\n";
	cout << "| Indique a lotacao total do barco:				        |\n";
	cout << "+----------------------------------------------------------+\n";

	cin >> lotacao;

	cout << "+----------------------------------------------------------+\n";
	cout << "| Indique a data da viagem (YY/MM/DD H:M):				        |\n";
	cout << "+----------------------------------------------------------+\n";

	getline(cin,data);
	tempo = new Time(data);

	preco = _fornecedores.at(index)->calculaPreco(numeroBarco, lotacao);
	
	
	novaOferta = new Oferta(nome, barco, destinos, distancia, lotacao, *tempo, preco);
	this->_fornecedores[index]->addOferta(*novaOferta);

}

void Empresa::modificaOferta()
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
	if (index = -1) { throw ObjetoInexistente<string>(nome_fornecedor); }


	cout << "+----------------------------------------------------------+\n";
	cout << "| Que propriedade do fornecedor é que pretende modificar?  |\n";
	cout << "+----------------------------------------------------------+\n";
	cout << "| 1 - Nome                                                 |\n";
	cout << "| 2 - NIF                                                  |\n";
	cout << "| 3 - Morada                                               |\n";
	cout << "| 4 - Definições de Fornecedor                             |\n";
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

		getline(cin, novamorada);
		_fornecedores.at(index)->setMorada(novamorada);
		break;

	case 4: _fornecedores.at(index)->setDefinicoesFornecedor();

	default:
		cout << "Essa opção não é viável. Pressione Enter para voltar ao menu anterior.";

	}
	cin.get();
	return;
}

void Empresa::removeOferta() {


	titulo();

	string ofertaremover;

	cout << "+----------------------------------------------------------+\n";
	cout << "| Qual e a oferta a remover?	                            |\n";
	cout << "+----------------------------------------------------------+\n";
	cin.ignore(INT_MAX,'\n');
	getline(cin,ofertaremover);
	deleteReservas(ofertaremover);
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
		try{
		cin >> tipodeutilizador;

		if (cin.fail()){
					cin.clear();
					cin.ignore(INT_MAX,'\n');
					throw InputInvalido<char>(tipodeutilizador);
			}
		}
		catch(InputInvalido<char> & ex){
					clearScreen();
					cout << "Erro: Introduziu um input invalido. So pode usar numeros inteiros. O seu input foi: " << ex << endl;
					cout << "Pressione Enter para voltar ao menu" << endl;
					cin.get();

		}

		switch (tipodeutilizador) {

		case 0:
			cout << "\n" << "Agradecemos a utilizacao do nosso servico, a aplicacao ira agora fechar.";
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
	
	titulo();
	cout << "\n";
	cout << "\n";
	cout << "Seja bem vindo ao gestor da Porto Rivers, aqui podera controlar todas as vertentes da sua empresa e visualizar toda a informacao de que necessita. \n";
	menuTipodeUtilizador();
	clearScreen();

}
