#include<stdio.h>
#include<unistd.h>
int main()
{
    int n;
    printf("Enter the size of the array\n");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the elements of the array\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    int eve=0,odd=0;
    int x = fork();
    if(x == 0) // child process
    {
        for(int i=0;i<n;i++)
        {
            if(arr[i]%2 == 0)
            {
                eve = eve+arr[i];
            }
        }
        printf("Child's Process id is %d\n",getpid());
        printf("Sum of even numbers is : %d\n",eve);
    }
    else //parent process
    {
        for(int i=0;i<n;i++)
        {
            if(arr[i]%2 != 0)
            {
                odd = odd+arr[i];
            }
        }
        printf("Parent's Process id is %d\n",getpid());
        printf("Sum of odd numbers is : %d\n",odd);
    }
}
