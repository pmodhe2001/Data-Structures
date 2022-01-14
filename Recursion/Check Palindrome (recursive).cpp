#include<string.h>

bool helper(char input[],int start,int end){
    if(start>=end){
        return true;
    }
     if(input[start]==input[end]){
return helper(input,start+1,end-1);
     }else{
         return false;
     }

   
}

bool checkPalindrome(char input[]) {
    return helper(input,0,strlen(input)-1);

}

#include <iostream>
using namespace std;

int main() {
    char input[50];
    cin >> input;
    
    if(checkPalindrome(input)) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }
}
