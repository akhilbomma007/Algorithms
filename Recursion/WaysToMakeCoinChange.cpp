/*
Ways To Make Coin Change:
Level: MEDIUM

You are given an infinite supply supply of coins of each of denominations D = {D0, D1, D2, D3, ...... Dn-1}. You need to figure out the total number of ways W, in which you can make change for Value V using coins of denominations D.
Note : Return 0, if change isn't possible.

Input Format
Line 1 : Integer n i.e. total number of denominations
Line 2 : n integers i.e. n denomination values
Line 3 : Value V

Output Format
Line 1 :  Number of ways i.e. W

Constraints :
1<=n<=10
1<=V<=500

Sample Input 1 :
Line 1 : 3
Line 2 : 1 2 3
Line 3 : 4

Sample Output
Line 1 : 4

Sample Output Explanation :
Number of ways are - 4 total i.e. (1,1,1,1), (1,1, 2), (1, 3) and (2, 2).

*/

#include <bits/stdc++.h>
using namespace std;

int countWaysToMakeChangeH(int d[], int n, int i, int x){
    if(x==0)
        return 1;
    if(x<0 || i>=n)
        return 0;
    return countWaysToMakeChangeH(d,n,i+1,x)+countWaysToMakeChangeH(d,n,i,x-d[i]);
}

int countWaysToMakeChange(int d[], int n, int x){
    int c=0;
    return countWaysToMakeChangeH(d,n,0,x);
}

int main() {
	int n;
	cin>>n;
	int d[n];
	for(int i=0;i<n;i++){
	    cin>>d[i];
	}
	int x;
	cin>>x;
	cout<<countWaysToMakeChange(d,n,x)<<endl;
	return 0;
}
