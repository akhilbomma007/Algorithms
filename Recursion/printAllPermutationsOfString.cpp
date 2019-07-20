#include <bits/stdc++.h>
using namespace std;

void printPermutationsH(string s, int n, int idx){
    if(idx==n){
        cout<<s<<endl;
        return;
    }
    for(int i=idx;i<n;i++){
        swap(s[idx],s[i]);
        printPermutationsH(s,n,idx+1);
        swap(s[idx],s[i]);
    }
}

void printPermutations(string s){
    int n = s.length();
    printPermutationsH(s,n,0);
}

int main() {
	string s;
	cin>>s;
	printPermutations(s);
	return 0;
}
