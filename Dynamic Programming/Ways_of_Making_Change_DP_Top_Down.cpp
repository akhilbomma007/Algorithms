/*
Ways of Making Change

PROBLEM STATEMENT:
Given an array of coins denominations
Assume there are infinite coins of each denomination.
How many ways are there to make change for given amount S?

INPUT FORMAT:
Line 1:  Integer T - Number of test cases.
Each test case consists of following lines:
Test Case Line 1:  Integer N - Number of elements in array.
Test Case Line 2:  N space separated integers, representing array elements.
Test Case Line 3:  Integer Q - Number of queries.
Test Case Line 4:  Q space separated values for S.

OUTPUT FORMAT:
For Each test case, print Q space separated answers, ways to make change for given sum S.

CONSTRAINTS:
1 <= T <= 100
0 <= Q, N <= 1000
1 <= S <= 5000

COMPLEXITIES:
Expected Time Complexity per test: O(N*S),
Allowed Space Complexity: O(N)

SAMPLE INPUT:
1
4
1 2 5 7
2
4 2

SAMPLE OUTPUT:
3 2

EXPLANATION:
Example: coins = {1, 2, 5, 7}, S = 4
We can make change in following 3 ways
(1+1+1+1), (1+1+2), (2+2)

*/
#include <bits/stdc++.h>
using namespace std;

unsigned long long waysOfMakingChangeH(int *a, int n, int s, unordered_map<string,unsigned long long> &dp){
  	if(s==0)
      return 1;

  	if(n<1 || s<0)
      return 0;

  	string key = to_string(n)+"|"+to_string(s);

  	if(dp.find(key)==dp.end()){
      dp[key] = waysOfMakingChangeH(a,n,s-a[n-1],dp)+waysOfMakingChangeH(a,n-1,s,dp);
    }

  	return dp[key];
}

unsigned long long waysOfMakingChange(int *a, int n, int s){
  	unordered_map<string,unsigned long long> dp;
  	return waysOfMakingChangeH(a,n,s,dp);
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++)
            cin>>a[i];
        int q;
        cin>>q;
        while(q--){
            int s;
            cin>>s;
            cout<<waysOfMakingChange(a,n,s)<<" ";
        }
        cout<<endl;
    }
    return 0;
}
