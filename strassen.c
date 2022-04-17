/*
Name: strassen
Eisodos: Pinakes A, B diastasis nxn
Apotelesma: To ginomeno C twn dyo pinakwn
Perigrafi: O algorithmos ypologizei to ginomeno dyo pinakwn efarmozontas ton
anadromiko algorithmo Strassen (texniki Diairei kai Vasileve)
*/

#include <stdio.h>
#define N 4

/*Dilwsi synartisis*/
void strassen(double A[N][N], double B[N][N], int n, double C[N][N]);

main(){
    /*Oi pinakes*/
    double A[N][N]={{2,-1,1,0},{1,0,1,0},{-1,2,1,0},{0,0,0,0}};
    double B[N][N]={{1,0,1,0},{0,1,-1,0},{-1,1,0,0},{0,0,0,0}};
    double C[N][N]; /*To ginomeno*/
    int i,j;
    /*klisi synartisis*/
    strassen(A,B,N,C);
    /*Ektypwsi apotelesmatos*/
    printf("Ginomeno pinakwn:\n");
    for(i=0;i<N;i++){
        for(j=0;j<N;j++)
            printf("%f ",C[i][j]);
        printf("\n");
    }
    system("pause");
}

/* Synartisi pou pairnei san parametro 2 pinakes diastasis nxn kai ypologizei to
ginomeno tous*/
void strassen(double A[N][N], double B[N][N], int n, double C[N][N]){
    double A11[N][N],A12[N][N],A21[N][N],A22[N][N];
    double B11[N][N],B12[N][N],B21[N][N],B22[N][N];
    double g1[N][N],g2[N][N],g3[N][N],g4[N][N];
    double g5[N][N], g6[N][N],g7[N][N];
    double dA1[N][N],dA2[N][N];
    double dB1[N][N],dB2[N][N];
    double sA1[N][N],sA2[N][N],sA3[N][N];
    double sB1[N][N],sB2[N][N],sB3[N][N];
    double sg1[N][N],sg2[N][N],sg3[N][N],sg4[N][N];

    int i,j;

    if(n==1)    /*An oi pinakes einai diastasis 1x1*/
        C[0][0]=A[0][0]*B[0][0];
    else {
        for(i=0;i<n/2;i++)
            for(j=0;j<n/2;j++){
                A11[i][j]=A[i][j];      /* panw aristera meros tou A*/
                A12[i][j]=A[i][n/2+j];  /* panw dexia meros tou A*/
                A21[i][j]=A[n/2+i][j];  /* katww aristera meros tou A*/
                A22[i][j]=A[n/2+i][n/2+j];  /* panw dexia meros tou A*/
                B11[i][j]=B[i][j];      /* panw aristera meros tou B*/
                B12[i][j]=B[i][n/2+j];  /* panw dexia meros tou A*/
                B21[i][j]=B[n/2+i][j];  /* katw aristera meros tou A*/
                B22[i][j]=B[n/2+i][n/2+j]; /* katw dexia meros tou A*/
            }

        for(i=0;i<n/2;i++)
            for(j=0;j<n/2;j++){
                dA1[i][j]=A11[i][j]-A21[i][j];  /*A11-A21*/
                dA2[i][j]=A12[i][j]-A22[i][j];  /*A12-A22*/
                dB1[i][j]=B12[i][j]-B22[i][j];  /*B12-B22*/
                dB2[i][j]=B21[i][j]-B11[i][j];  /*B21-B11*/
                sA1[i][j]=A11[i][j]+A22[i][j];  /*A11+A22*/
                sA2[i][j]=A21[i][j]+A22[i][j];  /*A21+A22*/
                sA3[i][j]=A11[i][j]+A12[i][j];  /*A11+A12*/
                sB1[i][j]=B11[i][j]+B12[i][j];  /*B11+B12*/
                sB2[i][j]=B11[i][j]+B22[i][j];  /*B11+B22*/
                sB3[i][j]=B21[i][j]+B22[i][j];  /*B21+B22*/
            }
        /*Anadromikes kliseis*/
        strassen(dA1,sB1,n/2,g1);   /*g1=(A11-A21)*(B11+B12)*/
        strassen(sA1,sB2,n/2,g2);   /*g2=(A11+A22)*(B11+B22)*/
        strassen(dA2,sB3,n/2,g3);   /*g3=(A12-A22)*(B21+B22)*/
        strassen(A11,dB1,n/2,g4);   /*g4=A11*(B12-B22)*/
        strassen(A22,dB2,n/2,g5);   /*g5=A22*(B21-B11)*/
        strassen(B11,sA2,n/2,g6);   /*g6=B11*(A21+A22)*/
        strassen(B22,sA3,n/2,g7);   /*g7=B22*(A11+A12)*/

        for(i=0;i<n/2;i++)
            for(j=0;j<n/2;j++){
                sg1[i][j]=g2[i][j]+g3[i][j]+g5[i][j]-g7[i][j];
                sg2[i][j]=g4[i][j]+g7[i][j];
                sg3[i][j]=g5[i][j]+g6[i][j];
                sg4[i][j]=-g1[i][j]+g2[i][j]+g4[i][j]-g6[i][j];
            }

        for(i=0;i<n/2;i++)
            for(j=0;j<n/2;j++)
                C[i][j]=sg1[i][j];  /*C11=g2+g3+g5-g7*/
        for(i=0;i<n/2;i++)
            for(j=0;j<n/2;j++)
                C[i][n/2+j]=sg2[i][j];  /*C12=g4+g7*/
        for(i=0;i<n/2;i++)
            for(j=0;j<n/2;j++)
                C[n/2+i][j]=sg3[i][j];  /*C21=g5+g6*/
        for(i=0;i<n/2;i++)
            for(j=0;j<n/2;j++)
                C[n/2+i][n/2+j]=sg4[i][j];  /*C22=-g1+g2+g4-g6*/
    }
}
