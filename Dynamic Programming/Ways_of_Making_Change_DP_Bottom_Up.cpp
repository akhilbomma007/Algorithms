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

unsigned long long dp[1001][5001];

unsigned long long waysOfMakingChange(int a[], int n, int s){
  	for(int i=0;i<=n;i++){
  	    dp[i][0] = 1;
  	}
  	for(int j=1;j<=s;j++){
  	    dp[0][j] = 0;
  	}
  	for(int i=1;i<=n;i++){
  	    for(int j=1;j<=s;j++){
  	        if(s-a[i-1]<0){
  	            dp[i][j] = dp[i-1][j];
  	        }
  	        else{
  	            dp[i][j] = dp[i][j-a[i-1]]+dp[i-1][j];
  	        }
  	    }
  	}
  	return dp[n][s];
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
