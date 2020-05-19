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
typedef struct DaneQuiz *daneQuiz;

struct DaneQuiz *AddDaneQuiz(daneQuiz head, char *title, int goodAns, char *first, char *second, char *third, char *fourth)
{
    struct DaneQuiz *dane;
    dane = (struct DaneQuiz *)malloc(sizeof(struct DaneQuiz));
    strcpy(dane->titleQuestion, title);  /*set Question*/
    dane->goodAnswer = goodAns;          /*set good Answer*/
    strcpy(dane->firstAnswer, first);    /*set First Answer*/
    strcpy(dane->secondAnswer, second);  /*set Second Answer*/
    strcpy(dane->thirdAnswer, third);    /*set Third Answer*/
    strcpy(dane->fourthAnswer, fourth);  /*set Fourth Answer*/
    dane->point = 0;                     /*set default */
    dane->next = NULL;                   /*set next, point to NULL*/
    if(!head){
        head = dane;
    }
    while (head->next){
        if (head->next == NULL){
            head->next = dane;
        }
        head = head->next;
    }
}

void showQuestionList(daneQuiz head){
    while (head){
        if (head){
            printf("1.%s\n1) %s\n2) %s\n3) %s\n4) %s\n", head->titleQuestion, head->firstAnswer, head->secondAnswer, head->thirdAnswer, head->fourthAnswer);
        }
        head = head->next;
    }
}
void createListQuestion() {
    struct DaneQuiz daneDoQuizu;
    int znak = 0;
    int i = 0;
    int j = 0;

    // TMP VARIABLE //
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
        goodAns = znak - 48;
        printf("%i ", goodAns);

    
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
        printf("\n=======================\n");
        // znak = getc(plik); //Clear end line
        // printf("%c\n", znak);

        AddDaneQuiz(titleQ, goodAns, firstAns, secondAns, thirdAns, fourthAns);
    }

    fclose(plik);
}


void showQuiz() {
    createListQuestion(); // Create list
}

int main() {
    struct DaneQuiz head;
    showQuiz();
    showQuestionList(&head);
    return 0;
}