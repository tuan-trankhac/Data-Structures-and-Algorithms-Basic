#include<iostream>
using namespace std;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
int PartitionMid(int a[], int left, int right){
    int pivot = a[(left+right)/2];
    while(left<right){
        while(a[left]<pivot) left++;
        while(a[right]>pivot) right--;
        if(left<right){
            swap(&a[left],&a[right]);
            left++;
            right--;
        }
    }
    return right;
}
void QuickSort(int a[], int left, int right){
    int index_pivot;
    if(left<right){
        index_pivot = PartitionMid(a, left, right);
        QuickSort(a, left, index_pivot-1);
        QuickSort(a, index_pivot+1, right);
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