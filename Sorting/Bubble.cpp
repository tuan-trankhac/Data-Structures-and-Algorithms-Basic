#include <iostream>
using namespace std;

void bubbleSort(int a[], int n)
{
    bool codoicho = true;
    for (int i = 1; i <= n - 1; i++)
    {
        if (codoicho == true)
        {
            codoicho = false;
            for (int j = 0; j <= n - i - 1; j++)
                if (a[j] > a[j + 1])
                {
                    int tmp = a[j];
                    a[j] = a[j + 1];
                    a[j + 1] = tmp;
                    codoicho = true;
                }
        }
    }
}
int main(){
    int A[]= {20,10,4,39,7};
    bubbleSort(A,5);
    for(int i=0 ; i<5;i++)
        cout<< A[i]<<" ";
}