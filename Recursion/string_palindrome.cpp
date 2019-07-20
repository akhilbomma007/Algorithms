// Recursive code to find weather a string is palindrome or not

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool isPalinH(string s ,int si,int ei){
    if(s[si]!=s[ei])
        return false;
    if(si==ei || si+1==ei)
        return true;
    isPalinH(s,si+1,ei-1);
}

bool isPalin(string s){
    return isPalinH(s,0,s.size()-1);
}

int main() {
	string s;
	cin>>s;
	cout << (isPalin(s) ? "Yes" : "No") << endl;
	return 0;
}
