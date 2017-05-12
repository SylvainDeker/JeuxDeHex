#define NMAX 100000
typedef int tab[NMAX];

tab t;

int f1(tab t, int n, int *posdeb, int *posfin);
int f2(tab t, int n, int *posdeb, int *posfin);
int f3(tab t, int n, int *posdeb, int *posfin);
int S(tab t, int d, int f);
int conjoint1(int i, int max_res, int N);
int conjoint2(int i, int max_res, int N);

