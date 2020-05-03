
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// struct DaneQuiz {
//     char titleQuestion[50];
//     int  goodAnswer;
//     char firstAnswer[50];
//     char secondAnswer[50];
//     char thirdAnswer[50];
//     char fourthAnswer[50];
//     int  point;
//     struct DaneQuiz * next;
// } DaneQuiz;


void showQuiz() {
    char question[100];
    char goodAns[2];
    FILE *plik = fopen("pytania.txt", "r");

    int znak = 0;
    int i = 0;

    do
    {
        printf("%c", znak);
        znak = getc(plik);
        question[i] = znak;
        i++;
    } while (znak != '\n');
    // printf("\n\n%s", question);
    int j = 0;
    do{
        printf("%d", znak);
        znak = getc(plik);
        goodAns[j] = znak;
        j++;
    } while (znak != '\n');

    fclose(plik);

}

int main() {
    // struct DaneQuiz DaneDoQuizu;
    showQuiz();

    return 0;
}