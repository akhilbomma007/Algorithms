#include <iostream>
using namespace std;

void print(char p[], int n){
    for(int j=0;j<n;j++)
        std::cout << p[j];
    cout<<endl;
}

void printBinStringsHelper(int n, char p[],int i){
    
    if(i==n){
        print(p,n);
        return;
    }
    
    for(int j=0;j<=1;j++){
        p[i]= j+'0';
        printBinStringsHelper(n,p,i+1);
    }
    // p[i]='1';
    // printBinStringsHelper(n,p,i+1);
}

void printBinStrings(int n, char p[]){
    
    printBinStringsHelper(n,p,0);    
}

int main() {
    int n;
    char p[n];
    cin>>n;
    printBinStrings(n,p);
    return 0;
}
