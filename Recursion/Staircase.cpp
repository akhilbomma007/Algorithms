/*
Staircase:
Level: EASY

A child is running up a staircase with n steps, and can hop either 1 step, 2 steps or 3 steps at a time. Implement a method to count how many possible ways the child can run up to the stairs. You need to return all possible number of ways.

Input format :
Integer n (No. of steps)

Constraints :
n <= 30

Sample Input 1:
4

Sample Output 1:
7
*/

#include<bits/stdc++.h>
using namespace std;

int waysUpStairH(int n,int curr){
    if(curr == n)
        return 1;
   	if(curr > n)
        return 0;
    return waysUpStairH(n,curr+1)+waysUpStairH(n,curr+2)+waysUpStairH(n,curr+3);
}

int waysUpStair(int n)
{
    return waysUpStairH(n,0);
}

int main(){
    int n;
    cin>>n;
    cout<<waysUpStair(n)<<endl;
    return 0;
}
