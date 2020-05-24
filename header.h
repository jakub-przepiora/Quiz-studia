#ifndef HEADERS_H
#define HEADERS_H
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

void createListQuestion(char *filename, char *name, int question);
void saveStats(int allPoints, char user[32]);
void checkAnsw(char *nickname, int *ans, int *goodAns);


#endif