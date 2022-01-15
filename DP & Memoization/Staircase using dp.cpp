#include <iostream>
using namespace std;

long staircase(int n){
    long* arr = new long[n+1];
    arr[0]=0;
    arr[1]=1;
    arr[2]=1;
    arr[3]=2;
    for(int i=4; i<n; i++){
        arr[i] = arr[i-1]+arr[i-2]+arr[i-3];
    }
    return arr[n];
}

int main()
{
	int n;
	cin >> n;
	cout << staircase(n);
}
