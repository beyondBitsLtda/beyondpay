#include <stdio.h>
#define MAX_REGISTROS 100
#define MAX_REGISTROS_TRANSF 100

typedef struct {
    int mes;
    int ano;
} Registro;

typedef struct {
    int mes;
    int ano;
    float transf;
    char categoria[50];
} Registro_transf;

int main() {
    Registro registros[MAX_REGISTROS];
    Registro_transf registros_transf[MAX_REGISTROS_TRANSF];
    int totalRegistros = 0;
    int totalRegistros_transf = 0;
    int escolha;
    float verba;

    do {
        printf("Bem - Vindo ao BeyondPay\n");
        printf("Sua aplicação para registro de transações\n");
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

        switch (escolha) {
            case 1:
                if (totalRegistros < MAX_REGISTROS) {
                    do {
                        printf("Insira o mês (1-12): ");
                        scanf("%d", &registros[totalRegistros].mes);
                        if (registros[totalRegistros].mes < 1 || registros[totalRegistros].mes > 12) {
                            printf("Mês inválido! O valor deve estar entre 1 e 12.\n");
                        }
                    } while (registros[totalRegistros].mes < 1 || registros[totalRegistros].mes > 12);

                    do {
                        printf("Insira o ano (1-9999): ");
                        scanf("%d", &registros[totalRegistros].ano);
                        if (registros[totalRegistros].ano < 1 || registros[totalRegistros].ano > 9999) {
                            printf("Ano inválido! O valor deve estar entre 1 e 9999.\n");
                        }
                    } while (registros[totalRegistros].ano < 1 || registros[totalRegistros].ano > 9999);

                    totalRegistros++;
                    printf("Registro concluído: %02d/%04d\n", registros[totalRegistros - 1].mes, registros[totalRegistros - 1].ano);
                } else {
                    printf("Limite de registros atingido.\n");
                }

                printf("Insira o seu Budget: ");
                scanf("%f", &verba);
                printf("Verba Registrada: %.2f\n", verba);
                break;

            case 2:
                if (totalRegistros_transf < MAX_REGISTROS_TRANSF) {
                        printf("Insira o mês (1-12): ");
                        scanf("%d", &registros_transf[totalRegistros_transf].mes);
                        if (registros_transf[totalRegistros_transf].mes < 1 || registros_transf[totalRegistros_transf].mes > 12) {
                            printf("Mês inválido! O valor deve estar entre 1 e 12.\n");
                        }
                        printf("Insira o ano (1-9999): ");
                        scanf("%d", &registros_transf[totalRegistros_transf].ano);
                        if (registros_transf[totalRegistros_transf].ano < 1 || registros_transf[totalRegistros_transf].ano > 9999) {
                            printf("Ano inválido! O valor deve estar entre 1 e 9999.\n");
                        } 

                   
                    printf("Insira o valor da Transação: ");
                    scanf("%f", &registros_transf[totalRegistros_transf].transf);
                    while (&registros_transf[totalRegistros_transf].transf <= 0) {
                        printf("O valor precisa ser maior que 0: ");
                        scanf("%f", &registros_transf[totalRegistros_transf].transf);
                        while (getchar() != '\n'); // Limpa o buffer para evitar loop infinito
                    }


                    printf("Insira a categoria da transação: ");
                    //while (getchar() != '\n'); // Limpa qualquer resíduo no buffer antes da leitura
                    scanf("%s", &registros_transf[totalRegistros_transf].categoria);

                    printf("Transação Registrada: %.2f\n", registros_transf[totalRegistros_transf].transf);
                    printf("Registro concluído: %02d/%04d - Valor: R$ %.2f - Categoria: %s\n",
                           registros_transf[totalRegistros_transf].mes,
                           registros_transf[totalRegistros_transf].ano,
                           registros_transf[totalRegistros_transf].transf,
                           registros_transf[totalRegistros_transf].categoria);

                    totalRegistros_transf++;
                } else {
                    printf("Limite de registros atingido.\n");
                }
                break;

            case 3:
                if (totalRegistros_transf == 0) {
                    printf("Nenhuma transação registrada.\n");
                } else {
                    printf("\n--- Transações Registradas ---\n");
                    for (int i = 0; i < totalRegistros_transf; i++) {
                        printf("%02d/%04d - Valor: R$ %.2f - Categoria: %c\n",
                               registros_transf[i].mes,
                               registros_transf[i].ano,
                               registros_transf[i].transf,
                               registros_transf[i].categoria);
                    }
                }
                break;

            case 4:
                printf("Programa encerrado.\n");
                break;

            default:
                printf("Opção inválida! Tente novamente.\n");
                break;
        }
    } while (escolha != 4);

    return 0;
}
