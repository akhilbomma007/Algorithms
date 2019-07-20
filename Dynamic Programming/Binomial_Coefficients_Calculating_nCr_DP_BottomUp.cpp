#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int t;
    cin>>t;
    long long a[1001][1001];
    for(int i=0;i<=1000;i++){
        a[i][0]=1;
        a[i][i]=1;
    }
    for(int i=1;i<=1000;i++){
        for(int j=1;j<i;j++){
            a[i][j]=(a[i-1][j-1]+a[i-1][j])%1000000007;
        }
    }
    while(t--){
        int n,r;
        cin>>n>>r;
        cout<<a[n][r]<<endl;
    }
    return 0;
}
