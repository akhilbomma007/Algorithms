/*
Merge Sort:

input:
first line : n
next line : n spaced separate integers

output:
sorted array

sample input:
5
5 4 3 2 1

sample output:
1 2 3 4 5
*/

#include <iostream>
using namespace std;

void merge(int a[],int i,int m,int j){
    int n=j-i+1;
    int t[n];
    int l,r,k;
    l=i;
    r=m+1;
    k=0;
    while(l<=m && r<=j){
        if(a[l]<=a[r]){
            t[k]=a[l];
            l++;
        }
        else{
            t[k]=a[r];
            r++;
        }
        k++;
    }
    while(r<=j){
        t[k]=a[r];
        r++;
        k++;
    }
    while(l<=m){
        t[k]=a[l];
        l++;
        k++;
    }
    k=0;
    for(int b=i;b<=j;b++){
        a[b]=t[k];
        k++;
    }
}

void mergeSortH(int a[],int i,int j){
    if(i==j)
        return;
    int m = (i+j)/2;
    mergeSortH(a,i,m);
    mergeSortH(a,m+1,j);
    merge(a,i,m,j);
}

void mergeSort(int a[],int n){
    mergeSortH(a,0,n-1);
}

int main() {
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
	    cin>>a[i];
	mergeSort(a,n);
	for(int i=0;i<n;i++)
	    cout<<a[i]<<" ";
	return 0;
}
