#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "ultron.h"
#define MAXSIZE 32



int main(int argc, char** argv) {
    int opt;
    Ultron ultron;
    ultron_init(&ultron);
    int tempA[MAXSIZE];
    char fileR[500];
    int tempV;
    for (int i = 0; i < MAXSIZE; i++){
        tempA[i] = 0;
    }
    int size;
    while ((opt = getopt(argc, argv, "i:f")) != -1){
        switch (opt){
            case'f' :
                int i = 0;
                FILE *count = fopen(argv[2], "r");
                while (fgets( fileR, sizeof(int) *4 , count ) != NULL) {
                    int j = atoi(fileR);
                    tempA[i] = j;
                    i++;
                }
                fclose(count);
                ultron_load(&ultron, i, tempA);
                int result = ultron_run(&ultron);
                printf("Result: %i\n", result);
                ultron_dump(&ultron);
                break;
            case'i' :
                size = atoi(argv[2]);
                for (int i = 0; i < size; i++) {
                    scanf("%i", &tempV);
                    tempA[i] = tempV;
                    ultron_load(&ultron, size, tempA);
                    ultron_run(&ultron);
                }
                ultron_dump(&ultron);
                break;
            default :
                for (int i = 0; i < 32; i++) {
                    scanf("%i", &tempV);
                    tempA[i] = tempV;
                    ultron_load(&ultron, 32, tempA);
                    ultron_run(&ultron);
                }
                ultron_dump(&ultron);
        }
    }
}
