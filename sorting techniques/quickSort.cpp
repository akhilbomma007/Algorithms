/*
Quick Sort:

input format:
single line having spaced integers

output:
sorted elements

sample input:
9 6 5 0 8 2 4 7

sample output:
0 2 4 5 6 7 8 9
*/

#include <bits/stdc++.h>
using namespace std;

int partition(vector<int> &a,int l,int h){
    int pivot = h;
    int i=l;
    int j=h-1;
    while(i<=j){
        while(a[i]<=a[pivot] && i<pivot)
            i++;
        while(a[j]>a[pivot])
            j--;
        if(i<j)
            swap(a[i],a[j]);
    }
    swap(a[i],a[pivot]);
    return i;
}

void quick_sortH(vector<int> &a,int l,int h){
    if(l>=h)
        return;
    int pi = partition(a,l,h);
    quick_sortH(a,l,pi-1);
    quick_sortH(a,pi+1,h);
}

void quick_sort(vector<int> &a){
    int l,h;
    l=0;
    h=a.size()-1;
    quick_sortH(a,l,h);
}

int main() {
	vector<int> a;
	int k;
	while(cin>>k){
	    a.push_back(k);
	}
	quick_sort(a);
	for(int i=0;i<a.size();i++)
	    cout<<a[i]<<" ";
	cout<<endl;
	return 0;
}
