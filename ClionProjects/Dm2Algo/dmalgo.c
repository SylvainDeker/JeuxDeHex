
#include "dmalgo.h"
#include <stdio.h>
#include <assert.h>
/*N > 0
 * S(deb,fin)
 * 0 <= deb <= fin <= N & 1 <= N <= NMAX
	0 <= deb <= fin <= N & 1 <= N <= NMAX */

int conjoint1(int i, int max_res, int N)
{
    int deb=0;
    int fin;
    int test=0;
    while (deb<i && i <= N)
    {
        fin=deb;
        while (fin<i)
        {
            if (S(t,deb,fin) == max_res){
                test=1;
                return test;
            }
            fin++;
        }
        deb++;
    }
    return test;
}

int conjoint2(int i, int max_res, int N)
{
    int test=0;
    int deb=0; int fin;
    while (deb<i && i <= N){
        for (fin=deb;fin<i;fin++){
            if (S(t,deb,fin) <= max_res){
                test=1;
            }
        }
        deb++;
    }
    return test;
}





int S(tab t, int d, int f)
{
    int s=0;
    for (int i=d; i<=f; i++)
        s=s+t[i];
    return s;
}



int f1(tab t, int n, int *posdeb, int *posfin){
    int p=0;
    int max_res=0;
    int c=0;

    for (int deb = 0; deb < n; deb++) {

        for (int fin = deb; fin < n; fin++) {

            p=0;
            for (int i = deb; i<=fin; i++) {
                p=p+t[i];
            }
            if (p > max_res){
                max_res=p;
                c++;
            }
            if(c==1){
                *posdeb=deb;
                *posfin=fin;
            }
        }
    }
    return max_res;
}


int f2(tab t, int n, int *posdeb, int *posfin){
    int p=0;
    int max_res=0;
    int c=0;
    *posdeb=0;
    *posfin=0;
    for (int deb = 0; deb < n; deb++) {
        p=0;

        for (int fin = deb; fin < n; fin++){
            p=p+t[fin];

            if (p > max_res){
                max_res=p;
                c++;
            }
            if(c == 1){
                *posdeb=deb;
                *posfin=fin;
            }
        }
    }
    return max_res;
}





int f3(tab t, int n, int *posdeb, int *posfin){
    tab res;
    int max_res;
    int i=0;
    res[0]=t[0];
    while(i != n){
//        INV : ∃D ∃F (0 ≤ D ≤ F < i ≤ N ∧ S(t, D, F ) = max_res)
//          ∧
//        ∀Deb ∀F in (0 ≤ Deb ≤ F in < i ≤ N → max_res ≥ S(t, Deb, F in))
//          ∧
//         (i ≤ N )
//          ∧
//         (i ≠ N)
        assert(conjoint1(i,max_res,n));
        assert(conjoint2(i,max_res,n));
        assert(i<=n);
        assert(i != n);

        if(res[i-1] > 0) {
            res[i] = res[i - 1] + t[i];
        }else{
            res[i]=t[i];
        }
        max_res=res[i];
        i++;

//        INV : ∃D ∃F (0 ≤ D ≤ F < i ≤ N ∧ S(t, D, F ) = max_res)
//          ∧
//        ∀Deb ∀F in (0 ≤ Deb ≤ Fin < i ≤ N → max_res ≥ S(t, Deb, F in))
//          ∧
//         (i ≤ N )
        assert(i <= n);
        assert(conjoint1(i,max_res,n));
        assert(conjoint2(i,max_res,n));
    }

//        INV : ∃D ∃F (0 ≤ D ≤ F < i ≤ N ∧ S(t, D, F ) = max_res)
//          ∧
//        ∀Deb ∀F in (0 ≤ Deb ≤ F in < i ≤ N → max_res ≥ S(t, Deb, F in))
//          ∧
//         (i ≤ N )
//          ∧
//          i=N
    assert(conjoint2(i,max_res,n));
    assert(conjoint2(i,max_res,n));
    assert(i = n);

    return max_res;
}
