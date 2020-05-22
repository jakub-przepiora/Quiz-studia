#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void saveStats(int allPoints, char user[32]) {
    FILE * statsFile = fopen("stats.txt", "a");
    if (statsFile== NULL) {
        perror("Error opening file.");
    }
    else{
        fprintf(statsFile, "%s: %d", user, allPoints);
        fclose(statsFile);
    }
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
void createListQuestion()
{
    // struct DaneQuiz daneDoQuizu;
    int znak = 0;
    int i = 0;
    int j = 0;
    int odpowiedzi[10];
    int goodAnsw[10];
    int p = 0;
    // TMP VARIABLE //
    int idQ = 1;
    char titleQ[50];
    int goodAns;
    char firstAns[50];
    char secondAns[50];
    char thirdAns[50];
    char fourthAns[50];

    FILE *plik = fopen("pytania.txt", "r");
    // go to END OF FILE
    while (fscanf(plik, "%d" ,&znak) != EOF) {
        
        // GET QUESTION
        znak = 0;
        i = 0;
        printf("\n");
        while (znak != 10)
        {

            znak = getc(plik);
            titleQ[i] = znak;
            printf("%c", znak);
            i++;
        }

        // GOOD ANSWER GET

        znak = 0;

        printf("Good Answer: ");
        znak = getc(plik);
        // if(!znak > 47 && !znak < 53) return;
        goodAnsw[p] = znak - 48;
        printf("%i ", goodAnsw[p]);

    
        // ALL ANSWER GET
        znak = getc(plik); //Clear end line
        printf("%c", znak);
        //// First ////

        printf("1) ");
        
        znak = 0;
        while (znak != '\n')
        {

            znak = getc(plik);
            firstAns[j] = znak;
            printf("%c", znak);
            j++;
        }

        //// Second ////
        printf("2) ");
        j = 0;
        znak = 0;
        while (znak != '\n')
        {

            znak = getc(plik);
            secondAns[j] = znak;
            printf("%c", znak);
            j++;
        }

        //// Third ////
        printf("3) ");
        j = 0;
        znak = 0;
        while (znak != '\n')
        {

            znak = getc(plik);
            thirdAns[j] = znak;
            printf("%c", znak);
            j++;
            // daneQuiz head;
        }
        //// Fourth ////
        printf("4) ");
        j = 0;
        znak = 0;
        while (znak != '\n')
        {
            znak = getc(plik);
            fourthAns[j] = znak;
            printf("%c", znak);
            j++;
        }
        printf("Podaj Twoja odpowiedz: ");
        int odpTMP;
        int wh = 0;
        scanf("%i",&odpTMP);
        while ( wh != 1)
        {
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

void showQuiz()
{
    createListQuestion(); // Create list
}

int main(int argc, char **argv) {
    // struct DaneQuiz head;
    showQuiz();
    // showQuestionList();
    
    return 0;
}