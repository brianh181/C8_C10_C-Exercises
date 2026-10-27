#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

int operate(int a, int b, char op) {
    printf("Operating: %d %c %d\n", a, op, b);
    switch (op) {
        case '+':
            return a + b;
        case '-':
            return a - b;
        case '*':
            return a * b;
        case '/':
            if (b != 0) {
                return a / b;
            } else {
                printf("Error: Division by zero\n");
                exit(EXIT_FAILURE);
            }
        default:
            printf("Error: Unknown operator '%c'\n", op);
            exit(EXIT_FAILURE);
    }
}

int main(void) {
    while (1) {
        int *operands = malloc(25 * sizeof(int));
        int *n_operands = malloc(25 * sizeof(int));
        char *operators = malloc(26 * sizeof(char));
        char *RPN = malloc(25 * sizeof(char));

        printf("Enter an expression: ");
        scanf("%99s", RPN);

        for (int i = 0; RPN[i] != '\0'; i++) {

            if (isdigit(RPN[i])) {
                while (isdigit(RPN[i])) {
                    operands[i] = operands[i] * 10 + (RPN[i] - '0');
                    printf("Operand: %d\n", operands[i]);
                    i++;
                }
            }
            else {
                for (int j = 0; j < sizeof(n_operands); j++) {
                    operands[j] = n_operands[j];
                    i++;
                }

                int n_operands[25] = {0};
            }
        
            while (RPN[i] == '+' || RPN[i] == '-' || RPN[i] == '*' || RPN[i] == '/' || RPN[i] == '=') {
                if (RPN[i] == '=') {
                    break;
                }

                int j = 0;
                operators[j] = RPN[i];
                i++, j++;
            }

            for (int k = 0; k < sizeof(operands) - 1; k++) {
                printf("%99s", operators);
                printf("operator: %c\n", operators[k]);
                int result = operate(operands[k], operands[k + 1], operators[k]);
                operands[k+1] = result;
                printf("Result: %d\n", result);
                operands[k] = 0;
            }

            int n_operand = 0;
            for (int j = 0; j < sizeof(operands) - 1; j++) {
                n_operand += operands[j];
            }
            
            for (int l = 0; l < sizeof(n_operands); l++) {
                if (n_operands[l] != 0) {
                    n_operands[l] = n_operand;
                    break;
                }
            }

            operators[0] = '\0';
        }

        printf("%d",sizeof(n_operands));

    }

    

}