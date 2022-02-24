#include <iostream>

using namespace std;

int maxElement(int *arr,int n){
    int maxE=arr[0];
    for(int i=0;i<n;i++){
        if(maxE<arr[i]){
            maxE=arr[i];
        }
    }
    return maxE;
}
void countingSort(int *&arr,int n){
    int maxE=maxElement(arr,n);
    cout<<maxE<<endl;
    int *res=new int[maxE+1];
    for(int i=0;i<maxE+1;i++){
        res[i]=0;
    }
    for(int i=0;i<n;i++){
        res[arr[i]]++;
    }
    int sortedIndex=0;
    for(int i=0;i<maxE+1;){
        if(res[i]>0){
            arr[sortedIndex]=i;
            res[i]--;
            sortedIndex++;
            
        }
        else{
            i++;
        }
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    
}
int main()
{
    int n;
    cin>>n;
    
    int *arr=new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    countingSort(arr,n);
    
}
