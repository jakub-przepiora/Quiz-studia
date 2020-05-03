// #include <stdlib.h>
// #include <stdio.h>
// #include <string.h>


// int main() {
//     char temat[40]; 
//     char nick[40];
//     char tresc[5];
//     char odpA[5], odpB[5], odpC[5], odpD[5];
//     char poprawna[5];
//     char odpowiedz;
//     int punkty = 0;
//     int nr_linii = 1;
//     char *linia[40];
//     int nr_pytania = 0;

//     FILE * plik = fopen("pytania.txt", "r");

//     if (plik == NULL) {
//         printf("Nie udalo sie otworzyc pliku!");
//         exit(0);
//     }
//     while (fscanf(plik, "%40s", linia) != '\n') {
//         switch (nr_linii) {
//         case 1:
//             *temat = linia;
//             break;
//         case 2:
//             *nick = linia;
//             break;
//         case 3:
//             tresc[nr_pytania] = linia;
//             break;
//         case 4:
//             odpA[nr_pytania] = linia;
//             break;
//         case 5:
//             odpB[nr_pytania] = linia;
//             break;
//         case 6:
//             odpC[nr_pytania] = linia;
//             break;
//         case 7:
//             odpD[nr_pytania] = linia;
//             break;
//         case 8:
//             poprawna[nr_pytania] = linia;
//             break;
//         }

//         if (nr_linii == 8)
//         {
//             nr_linii = 2;
//             nr_pytania++;
//         }
//         nr_linii++;
//     }

//     fclose(plik);
//     char odp[1];
//     int i = 0;
//     for (i = 0; i <= 4; i++){
//         printf("\n");
//         printf("%d", tresc[i]);
//         printf("A. %d\n", odpA[i]);
//         printf("B. %d\n", odpB[i]);
//         printf("C. %d\n", odpC[i]);
//         printf("D. %d\n", odpD[i]);

//         printf("Twoja odpowiedz: ") ;
//         scanf("%s", odp);

//         if (odpowiedz == poprawna[i]) {
//             printf("Dobrze! Zdobywasz punkt!");
//             punkty++;
//         }
//         else
//             printf("Zle! Brak punktu! Poprawna odpowiedz: %d", poprawna[i]);
//     }

//     printf("Koniec quizu. Zdobyte punkty: %d",punkty);

//         return 0;
// } 0d0a
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct daneQuiz {
    char titleQuestion[50];
    int  goodAnswer;
    char firstAnswer[50];
    char secondAnswer[50];
    char thirdAnswer[50];
    char fourthAnswer[50];
    int  point;
    struct daneQuiz * next;
};
void push_back(ListElement_type **head, int number)
{

    if (*head == NULL)
    {
        *head = (ListElement_type *)malloc(sizeof(ListElement_type));
        (*head)->data = number;
        (*head)->next = NULL;
    }
    else
    {
        ListElement_type *current = *head;

        while (current->next != NULL)
        {
            current = current->next;
        }

        current->next = (ListElement_type *)malloc(sizeof(ListElement_type));
        current->next->data = number;
        current->next->next = NULL;
    }
}
void showQuiz() {
    char question[40];
    FILE *plik = fopen("pytania.txt", "r");

    int znak;

    do
    {
        printf("%c", znak);
        znak = getc(plik);

    } while (znak != '\n');

    fclose(plik);
}

int main() {
    showQuiz();

    return 0;
}