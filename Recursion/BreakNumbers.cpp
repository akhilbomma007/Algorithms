/*
Break Numbers:
Level: HARD

Given an integer n, break it into smaller numbers such that their summation is equal to n. Print all such combinations in different lines.
Note : [1, 2, 1] and [1,1, 2] are same, so print the particular sequence with increasing order. Order of different combinations doesn't matter.

Input format :
Integer n

Output format :
Print all possible combinations in different lines

Constraints :
1 <= n <= 100

Input :
4

Output :
1 1 1 1
1 1 2
1 3
2 2
4
*/

#include<bits/stdc++.h>
using namespace std;

bool isSorted(vector<int> v){
    for(int i=1;i<v.size();i++){
        if(v[i]<v[i-1])
            return false;
    }
    return true;
}

void print(vector<int> v){
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}

void printCombinationH(int n,vector<int> v){
    if(n==0){
        if(isSorted(v)){
            print(v);
        }
        return;
    }

    if(n<0)
        return;

    for(int i=1;i<=n;i++){
        v.push_back(i);
        printCombinationH(n-i,v);
        v.pop_back(); // backtracking step
    }
}

void printCombination(int n)
{
    vector<int> v;
    printCombinationH(n,v);
}


int main(){
    int n;
    cin>>n;
    printCombination(n);
    return 0;
}
