//
// Created by poleto on 20/06/18.
//

#ifndef FILECOUNTINGSORT_FILECOUNTINGSORT_H
#define FILECOUNTINGSORT_FILECOUNTINGSORT_H
#define MAX 7

int maiorNoArquivo(FILE *);
void zerarArquivo(FILE*, int);
void incrementaLinha(int, FILE*);
void FileCountingSort(FILE *);

#endif //FILECOUNTINGSORT_FILECOUNTINGSORT_H
