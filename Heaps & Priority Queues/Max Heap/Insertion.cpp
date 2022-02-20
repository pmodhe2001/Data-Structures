
#include <iostream>
#include <vector>
using namespace std;
typedef long long int ll;

void heapify(vector<ll> &v,ll n){
    int parent=(n-1)/2;
    if(v[parent]==false){
        return;
    }
    if(v[n]>v[parent]){
        swap(v[n],v[parent]);
        heapify(v,parent);
    }
}
void Insert(vector<ll> &v,ll e){
    v.push_back(e);
    heapify(v,v.size()-1);
}

int main()
{
    vector<ll> v;
    ll n;
    cout<<"Enter no of elemts in heap initially : ";
    cin>>n;
    cout<<"Enter elements inside vector : ";
    for(int i=0;i<n;i++){
        ll d;
        cin>>d;
        v.push_back(d);
    }
    ll e;
    cout<<"Enter element to insert in heap : ";
    cin>>e;
    Insert(v,e);
    for (auto i:v){
        cout<<i<<" ";
    }
}
