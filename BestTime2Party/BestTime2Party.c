#include <stdio.h>
#include <string.h>
#include "simpio.h"
#include "genlib.h"

void Get_Info(int *row,int col1, int col2, string names[*row][col1], float hours[*row][col2]);
void Best_Hour(int row, int col1, int col2, string array1[row][col1], float array2[row][col2]);
int find_max(int sum[6]);

int main()
{
    int n;
    string names[n][1];
    float hours[n][2];

    Get_Info(&n,1,2,names,hours);
    Best_Hour(n,1,2,names,hours);

    system("PAUSE");
    return 0;
}

void Get_Info(int *row, int col1, int col2, string names[*row][col1], float hours[*row][col2])
{
    int i;

    printf("Give the number of the bands: ");
    scanf("%d", row); getchar();

    for(i=0;i<*row;i++)
    {
        printf("\nBand #%d name: ", i+1);
        names[i][col1]=GetLine();
        printf("Arrival Time: ");
        hours[i][col1]=GetReal();
        printf("Departure Tim: ");
        hours[i][col2]=GetReal();
    }
    printf("\n-------------------------------------------\n");
}

void Best_Hour(int row, int col1, int col2, string names[row][col1], float hours[row][col2])
{
    int sum[6]={0,0,0,0,0,0};
    float time[6]={18.00, 19.00, 20.00, 21.00, 22.00, 23.00};

    for(int i=0;i<row;i++)
    {
        for(int j=0;j<6;j++)
       {
           if (time[j] >= hours[i][col1] && time[j] < hours[i][col2]) //if the band starts on or before this time and ends after this time
            sum[j]+=1;
       }
    }

    for(int j=0;j<6;j++)
    {
        if (sum[j]==find_max(sum))
          {
              printf("\nBestTime2Party is: %.2f \n\nThere will be:\n", time[j]);
              printf("--------------\n");
              for(int i=0;i<row;i++)
              {
                  if(time[j] >= hours[i][col1] && time[j] < hours[i][col2])
                    printf("%s \n", names[i][col1]);
              }
              printf("\n");
          }
    }
}

int find_max(int sum[6])
{
    int max = sum[0];;
    for (int i=0;i<6;i++)
    {
        if (sum[i]>max)
            max=sum[i];
    }
    return max;
}
