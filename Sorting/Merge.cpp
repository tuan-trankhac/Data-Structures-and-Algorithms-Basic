#include<iostream>
using namespace std;
#define MAX 500
void merge(int a[], int first, int mid, int last){
    int tempA[MAX];
    int first1 = first; int last1 = mid;
    int first2 = mid+1 ; int last2 = last;
    int index = first1;
    for(;(first1<= last1)&&(first2<=last2);++index){
        if(a[first1]<a[first2]){
            tempA[index] = a[first1]; ++first1;
        }
        else{
            tempA[index] = a[first2]; ++first2;
        }
    }
    for(;first1<=last1; ++first1, ++index)
        tempA[index] = a[first1];
    for(;first2<=last2; ++first2, ++index)
        tempA[index] = a[first2];
    for(index = first; index <= last; ++index)
        a[index] = tempA[index];
}
void mergeSort(int a[], int first, int last){
    if(first< last){
        int mid = (first+last)/2;
        mergeSort(a, first, mid);
        mergeSort(a, mid+1, last);
        merge(a, first, mid, last);
    }
}
int main(){
    int a[]={8,4,3,2,1};
    mergeSort(a,0,4);
    for(int i=0;i<5;i++)
        cout<<a[i]<<" ";
}