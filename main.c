#include <stdio.h>
#include "FileCountingSort.h"

int main()
{
    FILE *fp = fopen("PCD.txt", "r");

    FileCountingSort(fp);
    return 0;
}