#include <iostream>
#include<cmath>
using namespace std;

int SetithBit(int n,int i){
    if(i==0){
        return n;
    }
    //return n | int(pow(2,i));
    return n | (1<<i-1);
}
int main()
{
    int n,i;
    cin>>n>>i;
    cout<<SetithBit(n,i)<<endl;
    
}
