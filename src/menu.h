#ifndef MENU_H_
#define MENU_H_

#ifdef _WIN32         //Para o windows reconhecer os caracteres portugueses
#include <windows.h>
#define SetPTchar() SetConsoleCP(1252); SetConsoleOutputCP(1252);
#else
#define SetPTchar() NULL
#endif

#ifdef _WIN32 //Para limpar o ecrã quer seja em Windows, quer seja em linux
#define clearScreen() system("cls");
#else
#define clearScreen() system("clear");
#endif



#endif /* SRC_MENU_H_ */
