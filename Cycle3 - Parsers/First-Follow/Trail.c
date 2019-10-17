#include<stdio.h>

void def(int A[10],int N)
{   
    int i;
    for(i=0;i<N;i++)
        A[i]=i;
}

void main()
{
    int A[10]={0},i;
    def(A,10);
    for(i=0;i<10;i++)
    printf("%d ",A[i]);
}