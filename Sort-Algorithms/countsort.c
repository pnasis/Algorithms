/*
�����: countsort
�������: � ������� S �� � �������� (����� int) ���� ����������. �� ����� �����������
         ������ 1 ��� m.
������: � ������� � ��� �������� ���� �������� �������������� ��� � ������� theseis.
���������: � ���������� ����������� ���� ������ ����� ��� 1 �� m ��� ������� �����
           ����� ��������������� � ���� ���� ���� �� ������ �� ����������� � �������.
*/

#include <stdio.h>

/*������ ����������*/
void countsort(int S[], int n, int m, int T[], int theseis[]);

main(){
    int i,N,m;
    int S[100]; /* � ������� �� �� �������� */
    int T[100], theseis[100];
    
    printf("Dose th diastash toy T:");
    scanf("%d",&N);
    
    for(i=0;i<N;i++){
    	printf("Dose ton %d ari8mo:",i);
        scanf("%d",&S[i]);
    }   
      /* �������� ������� ������*/
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
    /* �������� ������� ������*/
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

/* ��������� countsort */
void countsort(int S[], int n, int m, int T[], int theseis[]){
    int i,j;
    int C[m]; /* ������� ����������� ����������*/
    /* ���������� ������ ���������� C*/
    for(i=0;i<m;i++)
        C[i]=0;
    /* ���������� ������ �*/
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
