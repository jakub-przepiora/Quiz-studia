#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void saveStats(int allPoints, char user[32]) {
    FILE * statsFile = fopen("stats.txt", "a");
    if (statsFile== NULL) {
        perror("Error opening file.");
    }
    else{
        fprintf(statsFile, "%s: %d\n", user, allPoints);
        fclose(statsFile);
    }
    return;
}

void checkAnsw(int *ans, int *goodAns) {
    int points = 0;
    char nickname[32];
    for (int i = 0; i < 10; i++) {
        if (goodAns[i] == ans[i]){
            points++;
            
        }
    }
    printf("goodans: %d \n", points);
    printf("\nYour nickname: ");
    scanf("%s\n" ,nickname);
    saveStats(points, nickname);
    
    
}
void createListQuestion(){
    int znak = 0, i = 0, j = 0, odpowiedzi[10], goodAnsw[10], p = 0;           // INTIGER HELP VAARIABLE
    char titleQ[50], firstAns[50], secondAns[50], thirdAns[50], fourthAns[50]; // TMP VARIABLE 
    FILE *plik = fopen("pytania.txt", "r"); // File open
    while (fscanf(plik, "%d" ,&znak) != EOF) {     // go to END OF FILE
        znak = 0; //clear cache start read question
        i = 0;    //clear cache start read question
        printf("\n");
        while (znak != 10){ // GET QUESTION
            znak = getc(plik);
            titleQ[i] = znak;
            printf("%c", znak);
            i++;
        }
        // GOOD ANSWER GET 
        znak = 0;
        printf("Good Answer: "); // user for test
        znak = getc(plik);
        goodAnsw[p] = znak - 48;
        printf("%i ", goodAnsw[p]); // user for test
        // ALL ANSWER GET
        znak = getc(plik); //Clear end line
        printf("%c", znak);
        //// First ////
        printf("1) ");
        znak = 0;
        while (znak != '\n'){
            znak = getc(plik);
            firstAns[j] = znak;
            printf("%c", znak);
            j++;
        }
        //// Second ////
        printf("2) ");
        j = 0;
        znak = 0;
        while (znak != '\n'){
            znak = getc(plik);
            secondAns[j] = znak;
            printf("%c", znak);
            j++;
        }
        //// Third ////
        printf("3) ");
        j = 0;
        znak = 0;
        while (znak != '\n'){
            znak = getc(plik);
            thirdAns[j] = znak;
            printf("%c", znak);
            j++;
        }
        //// Fourth ////
        printf("4) ");
        j = 0;
        znak = 0;
        while (znak != '\n'){
            znak = getc(plik);
            fourthAns[j] = znak;
            printf("%c", znak);
            j++;
        }
        printf("Podaj Twoja odpowiedz: ");
        int odpTMP;
        int wh = 0;
        scanf("%i",&odpTMP);
        while ( wh != 1){
            if(odpTMP > 0 && odpTMP < 5) {
                odpowiedzi[p] = odpTMP;
                p++;
                wh = 1;
            }
            else {
                printf("Error answear\n Choose other answear:");
                scanf("%i", &odpTMP);
            }
        }
        printf("\n=======================\n");
    }
    fclose(plik);
    checkAnsw(goodAnsw, odpowiedzi);
}

int main(int argc, char **argv) {

    char base[20], nick[32];
    char howMany[5];
    int que;
    for(int i = 1; i < 7; i++){
        // printf("%s\n", argv[i]);
        if (strcmp(argv[i], "-o") == 0){
            printf("ok\n");
            strncpy(base, argv[i + 1], 20);
        }
        else if (strcmp(argv[i], "-n") == 0){
            printf("ok\n");
            strncpy(nick, argv[i + 1], 32);
        }
        else if (strcmp(argv[i], "-q") == 0){
            printf("ok\n");
            // long conv = strtol(, &tmp, 10);
            strcpy(howMany, argv[i+1]);
            que = atoi(howMany);
        }

        
    }
    
    printf("%s\n", base);
    printf("%s\n", nick);
    printf("%i\n", que);

    createListQuestion();

    return 0;
}