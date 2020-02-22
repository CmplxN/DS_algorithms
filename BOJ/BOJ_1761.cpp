#include <bits/stdc++.h>
using namespace std;
vector<pair<int,int>> v[40001];
int visited[40001];
int dp[17][40001];
int dpp[17][40001];
int depth[40001];
void swap(int *a, int *b){
	int temp = *a;
	*a=*b;
	*b=temp;
}
void dfs(int dep, int node){
	visited[node]=true;
	depth[node]=dep;
	for(auto &a : v[node]){
		if(visited[a.first])
			continue;
		dp[0][a.first]=node;
		dpp[0][a.first]=a.second;
		dfs(dep+1,a.first);
	}
}
int solve(int a, int b){
	int rtn = 0;
	if(depth[a] > depth[b])//b가 더 깊은 녀석
		swap(&a,&b);
	if(depth[a] != depth[b]) {
		for (int i = 16; i >= 0; --i) {
			if (depth[dp[i][b]] >= depth[a]) {//깊이 영은 없다.
				rtn += dpp[i][b];
				b = dp[i][b];
			}
		}
	}
	if(a==b)
		return rtn;
	for(int i=16;i>=0;--i){
		if(dp[i][b] != dp[i][a]){
			rtn+=(dpp[i][b]+dpp[i][a]);
			b=dp[i][b];
			a=dp[i][a];
		}
	}
	rtn+=(dpp[0][b]+dpp[0][a]);
	return rtn;
}
int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);
	int n,m,a,b,c;
	cin>>n;
	for(int i=0;i<n-1;++i){
		cin>>a>>b>>c;
		v[a].emplace_back(b,c);
		v[b].emplace_back(a,c);
	}
	dfs(0,1);
	for(int i=1;i<17;++i) {
		for (int j = 1; j < n + 1; ++j) {
			dp[i][j] = dp[i - 1][dp[i - 1][j]];
			dpp[i][j] = dpp[i - 1][dp[i - 1][j]] + dpp[i - 1][j];
		}
	}
	cin>>m;
	for(int i=0;i<m;++i){
		cin>>a>>b;
		cout<<solve(a,b)<<'\n';
	}
	return 0;
}
