#include <iostream>
using namespace std;

int staircase(int n){
    if(n==1 || n==0)
        return 1;
    if(n==2)
        return 2;
    
    int ans=staircase(n-1)+staircase(n-2)+staircase(n-3);
    return ans; 
}

int main() {
    int n, output;
    cin >> n;
    output=staircase(n);
    cout<< output <<endl;
}
