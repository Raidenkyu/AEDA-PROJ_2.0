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
		cout << "| 9 - Voltar para o Menu Inicial                           |\n";
		cout << "| 0 - Sair                                                 |\n";
		cout << "+----------------------------------------------------------+\n";

		cin >> opcaocliente;

		if (cin.fail()){
			cin.clear();
			cin.ignore(INT_MAX,'\n');
			throw InputInvalido<char>(opcaocliente);
		}

		switch (opcaocliente) {

		case 0:
			cout << "\n" << "Agradecemos a utilizacao do nosso servico, a aplicacao ira agora fechar.";
			return;
			break;

		case 1:
			//AdicionaCliente();
			break;
		case 2:
			//ModificaCliente();
			break;
		case 3:
			//RemoveCliente();
			break;

		case 9:
			menuInicial();
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
					throw InputInvalido<char>(opcaoRegisto);
				}
		switch (opcaoRegisto) {
		case 0:
			return;
			break;
		case 1:
			adicionaClienteRegistado();
			break;
		case 2:
			adicionaClienteNormal();
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

	cin >> nomeClienteRegistado;
	Cliente * novoClienteRegistado = new ClienteRegistado(nomeClienteRegistado, 0);
	addClientes(*novoClienteRegistado);
	cout << "Pressione Enter para regressar\n";
	cin.get();

}

void Empresa::removeCliente() {
	titulo();

	string clienteremover;
	int quickmaths;

	cout << "+----------------------------------------------------------+\n";
	cout << "| Qual e o cliente a remover?	                            |\n";
	cout << "+----------------------------------------------------------+\n";

	cin >> clienteremover;
	deleteClientes(clienteremover);
	cout << endl << "O cliente foi removido com sucesso" << endl;
	cout << "Pressione qualquer tecla para regressar" << endl;
	cin.get();

}

