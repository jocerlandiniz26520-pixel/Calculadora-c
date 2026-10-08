/**
 * @file calculadora.c
 * @brief Calculadora robusta em C com validação e tratamento de entradas de dados.
 * @author Seu Nome
 */

#include <stdio.h>
#include <stdlib.h>
#include <locale.h> 

int main(void) {
    // Permite que o programa aceite o formato de números local (ex: vírgula ou ponto decimal)
    setlocale(LC_ALL, ""); 

    char entrada[50]; // Buffer para armazenar as entradas como texto seguro
    char *endptr;      
    
    float x = 0, y = 0, resultado = 0;
    int op = 0;
    
    do {
        // 1. Menu de Opções Seguro
        do {
            printf("\n\t1 - Soma\n\t2 - Subtração\n\t3 - Multiplicação\n\t4 - Divisão\n"); 
            printf("Escolha uma opção: ");
            
            fgets(entrada, sizeof(entrada), stdin);
            op = (int)strtol(entrada, &endptr, 10);
            
            if (endptr == entrada || (*endptr != '\n' && *endptr != '\0')) {
                printf("\nErro: Digite apenas números inteiros para o menu!\n");
                op = 0;
            } else if (op < 1 || op > 4) {
                printf("\nOpção inválida! Digite um número de 1 a 4.\n");
            }
        } while (op < 1 || op > 4);

        // 2. Primeiro Número Fracionado Seguro
        do {
            printf("\nDigite o primeiro número: ");
            fgets(entrada, sizeof(entrada), stdin);
            x = strtof(entrada, &endptr); 
            
            if (endptr == entrada || (*endptr != '\n' && *endptr != '\0')) {
                printf("Entrada inválida! Digite um número válido.\n");
                endptr = NULL; 
            }
        } while (endptr == NULL);

        // 3. Segundo Número Fracionado Seguro
        do {
            printf("Digite o segundo número: ");
            fgets(entrada, sizeof(entrada), stdin);
            y = strtof(entrada, &endptr);
            
            if (endptr == entrada || (*endptr != '\n' && *endptr != '\0')) {
                printf("Entrada inválida! Digite um número válido.\n");
                endptr = NULL;
            }
        } while (endptr == NULL);

        // Processamento das operações aritméticas
        switch (op) {
            case 1: resultado = x + y; break;
            case 2: resultado = x - y; break;
            case 3: resultado = x * y; break;
            case 4:
                if (y != 0) {
                    resultado = x / y;
                } else {
                    printf("\nErro: Divisão por zero não é permitida!\n");
                    resultado = 0;
                }
                break;
        }

        printf("\nO resultado é: %0.2f", resultado);
        
        // 4. Validação de continuidade do loop
        do {
            printf("\n\nDeseja continuar? (1 - Sim / 0 - Não): ");
            fgets(entrada, sizeof(entrada), stdin);
            op = (int)strtol(entrada, &endptr, 10);
            
            if (endptr == entrada || (*endptr != '\n' && *endptr != '\0')) {
                op = -1;
            }
        } while (op != 0 && op != 1);

    } while (op == 1);

    return 0;
}
