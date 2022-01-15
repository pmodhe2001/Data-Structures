#include <iostream>
using namespace std;

bool check_ab(char input[], int startIndex) { 
    if (input[startIndex] == '\0') { 
        return true; 
    }
    if (input[startIndex] != 'a') { 
        return false; 
    }
    if (input[startIndex + 1] != '\0' && input[startIndex + 2] != '\0') { 
        if (input[startIndex + 1] == 'b' && input[startIndex + 2] == 'b') { 
            return check_ab(input, startIndex + 3); 
        }
    }
    return check_ab(input, startIndex + 1); 
}

bool checkAB(char input[]) { 
    bool ans = check_ab(input, 0); 
    return ans; 
}

int main() {
    char input[100];
    bool ans;
    cin >> input;
    ans=checkAB(input);
    if(ans)
        cout<< "true" << endl;
    else
        cout<< "false" << endl;
}
