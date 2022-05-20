#include<iostream>
using namespace std;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
int PartitionLast(int a[], int left, int right){
    int pivot = a[right];
    int j = left - 1;
    for(int i = left; i< right; i++){
        if(pivot >= a[i]){
            j++;
            swap(&a[i],&a[j]);
        }
    }
    a[right] = a[j+1];
    a[j+1] = pivot;
    return j+1;
}
void QuickSort(int a[], int left, int right){
    int index_pivot;
    if(left<right){
        index_pivot = PartitionLast(a, left, right);
        QuickSort(a, left, index_pivot-1);
        QuickSort(a, index_pivot+1,right);
    }
}
int main()
{
    int a[] = {-15 ,42 ,63 ,64 ,63 ,67 ,63, 6, 63, 6};
    QuickSort(a, 0, 9);
    for (int i = 0; i < 10; i++)
    {
        cout << a[i] << " ";
    }
}