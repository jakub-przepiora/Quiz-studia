#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

void saveStats(int allPoints, char user[32]) {
    time_t rawtime;
    struct tm *timeinfo;
    time(&rawtime);
    timeinfo = localtime(&rawtime);
    FILE * statsFile = fopen("stats.txt", "a");
    if (statsFile== NULL) {
        perror("Error opening file.");
    }
    else{
        fprintf(statsFile, "%s: %d | %s\n", user, allPoints, asctime(timeinfo));
        fclose(statsFile);
    }
    return;
}

void checkAnsw(char *nickname,int *ans, int *goodAns) {
    int points = 0;
    for (int i = 0; i < 10; i++) {
        if (goodAns[i] == ans[i]){
            points++;
        }
    }
    printf("goodans: %d \n", points);
    
    saveStats(points, nickname);
    
    
}
void createListQuestion(char *filename, char *name, int question){
    int znak = 0, i = 0, j = 0, odpowiedzi[10], goodAnsw[10], p = 0, random = 0, questionShowed = 0;           // INTIGER HELP VAARIABLE
    char titleQ[50], firstAns[50], secondAns[50], thirdAns[50], fourthAns[50]; // TMP VARIABLE
    FILE *plik = fopen(filename, "r");         // File open
    while (questionShowed != question && fscanf(plik, "%d", &znak) != EOF){ // go to END OF FILE
        // for(int k = 0; k < question; k++){
        random = rand();
        znak = 0; //clear cache start read question
        i = 0;    //clear cache start read question
        while (znak != 10){ // GET QUESTION
            znak = getc(plik);
            titleQ[i] = znak;
            if(random%2 == 0) printf("%c", znak);
            i++;
        }
        znak = 0;
        if(random%2 == 0) printf("Good Answer: "); // user for test
        znak = getc(plik);
        if(random%2 == 0) goodAnsw[p] = znak - 48;    // GOOD ANSWER GET
        if(random%2 == 0) printf("%i ", goodAnsw[p]); // user for test
        // ALL ANSWER GET
        znak = getc(plik); //Clear end line
        if(random%2 == 0) printf("%c", znak);
        if(random%2 == 0) printf("1) "); //// First ////
        znak = 0;
        while (znak != '\n'){
            znak = getc(plik);
            firstAns[j] = znak;
            if(random%2 == 0) printf("%c", znak);
            j++;
        }
        if(random%2 == 0) printf("2) "); //// Second ////
        j = 0;
        znak = 0;
        while (znak != '\n'){
            znak = getc(plik);
            secondAns[j] = znak;
            if(random%2 == 0)printf("%c", znak);
            j++;
        }
        if(random%2 == 0) printf("3) "); //// Third ////
        j = 0;
        znak = 0;
        while (znak != '\n'){
            znak = getc(plik);
            thirdAns[j] = znak;
            if(random%2 == 0) printf("%c", znak);
            j++;
        }
        if(random%2 == 0) printf("4) "); //// Fourth ////
        j = 0;
        znak = 0;
        while (znak != '\n'){
            znak = getc(plik);
            fourthAns[j] = znak;
            if(random%2 == 0) printf("%c", znak);
            j++;
        }
        if(random%2 == 0) printf("Podaj Twoja odpowiedz: ");
        int odpTMP;
        int wh = 0;
        if(random%2 == 0) scanf("%i",&odpTMP);
        if(random%2 == 0) while ( wh != 1){
            if(odpTMP > 0 && odpTMP < 5) {
                odpowiedzi[p] = odpTMP;
                p++;
                wh = 1;
            } else {
                printf("Error answear\n Choose other answear:");
                scanf("%i", &odpTMP);
            }
        }
        if(random%2 == 0) questionShowed++;
    }
    fclose(plik);
    checkAnsw(name,goodAnsw, odpowiedzi);
}

int main(int argc, char **argv) {

    char base[20], nick[32];
    char howMany[5];
    int que;
    for (int i = 1; i < argc; i++){
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
            strcpy(howMany, argv[i+1]);
            que = atoi(howMany);
        }
    }

    // printf("%s\n", base);
    // printf("%s\n", nick);
    // printf("%i\n", que);

    createListQuestion(base, nick, que);

    return 0;
}