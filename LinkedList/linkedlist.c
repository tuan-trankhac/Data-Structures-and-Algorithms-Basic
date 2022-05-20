#include <stdio.h>
#include <time.h>
#include <stdlib.h>
int a[100000];
int n = 0;
void insert(int x, int p)
{   if(p>n) insert(x,n) ;
    for (int j = n - 1; j >= p; j--)
        a[j + 1] = a[j];
    a[p] = x;
    n = n + 1;
}
void delete (int p)
{
    for (int j = p + 1; j <= n - 1; j++)
        a[j - 1] = a[j];
    n = n - 1;
}
int locate(int x)
{
    for (int j = 0; j <= n - 1; j++)
        if (a[j] == x)
            return j;
    return -1;
}
int main()
{
    srand((int)time(0));
    for (int i = 0; i < 100; i++)
    {
        insert(rand() % 100, i);
    }
    for (int i = 0; i < 50; i++)
    {
        delete (rand() % 50);
    }
    for (int i = 0; i < 50; i++)
    {
        printf("\n%d", locate(i));
    }
}