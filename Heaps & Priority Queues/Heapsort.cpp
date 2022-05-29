#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void maxHeapify(vector<int> &v,int i,int n){
    int l=2*i+1;
    int r=l+1;
    int largest=i;
    
    
    if(l<n && v[l]>v[i]){
        largest=l;
    }
    else{
        largest=i;
    }
    if(r<n && v[r]>v[largest]){
        largest=r;
    }
    
    if(largest!=i){
        swap(v[i],v[largest]);
        maxHeapify(v,largest,n);
    }
}

void BuildMaxHeap(vector<int> &v){
    int n=v.size();
    
    for(int i=(n/2);i>=0;i--){
        maxHeapify(v,i,n);
    }
}

void HeapSort(vector<int> &v){
    BuildMaxHeap(v);
    int n=v.size();
    for(int i=n-1;i>0;i--){
        swap(v[0],v[i]);
        n--;
        maxHeapify(v,0,n);
    }
}

int main()
{
    int n;
    cin>>n;
    
    vector<int> v;
    for(int i=0;i<n;i++){
        int d;
        cin>>d;
        v.push_back(d);
    }
    
    HeapSort(v);
    
    
    for(auto i:v){
        cout<<i<<" ";
    }
    
}
