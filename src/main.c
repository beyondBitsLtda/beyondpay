#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h> // Para a função Sleep()
#include <locale.h> // Permitir acentuação
#include <time.h> // Para obter o ano atual

#define MAX_REGISTROS 100
#define MAX_REGISTROS_TRANSF 100

char escolha_filtro = 's';
char escolha_filtro_periodo = 'n';
char escolha_categoria[50];
char inicio;

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
    FILE *arquivo = fopen("transacoes.txt", "a");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para escrita!\n");
        return;
    }

    fprintf(arquivo, "=== Transações Registradas ===\n");
    for (int i = 0; i < total; i++) {
        fprintf(arquivo, "%02d/%04d - R$ %.2f - Categoria: %s\n");
    }

    fprintf(arquivo, "\nSaldo Total: R$ %.2f\n", saldo);
    fclose(arquivo);
    printf("Transações salvas com sucesso em 'transacoes.txt'!\n");
}

void ver_transacoes(const char *transacoes) {
    FILE *arquivo; // Ponteiro para o arquivo
    char linha[256]; // Buffer para armazenar uma linha lida
    arquivo = fopen("transacoes.txt", "r");  // Abrir o arquivo em modo leitura

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para escrita!\n");
        return;
    }
    // Ler o arquivo linha por linha
    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        // Imprimir cada linha lida do arquivo
        printf("%s", linha);
    }
     // Fechar o arquivo
     fclose(arquivo);

}



