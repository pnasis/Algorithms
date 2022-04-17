/*
Name: mergesort
Eisodos: Pinakes T me n stoixeia
Apotelesma: Taxinomimenos pinakas S pou periexei ta stoixeia tou T
Perigrafi: O algorithmos spaei ton pinaka T se 2 ypopinakes kai kalei
anadromika ton eayto tou. Gia ti sygxwneysi twn taxinomimenwn ypopinakwn
xrisimopoiei ti synartisi merge2.
*/

#include <stdio.h>
#define N 10 /* Diastasi pinaka*/
/*Dilwsi synartisewn*/
void mergesort(double T[],int start, int end,double S[]);
void merge2(double A[], int na, double B[], int nb,double C[]);

main(){
    /* o pinakas T*/
    double T[]={7,5,6,9,5,4,17,10,15,3};
    /* O taxinomimenos pinakas*/
    double S[N];
    int i;
    /*klisi synartisis mergesort gia olokliro ton pinaka T*/
    mergesort(T,0,N-1,S);
    /* ektypwsi taxinomimenou pinaka*/
    printf("Taxinomimenos pinakas: [ ");
    for(i=0;i<N;i++) printf("%f ",S[i]);
    printf("]\n");
    system("pause");
}

/* Synartisi mergesort*/
void mergesort(double T[],int start, int end,double S[]){
    int n,nn;
    double A[N],B[N];
    n=end-start+1; /*Diastasi pinaka*/
    /* An o pinakas exeis ena mono stoixeio tote o pinakas thewreitai taxinomimenos*/
    if (n==1)
        S[0]=T[start];
    else {
        nn=(start+end)/2; /* meso tou pinaka */
        /* Klisi mergesort gia ton aristero ypopinaka*/
        mergesort(T,start,nn,A);
        /* Klisi mergesort gia ton dexio ypopinaka*/
        mergesort(T,nn+1,end,B);
        /* Sygxwnysi twn 2 taxinomimenwn ypopinakwn se enan neo pinaka*/
        merge2(A,nn-start+1,B,end-nn,S);
    }
}

/* H synartisi pairnei san parametro 2 taxinomimenous pinakes A kai B kai tis diastaseis tous
na kai nb antistoixa. Ta stoixeia twn 2 pinakwn ta apothikeyei se enan trito pinaka C
me tetoio tropo wste na einai kai pali taxinomimena */
void merge2(double A[], int na, double B[], int nb,double C[]){
    int i=0,j=0,k=0;
    int n,m;
    while(i<na && j<nb){
        /* Sygkrinei ta stoixeia twn A kai B ena pros ena kai apothikeyei to mikrotero
        apo ta 2 ston pinaka C proxwrontas ton antistoixo deikti*/
        if(A[i]<=B[j]){
            C[k]=A[i];
            i++;
        } else {
            C[k]=B[j];
            j++;
        }
        k++;
    }
    /* Apothikeyei ston C ta teleytaia stoixeia tou pinaka poy einai megalytera apo
    ola ta stoixeia toy allou pinaka*/
    n=na+nb;
    if(i>=na)
        for(m=0;m<n-k;m++)
            C[k+m]=B[j+m];
    else
        for(m=0;m<n-k;m++)
            C[k+m]=A[i+m];
}
