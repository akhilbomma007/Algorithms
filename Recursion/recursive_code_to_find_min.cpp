// recursive code to find min value in a vector

#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int findMinH(vector<int> v,int si,int ei){
    
    if(si==ei)
        return v[si];
    return min(findMinH(v,si,(si+ei)/2),findMinH(v,(si+ei)/2+1,ei));
}

int findMin(vector<int> v){
    return findMinH(v,0,v.size()-1);
}

int main() {
	vector<int> v;
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
	    int j;
	    cin>>j;
	    v.push_back(j);
	}
	int res = findMin(v);
	cout << res << endl;
	return 0;
}
