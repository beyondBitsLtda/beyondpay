#include <stdio.h>
#include <string.h>

#define MAX_REGISTROS 100
#define MAX_REGISTROS_TRANSF 100

char escolha_filtro = 's';
char escolha_filtro_periodo = 'n';
char escolha_categoria[50];

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

void salvar_transacoes(Registro_transf registros[], int total, float saldo) {
    FILE *arquivo = fopen("transacoes.txt", "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para escrita!\n");
        return;
    }

    fprintf(arquivo, "=== Transações Registradas ===\n");
    for (int i = 0; i < total; i++) {
        fprintf(arquivo, "%02d/%04d - R$ %.2f - Categoria: %s\n", 
                registros[i].mes, registros[i].ano, registros[i].transf, registros[i].categoria);
    }

    fprintf(arquivo, "\nSaldo Total: R$ %.2f\n", saldo);
    fclose(arquivo);
    printf("Transações salvas com sucesso em 'transacoes.txt'!\n");
}

int main() {
    Registro registros[MAX_REGISTROS];
    Registro_transf registros_transf[MAX_REGISTROS_TRANSF];

    int totalRegistros = 0;
    int totalRegistros_transf = 0;
    int escolha;
    float verba = 0.0;

    do {
        printf("Bem - Vindo ao BeyondPay\n");
        printf("+--------------------------------------------+\n");
        printf("|  1. Registrar Verba                      |\n");
        printf("|  2. Registrar Transações                 |\n");
        printf("|  3. Ver Transações                       |\n");
        printf("|  4. Calcular e Salvar Saldo              |\n");
        printf("|  5. Sair                                 |\n");
        printf("+--------------------------------------------+\n");
        printf("Escolha sua opção: ");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                if (totalRegistros < MAX_REGISTROS) {
                    printf("Insira o mês (1-12): ");
                    scanf("%d", &registros[totalRegistros].mes);
                    printf("Insira o ano (1-9999): ");
                    scanf("%d", &registros[totalRegistros].ano);
                    printf("Insira o seu Budget: ");
                    scanf("%f", &verba);
                    printf("Verba Registrada: %.2f\n", verba);
                    totalRegistros++;
                }
                break;

            case 2:
                if (totalRegistros_transf < MAX_REGISTROS_TRANSF) {
                    printf("Insira o mês (1-12): ");
                    scanf("%d", &registros_transf[totalRegistros_transf].mes);
                    printf("Insira o ano (1-9999): ");
                    scanf("%d", &registros_transf[totalRegistros_transf].ano);
                    printf("Insira o valor da Transação: ");
                    scanf("%f", &registros_transf[totalRegistros_transf].transf);
                    printf("Insira a categoria da transação: ");
                    scanf("%s", registros_transf[totalRegistros_transf].categoria);
                    totalRegistros_transf++;

                    // Calcular saldo atualizado
                    float saldo = verba;
                    for (int i = 0; i < totalRegistros_transf; i++) {
                        saldo -= registros_transf[i].transf;
                    }

                    // Salvar após cada transação
                    salvar_transacoes(registros_transf, totalRegistros_transf, saldo);
                }
                break;

            case 3:
                if (totalRegistros_transf == 0) {
                    printf("Nenhuma transação registrada.\n");
                } else {
                    printf("=== Transações Registradas ===\n");
                    for (int i = 0; i < totalRegistros_transf; i++) {
                        printf("%02d/%04d - R$ %.2f - Categoria: %s\n", 
                               registros_transf[i].mes, registros_transf[i].ano, 
                               registros_transf[i].transf, registros_transf[i].categoria);
                    }
                }
                break;

            case 4: {
                float saldo = verba;
                for (int i = 0; i < totalRegistros_transf; i++) {
                    saldo -= registros_transf[i].transf;
                }

                printf("Saldo Total: R$ %.2f\n", saldo);
                salvar_transacoes(registros_transf, totalRegistros_transf, saldo);
                break;
            }

            case 5:
                printf("Programa encerrado.\n");
                break;

            default:
                printf("Opção inválida! Tente novamente.\n");
        }
    } while (escolha != 5);

    return 0;
}
