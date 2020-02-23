#include <bits/stdc++.h>
using namespace std;
typedef struct info{
	string s;
	int idx;
}info;
vector<string> vs;
vector<info> v;
string s;
int tree[444444],n;
long long int ans;
bool compare(info a, info b){
	return a.s<b.s;
}
long long int solve(int l, int r){
	long long int rtn = 0;
	while(l<=r){
		if(l%2==1)
			rtn+=tree[l];
		if(r%2==0)
			rtn+=tree[r];
		l=(l+1)/2;
		r=(r-1)/2;
	}
	return rtn;
}
void update(int idx){
	while(idx > 0){
		tree[idx]++;
		idx = idx / 2;
	}
}
int main(){
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);
	cin>>n;
	int var=n-1;
	int log=0;
	while(var){
		var/=2;
		log++;
	}
	var=pow(2,log);
	for(int i=0;i<n;++i){
		cin>>s;
		vs.push_back(s);
	}
	sort(vs.begin(),vs.end());
	for(int i=0;i<n;++i){
		string temp = vs[i];
		reverse(temp.begin(),temp.end());
		v.push_back({temp,i});
	}
	sort(v.begin(),v.end(),compare);
	for(int i=0;i<n;++i){
		ans+=solve(var+v[i].idx,2*var-1);
		update(var+v[i].idx);
	}
	cout<<ans;
	return 0;
}
