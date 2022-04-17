/*
�����: selectsort
�������: � ������� � �� �� �������� ���� ���������� ��� � �������� n ��� �
������: � ������� � �������������
Perigrafi: � ���������� ��������� �� �������� ���� ������ � ��������� n. 
   � ���������� �� ���� ���� ������� ��� ������ � ��� ��������� �� ���������
   �������� ��� ����� ����� �������.
*/

#include <stdio.h>
#define N 9 /* �������� ��� ������ � */

/* ������ ���������� */
void bubblesort(double T[], int n);

main(){
    int i;
    double T[]={10,1,15,8,9,6,3,1,7}; /* �� �������� ��� � */

    /* �������� ������� ������ */
    printf("Arxikos pinakas:");
    for(i=0;i<N;i++)
        printf(" %f",T[i]);
    /* ����� ��� bubblesort */
    bubblesort(T,N);
    /* �������� ��� ������������� ������ */
    printf("\nTaxinomimenos pinakas:");
    for(i=0;i<N;i++)
        printf(" %f",T[i]);
    printf("\n");
    system("pause");
}

/* � ���������� bubblesort */
void bubblesort(double T[], int n){
    int i=n;
    int t=-1;
    int j;
    double temp; /* ��������� ��������� */
    while (i>=1 && t!=0){
        t=0;
        for (j=0;j<i-1;j++)
            if(T[j]>T[j+1]) {
                temp=T[j];  /* �������� ��� T[j], T[j+1]*/
                T[j]=T[j+1];
                T[j+1]=temp;
                t++;
                }
        i--;
    }
}
