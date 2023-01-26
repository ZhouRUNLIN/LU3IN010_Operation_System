#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tab.h"
#include <sys/time.h>
#include <sys/resource.h>

void PrintMem(){
    int ret;
    struct rusage usage;
    ret = getrusage(RUSAGE_SELF, &usage);
	if (0 != ret) {
		printf("getrusage failed\n");
	}
    else{
        printf("%s: %.3fM\n", "ru_maxrss", (usage.ru_maxrss / 1024.0));
    }
}

int main(){
    PrintMem();
    //test pour 2.1-2.3
    int tab1[NMAX];
    initTab(tab1, NMAX);
    printTab(tab1, 5);

    int* tab2 = (int*)malloc(sizeof(int)*NMAX);
    initTab(tab2, NMAX);
    printTab(tab2, 5);

    //test pour 2.5-2.6
    printf("somme de tab1 est : %d\n", sumTab(tab1, 5));
    printf("somme de tab2 est : %d\n", sumTab(tab2, 5));
    
    int min;
    minSumTab(&min, tab1, 5);
    printf("smallest number in the tab1 : %d\n", min);

    minSumTab(&min, tab2, 5);
    printf("smallest number in the tab1 : %d\n", min);

    PrintMem();
    free(tab2);
}