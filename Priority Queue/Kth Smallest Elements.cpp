#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<int> kSmallest(int *input, int n, int k) {
	
	priority_queue <int> pq; 
    
    // push first k elments in the priority queue
    for(int i=0 ;i<k; i++)
       pq.push(input[i]);
        
    
    for(int i =k ;i<n ; i++)
    {
        // for remaining elements compare the element with max of pq ie top
        //if smaller push in heap
        if(input[i] < pq.top())
        {
            pq.pop();
            pq.push(input[i]);
        }
    }
    
    vector<int> ans;
    
    while (!pq.empty())
    {
        ans.push_back(pq.top());
        pq.pop();
   
    }
    
    return ans;
    
}

int main() {
    int size;
    cin >> size;

    int *input = new int[size];

    for (int i = 0; i < size; i++) {
        cin >> input[i];
    }

    int k;
    cin >> k;

    vector<int> output = kSmallest(input, size, k);
    sort(output.begin(), output.end());

    for (int i = 0; i < output.size(); i++) {
        cout << output[i] << " ";
    }

    delete[] input;
}
/*
Example TestCase:
4
3 7 1 5
2
*/
