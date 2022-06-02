//https://www.codingninjas.com/codestudio/problems/reverse-the-array_1262298?topList=love-babbar-dsa-sheet-problems&leftPanelTab=1
void reverseHelper(vector<int> &arr,int m,int n){
    int len = (n-m)/2;
    int i=0;
    while(i<=len){
        swap(arr[m],arr[n]);
        m++;n--;
        i++;
    }
}

void reverseArray(vector<int> &arr , int m)
{
	// Write your code here.
    if(m==0){
        
    }
    else{
         reverseHelper(arr,m+1,arr.size()-1);
    }
}
