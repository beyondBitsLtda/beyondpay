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

                printf("Insira o seu Bugted: ");
                scanf("%f", &verba);
                printf("Verba Registrada: %.2f\n", verba);
                break;

            case 2:
                if (totalRegistros_transf < MAX_REGISTROS_TRANSF) {
                    do {
                        printf("Insira o mês (1-12): ");
                        scanf("%d", &registros_transf[totalRegistros_transf].mes);
                        if (registros_transf[totalRegistros_transf].mes < 1 || registros_transf[totalRegistros_transf].mes > 12) {
                            printf("Mês inválido! O valor deve estar entre 1 e 12.\n");
                        }
                    } while (registros_transf[totalRegistros_transf].mes < 1 || registros_transf[totalRegistros_transf].mes > 12);

                    do {
                        printf("Insira o ano (1-9999): ");
                        scanf("%d", &registros_transf[totalRegistros_transf].ano);
                        if (registros_transf[totalRegistros_transf].ano < 1 || registros_transf[totalRegistros_transf].ano > 9999) {
                            printf("Ano inválido! O valor deve estar entre 1 e 9999.\n");
                        }
                    } while (registros_transf[totalRegistros_transf].ano < 1 || registros_transf[totalRegistros_transf].ano > 9999);

                    printf("Insira o valor de Transação desejado: ");
                    scanf("%f", &registros_transf[totalRegistros_transf].transf);
                    while (registros_transf[totalRegistros_transf].transf <= 0) {
                        printf("O valor precisa ser maior que 0: ");
                        scanf("%f", &registros_transf[totalRegistros_transf].transf);
                    }

                    printf("Transação Registrada: %.2f\n", registros_transf[totalRegistros_transf].transf);
                    printf("Registro concluído: %02d/%04d - Valor: R$ %.2f\n",
                           registros_transf[totalRegistros_transf].mes,
                           registros_transf[totalRegistros_transf].ano,
                           registros_transf[totalRegistros_transf].transf);

                    totalRegistros_transf++;
                } else {
                    printf("Limite de registros atingido.\n");
                }
                break;

            case 0:
                printf("Programa encerrado.\n");
                break;

            default:
                printf("Opção inválida! Tente novamente.\n");
                break;
        }
    } while (escolha != 0);

    return 0;
}