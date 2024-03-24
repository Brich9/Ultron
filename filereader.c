#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ultron.h"
#include "elfheader.h"
#define MAXSIZE 32



int main (int argc, char** argv){
    int opt;
    
    int tempA[MAXSIZE];
    char fileR[500];
    int tempV;
    for(int i = 0; i < MAXSIZE; i++){
        tempA[i] = 0;
    }
    while ((opt = getopt(argc, argv, "f: ")) != -1){
        switch (opt){
            case'f' :
                int i = 0;
                FILE *count = fopen( argv[2], "r");
                while(fgets( fileR, sizeof(int), count ) != NULL) {

                    printf("%i", tempA[i]);

                }
        }
    }
}