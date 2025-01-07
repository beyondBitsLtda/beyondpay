/*main.c:
Centraliza o fluxo do programa.
Faz uso dos arquivos de cabeçalho (.h) do diretório include/ para chamar funções implementadas em src/.*/

/*incluindo os arquivos que serão lidos no main*/
/*Uma observação é que possivelmente terá que ser revisto e implementado outros códigos*/
// Verificar repositório "https://github.com/vivek081202/FinTrack-Expense_and_Budget_Analyzer/blob/main/src/main.c"

#include <stdio.h>
#include "finance.h"
#include "input.h"
#include "output.h"git 

int main () {
  int escolha; 
  float verba;
  char nome_usuario;
  
  // Definindo uma estrutura para representar uma data.

  typedef struct {
    int mes;
    int ano;
  } Data;

// Adptei a lógica de menu, criando a opção de cadastrar as verbas e transações com base o mês
// Vericar opção de realizar o Switch ao invés de While.
while (1)
{
  printf("Bem - Vindo ao BeyondPay - Sua aplicação para registro de transações\n\n");
        printf("+--------------------------+\n");
        printf("|  Registre ou confira suas transações aqui! |\n");
        printf("+--------------------------+\n");
        printf("|    1. Registrar Verba         |\n");
        printf("|    2. Registrar transações    |\n");
        printf("|    3. Ver Transações          |\n");
        printf("|    4. Sair                    |\n");
        printf("+--------------------------+\n");
        printf("Escolha sua opção: ");
        scanf("%d", &escolha);

        if (escolha == 1)
        {
          printf("Insira o mês no  qual deseja registrar a verba: \n");
          Data data;

          // Entrada de dados
        
            printf("Digite o mes: ");
            scanf("%d", &data.mes);

            printf("Digite o ano: ");
            scanf("%d", &data.ano);

            // Saída formatada
            printf("Data inserida: %02d/%04d\n",data.mes, data.ano);

            printf("Insira o seu Bugted: ");
            scanf("%f", &verba);
            printf("Verba Registrada: %.2f\n", verba);
          
          // Agora tenho que aprender a relacionar as verbas as dastas, pelo oque eu vi é dificil kk

        }

}

}













