#include "header.h"



int main(int argc, char **argv) {

    char base[20], nick[32];
    char howMany[5];
    int que;
    for (int i = 1; i < argc; i++){
        // printf("%s\n", argv[i]);
        if (strcmp(argv[i], "-o") == 0){
            strncpy(base, argv[i + 1], 20);
        }
        else if (strcmp(argv[i], "-n") == 0){
            strncpy(nick, argv[i + 1], 32);
        }
        else if (strcmp(argv[i], "-q") == 0){
            strcpy(howMany, argv[i+1]);
            que = atoi(howMany); 
        }
    }
    createListQuestion(base, nick, que);

    return 0;
}