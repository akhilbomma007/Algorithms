// print all subsequences of a given array

#include <iostream>
#include <vector>
#include<bits/stdc++.h>
using namespace std;

void print(int p[],int pi){
    int flag = 1;
    for(int i=0;i<=pi;i++){
        if(flag==1){
            cout<<p[i];
            flag=0;
        }
        else
            cout<<","<<p[i];
    }
    cout<<endl;
}

void printAllSubsequencesH(int a[],int n,int idx,int p[],int pi){
    if(idx>=n)
        return;
        
    p[pi]=a[idx];
    print(p,pi);
    
    //including current element
    printAllSubsequencesH(a,n,idx+1,p,pi+1);
    
    //excluding current element
    printAllSubsequencesH(a,n,idx+1,p,pi);
}

void printAllSubsequences(int a[],int n){
    int p[n];
    printAllSubsequencesH(a,n,0,p,0);
}

int main() {
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
	    cin>>a[i];
    printAllSubsequences(a,n);
	return 0;
}
