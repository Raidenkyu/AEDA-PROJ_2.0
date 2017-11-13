#include <iostream>
#include "menu.h"

using namespace std;

void titulo() {

	system("cls");

	cout << "__________              __           __________.__                               \n";
	cout << "\\______   \\____________/  |_  ____   \\______   \\__|__  __ ___________  ______      \n";
	cout << " |     ___/  _ \\_  __ \\   __\\/  _ \\   |       _/  \\  \\/ // __ \\_  __ \\/  ___/    \n";
	cout << " |    |  (  <_> )  | \\/|  | (  <_> )  |    |   \\  |\\   /\\  ___/|  | \\/\\___ \\   \n";
	cout << " |____|   \\____/|__|   |__|  \\____/   |____|_  /__| \\_/  \\_____>__|  /____  >\n";
	cout << "                                             \\/                            \\/       \n";
	cout << "\n";

}

void menuCliente() {
	while (true) {
		titulo();
		cout << "";
		
	}
}

void menuFornecedor() {

	while (true) {
		titulo();
		cout << "Conseguiste forneedor";
		cin.get();
	}
}

void menuTipodeUtilizador()
{
	
	
	titulo();
	int tipodeutilizador;
	while (true){

		
		cout << "+----------------------------------------------------------+\n";
		cout << "| Escolha o tipo de utilizador sobre o qual quer trabalhar |\n";
		cout << "+----------------------------------------------------------+\n";
		cout << "| Selecione a sua opcao (insira apenas o numero):          |\n";
		cout << "+----------------------------------------------------------+ \n";
		cout << "| 1 - Cliente                                              |\n";
		cout << "| 2 - Fornecedor                                           |\n";
		cout << "| 0 - Sair                                                 |\n";
		cout << "+----------------------------------------------------------+\n";
		
		cin >> tipodeutilizador;

		switch (tipodeutilizador) {

		case 0:
			cout << "\n" << "Agradecemos a utiliza��o do nosso servi�o, a aplica��o ir� agora fechar.";
			break;
		case 1:

			cout << "\n" << "Est� ser redirecionado para o menu do cliente...";
			menuCliente();
			break;

		case 2:

			cout << "\n" << "Est� ser redirecionado para o menu do fornecedor...";
			menuFornecedor();
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
	cout << "Seja bem vindo ao gestor da Porto River, aqui poder� controlar todas as vertentes da sua empresa e visualizar toda a informa��o de que necessita. \n";
	menuTipodeUtilizador();

}
