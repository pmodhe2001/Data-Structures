#include <iostream>
#include<cmath>
using namespace std;

bool checkSet(int n,int i){
    //int z=(n & int(pow(2,i))); This pow func can be replaced with left shift 
    // reducing time complexity by O(log(n)) times
    int z=(n & 1<<i);
    if(z==0){
        return false;
    }
    return true;
}
int main()
{
    int n,i;
    cin>>n>>i;
    
    string res=(checkSet(n,i)) ? "Yes" : "No";
    cout<<res<<endl;
    
}
