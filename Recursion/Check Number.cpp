#include<iostream>
using namespace std;

bool checkNumber(int arr[],int size,int x){
    if(size==0){
        return 0;
    }
    else if(arr[size]==x){
        return true;
    }
    checkNumber(arr,size-1,x);
}

int main(){
    int n;
    cin >> n;
  
    int *input = new int[n];
    
    for(int i = 0; i < n; i++) {
        cin >> input[i];
    }
    
    int x;
    
    cin >> x;
    
    if(checkNumber(input, n, x)) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }
}

