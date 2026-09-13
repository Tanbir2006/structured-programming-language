#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);

    int i;
    int isPrime = 1;

    for (i = 2; i < n; i++)
    {
        if (n % i == 0)
        {
            isPrime = 0;
            break;
        }
    }

    if (isPrime)
    {
        printf("The number is prime");
    }
    else
    {
        printf("The number is not prime");
    }

    return 0;
}
