#include<bits/stdc++.h>
#define rows 1000
#define cols 1000
using namespace std;


int countWays(int a[rows][cols],int r,int c){
    int cache[rows][cols];
    memset(cache,-1,sizeof(cache));
    for(int i=r-1;i>=0;i--){
        for(int j=c-1;j>=0;j--){
            if(i==r-1 && j==c-1)
                cache[i][j]=a[i][j];
            else{
                if(a[i][j]==0)
                    cache[i][j]=0;
                else if(i+1>=r)
                    cache[i][j] = cache[i][j+1];
                else if(j+1>=c)
                    cache[i][j] = cache[i+1][j];
                else
                    cache[i][j] = (cache[i+1][j]+cache[i][j+1])%1000000007;
            }
        }
    }
    return cache[0][0];
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