int main() {

        // Configura a localidade para UTF-8 (geralmente adequada para suportar acentuação)
        setlocale(LC_ALL, "portuguese");

        Sleep(2000); // Pausa por 3000 milissegundos (3 segundos)
        printf("######   ######   #     #   #####    #     #  ######   ######      #    #     #  \n");
        printf("#     #  #        #     #  #     #   ##    #  #     #  #      #  #   #  #     #  \n");
        printf("#     #  #         #   #   #     #   # #   #  #     #  #      # #     #  #   #   \n");
        printf("######   ####       # #    #     #   #  #  #  #     #  ######   #######   ##     \n");
        printf("#     #  #          #      #     #   #   # #  #     #  #        #     #   #      \n");
        printf("#     #  #          #      #     #   #    ##  #     #  #        #     #   #      \n");
        printf("######   ######     #       #####    #     #  ######   #        #     #   #      \n");
        Sleep(3000); // Pausa por 3000 milissegundos (3 segundos)
        printf("                 \n");
        printf("                 \n");
        printf("By Beyond Bits - A Beyond é o Futuro!");
        printf("                 \n");
        printf("                 \n");
        printf("Pressione qualquer tecla para continuar...\n");
        getchar(); // Aguarda o usuário pressionar Enter
        Sleep(3000); // Pausa por 3000 milissegundos (3 segundos)
        system("cls");






    Registro registros[MAX_REGISTROS];
    Registro_transf registros_transf[MAX_REGISTROS_TRANSF];

    int totalRegistros = 0;
    int totalRegistros_transf = 0;
    int escolha;
    float verba = 0.0;
    float verba_digitada = 0.0;

    do {
        printf("Bem - Vindo ao BeyondPay\n");
        printf("+--------------------------------------------+\n");
        printf("|  1. Registrar Verba                        |\n");
        printf("|  2. Registrar Transações                   |\n");
        printf("|  3. Ver Transações e Saldo                 |\n");
        printf("|  4. Sair                                   |\n");
        printf("|                                            |\n");
        printf("+--------------------------------------------+\n");
        printf("Escolha sua opção: ");
        scanf("%d", &escolha);

         switch (escolha) {
            case 1:
                if (totalRegistros < MAX_REGISTROS) {
                    int mes, ano;

                    // Validação do mês
                    int isMes;
                   do {
                        printf("Insira o mês (1-12): ");
                        isMes = scanf("%d", &mes);

                        if (isMes != 1) {
                        printf("Valor inválido! Por favor, insira um número inteiro para o mês.\n");
                        while (getchar() != '\n');  // Limpa o buffer do teclado para evitar loop infinito
                        } else if (mes < 1 || mes > 12) {
                        printf("O valor do mês deve estar entre 1 e 12. Tente novamente.\n");
                        }
                        } while (isMes != 1 || mes < 1 || mes > 12);
                        printf("Mês válido inserido: %d\n", mes);

                    // Validação do ano
                    int isAno;

                    // Obter o ano atual
                    time_t t = time(NULL);
                    struct tm tm = *localtime(&t);
                    int ano_atual = tm.tm_year + 1900;

                    do {
                        printf("Insira o ano (1900-%d): ", ano_atual);
                        isAno = scanf("%d", &ano);

                    if (isAno != 1) {
                        printf("Valor inválido! Por favor, insira um número inteiro para o ano.\n");
                    while (getchar() != '\n');  // Limpa o buffer para evitar loop infinito
                        } else if (ano < 1900 || ano > ano_atual) {
                            printf("Ano inválido! Por favor, insira um ano entre 1900 e %d.\n", ano_atual);
                        }
                    } while (isAno != 1 || ano < 1900 || ano > ano_atual);

                    printf("Ano válido inserido: %d\n", ano);

                    // Validação do "Budget" (verba)
                    int isValid;
                    do {
                        printf("Insira o seu Budget: ");
                        isValid = scanf("%f", &verba_digitada);

                        // Verificar se a entrada é válida
                        if (isValid != 1) {
                            printf("Valor inválido! Por favor, insira um número válido para o Budget.\n");
                            // Limpar o buffer do teclado para evitar loop infinito
                            while (getchar() != '\n');
                        } else if (verba_digitada < 0) {
                            printf("O valor do Budget não pode ser negativo. Tente novamente.\n");
                        }
                    } while (isValid != 1 || verba_digitada < 0);

                    verba += verba_digitada;
                    printf("Verba Registrada: %.2f\n", verba);
                    totalRegistros++;
                    Sleep(2000); // Pausa por 3000 milissegundos (3 segundos)
                    system("cls");
                }
                break;

            case 2:
                if (totalRegistros_transf < MAX_REGISTROS_TRANSF) {
                     int mes, ano;

                    // Validação do mês
                    int isMes;
                   do {
                        printf("Insira o mês (1-12): ");
                        isMes = scanf("%d", &mes);

                        if (isMes != 1) {
                        printf("Valor inválido! Por favor, insira um número inteiro para o mês.\n");
                        while (getchar() != '\n');  // Limpa o buffer do teclado para evitar loop infinito
                        } else if (mes < 1 || mes > 12) {
                        printf("O valor do mês deve estar entre 1 e 12. Tente novamente.\n");
                        }
                        } while (isMes != 1 || mes < 1 || mes > 12);
                        printf("Mês válido inserido: %d\n", mes);

                    // Validação do ano
                    int isAno;

                    // Obter o ano atual
                    time_t t = time(NULL);
                    struct tm tm = *localtime(&t);
                    int ano_atual = tm.tm_year + 1900;

                    do {
                        printf("Insira o ano (1900-%d): ", ano_atual);
                        isAno = scanf("%d", &ano);

                    if (isAno != 1) {
                        printf("Valor inválido! Por favor, insira um número inteiro para o ano.\n");
                    while (getchar() != '\n');  // Limpa o buffer para evitar loop infinito
                        } else if (ano < 1900 || ano > ano_atual) {
                            printf("Ano inválido! Por favor, insira um ano entre 1900 e %d.\n", ano_atual);
                        }
                    } while (isAno != 1 || ano < 1900 || ano > ano_atual);

                    printf("Ano válido inserido: %d\n", ano);

                float valor;
                int isValor;

                do {
                    printf("Insira o valor da Transação (positivo): ");
                    isValor = scanf("%f", &valor);

                if (isValor != 1) {
                    printf("Valor inválido! Insira um número válido.\n");
                    while (getchar() != '\n'); // Limpa o buffer de entrada
                } else if (valor <= 0) {
                    printf("O valor da transação deve ser maior que zero.\n");
                }
                } while (isValor != 1 || valor <= 0);

                registros_transf[totalRegistros_transf].transf = valor;

                printf("Insira a categoria da transação: ");
                scanf("%s", registros_transf[totalRegistros_transf].categoria);

                totalRegistros_transf++;
                Sleep(2000); // Pausa de 2 segundos
                system("cls");

                // Calcular saldo atualizado
                float saldo = verba;
                    for (int i = 0; i < totalRegistros_transf; i++) {
                    saldo -= registros_transf[i].transf;
                }

                    // Salvar após cada transação
                    salvar_transacoes(registros_transf, totalRegistros_transf, saldo);
                }
                break;

            case 3: {



                  // Chama a função para ler o arquivo no meio do código
                  ver_transacoes("transacoes.txt");
                  printf("Pressione qualquer tecla para continuar...\n");
                  getchar(); // Aguarda o usuário pressionar Enter




                }

            case 4:
                printf("Programa encerrado.\n");
                abort();

            default:
                printf("Opção inválida! Tente novamente.\n");

        }
    } while (escolha != 4);

    return 0;
}