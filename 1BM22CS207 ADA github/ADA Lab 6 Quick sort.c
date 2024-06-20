#include<stdio.h>
#include<time.h>
#include<stdlib.h> /* To recognise exit function when compiling with gcc*/
void QuickSort(int a[], int low, int high);
int partition(int a[], int low, int high);
void swap(int *x, int *y);
void main()
{
int a[15000],n,i,j,ch;
int low=0,high;
clock_t start,end;
    while(1)
    {
    printf("\n1:For manual entry of N value and array elements");
    printf("\n2:To display time taken for sorting number of elements N in the range 7500 to 14500");
    printf("\n3:To exit");
    printf("\nEnter your choice:");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1: printf("\nEnter the number of elements:");
                scanf("%d",&n);
                high=n-1;
                printf("\nEnter array elements:");
                for(i=0;i<n;i++)
                {
                    scanf("%d",&a[i]);
                }
                start=clock();
                QuickSort(a,low,high);
                end=clock();
                printf("\nSorted array is:");
                for(i=0;i<n;i++)
                    printf("%d\t",a[i]);
                printf("\n Time taken to sort %d numbers is %f Secs",n, (((double)(end-start))/CLOCKS_PER_SEC));
                break;
        case 2: n=7500;
                while(n<=14500)
                {
                    for(i=0;i<n;i++)
                    {
                        //a[i]=random(1000);
                        a[i]=n-i;
                    }
                    int start=clock();
                    QuickSort(a,0,n-1);
                    //Dummy loop to create delay
                    for(j=0;j<500000;j++)
                    {
                        int temp=38/600;
                    }
                    end=clock();
                    printf("\n Time taken to sort %d numbers is %f Secs",n, (((double)(end-start))/CLOCKS_PER_SEC));
                    n=n+1000;
                }
                break;
break;
        case 3: printf("Exiting...\n");
                exit(1);
                break;
    }
    }
}
void QuickSort(int a[],int low,int high)
{
    if(low<high)
    {
        int split_pt=partition(a,low,high);
        QuickSort(a,low,split_pt-1);
        QuickSort(a,split_pt+1,high);
    }

}
int partition(int a[],int low,int high)
{
    int pivot=a[low];
    int i=low;
    int j=high+1;
    do
    {
        do
        {
            i=i+1;
        }
        while(a[i]<pivot);

        do
        {
            j=j-1;
        }
        while(a[j]>pivot);
        if(i<j)
            swap(&a[i],&a[j]);
    }while(i<j);
    swap(&a[j],&a[low]);
    return j;
}
void swap(int *x,int *y)
{
    int temp=*x;
    *x=*y;
    *y=temp;
}
