/*
Has Subset with given Sum - DP Bottom Up

PROBLEM STATEMENT:
Given an array A of N integers and a sum S.
Can elements of this array, be added in any order to get sum S? each element can be used only once.

INPUT FORMAT:
Line 1: Integer T - Number of test cases.
Each test case has following lines:
    Test Case Line 1:  Integer N - Number of elements in array.
    Test Case Line 2:  N space separated integers.
    Test Case Line 3:  Integer Q - Number of sum Queries.
    Test Case Line 4:  Q space separated values for S.

OUTPUT FORMAT:
For a single test case, print Q space separated values - either true or false on single line.
True if given Sum is possible for any subset of array, false otherwise.  Every test case output should be on its own separate line.

CONSTRAINTS:
1 <= T, Q <= 100
0 <= N <= 1000
0 <= S  <= 10000
0 <= a[i] <= INT_MAX

COMPLEXITIES:
Per Test Expected Time Complexity: O(S * N)
Per Test Allowed Space Complexity: O(S* N)

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

SAMPLE OUTPUT:
true false
true false false

EXPLANATION:
Self Explanatory
*/

#include<bits/stdc++.h>
using namespace std;

bool hasSum(long long a[],int n,long long s,map<string,bool> &dp){
  	if(s==0)
      return true;
  	if(s<0 || n<1)
      return false;
  	string k = to_string(n)+"|"+to_string(s);
  	if(dp.find(k)==dp.end())
		dp[k] = hasSum(a,n-1,s-a[n-1],dp) || hasSum(a,n-1,s,dp);
  	return dp[k];
}

int main()
{
    int t;
  	cin>>t;
  	while(t--){
    	int n;
      	cin>>n;
      	long long a[n];
      	for(long long i=0;i<n;i++)
          cin>>a[i];
      	int q;
      	cin>>q;
      	while(q--){
          	map<string,bool> dp;
        	long long s;
          	cin>>s;
          	cout<<(hasSum(a,n,s,dp)==1?"true":"false")<<" ";
        }
      	cout<<"\n";
    }
	return 0;
}
