#include <iostream>
#include "menu.h"

using namespace std;

void titulo() {


	clearScreen();

	cout << "__________              __           __________.__                               \n";
	cout << "\\______   \\____________/  |_  ____   \\______   \\__|__  __ ___________  ______      \n";
	cout << " |     ___/  _ \\_  __ \\   __\\/  _ \\   |       _/  \\  \\/ // __ \\_  __ \\/  ___/    \n";
	cout << " |    |  (  <_> )  | \\/|  | (  <_> )  |    |   \\  |\\   /\\  ___/|  | \\/\\___ \\   \n";
	cout << " |____|   \\____/|__|   |__|  \\____/   |____|_  /__| \\_/  \\_____>__|  /____  >\n";
	cout << "                                             \\/                            \\/       \n";
	cout << "\n";

}

void adicionaCliente() {


	titulo();

	int opcaoRegisto;
	bool clientechoice = true;
	while (clientechoice) {

		cout << "+----------------------------------------------------------+\n";
		cout << "| Pretende tornar-se um cliente registado?                 |\n";
		cout << "+----------------------------------------------------------+\n";
		cout << "| Selecione a sua opcao (insira apenas o numero):          |\n";
		cout << "+----------------------------------------------------------+ \n";
		cout << "| 1 - Sim (terá conta registada e acumulará pontos)        |\n";
		cout << "| 2 - Não (continuará como cliente normal)                 |\n";
		cout << "| 0 - Sair                                                 |";
		cout << "+----------------------------------------------------------+\n";


	}
	

}

void menuCliente() {


	titulo();

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

		if (cin.fail())
			menuCliente();

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

void menuFornecedor() {

	titulo();

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
		cout << "| 9 - Voltar para o Menu Inicial                           |\n";
		cout << "| 0 - Sair                                                 |\n";
		cout << "+----------------------------------------------------------+\n";

		cin >> opcaofornecedor;

		if (cin.fail())
			menuFornecedor();

		switch (opcaofornecedor) {

		case 0:
			cout << "\n" << "Agradecemos a utiliza��o do nosso servi�o, a aplica��o ir� agora fechar.";
			return;
			break;

		case 1:
			//AdicionaFornecedor();
			break;
		case 2:
			//ModificaFornecedor();
			break;
		case 3:
			//RemoveFornecedor();
			break;

		case 9:
			menuInicial();
			break;

		default:
			cout << "Lamento, mas a op��o que inseriu n�o � v�lida. Ser� redirecionado/a para o in�cio do men�. \n";


		}

	}
}

void menuReservas() {


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
			//AdicionaReservas();
			break;
		case 2:
			//ModificaReservas();
			break;
		case 3:
			//RemoveReservas();
			break;

		case 0:
			return;
			break;

		default:
			cout << "Lamento, mas a op��o que inseriu n�o � v�lida. Ser� redirecionado/a para o in�cio do men�. \n";


		}

	}
}
void menuTipodeUtilizador()
{
	
	
	titulo();
	int tipodeutilizador;
	while (true){

		
		cout << "+----------------------------------------------------------+\n";
		cout << "| Escolha o tipo de opção sobre o qual quer trabalhar      |\n";
		cout << "+----------------------------------------------------------+\n";
		cout << "| Selecione a sua opcao (insira apenas o numero):          |\n";
		cout << "+----------------------------------------------------------+ \n";
		cout << "| 1 - Gestão de Clientes                                   |\n";
		cout << "| 2 - Gestão de Fornecedores                               |\n";
		cout << "| 3 - Gestão de Reservas                                   |\n";
		cout << "| 0 - Sair                                                 |\n";
		cout << "+----------------------------------------------------------+\n";
		
		cin >> tipodeutilizador;

		if (cin.fail())
			menuTipodeUtilizador();

		switch (tipodeutilizador) {

		case 0:
			cout << "\n" << "Agradecemos a utiliza��o do nosso servi�o, a aplica��o ir� agora fechar.";
			return;
			break;
		case 1:

			cout << "\n" << "Est� ser redirecionado para o menu do cliente...";
			menuCliente();
			break;

		case 2:

			cout << "\n" << "Est� ser redirecionado para o menu do fornecedor...";
			menuFornecedor();
			break;

		case 3:

			cout << "\n" << "Est� ser redirecionado para o menu das reservas...";
			menuReservas();
			break;

		default:
			cout << "Lamento, mas a op��o que inseriu n�o � v�lida. Ser� redirecionado/a para o in�cio do men�. \n";
		}
	}
}

void menuInicial()
{
	
	titulo();
	cout << "\n";
	cout << "\n";
	cout << "Seja bem vindo ao gestor da Porto Rivers, aqui poder� controlar todas as vertentes da sua empresa e visualizar toda a informa��o de que necessita. \n";
	menuTipodeUtilizador();

}
