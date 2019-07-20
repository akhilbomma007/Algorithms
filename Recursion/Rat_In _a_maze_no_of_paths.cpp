// Rat in a Maze count number of paths
#include <bits/stdc++.h>
#define r 100
#define c 100
using namespace std;

void print(int a[r][c],int m,int n){
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}

int countPathsH(vector<vector<int>> maze,int m,int n,int a[r][c],int i,int j){
    if(i==m-1 && j==n-1){
        a[i][j] = 1;
        print(a,m,n);
        cout<<endl;
        return 1;
    }
    if(i<0 || i>m-1 || j<0 || j>n-1 || maze[i][j]==0 || a[i][j] == 1)
        return 0;
    a[i][j] = 1;
    int k = 0;
    k = countPathsH(maze,m,n,a,i,j+1)+countPathsH(maze,m,n,a,i+1,j)+countPathsH(maze,m,n,a,i,j-1)+countPathsH(maze,m,n,a,i-1,j);
    a[i][j] = 0; // backtracking step
    return k;
}

int countPaths(vector<vector<int>> maze,int m,int n){
    int a[r][c];
    memset(a,0,sizeof(a));
    return countPathsH(maze,m,n,a,0,0);
}

int main() {
    int m,n;
    cin>>m>>n;
	vector<vector<int>> maze;
	for(int i=0;i<m;i++){
	    vector<int> row;
	    for(int j=0;j<n;j++){
	        int k;
	        cin>>k;
	        row.push_back(k);
	    }
	    maze.push_back(row);
	}
	cout<<countPaths(maze,m,n)<<endl;
	return 0;
}
