#include <stdio.h>
#include <string.h>
#define MAX_REGISTROS 100
#define MAX_REGISTROS_TRANSF 100

char escolha_filtro = 's';
char escolha_filtro_periodo = 'n';
char escolha_categoria[50];

typedef struct {
    int mes_periodo_inicial;
    int ano_periodo_inicial;
    int mes_periodo_final;
    int ano_periodo_final;
} periodo_filtro_inicial;

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
    periodo_filtro_inicial periodo;
    Registro_transf registros_transf[MAX_REGISTROS_TRANSF];
    int totalRegistros = 0;
    int totalRegistros_transf = 0;
    int escolha;
    float verba;

    do {
        printf("Bem - Vindo ao BeyondPay\n");
        printf("+--------------------------------------------+\n");
        printf("|  1. Registrar Verba                      |\n");
        printf("|  2. Registrar transações                 |\n");
        printf("|  3. Ver Transações                       |\n");
        printf("|  4. Calcular Saldo                       |\n");
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
                    totalRegistros++;
                    printf("Registro concluído: %02d/%04d\n", registros[totalRegistros - 1].mes, registros[totalRegistros - 1].ano);
                }
                printf("Insira o seu Budget: ");
                scanf("%f", &verba);
                printf("Verba Registrada: %.2f\n", verba);
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
                }
                break;

            case 3:
                if (totalRegistros_transf == 0) {
                    printf("Nenhuma transação registrada.\n");
                } else {
                    printf("Quer filtrar por categoria? (s/n): ");
                    getchar();
                    scanf("%c", &escolha_filtro);

                    if (escolha_filtro == 's') {
                        printf("Qual é a categoria? ");
                        scanf("%49s", escolha_categoria);
                        for (int i = 0; i < totalRegistros_transf; i++) {
                            if (strcmp(escolha_categoria, registros_transf[i].categoria) == 0) {
                                printf("%02d/%04d - R$ %.2f - Categoria: %s\n", registros_transf[i].mes, registros_transf[i].ano, registros_transf[i].transf, registros_transf[i].categoria);
                            }
                        }
                    } else {
                        printf("Quer filtrar por período? (s/n): ");
                        getchar();
                        scanf("%c", &escolha_filtro_periodo);

                        if (escolha_filtro_periodo == 's') {
                            printf("Insira o mês inicial (1-12): ");
                            scanf("%d", &periodo.mes_periodo_inicial);
                            printf("Insira o ano inicial (1-9999): ");
                            scanf("%d", &periodo.ano_periodo_inicial);
                            printf("Insira o mês final (1-12): ");
                            scanf("%d", &periodo.mes_periodo_final);
                            printf("Insira o ano final (1-9999): ");
                            scanf("%d", &periodo.ano_periodo_final);

                            if ((periodo.ano_periodo_inicial > periodo.ano_periodo_final) || 
                                (periodo.ano_periodo_inicial == periodo.ano_periodo_final && 
                                 periodo.mes_periodo_inicial > periodo.mes_periodo_final)) {
                                printf("Erro: O período inicial não pode ser depois do período final!\n");
                            } else {
                                printf("\nResultados dentro do período %02d/%d até %02d/%d:\n", 
                                       periodo.mes_periodo_inicial, periodo.ano_periodo_inicial, 
                                       periodo.mes_periodo_final, periodo.ano_periodo_final);
                                       for (int i = 0; i < totalRegistros_transf; i++) 
                                        // Verificação se a transação está dentro do período
                                        if ((registros_transf[i].ano > periodo.ano_periodo_inicial || 
                                             (registros_transf[i].ano == periodo.ano_periodo_inicial && 
                                              registros_transf[i].mes >= periodo.mes_periodo_inicial)) && 
                                            (registros_transf[i].ano < periodo.ano_periodo_final || 
                                             (registros_transf[i].ano == periodo.ano_periodo_final && 
                                              registros_transf[i].mes <= periodo.mes_periodo_final))) {
                                            printf("%02d/%04d - R$ %.2f - Categoria: %s\n", 
                                                   registros_transf[i].mes, registros_transf[i].ano, 
                                                   registros_transf[i].transf, registros_transf[i].categoria);
                                        }

                            }
                            
                        }
                    }
                }
                break;

            case 4: {
                float saldo = 0;
                for (int i = 0; i < totalRegistros_transf; i++) {
                    saldo += registros_transf[i].transf;
                }
                printf("Saldo total das transações: R$ %.2f\n", saldo);
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
