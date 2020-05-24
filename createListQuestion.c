#include "header.h"

void createListQuestion(char *filename, char *name, int question){
    int znak = 0, i = 0, j = 0, odpowiedzi[100], goodAnsw[100], p = 0, random = 0, questionShowed = 0; // INTIGER HELP VAARIABLE
    char titleQ[50], firstAns[50], secondAns[50], thirdAns[50], fourthAns[50];                       // TMP VARIABLE
    FILE *plik = fopen(filename, "r");                                                               // File open
    if (plik == NULL){
        perror("Error opening file.");
        return;
    } 
    while (questionShowed != question && fscanf(plik, "%d", &znak) != EOF){ // go to END OF FILE
        // for(int k = 0; k < question; k++){
        random = rand();
        znak = 0; //clear cache start read question
        i = 0;    //clear cache start read question
        while (znak != 10) { // GET QUESTION
            znak = getc(plik);
            titleQ[i] = znak;
            if (random % 2 == 0)
                printf("%c", znak);
            i++;
        }
        znak = 0;
        if (random % 2 == 0)
            printf("Good Answer: "); // user for test
        znak = getc(plik);
        if (random % 2 == 0)
            goodAnsw[p] = znak - 48; // GOOD ANSWER GET
        if (random % 2 == 0)
            printf("%i ", goodAnsw[p]); // user for test
        // ALL ANSWER GET
        znak = getc(plik); //Clear end line
        if (random % 2 == 0)
            printf("%c", znak);
        if (random % 2 == 0)
            printf("1) "); //// First ////
        znak = 0;
        while (znak != '\n')
        {
            znak = getc(plik);
            firstAns[j] = znak;
            if (random % 2 == 0)
                printf("%c", znak);
            j++;
        }
        if (random % 2 == 0)
            printf("2) "); //// Second ////
        j = 0;
        znak = 0;
        while (znak != '\n')
        {
            znak = getc(plik);
            secondAns[j] = znak;
            if (random % 2 == 0)
                printf("%c", znak);
            j++;
        }
        if (random % 2 == 0)
            printf("3) "); //// Third ////
        j = 0;
        znak = 0;
        while (znak != '\n')
        {
            znak = getc(plik);
            thirdAns[j] = znak;
            if (random % 2 == 0)
                printf("%c", znak);
            j++;
        }
        if (random % 2 == 0)
            printf("4) "); //// Fourth ////
        j = 0;
        znak = 0;
        while (znak != '\n')
        {
            znak = getc(plik);
            fourthAns[j] = znak;
            if (random % 2 == 0)
                printf("%c", znak);
            j++;
        }
        if (random % 2 == 0)
            printf("Podaj Twoja odpowiedz: ");
        int odpTMP;
        int wh = 0;
        if (random % 2 == 0)
            scanf("%i", &odpTMP);
        if (random % 2 == 0)
            while (wh != 1)
            {
                if (odpTMP > 0 && odpTMP < 5)
                {
                    odpowiedzi[p] = odpTMP;
                    p++;
                    wh = 1;
                }
                else
                {
                    printf("Error answear\n Choose other answear:");
                    scanf("%i", &odpTMP);
                }
            }
        if (random % 2 == 0)
            questionShowed++;
    }
    fclose(plik);
    checkAnsw(name, goodAnsw, odpowiedzi, question);
}
