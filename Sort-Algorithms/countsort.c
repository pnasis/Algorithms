/*
Όνομα: countsort
Είσοδος: Ο πίνακας S με Ν αριθμούς (τύπου int) προς ταξινόμηση. Οι τιμές κυμαίνονται
         μεταξύ 1 και m.
Έξοδος: Ο πίνακας Τ που περιέχει τους αριθμούς ταξινομημένους και ο πίνακας theseis.
Περιγραφή: Ο αλγόριθμος εφαρμόζεται όταν έχουμε τιμές από 1 ως m και μετράει πόσες
           φορές επαναλαμβάνεται η κάθε τιμή ώστε να μπορεί να ταξινομηθεί ο πίνακας.
*/

#include <stdio.h>

/*Δήλωση συνάρτησης*/
void countsort(int S[], int n, int m, int T[], int theseis[]);

main(){
    int i,N,m;
    int S[100]; /* Ο πίνακας με τα δεδομένα */
    int T[100], theseis[100];
    
    printf("Dose th diastash toy T:");
    scanf("%d",&N);
    
    for(i=0;i<N;i++){
    	printf("Dose ton %d ari8mo:",i);
        scanf("%d",&S[i]);
    }   
      /* Εκτύπωση αρχικού πίνακα*/
    printf("\nArxikos pinakas:");
    for(i=0;i<N;i++)
        printf(" %d",S[i]);
    /* Eyresi m */
    m=S[0];
	for (i=0;i<N;i++){
    	if (S[i]>m)
    		m=S[i];    	
    }
	/* taxinomisi stoixeiwn */
    countsort(S,N,m,T,theseis);
    /* Εκτύπωση τελικού πίνακα*/
    printf("\n\nTelikos pinakas:");
    for(i=0;i<N;i++)
        printf(" %d",T[i]);
    
    printf("\nS=");
    for(i=0;i<N;i++) printf("%d ",S[i]);
    printf("\nTheseis=");
    for(i=0;i<N;i++) printf("%d ",theseis[i]);
    
    printf("\n");
    system("pause");
}

/* Συνάρτηση countsort */
void countsort(int S[], int n, int m, int T[], int theseis[]){
    int i,j;
    int C[m]; /* Πίνακας αθροιστικών συχνοτήτων*/
    /* Μηδενισμός πίνακα συχνοτήτων C*/
    for(i=0;i<m;i++)
        C[i]=0;
    /* Μηδενισμός πίνακα Τ*/
    for(i=0;i<n;i++)
        T[i]=0;
    for(i=0;i<n;i++)
        C[S[i]-1]=C[S[i]-1]+1;
    for(i=1;i<m;i++)
        C[i]=C[i]+C[i-1];
    for(i=n-1;i>=0;i--){
        T[C[S[i]-1]-1]=S[i];
        printf("\nT=");
        for(j=0;j<n;j++) printf("%d ",T[j]);
        theseis[C[S[i]-1]-1]=i+1;
        C[S[i]-1]=C[S[i]-1]-1;
        printf("  C=");
        for(j=0;j<m;j++) printf("%d ",C[j]);
    }
}
