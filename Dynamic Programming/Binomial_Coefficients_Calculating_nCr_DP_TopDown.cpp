#include<bits/stdc++.h>
#define rows 1001
#define cols 1001
using namespace std;

long long nCr(int n,int r,long long a[rows][cols]){
    if(a[n][r]==-1){
        if(r==0 || r==n)
            a[n][r] = 1;
        else
        a[n][r] = (nCr(n-1,r,a)+nCr(n-1,r-1,a))%1000000007;
    }
    return a[n][r];
}

int main() {
    int t;
    cin>>t;
    long long a[rows][cols];
    memset(a,-1,sizeof(a));
    while(t--){
        int n,r;
        cin>>n>>r;
        cout<<nCr(n,r,a)<<endl;
    }
}
