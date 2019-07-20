#include<bits/stdc++.h>
#define rows 50
#define cols 50
using namespace std;

int findMaxCost(vector<vector<int>> a,int r,int c){
    int cache[rows][cols];
    cache[r-1][c-1] = a[r-1][c-1];
    for(int i=r-2;i>=0;i--)
        cache[i][c-1] = a[i][c-1]+cache[i+1][c-1];
    for(int i=c-2;i>=0;i--)
        cache[r-1][i] = a[r-1][i]+cache[r-1][i+1];
    for(int i=r-2;i>=0;i--){
        for(int j=c-2;j>=0;j--){
            cache[i][j]=a[i][j]+max(cache[i+1][j],cache[i][j+1]);
        }
    }
    return cache[0][0];
}

int main() {
    int t;
    cin>>t;
    while(t--){
        int r,c;
        cin>>r>>c;
        vector<vector<int>> a;
        for(int i=0;i<r;i++){
            vector<int> row;
            for(int j=0;j<c;j++){
                int k;
                cin>>k;
                row.push_back(k);
            }
            a.push_back(row);
        }
        cout<<findMaxCost(a,r,c)<<endl;
    }
    return 0;
}
