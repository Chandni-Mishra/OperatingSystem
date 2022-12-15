Write a c program to implement shortest seek time first disk scheduling algorithm

#include <stdio.h>
 
int main()
{
    int i,j,n,a[20],sum=0,d;
    float avg;
 
    printf("Enter number of locations\n");
    scanf("%d",&n);
 
    printf("Enter position of head\n");
    scanf("%d",&a[0]);
 
    printf("Enter elements of disk queue\n");
    for (i=1;i<=n;i++)
    scanf("%d",&a[i]);
 
    d=a[0];
 
    for (i=0;i<=n;i++)
    {
        for (j=i;j<=n;j++)
        {
            if (a[i]>a[j])
            {
                a[i]=a[i]+a[j];
                a[j]=a[i]-a[j];
                a[i]=a[i]-a[j];
            }
        }
    }
 
    for (i=0;i<=n;i++)
    {
        if (a[i]>d)
        {
            printf("%d -> %d\n",d,a[i]);
            sum=sum+a[i]-d;
            d=a[i];
        }
    }
    avg=sum/(float)n;
    printf("\nAverage Seek Time is %f\n",avg);
    return 0;
}
