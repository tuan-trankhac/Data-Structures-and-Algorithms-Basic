
#include<iostream>
using namespace std;
void InsertionSort(int A[], int n){
    for(int k=1; k<n; k++){
        int temp = A[k];
        int pos = k;
        while(pos>0 && A[pos-1]>temp){
            A[pos] = A[pos-1];
            pos--;
        }
        A[pos] = temp;
    }
}
int main(){
    int A[]= {20,10,4,39,7};
    InsertionSort(A,5);
    for(int i=0 ; i<5;i++)
        cout<< A[i]<<" ";
}