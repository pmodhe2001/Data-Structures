#include <iostream>
#include<cmath>
using namespace std;

int FlipithBit(int n,int i){
    //return (n ^ int(pow(2,i)));
     return (n ^ (1<<i));
}
int main()
{
    int n,i;
    cin>>n>>i;
    cout<<FlipithBit(n,i)<<endl;
    
}
