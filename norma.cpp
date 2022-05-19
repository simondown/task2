#include<stdio.h>
#include<stdlib.h>
#include<math.h>

double norma(int size, double* M){

    double norm = 0;
    double temp = 0;


    for(int i=0; i<size; i++){

        for(int j=0; j<size; j++){

            temp += fabs(M[i*size + j]);
          //  printf("Element sum №%d is %10.3e  ", j, temp);

        }

      //  printf("Sum №%d is %10.3e\n", i, temp);

        if(temp > norm)

            norm = temp;

        temp = 0;

    }

  //  printf("Norma M = %10.3e\n", norm);

    return norm;

}
