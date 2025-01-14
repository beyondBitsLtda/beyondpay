/*main.c:
Centraliza o fluxo do programa.
Faz uso dos arquivos de cabeçalho (.h) do diretório include/ para chamar funções implementadas em src/.*/

/*incluindo os arquivos que serão lidos no main*/
/*Uma observação é que possivelmente terá que ser revisto e implementado outros códigos*/
// Verificar repositório "https://github.com/vivek081202/FinTrack-Expense_and_Budget_Analyzer/blob/main/src/main.c"

#include <stdio.h>
#define MAX_REGISTROS 100 //define a quantidade max de registros no array
#define MAX_REGISTROS_TRANSF 100 //define a quantidade max de registros no array
//#include "finance.h"
//#include "input.h"
//#include "output.h"git

  // Definindo uma estrutura para representar uma data, mes, ano.
  typedef struct {
    //int dia;
    int mes;
    int ano;
    //float verba;
} Registro;

// Definindo uma estrutura para representar uma data, mes, ano e valor de transação
  typedef struct {
    //int dia;
    int mes;
    int ano;
    float transf;
    //float verba;
} Registro_transf;

int main () {

    Registro registros[MAX_REGISTROS]; // Array para armazenar registros
    Registro_transf registros_transf[MAX_REGISTROS_TRANSF]; // Array para armazenar registros
    int totalRegistros = 0; // Contador de registros
    int totalRegistros_transf = 0; // Contador de registros
    int escolha;
    //char nome_usuario;
    //Data data = {0, 0, 0};
    float verba;
    

    // Solicita o valor total mensal
    //printf("Informe o valor do dinheiro mensal : R$ ");
    //scanf("%f", &verba);

// Adptei a lógica de menu, criando a opção de cadastrar as verbas e transações com base o mês
// Vericar opção de realizar o Switch ao invés de While.

    //Usando DO pois ele tem ficar em loop para para so sair do menu quando a opção sair for selecionada
    do {
        printf("Bem - Vindo ao BeyondPay                      \n");
        printf("Sua aplicação para registro de transações     \n");
        printf("+--------------------------------------------+\n");
        printf("|  Registre ou confira suas transações aqui! |\n");
        printf("+--------------------------------------------+\n");
        printf("|    1. Registrar Verba                      |\n");
        printf("|    2. Registrar transações                 |\n");
        printf("|    3. Ver Transações                       |\n");
        printf("|    4. Sair                                 |\n");
        printf("+--------------------------------------------+\n");
        printf("Escolha sua opção: ");
        scanf("%d", &escolha);


        switch (escolha){
           case 1: // Registrar mês e ano
                if (totalRegistros < MAX_REGISTROS) {
                    // Validação do mês
                    do {
                        printf("Insira o mês (1-12): ");
                        scanf("%d", &registros[totalRegistros].mes);
                        if (registros[totalRegistros].mes < 1 || registros[totalRegistros].mes > 12) {
                            printf("Mês inválido! O valor deve estar entre 1 e 12.\n");
                        }
                    } while (registros[totalRegistros].mes < 1 || registros[totalRegistros].mes > 12);

                    // Validação do ano
                    do {
                        printf("Insira o ano (1-9999): ");
                        scanf("%d", &registros[totalRegistros].ano);
                        if (registros[totalRegistros].ano < 1 || registros[totalRegistros].ano > 9999) {
                            printf("Ano inválido! O valor deve estar entre 1 e 9999.\n");
                        }
                    } while (registros[totalRegistros].ano < 1 || registros[totalRegistros].ano > 9999);

                    // Incrementar o contador de registros
                    totalRegistros++;

                    // Mensagem de confirmação
                    printf("Registro concluído: %02d/%04d\n",
                           registros[totalRegistros - 1].mes,
                           registros[totalRegistros - 1].ano); //acessa o índice do último registro adicionado (porque os índices começam em 0).
                } else {
                    printf("Limite de registros atingido.\n");
                }

                    printf("Insira o seu Bugted: ");
                    scanf("%f", &verba);
                    printf("Verba Registrada: %.2f\n", verba);

                break;

            case 2: // Registrar verba. Aqui vamos ter que pensar em como vincular transferência com o mês registrado.
             if (totalRegistros_transf < MAX_REGISTROS_TRANSF) {
                    // Validação do mês
                    do {
                        printf("Insira o mês (1-12): ");
                        scanf("%d", &registros_transf[totalRegistros_transf].mes);
                        if (registros_transf[totalRegistros_transf].mes < 1 || registros[totalRegistros_transf].mes > 12) {
                            printf("Mês inválido! O valor deve estar entre 1 e 12.\n");
                        }
                    } while (registros_transf[totalRegistros_transf].mes < 1 || registros_transf[totalRegistros_transf].mes > 12);

                    // Validação do ano
                    do {
                        printf("Insira o ano (1-9999): ");
                        scanf("%d", &registros_transf[totalRegistros_transf].ano);
                        if (registros_transf[totalRegistros_transf].ano < 1 || registros_transf[totalRegistros_transf].ano > 9999) {
                            printf("Ano inválido! O valor deve estar entre 1 e 9999.\n");
                        }
                    } while (registros_transf[totalRegistros_transf].ano < 1 || registros_transf[totalRegistros_transf].ano > 9999);

                    // Incrementar o contador de registros
                    totalRegistros_transf++;

                    // Mensagem de confirmação
                    printf("Registro concluído: %02d/%04d\n",
                           registros[totalRegistros - 1].mes,
                           registros[totalRegistros - 1].ano); //acessa o índice do último registro adicionado (porque os índices começam em 0).
                } else {
                    printf("Limite de registros atingido.\n");
                }
                    Registro_transf registro_transferencia_control;
                     printf("Insira o valor de Transação desejado: ");
                     scanf("%f", &registro_transferencia_control.transf);
                     printf("Transação Registrada: %.2f\n", registro_transferencia_control);
                     while (registro_transferencia_control.transf <= 0) {
                     printf("O valor prescisa ser maior que 0: ");
                     scanf("%f", &registro_transferencia_control.transf);
                     // Exibindo apenas o último registro
                    int ultimoIndice = 2; // Índice do último elemento (tamanho do array - 1)
                    printf("Último Registro:\n");
                    printf("Data: %02d/%d - Valor: R$ %.2f\n"), 
                    registros_transf[totalRegistros_transf].mes, 
                    registros_transf[totalRegistros_transf].ano, 
                    registros_transf[totalRegistros_transf].transf;

                    return 0;        
               
            }

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




