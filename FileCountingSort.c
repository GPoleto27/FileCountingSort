//
// Created by poleto on 20/06/18.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FileCountingSort.h"

void FileCountingSort(FILE *fp)
{
    int maior, linha, num;
    char *str = malloc(8);
    register int i, j;

    FILE *dist = fopen("dist.txt", "w");
    FILE *ord;

    maior = maiorNoArquivo(fp);

    zerarArquivo(dist, maior);

    fclose(dist);

    while (!feof(fp))
    {
        fgets(str, 8, fp);
        linha = atoi(str);
        incrementaLinha(linha, dist);
    }

    fclose(fp);

    dist = fopen("dist.txt", "r");
    ord = fopen("ord.txt", "w");

    for (i = 0; i <= maior; i++)
    {
        fgets(str,8,dist);
        num = atoi(str);
        for (j = 0; j < num; j++)
        {
            fprintf(ord, "%d\n", i);
        }
    }

    fclose(dist);
    fclose(ord);
    remove("dist.txt");
    remove("pre.txt");
    remove("pos.txt");
}

int maiorNoArquivo(FILE *fp)
{
    int maior = 0;
    int aux;
    char *buffer = malloc(MAX * sizeof(char));
    while (!feof(fp))
    {
        if (fgets(buffer, MAX, fp))
        {
            aux = atoi(buffer);
            if (aux > maior)
                maior = aux;
        }
    }
    rewind(fp);
    return maior;
}

void zerarArquivo(FILE *dist, int maior)
{
    register int i;
    for (i = 0; i <= maior; i++)
    {
        fputs("0\n", dist);
    }
}

void incrementaLinha(int linha, FILE *fp)
{
    int num;
    register int i;
    char ch, *str = malloc(8);
    FILE *pre, *pos;

    pre = fopen("pre.txt", "w");
    fp = fopen("dist.txt", "r+");

    if (fp == NULL)
        return;

    for (i = 0; i < linha; i++)
    {
        while((ch = fgetc(fp)) != EOF)
        {
            fputc(ch, pre);
            if(ch=='\n') break;
        }
    }

    fclose(pre);

    fgets(str, 8, fp);
    num = atoi(str);
    num++;
    sprintf(str, "%d", num);
    strcat(str, "\n");

    pos = fopen("pos.txt", "w");

    while((ch = fgetc(fp)) != EOF)
    {
        fputc(ch, pos);
    }

    fclose(pos);
    fclose(fp);

    fp = fopen("dist.txt", "w");
    pre = fopen("pre.txt", "r");

    while((ch = fgetc(pre)) != EOF)
    {
        fputc(ch, fp);
    }

    fclose(pre);
    fputs(str, fp);

    pos = fopen("pos.txt", "r");

    while((ch = fgetc(pos)) != EOF)
    {
        fputc(ch, fp);
    }

    fclose(pos);
    fclose(fp);
}
