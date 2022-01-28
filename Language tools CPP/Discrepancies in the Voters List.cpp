//https://www.codechef.com/problems/VOTERS
#include <iostream>
#include<map>
#include<vector>
using namespace std;

int main() {
	int n1,n2,n3;
	cin>>n1>>n2>>n3;
	
	vector<int> arr1;
	vector<int> arr2;
	vector<int> arr3;
	
	map<int,int> mp;
	
	for(int i=0;i<n1;i++){
		int d;
		cin>>d;
		arr1.push_back(d);
		mp[arr1[i]]++;
	}
	for(int i=0;i<n2;i++){
		int d;
		cin>>d;
		arr2.push_back(d);
		mp[arr2[i]]++;
	}
	for(int i=0;i<n3;i++){
		int d;
		cin>>d;
		arr3.push_back(d);
		mp[arr3[i]]++;
	}
	
	
	vector<int> res;
	for(auto i:mp){
		if(i.second>=2){
			res.push_back(i.first);
		}
	}
	
	cout<<res.size()<<endl;
	for(int i=0;i<res.size();i++){
		cout<<res[i]<<endl;
	}
}