void Empresa::menuFornecedor() {

	int opcaofornecedor;

	while (true) {
		titulo();
		cout << "+----------------------------------------------------------+\n";
		cout << "| Escolha o que pretende fazer com os fornecedores         |\n";
		cout << "+----------------------------------------------------------+\n";
		cout << "| Selecione a sua opcao (insira apenas o numero):          |\n";
		cout << "+----------------------------------------------------------+ \n";
		cout << "| 1 - Adicionar Fornecedor                                 |\n";
		cout << "| 2 - Modificar Fornecedor                                 |\n";
		cout << "| 3 - Apagar Fornecedor                                    |\n";
		cout << "| 0 - Sair                                                 |\n";
		cout << "+----------------------------------------------------------+\n";

		cin >> opcaofornecedor;

		if (cin.fail()){
			cin.clear();
			cin.ignore(INT_MAX,'\n');
			throw InputInvalido<char>(opcaofornecedor);
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
			//RemoveFornecedor();
			break;

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

void Empresa::removeFornecedor() {
	titulo();

	string fornecedorremover;

	cout << "+----------------------------------------------------------+\n";
	cout << "| Qual e o fornecedor a remover?                           |\n";
	cout << "+----------------------------------------------------------+\n";

	cin.ignore(INT_MAX,'\n');
	getline(cin,fornecedorremover);
	deleteFornecedores(fornecedorremover);


	cout << "+----------------------------------------------------------+\n";
	cout << "| O fornecedor foi removida com sucesso.                   |\n";
	cout << "+----------------------------------------------------------+\n";
	cout << "Pressione Enter para regressar\n";
	cin.get();
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
	cout << "+----------------------------------------------------------+\n";
	cout << "Pressione Enter para regressar\n";
	cin.get();

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
		cout << "| 3 - Apagar Reserva                                       |\n";
		cout << "| 4 - Ver Reservas                                         |\n";
		cout << "| 0 - Sair                                                 |\n";
		cout << "+----------------------------------------------------------+\n";

		cin >> opcaoreservas;

		if (cin.fail())
			menuReservas();

		switch (opcaoreservas) {

		

		case 1:
			adicionaReserva();
			break;
		case 2:
			//ModificaReservas();
			break;
		case 3:
			removeReservas();
			break;

		case 0:
			return;
			break;

		default:
			cout << "Lamento, mas a opcao que inseriu nao e valida. Sera redirecionado/a para o inicio do menu. \n";


		}

	}
}

void Empresa::adicionaReserva() {

	titulo();
	string nome_fornecedor, nomeCliente;
	int tipodebarco, lotacao, preco;
	bool cancelada = false;;
	vector<Oferta> vectorOfertasDisponiveis;
	Oferta * oferta;
	Cliente * cliente;

	
	cout << "+----------------------------------------------------------+\n";
	cout << "| Estes sao os clientes:                                   |\n";
	cout << "+----------------------------------------------------------+\n";

	for (unsigned int i = 0; i < _clientes.size(); i++)
		cout << "Cliente: " << _clientes.at(i)->getNome() << endl << "Pontos: " << _clientes.at(i)->getPontos();

	

	cout << "+----------------------------------------------------------+\n";
	cout << "| Indique o nome do cliente:                               |\n";
	cout << "+----------------------------------------------------------+\n";

	cin.ignore(INT_MAX, '\n');
	getline(cin, nomeCliente);

	int indexCliente = BinarySearch(_clientes, nomeCliente);
	if (indexCliente = -1) { throw ObjetoInexistente<string>(nomeCliente); }
	

	cout << "+----------------------------------------------------------+\n";
	cout << "| Indique o nome do fornecedor:                            |\n";
	cout << "+----------------------------------------------------------+\n";

	cin.ignore(INT_MAX, '\n');
	getline(cin, nome_fornecedor);

	
	cout << "+----------------------------------------------------------+\n";
	cout << "| Escolha o tipo de barco:                                 |\n";
	cout << "+----------------------------------------------------------+\n";
	cout << "| 1 - Iate                                                 |\n";
	cout << "| 2 - Barco Rebelo                                         |\n";
	cout << "| 3 - Veleiro                                              |\n";
	cout << "+----------------------------------------------------------+\n";

	cin >> tipodebarco;

	if(!(tipodebarco == 1 || tipodebarco == 2 || tipodebarco == 3))
	{
		cout << "Resposta nao valida, sera devolvido ao menu anterior";
		return;
	}


	cout << "+----------------------------------------------------------+\n";
	cout << "| Indique a lotacao:                                       |\n";
	cout << "+----------------------------------------------------------+\n";

	cin >> lotacao;

	int index = BinarySearch(_fornecedores, nome_fornecedor);
	if (index = -1) { throw ObjetoInexistente<string>(nome_fornecedor); }
	preco = _fornecedores.at(index)->calculaPreco(tipodebarco, lotacao);


	Reserva * novaReserva = new Reserva(nome_fornecedor, oferta, nomeCliente, _clientes.at(indexCliente), preco, cancelada);
	addReservas(*novaReserva); 

}

void Empresa::removeReservas() {
	titulo();

	string reservaremover;

	cout << "+----------------------------------------------------------+\n";
	cout << "| Qual e a reserva a remover?	                            |\n";
	cout << "+----------------------------------------------------------+\n";

    cin.ignore(INT_MAX,'\n');
	getline(cin,reservaremover);
	

	cout << "+----------------------------------------------------------+\n";
	cout << "| A reserva foi removida com sucesso.                      |\n";
	cout << "+----------------------------------------------------------+\n";
	cout << "Pressione Enter para regressar\n";
	cin.get();
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

		cin >> opcaoOfertas;

		if (cin.fail())
			menuOfertas();

		switch (opcaoOfertas) {

		case 1:
			adicionaOferta();
			break;
		case 2:
			//ModificaOfertas();
			break;
		case 3:
			//RemoveOfertas();
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
	cout << "| Iate                                                     |\n";
	cout << "| Barco Rebelo                                             |\n";
	cout << "| Veleiro                                                  |\n";
	cout << "+----------------------------------------------------------+\n";

	cin >> barco;
	if (barco == "iate")
		numeroBarco = 1;
	else if (barco == "barco rebelo" || barco == "barco_rebelo")
		numeroBarco = 2;
	else if (barco == "veleiro")
		numeroBarco = 3;
	else {
		cout << "Esse nome nao e valido, seras retornado ao menu anterior";
		return;
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
	cout << "| Indique a data da viagem (YY/MM/DD):				        |\n";
	cout << "+----------------------------------------------------------+\n";

	getline(cin,data);
	tempo = new Time(data);

	preco = _fornecedores.at(index)->calculaPreco(numeroBarco, lotacao);
	
	
	novaOferta = new Oferta(nome, barco, destinos, distancia, lotacao, *tempo, preco);
	this->_fornecedores[index]->addOferta(*novaOferta);

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
	cout << "Pressione qualquer tecla para regressar" << endl;

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
					throw InputInvalido<char>(tipodeutilizador);
			}

		switch (tipodeutilizador) {

		case 0:
			cout << "\n" << "Agradecemos a utilizacao do nosso servico, a aplicacao ira agora fechar.";
			return;
			break;
		case 1:

			try{
			menuCliente();
			}
			catch(InputInvalido<char> & ex){
					clearScreen();
					cout << "Erro: Introduziu um input invalido. So pode usar numeros inteiros. O seu input foi: " << ex << endl;
					cout << "Pressione qualquer tecla para voltar ao menu" << endl;
					cin.get();
					menuCliente();
				}
			break;

		case 2:


			try{
			menuFornecedor();
			}
			catch(InputInvalido<char> & ex){
					clearScreen();
					cout << "Erro: Introduziu um input invalido. So pode usar numeros inteiros. O seu input foi: " << ex << endl;
					cout << "Pressione qualquer tecla para voltar ao menu" << endl;
					cin.get();
					menuFornecedor();
				}
			break;

		case 3:

			try{
				menuReservas();
			}
			catch(InputInvalido<char> & ex){
					clearScreen();
					cout << "Erro: Introduziu um input invalido. So pode usar numeros inteiros. O seu input foi: " << ex << endl;
					cout << "Pressione qualquer tecla para voltar ao menu" << endl;
					cin.get();
					menuReservas();
				}
			break;

		case 4:
			try{
			menuOfertas();
			}
			catch(InputInvalido<char> & ex){
					clearScreen();
					cout << "Erro: Introduziu um input invalido. So pode usar numeros inteiros. O seu input foi: " << ex << endl;
					cout << "Pressione qualquer tecla para voltar ao menu" << endl;
					cin.get();
					menuOfertas();
				}
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
	try{
		menuTipodeUtilizador();
	}
	catch(InputInvalido<char> & ex){
		clearScreen();
		cout << "Erro: Introduziu um input invalido. So pode usar numeros inteiros. O seu input foi: ";
		cout << ex ;
		cout << endl;
		cout << "Pressione qualquer tecla para voltar ao menu" << endl;
		menuTipodeUtilizador();
		cin.get();
	}
	clearScreen();

}
