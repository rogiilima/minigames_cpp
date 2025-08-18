void clear_terminal(){
    system("cls");
}

string random_word(){
    string words[4] = {"Abacaxi", "Manga", "Morango"};
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
void game_status(string hidden_word, int remaining_attempts, string letters_attempts, string feedback){
    cout << feedback << endl;
    cout << "Palavra: " << hidden_word << " Tentativas restantes: " << remaining_attempts << endl;
    cout << "Letras Digitadas: ";
    for (int i = 0; i < letters_attempts.size(); i++){
        cout << letters_attempts[i] << " - ";
    }
    cout << "\n";
}


void simple_game(){
    string word = random_word();
    for (auto &c : word) c = std::tolower(static_cast<unsigned char>(c)); // converte a string word para minúscula
    int len_word = word.size(); // Pegando o tamanho da palvra

    string hidden_word = hide_word(word, len_word); // pegando a palavra escondida
    
    int cont = 0, attempts = 0, max_attemps = 7; //Variáveis "globais"
    char letter; 
    string letters_attempts, feedback, risked_word; //Feedback retorna uma mensagem do jogo ao jogador
    
    
    while (word != hidden_word && attempts <= max_attemps){
        bool letter_typed = false;
        clear_terminal();
        game_status(hidden_word,(max_attemps - attempts), letters_attempts, feedback);
        feedback = "";
        
        cout << "Digite uma letra ou (digite: 1) para arriscar a palavra:" << endl;
        cin >> letter;
        fflush(stdin);
        letter = tolower(letter); // Transforma a entrada em minusculo.

        if (letter == '1')
        {
            cout << "Qual palavra você acha que é?" << endl;
            cin >> risked_word;
            for (auto &c : risked_word) c = std::tolower(static_cast<unsigned char>(c)); // converte a string para minúscula
            
            if (risked_word == word){
                hidden_word = risked_word; //Regra para acabar o jogo
            }else{
                attempts = max_attemps;    
            }
        }
        // NOTA: não faz diferença em termos computacionais verificar esse array, então colocar um if para ele pular isso tudo serio meio inutil
        // Verifica se a letra o usuario digitou é está nas tentativas anteriores
        for(cont = 0; cont < attempts; cont++){
            if( letters_attempts[cont] == letter ){
                letter_typed = true;
                feedback = "Você já tentou essa letra! Tente novente...";
                break;
            }
        }
        
        if (letter_typed == false){
            letters_attempts += letter;
            //Algoritmo de complexidade O(n) para descobrir se a letra está na palavra
            for(cont = 0; cont < len_word; cont++){
                if( tolower(word[cont]) == letter){
                hidden_word[cont] = word[cont];
                feedback = "Parabéns! Letra certa...Continue";
                }
            }
        attempts ++;
        }
    }
    
    if( word == hidden_word){
    cout << "Parabéns você venceu" << endl;
    }else{
    cout << "Fim de jogo. Você não ganhou :(" << endl;
    }
    cout << "A palavra era: " << word << endl;

    Sleep(2000);//Tempo após o final do jogo
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



