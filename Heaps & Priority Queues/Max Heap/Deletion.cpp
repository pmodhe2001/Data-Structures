#include <iostream>
#include <vector>
using namespace std;
typedef long long int ll;

void heapify(vector<ll> &v,ll n){
    ll left=2*n+1;
    ll right=2*n+2;
    ll MaxE=n;
    if(left<v.size() && v[left]>v[MaxE]){
        MaxE=left;
    }
    if(right<v.size() && v[right]>v[MaxE]){
        MaxE=right;
    }
    if(MaxE!=n){
        swap(v[MaxE],v[n]);
        heapify(v,MaxE);
    }
}
void Del(vector<ll> &v,ll e=0){
    swap(v[0],v[v.size()-1]);
    v.pop_back();
    heapify(v,0);
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
    Del(v);
    for (auto i:v){
        cout<<i<<" ";
    }
}
