#include <iostream>
#include<cstring>

using namespace std;

void removeX(char input[],int start){
    if(input[start]=='\0'){
        return;
    }
    removeX(input,start+1);
    int len=strlen(input);
    if(input[start]=='x'){
        int i=0;
        for(i=start+1;i<len;i++){
            input[i-1]=input[i];
        }
        input[i-1]='\0';
    }
}

void removeX(char input[]){
    removeX(input,0);
}

int main() {
    char input[100];
    cin.getline(input, 100);
    removeX(input);
    cout << input << endl;
}
