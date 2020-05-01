#include <stdlib.h>
#include <stdio.h>
#include <string.h>





int main()
{
    char temat, nick;
    char tresc[5];
    char odpA[5], odpB[5], odpC[5], odpD[5];
    char poprawna[5];
    char odpowiedz;
    int punkty = 0;
    int nr_linii = 1;
    char linia[40];
    int nr_pytania = 0;

    FILE * plik = fopen("pytania.txt", "r");

    if (plik == NULL)
    {
        printf("Nie udalo sie otworzyc pliku!");
        exit(0);
    }

    // znak = getc(plik);
    // while (znak != EOF) //pętla odczytująca po jednym znaku z pliku
    // {
    //     printf("%c", znak); //do napotkania znaku końca pliku EOF
    //     znak = getc(plik);
    // }
    while (fscanf(plik, "%s", linia) != '\n')
    {
        switch (nr_linii)
        {
        case 1:
            temat = linia;
            break;
        case 2:
            nick = linia;
            break;
        case 3:
            tresc[nr_pytania] = linia;
            break;
        case 4:
            odpA[nr_pytania] = linia;
            break;
        case 5:
            odpB[nr_pytania] = linia;
            break;
        case 6:
            odpC[nr_pytania] = linia;
            break;
        case 7:
            odpD[nr_pytania] = linia;
            break;
        case 8:
            poprawna[nr_pytania] = linia;
            break;
        }

        if (nr_linii == 8)
        {
            nr_linii = 2;
            nr_pytania++;
        }
        nr_linii++;
    }

    fclose(plik);
    char odp[1];
    int i = 0;
    for (i = 0; i <= 4; i++){
        printf("\n");
        printf("%d", tresc[i]);
        printf("A. %d\n", odpA[i]);
        printf("B. %d\n", odpB[i]);
        printf("C. %d\n", odpC[i]);
        printf("D. %d\n", odpD[i]);

        printf("Twoja odpowiedz: ") ;
        scanf("%s", odp);

        if (odpowiedz == poprawna[i]) {
            printf("Dobrze! Zdobywasz punkt!");
            punkty++;
        }
        else
            printf("Zle! Brak punktu! Poprawna odpowiedz: %d", poprawna[i]);
    }

    printf("Koniec quizu. Zdobyte punkty: %d",punkty);

        return 0;
}