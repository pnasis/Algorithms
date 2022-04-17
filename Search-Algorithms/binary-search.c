/*
�����: binsearch (������� ���������)
�������: ������� � �� � �������� (����� double) �������������� ��� a � �������
         ���� ��������� (typou double).
������: � ���� index ���� ����� ������� � ������� (����� int) ��� ��� ������ ��������� found
        (����� int) � ����� ������� �� ������� � ������� a � ���. 
���������: � ���������� ������� ������ �� �� ������ �������� ��� � ����� ���� ��� ��������.
           �� ��� ����� ���� � ��������� ������ ���� ��� �������� ����� ���� ���
           ����� ������� �� �� ���������� ��� ���������.
*/

#include <stdio.h>

/*������ ����������*/
void binsearch(double T[], int n, double a, int *found, int *index);

main(){
    double T[100];
    double a;
    int i,N;
    int found; /* ����� found=1 �� �� �������� �������. ������ ����� found=0*/
    int index; /* ���� ��� ��������� ��� �������� */
    
    printf("Dose th diastash toy T:");
    scanf("%d",&N);
    
    for(i=0;i<N;i++){
       printf("Dose ton %d ari8mo:",i);
       scanf("%lf",&T[i]);
       }   
       
    printf("Dwse stoixeio pou psaxnoume:");
    scanf("%lf",&a);
    
    /* ����� ��� ���������� linsearch*/
    binsearch(T,N,a,&found,&index);

    /* �������� �������������*/
    if(found==1) 
         printf("To stoixeio %f brethike sti thesi %d tou pinaka\n",a,index+1);
    else 
         printf("To stoixeio %f den brethike ston pinaka\n",a);
    
    system("pause");
}

/* ��������� �������� ���������� */
void binsearch(double T[], int n, double a, int *found, int *index){
    int i=0;    /* �������� ���� */
    int j=n-1;  /* ����� ���� */
    int k;      /* ������ ���� ������ */
    *found=0; /* ������ �������� ��� �� �������� ��� �������*/
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
