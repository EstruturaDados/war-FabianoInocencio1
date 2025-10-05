#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

// Define a quantidade máxima de territórios no jogo
#define MAXIMO_TERRITORIO 5

// Estrutura que representa cada território
struct territorio{
    char nome[30];  // Nome do território
    char cor[10];   // Cor do território (para fins visuais)
    int tropa;      // Quantidade de tropas no território
};

// Função para limpar o buffer de entrada após o scanf
void LimparBufferEntrada(){
    int c;
    while ((c = getchar())!= '\n' && c != EOF);
}

// Função que realiza a batalha entre dois territórios
void batalha(struct territorio *atacante, struct territorio *defensor){
    int valorAtacante = rand() % 6 + 1;
    int valorDefensor = rand() % 6 + 1;
    
    printf("O atacante %s atirou o dado: %d\n", atacante->nome, valorAtacante );
    printf("O Defensor %s atirou o dado: %d\n", defensor->nome, valorDefensor);
    
    if (valorAtacante > valorDefensor){
        printf("Vitória do atacante! O Defensor perdeu 1 tropa\n");
        defensor->tropa--;
    } else {
        printf("Vitória do defensor! O atacante perdeu 1 tropa\n");
        atacante->tropa--;
    }
}

// Função para exibir o mapa com os territórios e suas tropas
void mapa(struct territorio territorios[]){
    printf("===========================================\n");
    for (int i = 0; i < MAXIMO_TERRITORIO; i++){
        printf("%d. %s (Exército: %s, Tropas: %d)\n", i + 1,
               territorios[i].nome, territorios[i].cor, territorios[i].tropa);
        printf("-------------------------------------------\n");
    }
    printf("===========================================\n");
}

int main() {
    srand(time(NULL)); // Inicializa o gerador de números aleatórios
    
    struct territorio territorios[MAXIMO_TERRITORIO];
    
    printf("Cadastrar os territórios para o jogo War\n");
    printf("===========================================\n");
    
    for (int i = 0; i < MAXIMO_TERRITORIO; i++){
        printf("== Cadastrar o nome do território ==\n");
        fgets(territorios[i].nome, sizeof(territorios[i].nome), stdin);
        territorios[i].nome[strcspn(territorios[i].nome, "\n")] = 0;
        
        printf("== Cadastrar a cor (ex: azul, amarelo) ==\n");
        fgets(territorios[i].cor, sizeof(territorios[i].cor), stdin);
        territorios[i].cor[strcspn(territorios[i].cor, "\n")] = 0;
        
        printf("== Número de tropas ==\n");
        scanf("%d", &territorios[i].tropa);
        LimparBufferEntrada();
        printf("===========================================\n");
    }
    
    printf("\nMapa do mundo || Estado atual\n");
    mapa(territorios);
    
    int atacanteIndex, defensorIndex;
    printf("========= FASE DE ATAQUE ====================\n");
    
    printf("Escolha o território atacante: ");
    scanf("%d", &atacanteIndex);
    LimparBufferEntrada();
    
    printf("Escolha o território defensor: ");
    scanf("%d", &defensorIndex);
    LimparBufferEntrada();
    
    atacanteIndex--;
    defensorIndex--;
    
    printf("============ Resultado da Batalha ===========\n");
    
    if(atacanteIndex < 0 || atacanteIndex >= MAXIMO_TERRITORIO ||
       defensorIndex < 0 || defensorIndex >= MAXIMO_TERRITORIO){
        printf("Escolha inválida\n");
        return 1;
    }
    
    batalha(&territorios[atacanteIndex], &territorios[defensorIndex]);
    
    return 0;
}