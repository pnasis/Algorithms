/*
Όνομα: 141-linsearch (Σειριακή αναζήτηση)
Είσοδος: Πίνακας Τ με Ν αριθμούς (τύπου double) και a ο αριθμός προς αναζήτηση (typou double).
Έξοδος: Η θέση index στην οποία βρέθηκε ο αριθμός (τύπου int) και μια λογική μεταβλητή found
        (τύπου int) η οποία δηλώνει αν βρέθηκε ο αριθμός a ή όχι. 
Περιγραφή: Ο αλγόριθμος εξετάζει σειριακά ένα-προς-ένα τα στοιχεία του Τ και εντοπίζει αν 
           υπάρχει το στοιχείο προς αναζήτηση a.
*/

#include <stdio.h>

/*Δήλωση συνάρτησης*/
void linsearch(double T[], int n, double a, int *found, int *index);

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
    linsearch(T,N,a,&found,&index);

    /* Εκτύπωση αποτελέσματος*/
    if(found==1) 
         printf("To stoixeio %f brethike sti thesi %d tou pinaka\n",a,index+1);
    else 
         printf("To stoixeio %f den brethike ston pinaka\n",a);
    system("pause");
}

/* Συνάρτηση σειριακής αναζήτησης */
void linsearch(double T[], int n, double a, int *found, int *index){
    int k;
    *found=0; /* Αρχικά θέτουμε ότι το στοιχείο δεν βρέθηκε */
    *index=0;
    k=0;
    while(k<n && *found==0){
        if(T[k]==a){ /*Έλεγχος αν το στοιχείο είναι ίσο με αυτό στη θέση k*/
            *found=1;
            *index=k;
        }
        k++;
    }
}
