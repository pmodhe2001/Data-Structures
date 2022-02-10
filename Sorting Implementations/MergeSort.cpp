
#include <iostream>
#include <vector>

typedef long long int ll;
using namespace std;

void mergeArrays(vector<ll> &v,ll start,ll mid,ll end){
    ll size1=mid-start+1;;
    ll size2=end-mid;
    
    vector<ll> p1(size1);
    vector<ll> p2(size2);
    
    ll x=0;
    for(ll i=start;i<=mid;i++,x++){
        p1[x]=v[i];
    }
    
    ll y=0;
    for(ll i=mid+1;i<=end;i++,y++){
        p2[y]=v[i];
    }
    
    ll i=0,j=0;
    x=start;
    while(i<size1 && j<size2){
        if(p1[i]<=p2[j]){
            v[x]=p1[i];
            x++;i++;
        }
        else {
            v[x]=p2[j];
            x++;j++;
            
        }
    }
    
    while(i<size1){
        v[x]=p1[i];
        i++;x++;
    }
    while(j<size2){
        v[x]=p2[j];
        j++;x++;
    }
}
void mS(vector<ll> &v,ll start,ll end){
    if(start<end){
        ll mid=start+(end-start)/2;
        mS(v,start,mid);
        mS(v,mid+1,end);
        mergeArrays(v,start,mid,end);
    }
}
void MergeSort(vector<ll> &v){
    ll s=0;
    ll e=v.size()-1;
    mS(v,s,e);
}

void RandomInput(vector <ll>&v){
    ll n;
    cout<<"Enter no of elements : ";
    cin>>n;
    for(ll i=0;i<n;i++){
        ll d;
        //cin>>d;
        //random = offset + (rand() % range);
        d=0+(rand()%101);
        v.push_back(d);
    }
    
}

int main()
{
    vector<ll> v;
    RandomInput(v);
    MergeSort(v);
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
}
