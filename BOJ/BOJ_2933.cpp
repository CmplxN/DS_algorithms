#include <bits/stdc++.h>
using namespace std;
char cave[101][101];
int visited[101][101];
int r,c,n,input,mod,lowy[101];
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
bool dfs(int x, int y){
	if(lowy[x]<y) lowy[x]=y;
	visited[y][x]=1;
	if(y==r-1) return true;
	bool rtn=false;
	for(int i=0;i<4;++i){
		int nx=x+dx[i];
		int ny=y+dy[i];
		if(ny<0||nx<0||ny>=r||nx>=c||cave[ny][nx]=='.'||visited[ny][nx]) continue;
		rtn=rtn||dfs(nx,ny);
	}
	return rtn;
}
int mdfs(int x, int y){
	visited[y][x]++;
	int rtn=2147483647, ty=y+1;
	while(ty<r&&(cave[ty][x]=='.'||visited[ty][x]!=0)) ty++;
	if(ty!=y) rtn=ty-y-1;
	for(int i=0;i<4;++i){
		int nx=x+dx[i];
		int ny=y+dy[i];
		if(ny<0||nx<0||ny>=r||nx>=c||visited[ny][nx]!=1) continue;
		rtn=min(rtn,mdfs(nx,ny));
	}
	return rtn;
}
void grav(int min){
	for(int i=0;i<c;++i) {
		if (lowy[i] != -1) {
			int h = r;
			while (h != -1) if (visited[h][i]) break; else h--;
			for (; h != -1; --h) {
				if(visited[h][i]==0) continue;
				char temp = cave[h][i];
				cave[h][i] = '.';
				cave[h + min][i] = temp;
			}
		}
	}
}
int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);
	cin>>r>>c;
	for(int i=0;i<r;++i) for(int j=0;j<c;++j) cin>>cave[i][j];
	cin>>n;
	for(int i=0;i<n;++i,mod=(mod+1)%2){
		int j;
		cin>>input;
		if(i%2){for(j=c-1;j>=0;--j) if(cave[r-input][j]=='x') {cave[r-input][j]='.'; break;}}
		else{for(j=0;j<c;++j) if(cave[r-input][j]=='x') {cave[r-input][j]='.'; break;}}
		for(int k=0;k<4;++k){
			if(mod==k) continue;
			int nx=j+dx[k];
			int ny=r-input+dy[k];
			if(ny<0||nx<0||ny>=r||nx>=c||cave[r-input][j]=='x') continue;
			if(cave[ny][nx]=='.') continue;
			memset(visited,false,sizeof(visited));
			memset(lowy, -1, sizeof(lowy));
			if(dfs(nx,ny)) continue;
			grav(mdfs(nx,ny));
		}
	}
	for(int i=0;i<r;++i){
		for(int j=0;j<c;++j) cout<<cave[i][j];
		cout<<'\n';
	}
	return 0;
}
