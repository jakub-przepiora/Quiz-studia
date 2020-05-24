#include "header.h"



void saveStats(int allPoints, char user[32], int question)
{
    time_t rawtime;
    struct tm *timeinfo;
    time(&rawtime);
    timeinfo = localtime(&rawtime);
    FILE *statsFile = fopen("stats.csv", "a"); // File open to append
    if (statsFile == NULL){
        perror("Error opening file.");
    }
    else
    {
        fprintf(statsFile, ";%s;%d/%d;%s", user, allPoints, question, asctime(timeinfo));
        fclose(statsFile);
    }
    return;
}
void checkAnsw(char *nickname, int *ans, int *goodAns, int questions)
{
    int points = 0;
    for (int i = 0; i < questions; i++)
    {
        if (goodAns[i] == ans[i])
        {
            points++;
        }
    }
    printf("goodans: %d \n", points);

    saveStats(points, nickname, questions);
}