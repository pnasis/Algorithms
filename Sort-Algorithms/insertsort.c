/*
Όνομα: insertsort
Είσοδος: Ο μη ταξινομημένος πίνακας T (τύπου double) και το πλήθος των στοιχείων Ν 
         (τύπου int) του Τ.
Έξοδος: Ο πίνακας T ταξινομημένος
Perigrafi: Ο αλγόριθμος insertsort καλεί σε κάθε επανάληψη τη συνάρτηση
           insert ώστε να τοποθετείται το κάθε στοιχείο στη σωστή θέση στον Τ.
*/

#include <stdio.h>
#define N 10 /* Πλήθος στοιχείων του πίνακα */

/* Δήλωση συναρτήσεων */
void insert(double T[], int n, double a);
void insertsort(double T[], int n);

main(){
    int i;
    double T[]={1,7,3,6,5,10,9,2,4,5}; /* Ο πίνακας με τα δεδομένα */
    /* Εκτύπωση αρχικού πίνακα */
    printf("Arxikos pinakas:");
    for(i=0;i<N;i++)
        printf(" %f",T[i]);
    /* Κλήση insertsort*/
    insertsort(T,N);
    /* Εκτύπωση ταξινομημένου πίνακα */
    printf("\nTaxinomimenos pinakas:");
    for(i=0;i<N;i++)
        printf(" %f",T[i]);
    printf("\n");
    system("pause");
}

/* Συνάρτηση που ταξινομεί έναν πίνακα με n στοιχεία */
void insertsort(double T[], int n){
    int i;
    for(i=0;i<n;i++)
        insert(T,i,T[i]);
}

/* Εισαγωγή στοιχείου a στον πίνακα Τ */
void insert(double T[], int n, double a){
    int i;
    double temp; /* προσωρινή μεταβλητή */

    /* Τοποθέτηση του a στο τέλος του πίνακα */
    T[n]=a;
    i=n;
    /* Εναλλαγή στοιχείων του πίνακα */
    while(i>0 && T[i-1]>T[i]){
        temp=T[i-1];
        T[i-1]=T[i];
        T[i]=temp;
        i--;
    }

}

