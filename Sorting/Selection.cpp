#include <iostream>
using namespace std;

int SelectionSort(int a[], int n)
{   int count =0 ;
    for (int i = 0; i < n; i++)
    {
        int index_min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < a[index_min])
                {index_min = j;count++;}
        }
        int temp = a[i];
        a[i] = a[index_min];
        a[index_min] = temp;
    }
    return count;
}
int main()
{
    int a[] = {16, 60, 2, 25, 15,45,5,30,33,20};
    cout<<SelectionSort(a, 10);

}