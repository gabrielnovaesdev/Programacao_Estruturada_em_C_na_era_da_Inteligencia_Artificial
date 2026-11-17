# Monitoramento de temperatura em C

Atividade de Programação Estruturada em C na era da IA.

O programa pede o nome de um equipamento e 5 temperaturas, calcula a média, mostra se a situação é **NORMAL** ou **ALERTA** e grava o resultado em `relatorio.txt`.

**Versão web:** https://gabrielnovaesdev.github.io/Programacao_Estruturada_em_C_na_era_da_Inteligencia_Artificial/

## Regra do alerta

Se alguma temperatura for **maior que 35**, a situação é ALERTA. Exatamente 35 conta como NORMAL.

## Como compilar e rodar

```bash
gcc -std=c11 -Wall -Wextra -pedantic monitoramento.c -o monitoramento
./monitoramento        # no Windows: .\monitoramento.exe
```

## Exemplo de entrada e saída

Entrada: `Sensor02`, 20, 22, 25, 30, 35

```
--- RELATORIO ---
Equipamento: Sensor02
Media: 26.40 graus C
Situacao: NORMAL
Relatorio salvo com sucesso!
```

Cada execução acrescenta uma linha ao `relatorio.txt` no formato `nome;média;situação` (veja `relatorio_exemplo.txt`).

## Arquivos

- `index.html`: versão web do programa (publicada no GitHub Pages)
- `monitoramento.c`: o programa em C
- `relatorio_exemplo.txt`: exemplo do arquivo gerado
- `APS_Programacao_Estruturada_Prints_GitHub.pdf`: prints e explicações da atividade, com dados pessoais ocultados
