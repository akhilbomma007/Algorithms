#include <bits/stdc++.h>
using namespace std;

void printSubsequencesH(string s, string p, int n,int idx){
    if(idx==n){
        cout<<p<<endl;
        return;
    }
    printSubsequencesH(s,p,n,idx+1);
    printSubsequencesH(s,p+s[idx],n,idx+1);
}

void printSubsequences(string s){
    string p = "";
    int n = s.length();
    printSubsequencesH(s,p,n,0);
}

int main() {
	string s;
	cin>>s;
	printSubsequences(s);
	return 0;
}
