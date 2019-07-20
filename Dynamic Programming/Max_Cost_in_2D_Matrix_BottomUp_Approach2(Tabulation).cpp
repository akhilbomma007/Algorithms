#include<bits/stdc++.h>
#define rows 50
#define cols 50
using namespace std;

int findMaxCost(vector<vector<int>> a,int r,int c){
    int cache[rows][cols];
    for(int i=r-1;i>=0;i--){
        for(int j=c-1;j>=0;j--){
            if(i==r-1 && j==c-1)
                cache[i][j] = a[i][j];
            else{
                if(i+1==r)
                    cache[i][j] = a[i][j] + cache[i][j+1];
                else if(j+1==c)
                    cache[i][j] = a[i][j] + cache[i+1][j];
                else
                    cache[i][j] = a[i][j] + max(cache[i+1][j],cache[i][j+1]);
            }
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
