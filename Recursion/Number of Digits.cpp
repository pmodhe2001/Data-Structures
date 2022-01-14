#include<iostream>
using namespace std;

int count(int n){
    if(n<10){
        return
    }
    int smalans=count(n/10);
    return 1+smalans;
}

int main(){
    int n;
    cin >> n;
  
    cout << count(n) << endl;
}
