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

int RPN_Solving(char *rpn) {
    int n_operands_lsize = 0;
    int n_operands[n_operands_lsize];

    for (int i = 0; i < strlen(rpn); i++) {
        int operand_list_size, operator_list_size = 0;
        int operands[operand_list_size];
        int operators[operator_list_size + 1]; // +1 for /0

        printf("Processing character: %c\n", rpn[i]);
        if (isdigit(rpn[i])){
            int starti = i;
            while (isdigit(rpn[i])) {
                operand_list_size++;
                i++;
            }

            for (int j = 0; j < operand_list_size; j++) {
                printf("Processing character: %c\n", rpn[i]);
                operands[j] = rpn[starti + j] - '0'; //convert char to int and put in list
            }
        }
        else {
            printf("%c is not a digit\n", rpn[i]);
            switch (rpn[i]) {
                case '+':
                case '-':
                case '*':
                case '/':
                    operand_list_size = n_operands_lsize;
                    
                    for (int j = 0; j < operand_list_size; j++) {
                        operands[j] = n_operands[j];
                        n_operands[j] = 0;
                    }

                    n_operands_lsize = 0;
                
                case ' ':
                    break;
                case '=':
                    return n_operands[0];
                default:
                    printf("Error: Unknown character '%c'\n", rpn[i]);
                    exit(EXIT_FAILURE);
            }
        }

        operator_list_size = operand_list_size + 1;
        
        for (int j = 0; j < operator_list_size; j++) {
            if (rpn[i] == '+' || rpn[i] == '-' || rpn[i] == '*' || rpn[i] == '/') {
                operators[j] = rpn[i];
                i++;
            }
            else if (rpn[i] == ' ') {
                i++;
            }
            else if (rpn[i] == '=') {
                break;
            }
            else {
                printf("Error: Unknown character '%c'\n", rpn[i]);
                exit(EXIT_FAILURE);
            }
        }

        n_operands_lsize++;
        int result = 0;
        for (int j = 0; j < operand_list_size - 1; j++) {
            result = operate(operands[j], operands[j + 1], operators[j]);
            printf("Intermediate result: %d\n", result);
        }

        n_operands[n_operands_lsize - 1] = result;
        for (int j = 0; j < n_operands_lsize; j++) {
            printf("n_operands[%d] = %d\n", j, n_operands[j]);
        }
    }

}

int main(void) {
    while (true) {
        char rpn[100];
        printf("Enter RPN expression: ");
        fgets(rpn, sizeof(rpn), stdin);
        if (strncmp(rpn, "exit", 4) == 0) {
            break;
        }
        int result = RPN_Solving(rpn);
        printf("Result: %d\n", result);
    }

    return 0;
}