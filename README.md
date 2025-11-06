# Projetos de Jogos em C/C++

Este repositório contém jogos clássicos desenvolvidos em C++ como atividades práticas durante meu curso de C e C++. Os projetos demonstram conceitos de programação estruturada, manipulação de arrays bidimensionais, lógica de jogos e controle de fluxo.

## 🎮 Jogos Implementados

### 1. Jogo da Velha (Tic-Tac-Toe)
**Arquivo:** `aulajogodavelha.cpp`

Implementação completa do clássico jogo da velha para dois jogadores.

**Funcionalidades:**
- Sistema de turnos entre jogador X e jogador O
- Tabuleiro 3x3 representado por matriz de caracteres
- Validação de jogadas (impede jogar em posições ocupadas)
- Detecção automática de vitória em:
  - Linhas horizontais
  - Colunas verticais
  - Diagonais (principal e secundária)
- Sistema de pontuação persistente entre partidas
- Menu interativo com opções de continuar jogando ou voltar ao menu

**Detalhes técnicos:**
- Usa matriz `char tabuleiro[3][3]` para armazenar o estado do jogo
- Função `confereTabuleiro()` verifica todas as condições de vitória
- Mapeamento de posições 1-9 para coordenadas de matriz
- Sistema recursivo para reiniciar partidas mantendo pontuação
- Controle de rodadas (máximo 9 jogadas possíveis)

**Como jogar:**
```
Mapa de posições:
7 | 8 | 9
4 | 5 | 6
1 | 2 | 3
```

---

### 2. Batalha Naval
**Arquivo:** `aulajogodabatalhanaval.cpp`

Versão simplificada do jogo de batalha naval com posicionamento aleatório de navios.

**Funcionalidades:**
- Tabuleiro 10x10 com coordenadas linha/coluna
- 10 barcos posicionados aleatoriamente
- Sistema de máscara (oculta posição dos barcos)
- Feedback visual com cores ANSI:
  - Azul para água ('A')
  - Verde para partes de barco ('P')
- Sistema de pontuação (10 pontos por acerto)
- Limite de 5 tentativas por partida
- Mensagens de feedback após cada tiro

**Detalhes técnicos:**
- Duas matrizes paralelas:
  - `tabuleiro[10][10]`: estado real do jogo
  - `mascara[10][10]`: visão do jogador (oculta barcos não descobertos)
- Função `posicionaBarcos()` usa `rand()` para posicionamento aleatório
- `srand(time(NULL))` garante aleatoriedade real a cada execução
- Cores no terminal usando escape codes ANSI
- Validação de entrada (coordenadas entre 0-9)

**Mecânica de jogo:**
- Digite linha e coluna para atirar
- 'A' = Água (errou)
- 'P' = Barco pequeno (10 pontos)
- Objetivo: Maximizar pontuação em 5 tentativas

---

### 3. Jogo da Forca
**Arquivos:** `main.cpp` + `funcoes.h`

Implementação moderna do jogo da forca com sistema modular.

**Funcionalidades:**
- Banco de palavras aleatórias
- Exibição progressiva da palavra conforme acertos
- Registro de letras já tentadas
- Opção de arriscar a palavra completa
- Sistema de feedback colorido (verde/vermelho/branco)
- Máximo de 7 tentativas erradas
- Validação de entrada (não aceita letras repetidas)
- Conversão automática para minúsculas

**Detalhes técnicos:**
- **Arquitetura modular:** Separação entre lógica (funcoes.h) e execução (main.cpp)
- **Funções principais:**
  - `random_word()`: Seleciona palavra aleatória do banco
  - `hide_word()`: Cria string oculta com underscores
  - `game_status()`: Exibe interface do jogo
  - `simple_game()`: Loop principal do jogo
- **Manipulação de strings:**
  - `tolower()`: Normaliza entrada do usuário
  - Comparação caractere a caractere para descobrir letras
- **Configurações especiais:**
  - `SetConsoleOutputCP(65001)`: Habilita UTF-8 no terminal Windows
  - `Sleep()`: Pausas para feedback visual
  - Cores ANSI via `#define` para feedback visual

