#include <stdio.h>
#include <math.h>

int gcd(int n1, int n2)
{
    int div = 1;
    for (int i = 1; i <= n1 && i <= n2; i++)
    {
        if (n1 % i == 0 && n2 % i == 0)
        {
            div = i;
        }
    }
    return div;
}

int main()
{
    int n1 = 4, n2 = 12;
    int res = gcd(n1, n2);
    printf("The Greatest Common Divisor %d", res);
    return 0;
}
/*An theorem is left.*/