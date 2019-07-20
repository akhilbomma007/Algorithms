/*

Generate all parenthesis:
Level: HARD
Given n pairs of parentheses, write a function to generate and print all combinations of well-formed parentheses. That is, you need to generate all possible valid set of parenthesis that can be formed with given number of pairs.

Input format :
Integer n

Output format :
Print all possible valid parenthesis in different lines

Note: Order in which different combinations of well-formed parentheses are printed in different lines doesn't matter.

Constraints :
1 <= n <= 10

Sample Input :
3

Sample Output :
((()))
(()())
(())()
()(())
()()()

*/

#include<bits/stdc++.h>
using namespace std;

bool isValid(string s){
    stack<char> stk;
    for(char c:s){
        if(c == '(')
            stk.push(c);
        else if(c == ')'){
            if(stk.empty())
                return false;
            stk.pop();
        }
    }
    if(stk.empty())
        return true;
   	else
        return false;
}

bool shouldSwap(string s,int start,int curr){
    for(int i=start;i<curr;i++){
        if(s[i]==s[curr])
            return false;
    }
    return true;
}

void findValidParanthesisH(string s,int n,int idx){
    if(idx == n){
  		if(isValid(s))
        	cout<<s<<endl;
        return;
    }

    for(int i=idx;i<n;i++){
        if(shouldSwap(s,idx,i)){
            swap(s[idx],s[i]);
            findValidParanthesisH(s,n,idx+1);
            swap(s[idx],s[i]); //backtracking step
        }
    }
}

void printWellFormedParanthesis(int n){
    // Write your code here
	string s = "";
    for(int i=0;i<n;i++){
        s+="(";
    }
    for(int i=0;i<n;i++){
        s+=")";
    }
    int l = s.length();
    findValidParanthesisH(s,l,0);
}

int main(){
    int n;
    cin>>n;
    printWellFormedParanthesis(n);
    return 0;
}
