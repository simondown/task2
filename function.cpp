#include<stdio.h>
#include<stdlib.h>
#include<math.h>

double function(int formula, int size, int i, int j) {

                switch (formula){


                    case 1:

                        return (size - std::max(i,j) + 1);


                    case 2:

                        if(i==j) return 2;

                        else if(abs(i-j)==1) return 1;

                        return 0;


                    case 3:

                        if((i==j) && (i<size)) return 1;

                        else if(j==size) return i;

                        else if(i==size) return j;

                        return 0;


                    case 4:

                        return (1/((double)i + j - 1));

                }

    return 0;

}

void input (int size, int formula, double* M){

    for(int i=1; i<=size; i++){

        for(int j=1; j<= size; j++){

            M[(i-1)*size + (j-1)] = function(formula, size, i, j);
        }
    }

}
