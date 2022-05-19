#include<new>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include"head.h"



int main (int argc, char **argv){

    int size;
    int res;
    int formula;
    double eps;
    char file[50];
    double value;

    clock_t start, stop;



    if(argc< 5 || argc>6){

        printf("\nWrong parameters\n\n");
        return 1;

    }

    sscanf(argv[1], "%d", &size);
    printf("\nThe size of the matrix: %d\n\n", size);


    sscanf(argv[2], "%d", &res);

    if(res > size){

        printf("Wrong parameters\n");

        return 1;

    }

    double* M = 0;

    double* Mc = 0;

    try {

    M = new double[size*size];

    Mc = new double[size*size];

    } catch (std::bad_alloc &e) {

        printf("Can't allocate memory");
        return 2;


    }

    sscanf(argv[3], "%lf", &eps);

    sscanf(argv[4], "%d", &formula);

    if(formula < 0 || formula > 4){

        printf("Wrong formula\n\n");
        delete[] M;

        return 3;
    }

    if(formula != 0){

        printf("You chose formula №%d\n\n", formula);

        input(size, formula, M);
    }

    else{

        if(argc < 6) {

            printf("Please, enter the file\n");
            delete[] M;
            return 4;

        }

        sscanf(argv[5], "%s", file);

        printf("From the file: %s\n\n", file);

        if (text(size, file, M) != 0) {

            delete[] M;

            return 5;
        }

    }

    if(formula == 0){

        printf("Enter k:\n");
        scanf("%d", &formula);

        if(formula<0 || formula>size){

            printf("Wrong k. Enter k from 1 to %d\n:", size);
            scanf("%d", &formula);
        }



    }

    printf("The matrix A is:\n");

    print(res, size, 1, M);

    start = clock();

    if (solution(size, formula, M, Mc, &value, eps) !=0){

        delete[] M;
        delete[] Mc;

        printf("Something went wrong");

        return 5;
    }

    stop = clock();


    printf("The %d-eigenvalue is: %10.3e\n", formula, value);

    printf("Time required: %lf seconds\n", ((double)(stop-start))/CLOCKS_PER_SEC);



    /*if(formula == 0)
        text(size, file, M);

    if(formula != 0)
        input(size, formula, M);


    for(int i=0; i<size; i++)
        Xn[i] = 0;


    norma(size, M, V, X, Xn, &N);

    printf("Norma: %10.3e\n", N);



    for(int i=0; i<size; i++)
        Xn[i] = 0;


    accuracy(size, X, Xn, &P);

    printf("Accuracy: %10.3e\n", P); */


    delete[] M;
    delete[] Mc;

    return 0;
}
