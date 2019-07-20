//Longest subsequence such that adjacent elements have at least one common digit

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

bool common_dig(int a,int b){
    string s1 = to_string(a);
    string s2 = to_string(b);
    for(char x1:s1){
        for(char x2:s2){
            if(x1==x2)
                return true;
        }
    }
    return false;
}

int main(){
    int n;
    cin>>n;
    int a[n];
    vector<int> v;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    
    auto start = high_resolution_clock::now();
    
    v.push_back(a[0]);
    int j=0;
    for(int i=1;i<n;i++){
        if(common_dig(v[j],a[i])){
            v.push_back(a[i]);
            j++;
        }
    }
    cout<<v.size()<<endl;
    for(int i=0;i<v.size();i++)
        cout<<v[i]<<" ";
    cout<<endl;
    
    auto stop = high_resolution_clock::now(); 
	auto duration = duration_cast<microseconds>(stop - start);
	cout << "Time taken by function: "<< duration.count() << " microseconds"<< endl;

    return 0;
}