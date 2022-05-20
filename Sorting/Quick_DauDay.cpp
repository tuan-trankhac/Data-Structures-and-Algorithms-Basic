#include <iostream>
using namespace std;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
int Partition(int a[], int left, int right)
{
    int i = left;
    int j = right;
    int pivot = a[left];
    while (true)
    {
        i = i + 1;
        while (i <= right && a[i] < pivot)
            i = i + 1;
        while (j >= left && pivot < a[j])
            j = j - 1;
        if (i >= j)
            break;
        swap(&a[i], &a[j]);
    }
    swap(&a[j], &a[left]);
    return j;
}
void QuickSort(int a[], int left, int right)
{
    int index_pivot;
    if (left < right)
    {
        index_pivot = Partition(a, left, right);
        QuickSort(a, left, index_pivot - 1);
        QuickSort(a, index_pivot + 1, right);
    }
}
int main()
{
    int a[] = {-15, 42, 63, 64, 63, 67, 63, 6, 63, 6};
    QuickSort(a, 0, 9);
    for (int i = 0; i < 10; i++)
    {
        cout << a[i] << " ";
    }
}