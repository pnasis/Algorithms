/*
�����: quicksort
�������: ������� T (����� double) �� N ��������
������: � ������� � �������������
���������: � ��������� ������ ����� ��� � �� 3 ���������� �� ���� �� ��������� 
           split ��� ��� �������� ����� ���������� ��� ����� ���.
*/

#include <stdio.h>
#define N 10

void quicksort(double T[], int n);
void split(double T[],int n,double a, double x[],int *dimof_x,double y[],int *dimof_y,double z[],int *dimof_z);

main(){
    double T[]={4,5,10,5,7,3,6,2,8,9};
    int i;
    printf("\nArxikos pinakas T:[ ");
    for(i=0;i<N;i++) printf("%f ",T[i]);
    printf("]");
    /* ����� ��� quicksort*/
    quicksort(T,N);
    printf("\nTaxinomimenos pinakas T:[");
    for(i=0;i<N;i++) printf("%f ",T[i]);
    printf("]\n");
    system("pause");
}

/*��������� quicksort*/
void quicksort(double T[], int n){
    double x[N],y[N],z[N];
    int i;
    int dimof_x=0, dimof_y=0,dimof_z=0; /* ���������� ���������� x,y,z*/
    if(n>=2) {
        /* ����������� ��� � �� ���� �� ����� �������� ���, ���. T[0]*/
        split(T,n,T[0],x,&dimof_x,y,&dimof_y,z,&dimof_z);
        /* ���������� ����� ��� quicksort ��� ���� ���������� x ��� z*/
        quicksort(x,dimof_x);
        quicksort(z,dimof_z);
        /* ����� ��� x, y ��� z */
        for(i=0;i<dimof_x;i++) T[i]=x[i];
        for(i=0;i<dimof_y;i++) T[dimof_x+i]=y[i];
        for(i=0;i<dimof_z;i++) T[dimof_x+dimof_y+i]=z[i];
    }
}

/* ��������� split */
void split(double T[],int n,double a, double x[],int *dimof_x,double y[],int *dimof_y,double z[],int *dimof_z){
    int i;
    for(i=0;i<n;i++)
        if(T[i]<a) { 
            x[*dimof_x]=T[i];
            (*dimof_x)++;
        } else if (T[i]==a){ 
            y[*dimof_y]=T[i];
            (*dimof_y)++;
        } else {    
            z[*dimof_z]=T[i];
            (*dimof_z)++;
        }
}
