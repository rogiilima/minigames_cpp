void clear_terminal(){
    system("cls");
}

string random_word(){
    string words[3] = {"Abacaxi", "Manga", "Morango"};
    int random_index = (rand() % 3);
    return words[random_index];
    
}
void simple_game(){
    
    
    string word = random_word();
    cout << word << endl;
    Sleep(5000);
}


void menu_inicial(){
    int option = 0;
    
    do{
        clear_terminal();
        cout << "Bem-vindo ao Jogo da Forca!" << endl;
        cout << "1. Jogar" << endl;
        cout << "2. Sobre" << endl;
        cout << "3. Sair" << endl; 
        cout << "Escolha uma opcao:";
        cin >> option;
    
        switch (option){
        case 1:
            simple_game();
            break;
        case 2:
            break;
        case 3:
            clear_terminal(); 
            cout << "Até Mais!";
            Sleep(3500);
            break;
        default:
            cout << "Digite uma opção válida!";
            Sleep(1200);
            clear_terminal();
            break;
        }
    } while (option != 3 );
    
}



