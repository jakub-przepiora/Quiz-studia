
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

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

    FILE *plik = fopen("pytania.txt", "r");

    // GET QUESTION
    int znak = 0;
    int i = 0;
    while (znak != '\n')
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
    int j = 0;
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
    fclose(plik);
}


void showQuiz() {
    createListQuestion(); // Create list
}

int main() {
    showQuiz();

    return 0;
}