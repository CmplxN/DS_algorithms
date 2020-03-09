#include <bits/stdc++.h>
using namespace std;
int n,m[12][12],visited[12][12],ans[2],wb[12][12];
bool check(int x, int y){
	int i=1;
	while(x-i>=0&&y-i>=0){
		if(visited[y-i][x-i]) return false;
		i++;
	}
	i=1;
	while(x+i<n&&y-i>=0){
		if(visited[y-i][x+i]) return false;
		i++;
	}
	return true;
}
int dfs(int x, int y, int no, int w){
	int rtn=0;
	if(!check(x,y)) return no;
	int nx=x;
	int ny=y;
	visited[y][x]=true;
	while(nx!=0||ny!=n){
		if(m[ny][nx]==1&&(nx!=x||ny!=y)&&wb[ny][nx]==w) rtn=max(rtn,dfs(nx,ny,no+1,w));
		if(nx==n-1){
			nx=0;
			ny++;
		}
		else nx++;
	}
	visited[y][x]=false;
	if(rtn==0) return no+1;
	return rtn;
}
int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);
	cin>>n;
	for(int i=0;i<12;i++) for(int j=0;j<12;++j) wb[i][j]=(i+j)%2;
	for(int i=0;i<n;++i) for(int j=0;j<n;++j) cin>>m[i][j];
	for(int i=0;i<n;++i) for(int j=0;j<n;++j) if(m[i][j]==1&&wb[i][j]==0) ans[0]=max(ans[0],dfs(j,i,0,0));
	for(int i=0;i<n;++i) for(int j=0;j<n;++j) if(m[i][j]==1&&wb[i][j]==1) ans[1]=max(ans[1],dfs(j,i,0,1));
	cout<<ans[0]+ans[1];
	return 0;
}
