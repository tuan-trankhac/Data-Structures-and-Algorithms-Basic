#include <iostream>
#define MAX 100
using namespace std;
int x[MAX] = {14, 11, 13, 12, 26, 19, 20, 24, 18, 27};
void adjust(int root, int size)
{
    int child;
    int rootkey;
    int tmp;
    tmp = x[root];
    rootkey = x[root];
    child = 2 * root;
    while (child <= size)
    {
        if ((child < size) && x[child] < x[child + 1])
        {
            child++;
        }
        if (rootkey > x[child])
        {
            break;
        }
        else
        {
            tmp = x[child / 2];
            x[child / 2] = x[child];
            x[child] = tmp;
            child *= 2;
        }
    }
}
int BuildHeap(int size)
{
    int count = 0;

    for (int i = size / 2; i > 0; i--)
    {
        adjust(i, size);
        count++;
    }
    return count;
}
void HeapSort(int size)
{
    int tmp;
    BuildHeap(size);
    for (int i = size - 1; i > 0; i--)
    {
        tmp = x[1];
        x[1] = x[i + 1]; 
        x[i + 1] = tmp;
        adjust(1, i);
    }
}
int main()
{
    // HeapSort(9);
    cout << BuildHeap(10)<<endl;
    for(int i=1;i<=10;i++){
        cout<<"  "<<x[i];
    }
}