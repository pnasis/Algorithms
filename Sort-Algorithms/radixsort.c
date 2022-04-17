/*
Name: radixsort
Eisodos: Pinakas T me n arithmous typou int pou o kathenas apoteleitai apo d psifia
Apotelesma: O pinakas T taxinomimenos
Perigrafi: O algorithmos xrisimopoiei allon algorithmo taxinomisis (countsort) gia tin taxinomisi
  twn arithmwn ws pros to teleytaio psifio, meta ws pros to proteleytaio psifio kok
*/

#include <stdio.h>
#define N 7 /* Diastasi toy pinaka*/
#define D 3 /* Plithos psifiwn kathe arithmou */

/*Dilwsi synartisewn*/
void radixsort(int T[], int n, int d);
void countsort(int S[], int n, int m, int T[], int theseis[]);
long int power10(int n);

main(){
    int i;
    int T[]={328,467,667,838,446,721,356}; /* O pinakas me ta dedomena */
    /* Ektypwsi arxikou pinaka*/
    printf("\nArxikos pinakas:");
    for(i=0;i<N;i++)
        printf(" %d",T[i]);
    /* taxinomisi stoixeiwn */
    radixsort(T,N,D);
    /* Ektypwsi arxikou pinaka*/
    printf("\n\nTelikos pinakas:");
    for(i=0;i<N;i++)
        printf(" %d",T[i]);
}

/* Synartisi radixsort */
void radixsort(int T[], int n, int d){
    int i,j;
    int x[N], x1[N], theseis[N], T1[N];
    /* Epanalipsi gia ola ta psifia twn arithmwn */
    for(i=1;i<=D;i++){
        /* Antigrafi toy pinaka T ston T1 */
        for(j=0;j<n;j++)
            T1[j]=T[j];
        /* Pairnoume ena-ena ta psifia twn arithmwn apo dexia pros ta aristera
        kai ta topothetoume ston pinaka x*/
        for(j=0;j<n;j++)
            x[j]=(T[j]%power10(i))/power10(i-1)+1;
        /* Kaloume tin countsort gia tin taxinomisi ws pros to kathe psifio
        To apotelesma paei ston pinaka x1 */
        countsort(x,n,10,x1,theseis);
        /* Anadiatasoume ta stoixeia tou pinaka T me basi tin taxinomisi poy mas edwse
        o countsort. Xrisimopoioyme ton pinaka theseis pou epistrefei i countsort */
        for(j=0;j<n;j++)
            T[j]=T1[theseis[j]];
    }
    printf("\n");
    system("pause");
}

/* Synartisi taxinomisis countsort */
void countsort(int S[], int n, int m, int T[], int theseis[]){
    int i,j;
    int C[10]; /* pinakas athroistikwn syxnotitwn*/
    /* Midenismos pinaka syxnotitwn C*/
    for(i=0;i<m;i++)
        C[i]=0;
    /* Midenismos T*/
    for(i=0;i<n;i++)
        T[i]=0;
    for(i=0;i<n;i++)
        C[S[i]-1]=C[S[i]-1]+1;
    for(i=1;i<m;i++)
        C[i]=C[i]+C[i-1];
    for(i=n-1;i>=0;i--){
        T[C[S[i]-1]-1]=S[i];
        theseis[C[S[i]-1]-1]=i;
        C[S[i]-1]=C[S[i]-1]-1;
    }
}

/*Synartisi pou ypologizei gia enan akeraio n ti dynami 10^n*/
long int power10(int n){
    int i;
    long int p=1;
    for(i=0;i<n;i++)
        p=p*10;
    return p;
}
