/*
INPUT: An array T with N numbers.
OUTPUT: The index of the number and a found value. 
DESCRIPTION: The algorithm checks first if the middle value of the array T is the value that we are looking for.
             If it's not, then it checks on the left or right part depending on how big the value was.
*/

#include <stdio.h>

void binsearch(double T[], int n, double a, int *found, int *index);

main(){
    double T[100];
    double a;
    int i,N;
    int found; /* if found=1 the element was found, else found=0*/
    int index; /*The index of the element we want*/
    
    printf("Give the size of the T:");
    scanf("%d",&N);
    
    for(i=0;i<N;i++){
       printf("Give the %d number:",i);
       scanf("%lf",&T[i]);
       }   
       
    printf("Give the desirable element:");
    scanf("%lf",&a);
    
    /* Κλήση της συνάρτησης linsearch*/
    binsearch(T,N,a,&found,&index);

    /* Εκτύπωση αποτελέσματος*/
    if(found==1) 
         printf("The element %f found on the %d index of the array\n",a,index+1);
    else 
         printf("The element %f not found\n",a);
    
    system("pause");
}

/* Binary search function*/
void binsearch(double T[], int n, double a, int *found, int *index){
    int i=0;    /* left part */
    int j=n-1;  /* right part */
    int k;      /* middle value of the array */
    *found=0;
    *index=0;
    k=0;
    while(i<=j && *found==0){
        k=(i+j)/2;
        if (T[k]==a) {
            *found=1;
            *index=k;
        }else if (a<T[k]) j=k-1;
        else i=k+1;
    }
}
