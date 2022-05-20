#include <iostream>
using namespace std;

int BinSearch(int high, int low, int A[], int x)
{
    int mid = (high + low) / 2;
    if (A[mid] == x)
        return mid;
    else if (x < A[mid])
        return BinSearch(mid, low, A, x);
    else
        return BinSearch(high, mid + 1, A, x);
}
int main()
{
    int A[] = { 1, 5, 13, 29, 30, 50, 77, 103 };
    cout << BinSearch(7, 0, A, 50) << endl;
}