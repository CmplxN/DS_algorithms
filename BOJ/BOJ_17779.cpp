#include <bits/stdc++.h>
using namespace std;
int n,field[20][20],naming[20][20],visited[20][20],ans=2147483647;
int dx[4]={-1,1,0,0};
int dy[4]={0,0,1,-1};
void dfs(int x, int y, int no){
	naming[y][x]=no;
	visited[y][x]=no;
	for(int i=0;i<4;++i){
		int nx=x+dx[i];
		int ny=y+dy[i];
		if(nx<0||ny<0||nx>=n||ny>=n||naming[ny][nx]!=0) continue;
		dfs(nx,ny,no);
	}
}
int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);
	cin>>n;
	for(int i=0;i<n;++i) for(int j=0;j<n;++j) cin>>field[i][j];
	for(int i=0;i<n;++i) for(int j=0;j<n;++j) for(int d1=1;i-d1>=0;++d1) for(int d2=1;i+d2<n&&j+d1+d2<n;++d2){
		memset(naming,0,sizeof(naming));
		memset(visited,0,sizeof(visited));
		for(int l=0;l<=d1;++l) naming[i-l][j+l]=5;
		for(int l=1;l<=d2;++l) naming[i+l][j+l]=5;
		for(int l=1;l<=d2;++l) naming[i+l-d1][j+l+d1]=5;
		for(int l=1;l<d1;++l) naming[i-l+d2][j+l+d2]=5;
		for(int l=i-d1-1;l>=0;--l) naming[l][j+d1]=1;
		for(int l=i+d2+1;l<n;++l) naming[l][j+d2]=4;
		for(int l=j-1;l>=0;--l) naming[i][l]=3;
		for(int l=j+d1+d2+1;l<n;++l) naming[i+d2-d1][l]=2;
		dfs(j,i+1,3);
		dfs(j,i-1,1);
		dfs(j+d1+d2,i+1+d2-d1,4);
		dfs(j+d1+d2,i-1+d2-d1,2);
		int sum[5]={0,0,0,0,0};
		for(int y=0;y<n;++y) for(int x=0;x<n;++x){
			if(naming[y][x]==0) naming[y][x]=5;
			sum[naming[y][x]-1]+=field[y][x];
		}
		ans=min(ans,*max_element(sum,sum+5)-*min_element(sum,sum+5));
	}
	cout<<ans;
	return 0;
}
