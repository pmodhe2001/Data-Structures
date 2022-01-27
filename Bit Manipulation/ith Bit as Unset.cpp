#include <iostream>
#include<cmath>
using namespace std;

int unSetithBit(int n,int i){
    if(i==0){
        return n;
    }
    //return n & ~int(pow(2,i));
    return n & ~(1<<i);
}
int main()
{
    int n,i;
    cin>>n>>i;
    cout<<unSetithBit(n,i)<<endl;
    
}
