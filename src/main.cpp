/*
 * main.cpp
 *
 *  Created on: 16/10/2017
 *      Author: JCM, CV, JA
 */

#include <iostream>
#include "cruise.h"

using namespace std;



void titulo() {


	cout << "__________              __           __________.__                               _____                                             \n";
	cout << "\\______   \\____________/  |_  ____   \\______   \\__|__  __ ___________  ______   /     \\ _____    ____ _____     ____   ___________ \n";
	cout << " |     ___/  _ \\_  __ \\   __\\/  _ \\   |       _/  \\  \\/ // __ \\_  __ \\/  ___/  /  \\ /  \\\\__  \\  /    \\\\__  \\   / ___\\_/ __ \\_  __ \\ \n";
	cout << " |    |  (  <_> )  | \\/|  | (  <_> )  |    |   \\  |\\   /\\  ___/|  | \\/\\___ \\  /    Y    \\/ __ \\|   |  \\/ __ \\_/ /_/  >  ___/|  | \\/\n";
	cout << " |____|   \\____/|__|   |__|  \\____/   |____|_  /__| \\_/  \\___  >__|  /____  > \\____|__  (____  /___|  (____  /\\___  / \\___  >__|   \n";
	cout << "                                             \\/              \\/           \\/          \\/     \\/     \\/     \\//_____/      \\/       \n";
	cout << "\n";

}

void menuInicial()
{
	titulo();
	cout << "\n";
	cout << "\n";
	cout << "Seja bem vindo ao gestor da Porto River, aqui poder� controlar todas as vertentes da sua empresa e visualizar toda a informa��o de que necessita. \n";

}

int main(){

	menuInicial();
		cin.get();
	Empresa Porto_Rivers();
	return 0;
}



