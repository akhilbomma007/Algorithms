/*
0/1 KnapSack:

input format:
1st line contains array of values
2nd line contains array of weights associated with values
3rd line contains capacity of KnapSack

output format:
single line containing maximum value that can be carried in KnapSack

sample input:
20 5 10 40 15 25
1 2 3 8 7 4
10

sample output:
60
*/


#include <bits/stdc++.h>
using namespace std;

int knap_sackH(vector<int> v,vector<int> w,int idx,int W){
    if(W==0)
        return 0;
    if(W<0 || idx>=v.size())
        return INT_MIN;
    int include = v[idx]+knap_sackH(v,w,idx+1,W-w[idx]);
    int exclude = knap_sackH(v,w,idx+1,W);
    return max(include,exclude);
}

int knap_sack(vector<int> v,vector<int> w,int W){
    return knap_sackH(v,w,0,W);
}

int main() {
	int n,c;
  vector<int> t;
	vector<int> v;
	vector<int> w;
	while(cin>>n){
	    t.push_back(n);
	}
	c = t[t.size()-1];
	t.pop_back();
	int s = t.size();
	for(int i=0;i<s;i++){
	    if(i<s/2)
	        v.push_back(t[i]);
	    else
	        w.push_back(t[i]);
	}
	t.clear();
	cout<<knap_sack(v,w,c)<<endl;
	return 0;
}
