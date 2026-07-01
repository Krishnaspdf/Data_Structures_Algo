#include <stdio.h>



void recurse(int n, char name[])
{
    if (n <= 0)
    {
        return;
    }
    printf(" %s ", name);
    recurse(n - 1, name);
}

int main()
{
    int n;
    char name[50];
    printf("What Is Your Name: ");
    scanf("%s", name);
    printf("N = ");
    scanf("%d", &n);
    recurse(n, name);
    printf("\n");
    return 0;
}