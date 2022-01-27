#include <iostream>
#include<cmath>
using namespace std;

int unsetFirstsetBit(int n){
     return (n & (n-1));
}
int main()
{
    int n;
    cin>>n;
    cout<<unsetFirstsetBit(n)<<endl;
    
}
