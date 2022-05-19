#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include"head.h"
#define epsmash 1e-15

int number(int size, double* Mc, double c){

    double x, y, a, b, g, u, v;

    int m;

    for(int i=0; i<size; i++){

        Mc[i*size + i] -= c;

    }

    //print(4, size, 1, Mc);

    coef1(size, Mc);

    x = Mc[0];
    y = 1;

    if(sign(x*y)<0)
        m = 1;

    else m = 0;


    for(int i=1; i<size; i++){

        a = Mc[i*size + i];
        b = Mc[i*size + (i-1)];

        g = coef2(x, b, y);

        u = g*(a*x - b*b*y);
        v = g*x;

        if (sign(u*x)<0)
            m++;

        x=u;
        y=v;

    }

    return m;
}


void coef1(int size, double* Mc){

    double amax = 0;
    double bmax = 0;
    double max = 0;


   // print(4, size, 1, Mc);

    for(int i=0; i<size; i++){

        if(fabs(Mc[i*size + i]) > amax)
            amax = fabs(Mc[i*size + i]);

    }

   // printf("amax = %10.3e  ", amax);

    for(int i=0; i<size-1; i++){

        if(fabs(Mc[(i+1)*size + i]) > bmax)
            bmax = fabs(Mc[(i+1)*size + i]);

    }

   // printf("bmax = %10.3e  ", bmax);

    max = amax;

    if(bmax > amax)
        max = bmax;

    for(int i=0; i<size; i++){

        for(int j=0; j<size; j++){

            Mc[i*size + j] /= 4*max;

        }

    }

   // printf("max = %10.3e \n", max);

}


double coef2(double x, double b, double y){

    double gamma = 0;

    double max = fabs(x);

    if(fabs(b*b*y)>max)
        max=fabs(b*b*y);

    gamma = (1/epsmash)/max;

    return gamma;

}

int sign(double x){

    if(x<0) return -1;

    if(x>0) return 1;

    else return 0;

}


