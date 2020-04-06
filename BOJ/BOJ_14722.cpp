#include <bits/stdc++.h>
using namespace std;
int n,dp[1111][1111][3];
int dx[2]={1,0};
int dy[2]={0,1};
int v[1111][1111];
int dfs(int x,int y,int status){
	if(x==n-1&&y==n-1){
		if(v[y][x]==(status+1)%3) return 1;
		else return 0;
	}
	if(dp[y][x][status]!=-1) return dp[y][x][status];
	dp[y][x][status]=0;
	for(int i=0;i<2;++i){
		int nx = dx[i]+x;
		int ny = dy[i]+y;
		if(nx<0||ny<0||nx>=n||ny>=n) continue;
		if(v[ny][nx]==(status+1)%3) dp[y][x][status]=max(dp[y][x][status],dfs(nx,ny,(status+1)%3)+1);
		dp[y][x][status]=max(dp[y][x][status],dfs(nx,ny,status));
	}
	return dp[y][x][status];
}
int main(){
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);
	cin>>n;
	for(int i=0;i<n;++i) for(int j=0;j<n;++j) cin>>v[i][j];
	memset(dp,-1,sizeof(dp));
	if(v[0][0]!=0) cout<<dfs(0,0,2);
	else cout<<dfs(0,0,0)+1;
	return 0;
}
