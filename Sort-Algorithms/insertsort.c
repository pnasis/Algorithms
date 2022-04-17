/*
�����: insertsort
�������: � �� ������������� ������� T (����� double) ��� �� ������ ��� ��������� � 
         (����� int) ��� �.
������: � ������� T �������������
Perigrafi: � ���������� insertsort ����� �� ���� ��������� �� ���������
           insert ���� �� ������������ �� ���� �������� ��� ����� ���� ���� �.
*/

#include <stdio.h>
#define N 10 /* ������ ��������� ��� ������ */

/* ������ ����������� */
void insert(double T[], int n, double a);
void insertsort(double T[], int n);

main(){
    int i;
    double T[]={1,7,3,6,5,10,9,2,4,5}; /* � ������� �� �� �������� */
    /* �������� ������� ������ */
    printf("Arxikos pinakas:");
    for(i=0;i<N;i++)
        printf(" %f",T[i]);
    /* ����� insertsort*/
    insertsort(T,N);
    /* �������� ������������� ������ */
    printf("\nTaxinomimenos pinakas:");
    for(i=0;i<N;i++)
        printf(" %f",T[i]);
    printf("\n");
    system("pause");
}

/* ��������� ��� ��������� ���� ������ �� n �������� */
void insertsort(double T[], int n){
    int i;
    for(i=0;i<n;i++)
        insert(T,i,T[i]);
}

/* �������� ��������� a ���� ������ � */
void insert(double T[], int n, double a){
    int i;
    double temp; /* ��������� ��������� */

    /* ���������� ��� a ��� ����� ��� ������ */
    T[n]=a;
    i=n;
    /* �������� ��������� ��� ������ */
    while(i>0 && T[i-1]>T[i]){
        temp=T[i-1];
        T[i-1]=T[i];
        T[i]=temp;
        i--;
    }

}

