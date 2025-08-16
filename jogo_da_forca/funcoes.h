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
        hidden_word += "_";
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
    
    int cont = 0, attempts = 0, max_attemps = 7; //Variáveis "globais"
    char letter;


    while (word != hidden_word && attempts <= max_attemps){
        clear_terminal();
        game_status(hidden_word,(max_attemps - attempts));
        
        cout << "Digite uma letra:" << endl;
        cin >> letter;
        fflush(stdin);
        //Algoritmo de complexidade O(n) para descobrir se a letra está na palavra
        for(cont = 0; cont < len_word; cont++){
            if( tolower(word[cont]) == letter){
                hidden_word[cont] = word[cont];
            }
        }

        attempts ++;
    }
    
    if( word == hidden_word){
        cout << "Parabéns você venceu" << endl;
    }else{
        cout << "Fim de jogo. Você não ganhou :(" << endl;
    }
    


    cout << "A palavra era: " << word << endl;

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



