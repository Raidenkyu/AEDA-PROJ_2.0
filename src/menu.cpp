#include <iostream>
#include "menu.h"
#include "cruise.h"
#include <climits>

using namespace std;

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
			cout << "\n" << "Agradecemos a utiliza��o do nosso servi�o, a aplica��o ir� agora fechar.";
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
			cout << "Lamento, mas a op��o que inseriu n�o � v�lida. Ser� redirecionado/a para o in�cio do men�. \n";


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
		cout << "| 1 - Sim (terá conta registada e acumulará pontos)        |\n";
		cout << "| 2 - Não (continuará como cliente normal)                 |\n";
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
			cout << "Lamento, mas a op��o que inseriu n�o � v�lida. Ser� redirecionado/a para o in�cio do men�. \n";
		}

	}


}

void Empresa::adicionaClienteNormal() {

	titulo();
	string nomeCliente;

	cout << "+----------------------------------------------------------+\n";
	cout << "| Qual é o seu nome?                                       |\n";
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

}

void Empresa::removeCliente() {
	titulo();

	string clienteremover;
	int quickmaths;

	cout << "+----------------------------------------------------------+\n";
	cout << "| Qual é o cliente a remover?	                            |\n";
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
			cout << "\n" << "Agradecemos a utiliza��o do nosso servi�o, a aplica��o ir� agora fechar.";
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
			cout << "Lamento, mas a op��o que inseriu n�o � v�lida. Ser� redirecionado/a para o in�cio do men�. \n";


		}

	}
}

void Empresa::adicionaFornecedor() {

	titulo();
	string nomeFornecedor, morada;
	int NIF;

	cout << "+----------------------------------------------------------+\n";
	cout << "| Qual é o nome do fornecedor?                             |\n";
	cout << "+----------------------------------------------------------+\n";

	cin >> nomeFornecedor;

	cout << "+----------------------------------------------------------+\n";
	cout << "| Indique o NIF:                                           |\n";
	cout << "+----------------------------------------------------------+\n";

	cin >> NIF;

	cout << "+----------------------------------------------------------+\n";
	cout << "| Indique a morada:                                        |\n";
	cout << "+----------------------------------------------------------+\n";

	cin >> morada;
	Fornecedor * novoFornecedor = new Fornecedor(nomeFornecedor, NIF, morada);
	addFornecedores(*novoFornecedor);
}

void Empresa::removeFornecedor() {
	titulo();

	string fornecedorremover;
	int quickmaths;

	cout << "+----------------------------------------------------------+\n";
	cout << "| Qual é o fornecedor a remover?                           |\n";
	cout << "+----------------------------------------------------------+\n";

	cin >> fornecedorremover;
	deleteFornecedores(fornecedorremover);


	cout << "+----------------------------------------------------------+\n";
	cout << "| O fornecedor foi removida com sucesso.                   |\n";
	cout << "| 1 - Menu Inicial                                         |\n";
	cout << "| 2 - Menu Fornecedores                                    |\n";
	cout << "+----------------------------------------------------------+\n";

	switch (quickmaths) {
	case 1:
		menuInicial();
		break;
	case 2:
		menuFornecedor();
		break;
	default:
		return;
		break;
	}

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
			cout << "Lamento, mas a op��o que inseriu n�o � v�lida. Ser� redirecionado/a para o in�cio do men�. \n";


		}

	}
}

void Empresa::adicionaReserva() {

	titulo();
	string nomeFornecedor, nomeCliente;
	int preco;
	bool cancelada = false;;
	vector<Oferta> vectorOfertasDisponiveis;

	cout << "+----------------------------------------------------------+\n";
	cout << "| Qual é o nome do fornecedor?                             |\n";
	cout << "+----------------------------------------------------------+\n";

	cin >> nomeFornecedor;

	cout << "+----------------------------------------------------------+\n";
	cout << "| Escolha entre as ofertas disponíveis:                    |\n";
	cout << "+----------------------------------------------------------+\n";

	/* Fornecedor &getOfertasbyname(nomeFornecedor) = vectorOfertasDisponiveis;

	Mais tarde pôe-se isto a funcionar*/

	cout << "+----------------------------------------------------------+\n";
	cout << "| Indique o  nome:                                         |\n";
	cout << "+----------------------------------------------------------+\n";

	cin >> nomeCliente;

	cout << "+----------------------------------------------------------+\n";
	cout << "| Escolha o nome a partir da lista de clientes:            |\n";
	cout << "+----------------------------------------------------------+\n";

	/* Mesma coisa que em cima*/

	cout << "+----------------------------------------------------------+\n";
	cout << "| Registe o montante a pagar:                              |\n";
	cout << "+----------------------------------------------------------+\n";

	cin >> preco;

	/*
	Reserva * novaReserva = new Reserva(nomeFornecedor, oferta, nomeCliente, cliente, preco, cancelada);
	addReservas(*novaReserva); */

}

