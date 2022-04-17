/*
Όνομα: selectsort
Είσοδος: Ο πίνακας Τ με τα στοιχεία προς ταξινόμηση και η διάσταση n του Τ
Έξοδος: Ο πίνακας Τ ταξινομημένος
Perigrafi: Ο αλγόριθμος ταξινομεί τα στοιχεία ενός πίνακα Τ διάστασης n. 
   Ο αλγόριθμος σε κάθε βήμα σαρώνει τον πίνακα Τ και εναλλάσει τα γειτονικά
   στοιχεία που έχουν λάθος διάταξη.
*/

#include <stdio.h>
#define N 9 /* Διάσταση του πίνακα Τ */

/* Δήλωση συνάρτησης */
void bubblesort(double T[], int n);

main(){
    int i;
    double T[]={10,1,15,8,9,6,3,1,7}; /* Τα στοιχεία του Τ */

    /* Εκτύπωση αρχικού πίνακα */
    printf("Arxikos pinakas:");
    for(i=0;i<N;i++)
        printf(" %f",T[i]);
    /* Κλήση της bubblesort */
    bubblesort(T,N);
    /* Εκτύπωση του ταξινομημένου πίνακα */
    printf("\nTaxinomimenos pinakas:");
    for(i=0;i<N;i++)
        printf(" %f",T[i]);
    printf("\n");
    system("pause");
}

/* Ο αλγόριθμος bubblesort */
void bubblesort(double T[], int n){
    int i=n;
    int t=-1;
    int j;
    double temp; /* Προσωρινή μεταβλητή */
    while (i>=1 && t!=0){
        t=0;
        for (j=0;j<i-1;j++)
            if(T[j]>T[j+1]) {
                temp=T[j];  /* Εναλλαγή των T[j], T[j+1]*/
                T[j]=T[j+1];
                T[j+1]=temp;
                t++;
                }
        i--;
    }
}
