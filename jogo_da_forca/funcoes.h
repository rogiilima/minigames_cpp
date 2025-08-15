void clear_terminal(){
    system("cls");
}

string random_word(){
    string words[3] = {"Abacaxi", "Manga", "Morango"};
    int random_index = (rand() % 3);
    return words[random_index];
    
}

// Adicionando "_" em cada letra da palavra
string hide_word(string word, int len_word){
    int cont = 0;
    string hidden_word;
    while (cont < len_word){
        hidden_word += " _";
        cont++;
    }
    return hidden_word;
}
// Exibe o status do jogo, tipo menu e algumas outras coisas
void game_status(string hidden_word, int remaining_attempts ){
    cout << "Palavra: " << hidden_word << " Tentativas restantes: " << remaining_attempts << endl;
}


void simple_game(){
    
    
    string word = random_word();
    int len_word = word.size(); // Pegando o tamanho da palvra

    string hidden_word = hide_word(word, len_word); // pegando a palavra escondida

    int attempts = 0, max_attemps = 7;
    char letter;
    
    while (attempts <= max_attemps){
        clear_terminal();
        game_status(hidden_word,(max_attemps - attempts));
        
        cout << "Digite uma letra:" << endl;
        cin >> letter;
        fflush(stdin);
        attempts ++;
    }
    



    cout << hidden_word << endl;

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
        fflush(stdin);
    
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



