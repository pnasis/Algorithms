/*
DESCRIPTION: The algorithm scans the array and swaps "neighbors" that are in the wrong possision.
*/

#include <stdio.h>
#define N 9

void bubblesort(double T[], int n);

main(){
    int i;
    double T[]={10,1,15,8,9,6,3,1,7};

    /*Printing the original array*/
    printf("Original array:");
    for(i=0;i<N;i++)
        printf(" %f",T[i]);
    /*We call the bubblesort function*/
    bubblesort(T,N);
    /*Printing the sorted array*/
    printf("\nSorted array:");
    for(i=0;i<N;i++)
        printf(" %f",T[i]);
    printf("\n");
    system("pause");
}

/*Bubblesort Function*/
void bubblesort(double T[], int n){
    int i=n;
    int t=-1;
    int j;
    double temp; /*Temporary variable*/
    while (i>=1 && t!=0){
        t=0;
        for (j=0;j<i-1;j++)
            if(T[j]>T[j+1]) {
                temp=T[j];  /* We swap T[j] with T[j+1]*/
                T[j]=T[j+1];
                T[j+1]=temp;
                t++;
                }
        i--;
    }
}
