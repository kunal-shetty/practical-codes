#include <stdio.h>
int main() {
    int i,j,n,ch,temp;
    printf("\nEnter the number of elements in the array\n");
    scanf("%d",&n);
    int A[n];
    printf("\nEnter the elements in the array\n");
    for(i=0;i<n;i++){
        scanf("%d",&A[i]);
    }
    printf("Elements before sorting\n");
    for(i=0;i<n;i++){
        printf("%d\n",A[i]);
    }
    do{
        printf("\nMenu!!!\n1 for Ascending Order\n2 for Descending Order\n3 to exit\n");
        scanf("%d",&ch);
        switch(ch){
            case 1:
            for(i=0;i<n-1;i++){
                for(j=0;j<n-1;j++){
                    if(A[j]>A[j+1])
                    {
                        temp=A[j];
                        A[j]=A[j+1];
                        A[j+1]=temp;
                    }
                }
            }
            printf("\n Elements in Ascending Order");
            for(i=0;i<n;i++){
                printf("\n%d",A[i]);
            }
            break;
            case 2:
             for(i=0;i<n-1;i++){
                for(j=0;j<n-1;j++){
                    if(A[j]<A[j+1])
                    {
                        temp=A[j];
                        A[j]=A[j+1];
                        A[j+1]=temp;
                    }
                }
            }
            printf("\n Elements in Descending Order");
            for(i=0;i<n;i++){
                printf("\n%d",A[i]);
            }
            break;
            case 3:
            printf("\nExiting the program!");
             return 0;
            default:
            printf("Invalid Choice");
    }
    printf("\nContinue? 1 = yes / 2 = no\n");
    scanf("%d",&ch);
    }while(ch==1);
return 0;
}
