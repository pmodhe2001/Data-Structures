#include <iostream>
#include <string>
#include<unordered_set>

using namespace std;

string uniqueChar(string str) {
    string ans;
    unordered_set<char> mp; // we can only insert unique elements in set data structure
    for(int i=0;str[i]!='\0';i++){
        if(mp.find(str[i])==mp.end())
        ans.push_back(str[i]); 
        mp.insert(str[i]); 
    }
    return ans;
}

int main() {
    string str;
    cin >> str;
    cout << uniqueChar(str);
}
