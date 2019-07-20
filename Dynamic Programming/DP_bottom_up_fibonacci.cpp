#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono; 

long long f[101];

long long fib(int n){
    f[0]=0;
    f[1]=1;
    for(int i=2;i<=n;i++){
        f[i]=f[i-1]+f[i-2];
    }
    return f[n];
}

int main() {
	long long n;
	cin>>n;
	memset(f,-1,sizeof(f));
	auto start = high_resolution_clock::now(); 
	cout<<fib(n)<<endl;
	auto stop = high_resolution_clock::now(); 
	auto duration = duration_cast<microseconds>(stop - start);
	cout << "Time taken by function: "
         << duration.count() << " microseconds" << endl;
	return 0;
}