**Estrutura do código:**
```cpp
main.cpp: Inicialização e configuração do terminal
funcoes.h: Toda lógica do jogo (menu, gameplay, validações)
```

**Observação:** Versão atual não suporta acentuação (limitação explicada ao usuário)

---

### 4. Arquivos Auxiliares

#### `transicao.cpp`
Código didático demonstrando a transição entre C e C++.

**Demonstra:**
- Diferença entre `printf` (C) e `cout` (C++)
- Manipulação de arrays de char vs strings C++
- Sintaxe de impressão formatada em ambas linguagens
- Exemplo prático: palavra "gol" em C e C++

#### `menubasico.cpp`
Template vazio para desenvolvimento de novos projetos com menu.

---

## 🎯 Conceitos Aplicados

### Programação Estruturada
- Modularização com funções específicas
- Separação de responsabilidades
- Reutilização de código

### Estruturas de Dados
- **Matrizes bidimensionais:** Representação de tabuleiros
- **Arrays unidimensionais:** Bancos de palavras, histórico de jogadas
- **Strings:** Manipulação de texto e entrada do usuário

### Lógica de Programação
- **Loops aninhados:** Percorrer matrizes
- **Condicionais complexas:** Detecção de vitória
- **Validação de entrada:** Prevenção de erros do usuário
- **Recursão:** Reinício de jogos mantendo estado

### Aleatoriedade
- `srand(time(NULL))`: Seed baseada em tempo
- `rand()`: Geração de números pseudoaleatórios
- Aplicação: Posicionamento de barcos, seleção de palavras

### Interface de Usuário
- Menus interativos
- Feedback visual com cores ANSI
- Limpeza de tela (`system("CLS")`)
- Mapas de instrução para jogadores

---

## 🛠️ Como Compilar e Executar

### Jogo da Velha e Batalha Naval
```bash
g++ aulajogodavelha.cpp -o jogodavelha
./jogodavelha

g++ aulajogodabatalhanaval.cpp -o batalhanaval
./batalhanaval
```

### Jogo da Forca (com arquivo de cabeçalho)
```bash
g++ main.cpp -o forca
./forca
```

### Requisitos
- Compilador C++ (g++, MinGW, MSVC)
- Sistema operacional: Windows (comandos `system("CLS")` e cores ANSI)
- Para Linux/Mac: Substituir `system("CLS")` por `system("clear")`

---

## 📝 Notas de Desenvolvimento

### Aprendizados
- **Matrizes:** Representação eficiente de tabuleiros de jogos
- **Validação:** Importância de checar entradas do usuário
- **Modularização:** Facilita manutenção e legibilidade
- **Aleatoriedade:** Necessidade de seed para valores realmente aleatórios
- **UX:** Feedback visual melhora experiência do jogador

### Limitações Conhecidas
- **Jogo da Forca:** Não aceita caracteres acentuados
- **Cores ANSI:** Podem não funcionar em terminais muito antigos
- **Comandos Windows:** `system("CLS")` e `Sleep()` específicos do Windows
- **Batalha Naval:** Implementação simples sem navios de tamanhos variados

### Possíveis Melhorias Futuras
- [ ] Adicionar modo contra IA nos jogos
- [ ] Implementar salvamento de recordes
- [ ] Suporte multiplataforma (Linux/Mac)
- [ ] Jogo da Forca com banco de palavras externo (arquivo .txt)
- [ ] Batalha Naval com navios de diferentes tamanhos
- [ ] Interface gráfica com bibliotecas como SDL ou SFML

---

## 🎓 Contexto Acadêmico

Estes projetos foram desenvolvidos como atividades práticas durante meu curso de C e C++. Cada jogo representa a aplicação de conceitos específicos aprendidos:

- **Jogo da Velha:** Arrays multidimensionais e lógica condicional
- **Batalha Naval:** Aleatoriedade e sistemas de máscara/ocultação
- **Jogo da Forca:** Modularização e manipulação avançada de strings

Os códigos priorizam clareza didática e demonstração de conceitos ao invés de otimização extrema.

---

*Desenvolvido como material prático do curso de C/C++, 2025*
