#include <stdio.h>
#include <omp.h>
void main()
{
    int a[]={8,7,5,9,10,2,3,6};
    int n=sizeof(a)/sizeof(a[0]);
    int tid;
    int temp;
    #pragma omp parallel num_threads(n)
    {
        for(int p=0;p<n;p++)
        {
            if(p%2==0)
            {
                #pragma omp for
                for(int i=1;i<n;i=i+2)
                {
                    if(a[i-1]>a[i])
                    {
                        temp=a[i-1];
                        a[i-1]=a[i];
                        a[i]=temp;
                    }
                }
            }
            else
            {
                #pragma omp for
                for(int i=1;i<n-1;i=i+2)
                {
                    if(a[i]>a[i+1])
                    {
                        temp=a[i+1];
                        a[i+1]=a[i];
                        a[i]=temp;
                    }
                }
            }
            }
        }
        for(int i=0;i<n;i++)
        {
            printf("%d ",a[i]);
        }
    }