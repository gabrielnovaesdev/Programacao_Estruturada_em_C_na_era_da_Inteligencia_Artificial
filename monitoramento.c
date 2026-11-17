#include <stdio.h>
#include <string.h>

#define TOTAL 5
#define LIMITE 35.0f

/* Registro que sera gravado no arquivo */
typedef struct {
    char nome[40];
    float media;
    int alerta;
} Relatorio;

/* Calcula a media dos valores do vetor */
float calcular_media(const float valores[], int quantidade) {
    float soma = 0.0f;

    for (int i = 0; i < quantidade; i++) {
        soma += valores[i];
    }

    return soma / quantidade;
}

/* Retorna 1 se alguma temperatura for MAIOR que o limite; senao 0 */
int verificar_alerta(const float valores[], int quantidade) {
    for (int i = 0; i < quantidade; i++) {
        if (valores[i] > LIMITE) {
            return 1;
        }
    }

    return 0;
}

/* Acrescenta uma linha no arquivo relatorio.txt (modo "a" = append) */
int salvar_relatorio(const Relatorio *r) {
    FILE *arquivo = fopen("relatorio.txt", "a");

    if (arquivo == NULL) {
        return 0;
    }

    fprintf(arquivo, "%s;%.2f;%s\n",
            r->nome,
            r->media,
            r->alerta ? "ALERTA" : "NORMAL");

    if (fclose(arquivo) != 0) {
        return 0;
    }

    return 1;
}

int main(void) {
    char equipamento[40];
    float temperaturas[TOTAL];

    printf("Nome do equipamento (sem espacos): ");
    if (scanf("%39s", equipamento) != 1) {
        return 1;
    }

    for (int i = 0; i < TOTAL; i++) {
        printf("Temperatura %d: ", i + 1);

        if (scanf("%f", &temperaturas[i]) != 1) {
            printf("Entrada invalida.\n");
            return 1;
        }
    }

    float media = calcular_media(temperaturas, TOTAL);
    int alerta = verificar_alerta(temperaturas, TOTAL);

    printf("\n--- RELATORIO ---\n");
    printf("Equipamento: %s\n", equipamento);
    printf("Media: %.2f graus C\n", media);
    printf("Situacao: %s\n", alerta ? "ALERTA" : "NORMAL");

    Relatorio resultado;

    strcpy(resultado.nome, equipamento);
    resultado.media = media;
    resultado.alerta = alerta;

    if (salvar_relatorio(&resultado)) {
        printf("Relatorio salvo com sucesso!\n");
    } else {
        printf("Nao foi possivel salvar o relatorio.\n");
    }

    return 0;
}
