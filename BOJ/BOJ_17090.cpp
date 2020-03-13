#include <bits/stdc++.h>
using namespace std;
int n,m,maze[501][501],visited[501][501],ans;
int dy[4]={-1,0,1,0};
int dx[4]={0,1,0,-1};
int dfs(int x, int y){
	if(x<0||y<0||x>=m||y>=n) return 1;
	if(visited[y][x] != -1) return visited[y][x];
	visited[y][x]=0;
	int nx = dx[maze[y][x]] + x;
	int ny = dy[maze[y][x]] + y;
	return (visited[y][x] = visited[y][x] + dfs(nx,ny));
}
int main(){
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);
	string s;
	cin>>n>>m;
	for(int i=0;i<n;++i){
		cin>>s;
		for(int j=0;j<m;++j){
			if(s[j]=='U') maze[i][j]=0;
			else if(s[j]=='R') maze[i][j]=1;
			else if(s[j]=='D') maze[i][j]=2;
			else if(s[j]=='L') maze[i][j]=3;
			visited[i][j]=-1;
		}
	}
	for(int i=0;i<n;++i) for(int j=0;j<m;++j) ans+=dfs(j,i);
	cout<<ans;
	return 0;
}
