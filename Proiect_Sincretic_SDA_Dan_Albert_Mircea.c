#include <stdio.h>
#include <stdlib.h>

int main()
{
    srand(time(0));
    int M,N,i,j,*x,Q=0;
    do
    {
    printf("M=");
    scanf("%d",&M);
    printf("N=");
    scanf("%d",&N);

    x=(int *)malloc(sizeof(int)*N*M);//alocare spatiu matrice

    for(i=0; i < M*N; i++)//generare matrice
            x[i] = rand();

    for(i=0; i < M*N; i++)//afisare matrice
            printf("%d ",x[i]);
        printf("\n");
    for(i=0; i < M; i++)
        for(j=0; j < N; j++)//suma diag principala
        {
            if(i==j)
            Q+=x[i*N+j];
        }

printf("\n"); printf("Suma Diag P=%d",Q);Q=0;

    for(i=0; i < M; i++)
        for(j=0; j < N; j++)//suma diag secundara
        {
            if(i+j==M-1)
            Q+=x[i*N+j];
        }

 printf("\n"); printf("Suma Diag S=%d",Q);
Q=0;
  for(i=0; i < M; i++)
        for(j=0; j < N; j++)//Max sub diag principala
        {
            if(i>j && Q < x[i*N+j])
            Q=x[i*N+j];
        }
        printf("\n"); printf("Max Sub Diag P=%d",Q);
        Q=NULL;
  for(i=0; i < M; i++)
        for(j=0; j < N; j++)//Min sub diag principala
        {
            if(Q==NULL)
                Q=x[i*N+j];
            if(i>j && Q > x[i*N+j])
            Q=x[i*N+j];
        }
        printf("\n"); printf("Min Sub Diag P=%d",Q);
        Q=0;
  for(i=0; i < M; i++)
        for(j=0; j < N; j++)//Max sub diag secundara
        {
            if(i+j>M-1 && Q < x[i*N+j])
            Q=x[i*N+j];
        }
        printf("\n"); printf("Max Sub Diag S=%d",Q);
        Q=NULL;
  for(i=0; i < M; i++)
        for(j=0; j < N; j++)//Min sub diag secundara
        {
            if(Q==NULL)
                Q=x[i*N+j];
            if(i+j>M-1 && Q > x[i*N+j])
            Q=x[i*N+j];
        }
        printf("\n"); printf("Min Sub Diag S=%d",Q);
 free(x);
 printf("\nGenerare matrice noua? 1-Da 0-Nu\n");scanf("%d",&Q);
    }while(Q!=0);
    return 0;
}
