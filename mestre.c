#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

#define MAXIMO_TERRITORIO 5

struct territorio {
    char nome[30];
    char cor[10];
    int tropa;
};

// Protótipos
void LimparBufferEntrada();
void batalha(struct territorio *atacante, struct territorio *defensor);
void mapa(struct territorio territorios[]);
void ataque(int *atacanteIndex);
void defesa(int *defensorIndex);
int validarEscolha(int index);
int continuarRodada();

int main() {
    int atacanteIndex;
    int defensorIndex;

    srand(time(NULL));

    struct territorio territorios[MAXIMO_TERRITORIO] = {
        {"USA", "Vermelho", 5},
        {"Japão", "Azul", 5},
        {"Brasil", "Verde", 5},
        {"Italia", "Amarelo", 5},
        {"Australia", "Roxo", 5}
    };

    printf("========== MAPA DO TERRITÓRIO ============\n");
    mapa(territorios);

    printf("========= INÍCIO DAS RODADAS ====================\n");

    // Loop principal de rodadas
    while(1){
        // Escolha do atacante com validação
        do {
            ataque(&atacanteIndex);
        } while(!validarEscolha(atacanteIndex - 1));

        // Escolha do defensor com validação
        do {
            defesa(&defensorIndex);
        } while(!validarEscolha(defensorIndex - 1));

        // Ajusta para índice 0
        atacanteIndex--;
        defensorIndex--;

        batalha(&territorios[atacanteIndex], &territorios[defensorIndex]);

        printf("\nMapa atualizado após a batalha:\n");
        mapa(territorios);

        // Pergunta se quer continuar
        if(!continuarRodada()){
            printf("Fim das rodadas. Obrigado por jogar!\n");
            break;
        }
    }

    return 0;
}

// Limpa o buffer de entrada
void LimparBufferEntrada() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Simula a batalha
void batalha(struct territorio *atacante, struct territorio *defensor) {
    int valorAtacante = rand() % 6 + 1;
    int valorDefensor = rand() % 6 + 1;

    printf("\nO atacante %s lançou o dado: %d\n", atacante->nome, valorAtacante);
    printf("O defensor %s lançou o dado: %d\n", defensor->nome, valorDefensor);

    if (valorAtacante > valorDefensor) {
        printf("Vitória do atacante! O defensor perdeu 1 tropa.\n");
        defensor->tropa--;
    } else {
        printf("Vitória do defensor! O atacante perdeu 1 tropa.\n");
        atacante->tropa--;
    }
}

// Mostra o mapa
void mapa(struct territorio territorios[]) {
    printf("===========================================\n");
    for (int i = 0; i < MAXIMO_TERRITORIO; i++) {
        printf("%d. %s (Exército: %s, Tropas: %d)\n",
               i + 1,
               territorios[i].nome,
               territorios[i].cor,
               territorios[i].tropa);
        printf("-------------------------------------------\n");
    }
    printf("===========================================\n");
}

// Funções modulares para ataque e defesa
void ataque(int *atacanteIndex) {
    printf("Escolha o território atacante: ");
    scanf("%d", atacanteIndex);
    LimparBufferEntrada();
}

void defesa(int *defensorIndex) {
    printf("Escolha o território defensor: ");
    scanf("%d", defensorIndex);
    LimparBufferEntrada();
}

// Valida se o índice está dentro do limite
int validarEscolha(int index) {
    if(index < 0 || index >= MAXIMO_TERRITORIO){
        printf("Escolha inválida! Tente novamente.\n");
        return 0; // inválido
    }
    return 1; // válido
}

// Pergunta se quer continuar a próxima rodada
int continuarRodada(){
    char resposta;
    printf("Deseja continuar para a próxima rodada? (s/n): ");
    scanf(" %c", &resposta);
    LimparBufferEntrada();
    if(resposta == 's' || resposta == 'S')
        return 1;
    return 0;
}