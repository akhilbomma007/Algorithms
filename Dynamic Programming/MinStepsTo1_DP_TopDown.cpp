/*
Min Steps to one:
Level: EASY

Given a positive integer n, find the minimum number of steps s, that takes n to 1. You can perform any one of the following 3 steps.
1.) Subtract 1 from it. (n= n - ­1) ,
2.) If its divisible by 2, divide by 2.( if n%2==0, then n= n/2 ) ,
3.) If its divisible by 3, divide by 3. (if n%3 == 0, then n = n / 3 ).
Just write brute-force recursive solution for this.

Input format :
Line 1 : A single integer i.e. n

Output format :
Line 1 : Single integer i.e number of steps

Constraints :
1 <= n <= 500

Sample Input 1 :
4

Sample Output 1 :
2

Sample Output 1 Explanation :
For n = 4
Step 1 : n = 4/2 = 2
Step 2 : n = 2/2 = 1

Sample Input 2 :
7

Sample Output 2 :
3

Sample Output 2 Explanation :
For n = 7
Step 1 : n = 7 ­ - 1 = 6
Step 2 : n = 6 / 3 = 2
Step 3 : n = 2 / 2 = 1

*/

#include<bits/stdc++.h>
using namespace std;

int countSteps(int n,int dp[]){
    if(dp[n]==-1){
        if(n==1)
        	dp[n] = 0;
    	  else{
            int a=INT_MAX;
    		    int b=INT_MAX;
    		    int c=INT_MAX;

    		    if(n%3==0)
        		  a = 1+countSteps(n/3,dp);

    		    if(n%2==0)
        		  b = 1+countSteps(n/2,dp);

    		    c = 1+countSteps(n-1,dp);
            
    		    dp[n] = min(a,min(b,c));
        }
    }
    return dp[n];
}

int countStepsTo1(int n){
    int dp[501];
    memset(dp,-1,sizeof(dp));
    return countSteps(n,dp);
}

int main(){
  int n;
  cin>>n;
  cout<<countStepsTo1(n)<<endl;
  return 0;
}
