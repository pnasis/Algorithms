/*
Όνομα: binsearch (Δυαδική αναζήτηση)
Είσοδος: Πίνακας Τ με Ν αριθμούς (τύπου double) ταξινομημένους και a ο αριθμός
         προς αναζήτηση (typou double).
Έξοδος: Η θέση index στην οποία βρέθηκε ο αριθμός (τύπου int) και μια λογική μεταβλητή found
        (τύπου int) η οποία δηλώνει αν βρέθηκε ο αριθμός a ή όχι. 
Περιγραφή: Ο αλγόριθμος ελεγχει αρχικά αν το μεσαίο στοιχείο του Τ είναι αυτό που ψάχνουμε.
           Αν δεν είναι τότε η αναζήτηση ψάχνει είτε στο αριστερό τμήμα είτε στο
           δεξιό ανάλογα με το αποτέλεσμα της σύγκρισης.
*/

#include <stdio.h>

/*Δήλωση συνάρτησης*/
void binsearch(double T[], int n, double a, int *found, int *index);

main(){
    double T[100];
    double a;
    int i,N;
    int found; /* Είναι found=1 αν το στοιχείο βρέθηκε. Αλλιώς είναι found=0*/
    int index; /* Θέση του στοιχείου που ψάχνουμε */
    
    printf("Dose th diastash toy T:");
    scanf("%d",&N);
    
    for(i=0;i<N;i++){
       printf("Dose ton %d ari8mo:",i);
       scanf("%lf",&T[i]);
       }   
       
    printf("Dwse stoixeio pou psaxnoume:");
    scanf("%lf",&a);
    
    /* Κλήση της συνάρτησης linsearch*/
    binsearch(T,N,a,&found,&index);

    /* Εκτύπωση αποτελέσματος*/
    if(found==1) 
         printf("To stoixeio %f brethike sti thesi %d tou pinaka\n",a,index+1);
    else 
         printf("To stoixeio %f den brethike ston pinaka\n",a);
    
    system("pause");
}

/* Συνάρτηση δυαδικής αναζήτησης */
void binsearch(double T[], int n, double a, int *found, int *index){
    int i=0;    /* αριστερό άκρο */
    int j=n-1;  /* δεξιό άκρο */
    int k;      /* μεσαία τιμή πίνακα */
    *found=0; /* αρχικά θεωρούμε ότι το στοιχείο δεν βρέθηκε*/
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
