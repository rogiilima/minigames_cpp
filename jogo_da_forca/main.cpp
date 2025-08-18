#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <windows.h>
#include <locale.h>
using namespace std;

// ANSI para cores no terminal (Usando com o print(NOME DA COR))
#define VERMELHO "\033[1;31m"
#define VERDE "\033[1;32m"
#define RESET "\033[0m"

#include "funcoes.h"

int main(){
    SetConsoleOutputCP(65001); //Substitui o setlocale e força o terminal a sair fonte utf-8
    SetConsoleCP(CP_UTF8);

    srand( (unsigned)time(NULL));

    menu_inicial();
    return 0;   
}
