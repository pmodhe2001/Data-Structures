#include<iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

void intersection(int input1[], int input2[], int size1, int size2) {
    unordered_map<int,int> mp ;
    
   sort(input1,input1+size1);sort(input2,input2+size2);
    for(int i=0 ;i<size1 ;i++){
         mp[input1[i]]++;
    }
    for(int i=0 ;i<size2 ;i++)
    {
        if(mp[input2[i]]>0)
        {
            cout<<input2[i]<<" ";
            mp[input2[i]]--;  //reduce its occurence by 1;
        }
            
    }
} 

int main()
{
	int t;
	cin >> t;

		int size1, size2;

		cin >> size1;
		int *input1 = new int[size1];

		for (int i = 0; i < size1; i++)
		{
			cin >> input1[i];
		}

		cin >> size2;
		int *input2 = new int[size2];

		for (int i = 0; i < size2; i++)
		{
			cin >> input2[i];
		}

		intersection(input1, input2, size1, size2);
		
		delete[] input1;
		delete[] input2;
		
		cout << endl;

	return 0;
}
