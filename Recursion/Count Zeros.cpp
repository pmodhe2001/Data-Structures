#include <iostream>
using namespace std;

int countZeros(int n) {
    if(n==0)
    {
        return 0;
    }

    int last_digit=n%10;
    int ans=countZeros(n/10);
    if(last_digit==0)
    {
        return ans+1;
    }else
    {
        return ans;
    }
}

int main() {
    int n;
    cin >> n;
    cout << countZeros(n) << endl;
}
