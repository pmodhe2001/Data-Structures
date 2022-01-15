#include <iostream>
using namespace std;

int length(char input[]){
	int len = 0;
	for(int i =0;input[i]!='\0';i++){
		len++;
	}
	return len;
}

//Recursive Function
void pairStar(char input[]){
    int start=0;
	//Base Case: Reached End Of String
	if(input[start]!='\0'){
	   
	//Recursive Call 
	//pairStar(input);
	    if(input[start] == input[start+1]){
		      int l = length(input);
		      //Extending the string
		      //input[l+1] = '\0';
		      int i;
		      //To shift the letters by 1
		      for(i = l;i>start;i--){
			         input[i+1] = input[i];
		       }
              input[start + 1] ='*';
              pairStar(input + 2);
		//Entering * in between	
	    }
         pairStar(input + 1);
    }
}

int main() {
   char input[100];
   cin.getline(input, 100);
   pairStar(input);
   cout << input << endl;
}


int main() {
   char input[100];
   cin.getline(input, 100);
   pairStar(input);
   cout << input << endl;
}
