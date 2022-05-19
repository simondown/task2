#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include"head.h"

int solution (int size, int formula, double* M, double* Mc, double* value, double eps){

    simplify(size, M);

   // printf("Now the matrix A is:\n");
   // print(4, size, 1, M);


    double b = norma(size, M);

    //printf("b = norma = %10.3e  ", b);

    double a = -b*1.1;

    //printf("a = %10.3e  ", a);

    double c = 0;

    double len = 2*b;

    //printf("len = %10.3e\n",len);

   /* c = (a + b)/2;

    printf("c = %10.3e\n", c);

    copy(size, M, Mc);

    printf("1Mc[n n]= %10.3e  ", Mc[(size-1)*size + (size-1)]);

    for(int i=0; i<size; i++){

        Mc[i*size + i] -= c;

    }

    printf("2Mc[n n]= %10.3e\n", Mc[(size-1)*size + (size-1)]);

    print(4, size, 1, Mc);

    printf("Num = %d \n", number(size, Mc, c));

*/

    while(len>eps){

        c = (a + b)/2;

        copy(size, M, Mc);

        if(number(size, Mc, c) < formula)

            a = c;

        else

            b = c;

        len /= 2;

    }

    *value = (a + b)/2;


    return 0;
}
