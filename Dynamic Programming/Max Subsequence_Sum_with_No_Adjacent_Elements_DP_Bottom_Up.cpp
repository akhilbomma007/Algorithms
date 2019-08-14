/*
Max Subsequence Sum with No Adjacent Elements

PROBLEM STATEMENT:
Given an array of integers.
Return the maximum sum that can be obtained by adding elements of array such that no two adjacent elements are selected.
i.e. If a[i] is taken into sum... a[i-1] and a[i+1] can not be included at all.

INPUT FORMAT:
Line 1:  Integer T - Number of test cases.
Each Test Case Consists of following lines of input:
TC Line 1:  Integer N - Number of elements in array.
TC Line 2:  N space separated integers representing array elements.

OUTPUT FORMAT:
For each test case print single line of output having maximum subsequence sum possible.

CONSTRAINTS:
1 <= T <= 50
0 <= N <= 1000

COMPLEXITIES:
Expected Time Complexity: O(T*N*N),
Allowed Space Complexity: O(T*N*N)

SAMPLE INPUT:
2
5
0 2 3 4 1
2
9 49
7
30 34 14 121 5 2
3
3 37 9
*/

#include <bits/stdc++.h>
using namespace std;

int maxSumWithNoAdjacentElements(int a[], int n){
  	int dp[n+1];
  	dp[0]=0;
  	for(int i=1;i<=n;i++){
      	if(i-2<=0)
          	dp[i] = max(a[i-1],dp[i-1]);
      	else
    		dp[i] = max(a[i-1]+dp[i-2],dp[i-1]);
    }
  	return dp[n];
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
        cout<<maxSumWithNoAdjacentElements(a,n)<<endl;
    }
    return 0;
}