void Empresa::removeReservas() {
	titulo();

	string reservaremover;
	int quickmaths;

	cout << "+----------------------------------------------------------+\n";
	cout << "| Qual é a reserva a remover?	                            |\n";
	cout << "+----------------------------------------------------------+\n";

	cin >> reservaremover;
	deleteReservas(reservaremover);


	cout << "+----------------------------------------------------------+\n";
	cout << "| A reserva foi removida com sucesso.                      |\n";
	cout << "| 1 - Menu Inicial                                         |\n";
	cout << "| 2 - Menu Reservas                                        |\n";
	cout << "+----------------------------------------------------------+\n";

	switch (quickmaths) {
	case 1:
		menuInicial();
		break;
	case 2:
		menuReservas();
		break;
	default:
		return;
		break;
	}

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
		cout << "+---------------------------------------------------------+ \n";
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
			cout << "Lamento, mas a op��o que inseriu n�o � v�lida. Tente outra vez" << endl;
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
	std::string temp = "";
	std::vector<std::string> destinos;
	unsigned int distancia;
	unsigned int lotacao;
	std::string data;

	cout << "+----------------------------------------------------------+\n";
	cout << "| Qual é o nome do fornecedor?                             |\n";
	cout << "+----------------------------------------------------------+\n";

	cin >> nome;

	cout << "+----------------------------------------------------------+\n";
	cout << "| Qual é o barco escolhido?			                    |\n";
	cout << "+----------------------------------------------------------+\n";

	cin >> barco;

	cout << "+----------------------------------------------------------+\n";
	cout << "| Indique os destinos (escreva FIM quando terminar):       |\n";
	cout << "+----------------------------------------------------------+\n";

	while (temp != "FIM")
	{
		destinos.push_back(temp);
		cin >> temp;
		cout << "\n";
	}

	cout << "+----------------------------------------------------------+\n";
	cout << "| Indique a distância total percorrida:			        |\n";
	cout << "+----------------------------------------------------------+\n";

	cin >> distancia;

	cout << "+----------------------------------------------------------+\n";
	cout << "| Indique a lotação total do barco:				        |\n";
	cout << "+----------------------------------------------------------+\n";

	cin >> lotacao;

	cout << "+----------------------------------------------------------+\n";
	cout << "| Indique a data da viagem (YY/MM/DD):				        |\n";
	cout << "+----------------------------------------------------------+\n";

	cin >> data;


	/*
	Oferta * novaOferta = new Oferta(nome, barco, destinos, distancia, lotacao, data);
	Fornecedor addOfertas(*novaOferta); */

}

void Empresa::removeOferta() {


	titulo();

	string ofertaremover;

	cout << "+----------------------------------------------------------+\n";
	cout << "| Qual é a oferta a remover?	                            |\n";
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
		cout << "| Escolha o tipo de opção sobre o qual quer trabalhar      |\n";
		cout << "+----------------------------------------------------------+\n";
		cout << "| Selecione a sua opcao (insira apenas o numero):          |\n";
		cout << "+----------------------------------------------------------+ \n";
		cout << "| 1 - Gestão de Clientes                                   |\n";
		cout << "| 2 - Gestão de Fornecedores                               |\n";
		cout << "| 3 - Gestão de Reservas                                   |\n";
		cout << "| 4 - Gestão de Ofertas                                    |\n";
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
			cout << "\n" << "Agradecemos a utiliza��o do nosso servi�o, a aplica��o ir� agora fechar.";
			return;
			break;
		case 1:

			try{
			menuCliente();
			}
			catch(InputInvalido<char> & ex){
					clearScreen();
					cout << "Erro:Introduziu um input invalido. Só pode usar números inteiros. O seu input foi: " << ex << endl;
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
					cout << "Erro:Introduziu um input invalido. Só pode usar números inteiros. O seu input foi: " << ex << endl;
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
					cout << "Erro:Introduziu um input invalido. Só pode usar números inteiros. O seu input foi: " << ex << endl;
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
					cout << "Erro:Introduziu um input invalido. Só pode usar números inteiros. O seu input foi: " << ex << endl;
					cout << "Pressione qualquer tecla para voltar ao menu" << endl;
					cin.get();
					menuOfertas();
				}
			break;
		default:
			clearScreen();
			cout << "Lamento, mas a op��o que inseriu n�o � v�lida. Tente outra vez. \n";
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
	cout << "Seja bem vindo ao gestor da Porto Rivers, aqui poder� controlar todas as vertentes da sua empresa e visualizar toda a informa��o de que necessita. \n";
	try{
		menuTipodeUtilizador();
	}
	catch(InputInvalido<char> & ex){
		clearScreen();
		cout << "Erro:Introduziu um input invalido. Só pode usar números inteiros. O seu input foi: ";
		cout << ex ;
		cout << endl;
		cout << "Pressione qualquer tecla para voltar ao menu" << endl;
		menuTipodeUtilizador();
		cin.get();
	}
	clearScreen();

}
