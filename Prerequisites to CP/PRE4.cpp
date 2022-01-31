/*For e.g. villagers from villages 0and n-1, 1 and n-2, 2 and n-3 are combined. The number of villages is always even. So, clearly
there will be n/2 combinations from all the villages. 
You have to tell how many groups
will be formed in each combination and how many villagers will be left without the complete group of 10 peoples.

Input Format:
First-line will have a single integer ‘n’ denotes the number of villages.
The second line will have ‘n’ space-separated integers denoting the population of villages.

Output format:
Print ‘n/2’ lines of two space-separated integers, first will be no. of groups and second will be villagers left without a group.
The first line will have the result of a combination of 0 and n-1, second will have 1 and n-2 and so on.

Constraints:
1 <= n <= 10^5
1 <= Ai <= 10^6
‘n’ will always be even
Sample Input:
10
26 96 18 24 87 51 44 86 75 32
Sample Output:
5 8
17 1
10 4
6 8
13 8*/
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)cin>>arr[i];
    int start=0;int end=n-1;
    while(start>end){
         cout<<(arr[start]+arr[end])/5<<" "<<(arr[start]+arr[end])%5<<endl;
         start++;
         end--;
    }
}
