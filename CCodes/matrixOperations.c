#include <stdio.h>
int main() 
{
int r, c, i, j;
   printf("\n Enter the number of rows: \t") ;
   scanf("%d", &r) ;
   printf(" \n Enter the number of columns: \t") ;
   scanf("%d", &c) ;
   int A[r][c];
   printf(" \n Enter the elements of the matrix \n") ;
for (i=0;i<r;i++) 
{
for (j=0;j<c;j++)
{
printf(" \n Elements [%d][%d] : ", i, j) ;
scanf("%d",&A[i][j]) ;
}
}
printf("The Matrix is: \n");
for(i=0;i<r;i++) 
{
  for(j=0;j<c;j++) 
  printf ("%d \t ",A[i][j]);
  printf("\n");
}
}
