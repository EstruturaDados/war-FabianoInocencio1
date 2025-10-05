/// pacotes incluídos
#include <stdio.h>
#include <string.h>

// definindo a quantidade de terrítorios no jogo
#define MAXIMO_TERRITORIO 5

//Criando a estrutura do programa
struct territorio{
    char nome[30];
    char cor[10];
    int tropa;
  };
 /// limpeza de buffer  
void LimparBufferEntrada(){
 int c;
 while ((c = getchar())!= '\n' && c != EOF);
   
}



int main() {
// Cria um array de estruturas "territorio" com tamanho definido por MAXIMO_TERRITORIO
struct territorio territorios[MAXIMO_TERRITORIO];
int contagem = 0;
 
// Loop para cadastrar os dados de cada território


  printf("Cadastrar os 5 territórios para o jogo war \n");
  printf("============================================\n");


for (int i=0; i < MAXIMO_TERRITORIO; i++ ){
 
 
   printf("== Cadastrar o nome do território ==\n");
   fgets(territorios[i].nome,sizeof(territorios[i].nome),stdin);
    territorios[i].nome[strcspn(territorios[i].nome, "\n")] = 0;    
     
   
   printf("== Cadastrar a cor ex: azul, amarelo ==\n");
   fgets(territorios[i].cor, sizeof(territorios[i].cor),stdin);
    territorios[i].cor[strcspn(territorios[i].cor, "\n")] = 0;
   
  printf("== Numero de tropa == \n");
  scanf("%d", &territorios[i].tropa);
  LimparBufferEntrada();
  printf("=================================\n");
  contagem++;
   

}

// Loop para apresentar os dados de cada território

  for (int i= 0; i < MAXIMO_TERRITORIO; i++){
    printf("Território: %d  \n", i + 1 );
   
    printf("-Nome: %s\n", territorios[i].nome);
    printf("-Cor: %s\n", territorios[i].cor);
    printf("-Tropas: %d\n",territorios[i].tropa);

 printf("====================================\n");    
  }

    return 0;
}