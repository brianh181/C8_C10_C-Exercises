#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

void Operate(int *Operands, int OperandCount, int *new_Operands, int *new_Operandcount, char *Operators) {
    new_Operands[*new_Operandcount] = Operands[0];

    for (int i = 0; i < OperandCount - 1; i++) {

        switch (Operators[i]) {
            case '+':
                new_Operands[*new_Operandcount] += Operands[i + 1];
                break;
            case '-':
                new_Operands[*new_Operandcount] -= Operands[i + 1];
                break;
            case '*':
                new_Operands[*new_Operandcount] *= Operands[i + 1];
                break;
            case '/':
                new_Operands[*new_Operandcount] /= Operands[i + 1];
                break;
        }
    }

    (*new_Operandcount)++;
}

int main(void) {
    #define MAX_LIST_LENGTH 100
    
    char RPN[MAX_LIST_LENGTH + 1], Operators[MAX_LIST_LENGTH + 1];
    int OperandCount = 0, Operands[MAX_LIST_LENGTH];
    int new_Operandcount = 0, New_Operands[MAX_LIST_LENGTH];

    while (true) {
        new_Operandcount = 0;
        memset(New_Operands, 0, sizeof(New_Operands));
        memset(RPN, '\0', sizeof(RPN));
        memset(Operands, 0, sizeof(Operands));
        memset(Operators, '\0', sizeof(Operators));
        OperandCount = 0;

        printf("Enter an RPN expression: ");
        scanf("%s", RPN);

        char *character = RPN;

        for (character = &RPN[0]; *character != '\0'; character++) {
            bool was_operator = false;

            if (isdigit(*character)) {
                Operands[OperandCount++] = *character - '0';

            } else if (*character == '+' || *character == '-' || *character == '*' || *character == '/') {
                if (OperandCount < 1) {
                    OperandCount = new_Operandcount;

                    for (int i = 0; i < new_Operandcount; i++) {
                        Operands[i] = New_Operands[i];
                    }

                    memset(New_Operands, 0, sizeof(New_Operands));
                    new_Operandcount = 0;
                    
                }
                else if (OperandCount < 2) {
                    OperandCount = new_Operandcount + 1;
                    Operands[OperandCount - 1] = Operands[0];

                    for (int i = 0; i < new_Operandcount; i++) {
                        Operands[i] = New_Operands[i];
                    }

                    memset(New_Operands, 0, sizeof(New_Operands));
                    new_Operandcount = 0;
                }

                for (int i = 0; i < OperandCount - 1; i++) {
                    Operators[i] = *character;
                    character++;
                    was_operator = true;
                }

                Operate(Operands, OperandCount, New_Operands, &new_Operandcount, Operators);

                memset(Operands, 0, sizeof(Operands));
                memset(Operators, '\0', sizeof(Operators));
                OperandCount = 0;

            } else if (*character == '=') {
                printf("Value of expression: %d\n", New_Operands[0]);
            }
            else {
                printf("Invalid input\n");
                exit(EXIT_FAILURE);
            }

            if (was_operator) {
                character--;
            }
        }
    }
}