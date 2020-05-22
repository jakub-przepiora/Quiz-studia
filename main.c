#include <stdlib.h>
#include <stdio.h>
#include <string.h>
// #include <cstdio.h>

// struct DaneQuiz {
//     int id;
//     char titleQuestion[50];
//     int  goodAnswer;
//     char firstAnswer[50];
//     char secondAnswer[50];
//     char thirdAnswer[50];
//     char fourthAnswer[50];
//     int  point;
//     struct DaneQuiz * next;
// } DaneQuiz;
// typedef struct DaneQuiz *daneQuiz;

// struct DaneQuiz *AddDaneQuiz(daneQuiz head, int idQuest, char *title, int goodAns, char *first, char *second, char *third, char *fourth)
// {
//     struct DaneQuiz *dane;
//     dane = (struct DaneQuiz *)malloc(sizeof(struct DaneQuiz));
//     dane->id = idQuest;
//     strcpy(dane->titleQuestion, title);  /*set Question*/
//     dane->goodAnswer = goodAns;          /*set good Answer*/
//     strcpy(dane->firstAnswer, first);    /*set First Answer*/
//     strcpy(dane->secondAnswer, second);  /*set Second Answer*/
//     strcpy(dane->thirdAnswer, third);    /*set Third Answer*/
//     strcpy(dane->fourthAnswer, fourth);  /*set Fourth Answer*/
//     dane->point = 0;                     /*set default */
//     dane->next = NULL;                   /*set next, point to NULL*/
//     if(head != NULL) {
//         head = dane;
//         printf("first elemmenet");
//     }
//     else {
//         while (head->next != NULL) {
//             if (head->next == NULL){
//                 head->next = dane;
//             }
//             head = head->next;
//         }
//     }
//     free(dane);
    
// }

// void showQuestionList(){
//     printf("Dynamic list: \n");
//     while (head != NULL) {
//         if (head != NULL) {
//             printf("%i" ,head->id);
//         }
//         head = head->next;
//     }
//     return;
// }
void saveStats(int allPoints, char user[32]) {
    FILE * statsFile = fopen("stats.txt", "a");
    if (pFile == NULL) {
        perror("Error opening file.");
    }
    else{
        while (!feof(pFile)){
            if (fgets(buffer, 100, pFile) != NULL){
                
            }
        }

        fclose(statsFile);
    }

void checkAnsw(int ans, int goodAns) {
    int points = 0;
    char nickname[32];
    for (int i = 0; i < 10; i++) {
        if (goodAns == ans){
            points++;
        }
    }

    printf("\nYour nickname: ");
    scanf(nickname);
    
    
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
        // znak = getc(plik); //Clear end line
        // printf("%c\n", znak);

        // AddDaneQuiz( idQ, titleQ, goodAns, firstAns, secondAns, thirdAns, fourthAns);
        // idQ++;
    }

    fclose(plik);
    checkAnsw(goodAnsw, odpowiedzi);
}

void showQuiz()
{
    createListQuestion(); // Create list
}

int main() {
    // struct DaneQuiz head;
    showQuiz();
    // showQuestionList();
    
    return 0;
}