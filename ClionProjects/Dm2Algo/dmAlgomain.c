#include <stdio.h>
#include "dmalgo.h"
#include <time.h>
#include <stdlib.h>

int main(){
    srand(time(NULL));
    int posdeb;
    int posfin;
    int N=10000;

    clock_t debut, fin;
    for (int i = 0; i < N; ++i) {
        t[i]=rand()%21-10;
    }
    printf("N = %d\n",N);


    debut=clock();
    printf("f1  t  : %d\n",f1(t,N,&posdeb, &posfin));
    fin=clock();
    printf("temps CPU : %.2f secondes \n", (double) (fin-debut)/CLOCKS_PER_SEC);


    debut=clock();
    printf("f2  t  : %d\n",f2(t,10000, &posdeb, &posfin));
    fin=clock();
    printf("temps CPU : %.4f secondes \n", (double) (fin-debut)/CLOCKS_PER_SEC);

    debut=clock();
    printf("f3  t  : %d\n",f3(t,10000, &posdeb, &posfin));
    fin=clock();
    printf("temps CPU : %.4f secondes \n", (double) (fin-debut)/CLOCKS_PER_SEC);

    N=100000;

    debut=clock();
    printf("f2  t  : %d\n",f2(t,100000, &posdeb, &posfin));
    fin=clock();
    printf("temps CPU : %.4f secondes \n", (double) (fin-debut)/CLOCKS_PER_SEC);

    debut=clock();
    printf("f3  t  : %d\n",f3(t,100000, &posdeb, &posfin));
    fin=clock();
    printf("temps CPU : %.4f secondes \n", (double) (fin-debut)/CLOCKS_PER_SEC);

}
