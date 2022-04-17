/*
INPUT: An array T with N elements and a the number we want to find.
OUTPUT: The index that the element has been found and a found value.
DESCRIPTION: The algorithm checks every index of the array and checks if the number a exists.
*/

#include <stdio.h>

void linsearch(double T[], int n, double a, int *found, int *index);

main(){
    double T[100];
    double a;
    int i,N;
    int found; /*If found=1 the element has been found, else found=0*/
    int index; /*The index of the element we are looking for*/
    
    printf("Give the size of T:");
    scanf("%d",&N);
    
    for(i=0;i<N;i++){
       printf("Give the %d number:",i);
       scanf("%lf",&T[i]);
       }   
       
    printf("Give the desirable number:");
    scanf("%lf",&a);
    
    /*We call the linsearch Function*/
    linsearch(T,N,a,&found,&index);

    /*Results*/
    if(found==1) 
         printf("The element %f has been found at the %d index of the array\n",a,index+1);
    else 
         printf("The element %f not found\n",a);
    system("pause");
}

/* Linear Search Function*/
void linsearch(double T[], int n, double a, int *found, int *index){
    int k;
    *found=0;
    *index=0;
    k=0;
    while(k<n && *found==0){
        if(T[k]==a){ /*We check if the element is equals with the k index's value*/
            *found=1;
            *index=k;
        }
        k++;
    }
}
