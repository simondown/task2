#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include"head.h"
#define eps 1e-15

void simplify(int size, double *M){

    double x, y;
    double norma;
    double cos, sin;
    double temp1, temp2;

    for(int i=0; i<size-2; i++){

        for(int j=i+2; j<size; j++){

            x = M[(i+1)*size+i];
            y = M[j*size+i];
            norma = sqrtf(x*x + y*y);

           // printf("norma is %f\n", norma);

            if(fabs(norma) < eps) continue;

            cos = x/norma;
            sin = -y/norma;

            for(int k=0; k<size; k++){

                temp1 = M[(i+1)*size+k];
                temp2 = M[j*size+k];
                M[(i+1)*size+k] = cos*temp1 - sin*temp2;
                M[j*size+k] = cos*temp2 + sin*temp1;

            }

            for(int k=0; k<size; k++){

                temp1 = M[k*size+(i+1)];
                temp2 = M[k*size+j];
                M[k*size+(i+1)] = cos*temp1 - sin*temp2;
                M[k*size+j] = cos*temp2 + sin*temp1;

            }

        }

    }

}
