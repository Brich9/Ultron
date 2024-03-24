#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ultron.h"

#define MAXSIZE 32


void ultron_init(Ultron* ultron) {
    ultron->programC = 0;
    ultron ->accumC = 0;
    for (int i = 0; i < MAXSIZE; i++) {
        ultron->arr[i] = 0;
    }
}

void ultron_dump(Ultron* ultron) {
    printf("PC: %i\n", ultron->programC);
    printf("AC: %i\n", ultron->accumC);
    for (int i = 0; i < MAXSIZE; i++){
        printf("%2i %4i\n", i, ultron->arr[i]);
    }
}

int ultron_memory(Ultron* ultron, int location) {
    return ultron->arr[location];
}

int ultron_accumulator(Ultron* ultron) {
    return ultron->accumC;
}

int ultron_pc(Ultron* ultron) {
    return ultron->programC;
}

void ultron_load(Ultron* ultron, int size, int* instructions) {
    for (int i = 0; i < size; i++){
        ultron->arr[i] = instructions[i];
    }
}

int ultron_run(Ultron* ultron) {
    int flag = 0;
    int count = 32;
    if (ultron->arr[8] > 32){
        count = ultron->arr[8] * sizeof(int) * sizeof(int);
    }
    for (int i = 0; i < count; i++) {
        int instruction = ultron->arr[ultron->programC];
        int operation = ultron->arr[ultron->programC]/100;
        int operand = ultron->arr[ultron->programC] % 100;
        
        if ( instruction == sizeof(long unsigned int) ){
            printf("hi");
        }
            // if (operation == READ || operation == WRITE || operation == LOAD ||
            //     operation == STORE || operation == ADD || operation == SUBTRACT ||
            //     operation == BRANCHNEG || operation == HALT) {
            //         return -1;
            //     }
        if (operand < 0 || operand > 32) {
            return -2;
        }
        if (ultron->programC > 32 || ultron->programC < 0) {
            return -3;
        }
        switch (operation) {
            case READ:
                printf("? ");
                scanf("%d", &ultron->arr[operand]);
                ultron->programC += 1;
                break;
            case WRITE:
                printf("= %d\n", ultron->arr[operand]);
                ultron->programC += 1;
                break;
            case LOAD:
                ultron->accumC = ultron->arr[operand];
                ultron->programC += 1;
                break;
            case STORE:
                ultron->arr[operand] = ultron->accumC;
                ultron->programC += 1;
                break;
            case ADD:
                ultron->accumC += ultron->arr[operand];
                ultron->programC += 1;
                break;
            case SUBTRACT:
                ultron->accumC -= ultron->arr[operand];
                ultron->programC += 1;
                break;
            case BRANCHNEG:
                if (ultron->accumC < 0) {
                    ultron->programC = operand;
                } else {
                    ultron->programC++;
                }
                break;
            case HALT:
                return 0;
                break;
           }
           if (operation == HALT) {
                flag++;
           }
    }
    return 0;
}
