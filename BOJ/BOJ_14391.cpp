#include <bits/stdc++.h>
using namespace std;
int n,m;
string s[4];
bool used[4][4];
int dfs(int x, int y, int no){
	if(no == n*m) return 0;
	int rtn = 0;
	int cur = 0;
	int i;
	for(i=0;i<n;++i){
		if(y+i>=n||used[y+i][x]) break;
		cur *= 10;
		cur += s[y+i][x]-'0';
		used[y+i][x]=true;
		bool out = false;
		for(int k=0;k<n;++k){
			for(int l=0;l<m;++l){
				if(!used[k][l]){
					rtn=max(rtn,dfs(l,k,no+i+1)+cur);
					out = true;
					break;
				}
			}
			if(out) break;
		}
		if(!out) rtn=max(rtn,dfs(0,0,no+i+1)+cur);
	}
	for(int j=0;j<i;++j){
		used[y+j][x]=false;
	}
	cur=0;
	for(i=0;i<m;++i){
		if(x+i>=m||used[y][x+i]) break;
		cur *= 10;
		cur += s[y][x+i]-'0';
		used[y][x+i]=true;
		bool out = false;
		for(int k=0;k<n;++k){
			for(int l=0;l<m;++l){
				if(!used[k][l]){
					rtn=max(rtn,dfs(l,k,no+i+1)+cur);
					out = true;
					break;
				}
			}
			if(out) break;
		}
		if(!out) rtn=max(rtn,dfs(0,0,no+i+1)+cur);
	}
	for(int j=0;j<i;++j){
		used[y][x+j]=false;
	}
	return rtn;
}
int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=0;i<n;++i) cin>>s[i];
	cout<<dfs(0,0,0);
	return 0;
}
