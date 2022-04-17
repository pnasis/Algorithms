/*
�����: 141-linsearch (�������� ���������)
�������: ������� � �� � �������� (����� double) ��� a � ������� ���� ��������� (typou double).
������: � ���� index ���� ����� ������� � ������� (����� int) ��� ��� ������ ��������� found
        (����� int) � ����� ������� �� ������� � ������� a � ���. 
���������: � ���������� �������� �������� ���-����-��� �� �������� ��� � ��� ��������� �� 
           ������� �� �������� ���� ��������� a.
*/

#include <stdio.h>

/*������ ����������*/
void linsearch(double T[], int n, double a, int *found, int *index);

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
    linsearch(T,N,a,&found,&index);

    /* �������� �������������*/
    if(found==1) 
         printf("To stoixeio %f brethike sti thesi %d tou pinaka\n",a,index+1);
    else 
         printf("To stoixeio %f den brethike ston pinaka\n",a);
    system("pause");
}

/* ��������� ��������� ���������� */
void linsearch(double T[], int n, double a, int *found, int *index){
    int k;
    *found=0; /* ������ ������� ��� �� �������� ��� ������� */
    *index=0;
    k=0;
    while(k<n && *found==0){
        if(T[k]==a){ /*������� �� �� �������� ����� ��� �� ���� ��� ���� k*/
            *found=1;
            *index=k;
        }
        k++;
    }
}
