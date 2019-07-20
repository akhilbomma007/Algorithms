#include <iostream>
#include <chrono> 
using namespace std;
using namespace std::chrono; 

long long fib(int n){
    if(n<=1)
        return n;
    return fib(n-1)+fib(n-2);
}

int main() {
	long long n;
	cin>>n;
	auto start = high_resolution_clock::now(); 
	cout<<fib(n)<<endl;
	auto stop = high_resolution_clock::now(); 
	auto duration = duration_cast<microseconds>(stop - start);
	cout << "Time taken by function: "<< duration.count() << " microseconds" <<endl;
	return 0;
}
