/*
Max Cost in 2D Matrix

PROBLEM STATEMENT:
Given a 2D Matrix containing integers,  Find the maximum cost that one will incur to start from TOP LEFT (0, 0) to reach to bottom right of matrix.
You can only move in RIGHT or DOWN directions.

INPUT FORMAT:
Line 1:  Integer T - Number of Test Cases.​Each Test Case consists of following lines.
Test Case Line 1:  Integers R C (space separated to represent matrix dimensions).
Next R lines of test case contain C integers each (space separated) to represent matrix elements.

OUTPUT FORMAT:
For each test case print single line of output, containing a number that is MAX possible sum out of all the paths starting from (0,0) and ending at (R-1, C-1)

CONSTRAINTS:
1 <= T <= 10
1 <= R, C <= 50
-5000 <= A[i] <= 5000

COMPLEXITIES:
Expected Time Complexity: O(T*M*N),
Allowed Space Complexity: O(T*M*N)

SAMPLE INPUT:
2
3 3
1 2 3
4 9 6
7 8 9
3 3
1 2 3
4 8 2
1 5 3

SAMPLE OUTPUT:
31
21

EXPLANATION:
Test Case 1:  Max Cost Path is 31
(1 -> 4 -> 9 -> 8 -> 9)

Test Case 2:  Max Cost Path is 21
(1 -> 4 -> 8 -> 5 - > 3)

*/
#include<bits/stdc++.h>
#define R 200
#define C 200
using namespace std;

int helper(int a[R][C], int m, int n,unordered_map<string,int> &dp)
{
  	if(m==1 && n==1)
      	return a[0][0];
  	string key = to_string(m)+"|"+to_string(n);
  	if(dp.find(key)==dp.end()){
  		if(m-1<=0)
    		dp[key] = a[m-1][n-1]+helper(a,m,n-1,dp);
  		else if(n-1<=0)
      		dp[key] = a[m-1][n-1]+helper(a,m-1,n,dp);
        else
			dp[key] =  a[m-1][n-1]+max(helper(a,m-1,n,dp),helper(a,m,n-1,dp));
    }
  	return dp[key];
}

int maxPathCost(int a[R][C], int m, int n)
{
  	unordered_map<string,int> dp;
  	return helper(a,m,n,dp);
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int m,n;
        cin>>m>>n;
        int a[R][C];
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                cin>>a[i][j];
            }
        }
        cout<<maxPathCost(a,m,n)<<endl;
    }
    return 0;
}
