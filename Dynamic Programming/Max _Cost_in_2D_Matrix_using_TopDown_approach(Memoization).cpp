#include<bits/stdc++.h>
#define rows 50
#define cols 50
using namespace std;

int findMaxCostH(vector<vector<int>> a,int i,int j,int r,int c,int cache[rows][cols]){
    if(i>=r || j>=c)
            return INT_MIN;
    if(cache[i][j]==INT_MIN){
        if(i==r-1 && j==c-1)
            cache[i][j] = a[r-1][c-1];
        else
            cache[i][j] =  a[i][j]+max(findMaxCostH(a,i+1,j,r,c,cache),findMaxCostH(a,i,j+1,r,c,cache));
    }
    return cache[i][j];
}

int findMaxCost(vector<vector<int>> a,int r,int c){
    int cache[rows][cols];
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            cache[i][j]=INT_MIN;
        }
    }
    return findMaxCostH(a,0,0,r,c,cache);
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
