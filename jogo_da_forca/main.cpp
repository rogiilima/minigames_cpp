#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <windows.h>

using namespace std;
void limpa_tela(){
    system("cls");
}

int main(){
    int opcao = 0;
    
    
    limpa_tela();
    cout << "Bem-vindo ao Jogo da Forca!" << endl;
    cout << "Escolha uma opcao:" << endl;
    cout << "1. Jogar" << endl;
    cout << "2. Jogar em Dupla" << endl;
    cout << "3. Sobre" << endl;
    cout << "4. Sair" << endl; 
    
    

    return 0;   
}
