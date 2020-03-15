#include <bits/stdc++.h>
using namespace std;
int n,m,input;
vector<int> v;
bool check(int M){
	int cnt=1,maxi=v[0],mini=v[0];
	for(int i : v){
		maxi=max(i,maxi);
		mini=min(i,mini);
		if(maxi-mini>M){
			cnt++;
			maxi=i;
			mini=i;
		}
	}
	return cnt<=m;
}
int main(){
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=0;i<n;++i){
		cin>>input;
		v.push_back(input);
	}
	int l=0;
	int r=*max_element(v.begin(),v.end());
	while(l<=r){
		int mid=(l+r)/2;
		if(check(mid))
			r=mid-1;
		else l=mid+1;
	}
	cout<<r+1;
	return 0;
}
