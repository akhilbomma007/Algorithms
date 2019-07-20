#include<bits/stdc++.h>
#define rows 1000
#define cols 1000
using namespace std;

int countWaysH(int a[rows][cols],int i,int j,int r,int c,int cache[rows][cols]){
    if(i>=r || j>=c)
        return 0;
    if(cache[i][j]==-1){
        if(a[i][j]==0)
            cache[i][j] = 0;
        else if(i==r-1 && j==c-1)
            cache[i][j] = 1;
        else
            cache[i][j] = (countWaysH(a,i+1,j,r,c,cache)+countWaysH(a,i,j+1,r,c,cache))%1000000007;
    }
    return cache[i][j];
}

int countWays(int a[rows][cols],int r,int c){
    int cache[rows][cols];
    memset(cache,-1,sizeof(cache));
    return countWaysH(a,0,0,r,c,cache);
}

int main() {
    int t;
    cin>>t;
    while(t--){
        int m,n,p;
        cin>>m>>n;
        int a[rows][cols];
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                a[i][j]=1;
            }
        }
        cin>>p;
        while(p--){
            int i,j;
            cin>>i>>j;
            a[i-1][j-1]=0;
        }
        cout<<countWays(a,m,n)<<endl;
    }
    return 0;
}
