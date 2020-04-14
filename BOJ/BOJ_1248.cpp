#include <bits/stdc++.h>
#define RANGE 21
using namespace std;
int n,candidate[RANGE],sum[11][11];
bool used[RANGE];
int ans[11];
string s;
bool check(int no,int loc){
	int temp = loc;
	for(int i=0;i<=loc;++i){
		if(i<loc){
			if(s[temp]=='-'&&sum[i][loc-1]+no>=0) return false;
			if(s[temp]=='+'&&sum[i][loc-1]+no<=0) return false;
			if(s[temp]=='0'&&sum[i][loc-1]+no!=0) return false;
			sum[i][loc]=sum[i][loc-1]+no;
		}else{
			if(s[temp]=='-'&&no>=0) return false;
			if(s[temp]=='+'&&no<=0) return false;
			if(s[temp]=='0'&&no!=0) return false;
			sum[loc][loc]=no;
		}
		temp+=n-i-1;
	}
	return true;
}
void dfs(int dep){
	if(dep==n){
		for(int i=0;i<n;++i) cout<<ans[i]<<' ';
		exit(0);
		return;
	}
	for(int i=0;i<RANGE;++i){
		ans[dep]=candidate[i];
		if(check(ans[dep],dep)) dfs(dep+1);
	}
}
int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);
	cin>>n>>s;
	for(int i=0;i<RANGE;++i) candidate[i]=i-10;
	dfs(0);
	return 0;
}
