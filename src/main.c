/*main.c:
Centraliza o fluxo do programa.
Faz uso dos arquivos de cabeçalho (.h) do diretório include/ para chamar funções implementadas em src/.*/

/*incluindo os arquivos que serão lidos no main*/
/*Uma observação é que possivelmente terá que ser revisto e implementado outros códigos*/
// Verificar repositório "https://github.com/vivek081202/FinTrack-Expense_and_Budget_Analyzer/blob/main/src/main.c"

#include <stdio.h>
//#include "finance.h"
//#include "input.h"
//#include "output.h"git

  // Definindo uma estrutura para representar uma data, mes, ano.
  typedef struct {
    int dia;
    int mes;
    int ano;
  } Data;

int main () {

  int escolha;
  float verba = 0.0;
  //char nome_usuario;
  Data data = {0, 0, 0};

    // Solicita o valor total mensal
    printf("Informe o valor do dinheiro mensal : R$ ");
    scanf("%f", &verba);

    // *Brayan =  Voltar a lógica do menu anterior , e realizar as validações dentro da opção de cadastrar verba.
    // *Brayan = Fazer verificação se o usuário não usou outra opção que esteja fora do menu.
    // *Brayan = Remover dia do typedef.
    
    //Usando DO pois ele tem ficar em loop para para so sair do menu quando a opção sair for selecionada
    do {
        printf("Bem - Vindo ao BeyondPay - Sua aplicação para registro de transações\n\n");
        printf("+-------------------------------------------+\n");
        printf("|  Registre ou confira suas transações aqui!|\n");
        printf("+-------------------------------------------+\n");
        printf("|    1. Registrar a Dia                     |\n");
        printf("|    2. Registrar a Mês                     |\n");
        printf("|    3. Registrar a Ano                     |\n");
        printf("|    4. Registrar Verba                     |\n");
        printf("|    5. Registrar transações                |\n");
        printf("|    6. Ver Transações                      |\n");
        printf("|    7. Ver Total de entrada e saida        |\n");
        printf("|    0. Sair                                |\n");
        printf("+-------------------------------------------+\n");
        printf("Escolha sua opção: ");
        scanf("%d", &escolha);

        switch (escolha){
            case 1: //Registrar a data
            do{
                printf("Digite um data (1-31):");
                scanf("%d", &data.dia);
                if(data.dia < 1 || data.dia > 31){
                    printf("Dia inválido! Deve estar entre 1 e 31.\n");
                }
            }while(data.dia < 1 || data.dia > 31);
            break;

            case 2: //Registrar o mes
            do{
                printf("Digite um Mês (1-12):");
                scanf("%d", &data.mes);
                if(data.mes < 1 || data.mes > 12){
                    printf("Mês inválido! Deve estar entre 1 e 12.\n");
                }
            }while(data.mes < 1 || data.mes > 12);
            break;

            case 3: //Registrar o ano
            do{
                printf("Digite um ano (1-9999):");
                scanf("%d", &data.ano);
                if(data.ano < 1 || data.ano > 9999){
                    printf("Ano inválido! Deve estar entre 1 e 9999.\n");
                }
            }while(data.ano < 1 || data.ano > 9999);
            break;

            case 0:
                printf("Programa encerrado.\n");
                break;

            default: //Opção Invalida
            printf("Opcao invalida! Tente Novamente. \n");
            break;

            }

        } while(escolha != 0);// Termina o programa

        return 0;

        }

//while (1)
//{

  //      if (escolha == 1)
    //    {
      //    printf("Insira o mês no  qual deseja registrar a verba: \n");
        //  Data data;

          // Entrada de dados

          //  printf("Digite o mes: ");
            //scanf("%d", &data.mes);

            //printf("Digite o ano: ");
            //scanf("%d", &data.ano);

            // Saída formatada
            //printf("Data inserida: %02d/%04d\n",data.mes, data.ano);



          // Agora tenho que aprender a relacionar as verbas as dastas, pelo oque eu vi é dificil kk

        //}

//}

//}


