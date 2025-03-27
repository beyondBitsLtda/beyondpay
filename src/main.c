#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h> // Para a função Sleep()

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
    FILE *arquivo = fopen("transacoes.txt", "a");
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
        printf("|  1. Registrar Verba                      |\n");
        printf("|  2. Registrar Transações                 |\n");
        printf("|  3. Ver Transações                       |\n");
        printf("|  4. Sair                                 |\n");
        printf("|                                          |\n");
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
                    scanf("%f", &verba_digitada);
                    verba = verba + verba_digitada;
                    printf("Verba Registrada: %.2f\n", verba);
                    totalRegistros++;
                    Sleep(3000); // Pausa por 3000 milissegundos (3 segundos)
                    system("cls");
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
                    Sleep(3000); // Pausa por 3000 milissegundos (3 segundos)
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
