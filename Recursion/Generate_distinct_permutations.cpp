/*
  Generate All Distinct Permutations of a given string
*/

#include <iostream>
using namespace std;

bool shouldSwap(string s,int start,int curr){
    for(int i=start;i<curr;i++){
        if(s[i]==s[curr])
            return false;
    }
    return true;
}

void permutationsH(string s,int n,int idx){
    if(idx == n){
        cout<<s<<endl;
    }
    for(int i=idx;i<n;i++){
        if(shouldSwap(s,idx,i)){
            swap(s[idx],s[i]);
            permutationsH(s,n,idx+1);
            swap(s[idx],s[i]); //backtracing step
        }
    }
}

void permutations(string s){
    int n = s.length();
    permutationsH(s,n,0);
}

int main() {
	string s;
	cin>>s;
	permutations(s);
	return 0;
}
