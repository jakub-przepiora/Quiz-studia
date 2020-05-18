#include <stdlib.h>
#include <stdio.h>
#include <string.h>
// #include <cstdio.h>

struct DaneQuiz {
    char titleQuestion[50];
    int  goodAnswer;
    char firstAnswer[50];
    char secondAnswer[50];
    char thirdAnswer[50];
    char fourthAnswer[50];
    int  point;
    struct DaneQuiz * next;
} DaneQuiz;

void createListQuestion() {
    struct DaneQuiz daneDoQuizu;
    int znak = 0;
    int i = 0;
    int j = 0;
    FILE *plik = fopen("pytania.txt", "r");

    while (fscanf(plik, "%10i" ,znak) != EOF) // go to END OF FILE
    {
        // GET QUESTION
        znak = 0;
        i = 0;
        printf("\n");
        while (znak != 10)
        {

            znak = getc(plik);
            daneDoQuizu.titleQuestion[i] = znak;
            printf("%c", znak);
            i++;
        }

        // GOOD ANSWER GET

        znak = 0;

        printf("Good Answer: ");
        znak = getc(plik);
        // if(!znak > 47 && !znak < 53) return;
        daneDoQuizu.goodAnswer = znak - 48;
        printf("%i ", daneDoQuizu.goodAnswer);

    
        // ALL ANSWER GET
        znak = getc(plik); //Clear end line
        printf("%c", znak);
        //// First ////

        printf("1) ");
        
        znak = 0;
        while (znak != '\n')
        {

            znak = getc(plik);
            daneDoQuizu.firstAnswer[j] = znak;
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
            daneDoQuizu.secondAnswer[j] = znak;
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
            daneDoQuizu.thirdAnswer[j] = znak;
            printf("%c", znak);
            j++;
        }
        //// Fourth ////
        printf("4) ");
        j = 0;
        znak = 0;
        while (znak != '\n')
        {
            znak = getc(plik);
            daneDoQuizu.fourthAnswer[j] = znak;
            printf("%c", znak);
            j++;
        }
        printf("\n=======================\n");
        // znak = getc(plik); //Clear end line
        // printf("%c\n", znak);
    }

    fclose(plik);
}


void showQuiz() {
    createListQuestion(); // Create list
}

int main() {
    showQuiz();

    return 0;
}