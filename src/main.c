/*main.c:
Centraliza o fluxo do programa.
Faz uso dos arquivos de cabeçalho (.h) do diretório include/ para chamar funções implementadas em src/.*/

/*incluindo os arquivos que serão lidos no main*/
/*Uma observação é que possivelmente terá que ser revisto e implementado outros códigos*/
// Verificar repositório "https://github.com/vivek081202/FinTrack-Expense_and_Budget_Analyzer/blob/main/src/main.c"

#include <stdio.h>
#include "finance.h"
#include "input.h"
#include "output.h"

int main () {
  int escolha; 
  float buget;
  char nome_usuario;
  
  // Definindo uma estrutura para representar uma data

  typedef struct {
    int dia;
    int mes;
    int ano;
  } Data;


while (1)
{
  printf("Bem - Vindo ao BeyondPay - Sua aplicação para registro de transações\n\n");
        printf("+--------------------------+\n");
        printf("|  Registre ou confira suas transações aqui! |\n");
        printf("+--------------------------+\n");
        printf("|    1. Registrar transações    |\n");
        printf("|    2. Ver Transações          |\n");
        printf("|    3. Sair                    |\n");
        printf("+--------------------------+\n");
        printf("Choose an option: ");
        scanf("%d", &escolha);

}

}













