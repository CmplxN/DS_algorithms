#include <bits/stdc++.h>
using namespace std;
typedef struct info{
	int x,y,c,l;
}info;
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
bool visited[1001][1001][11];
vector<string> v;
int main(){
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);
	int n,m,k;
	string s;
	cin>>n>>m>>k;
	for(int i=0;i<n;++i){
		cin>>s;
		v.push_back(s);
	}
	queue<info> q;
	q.push({0,0,k,0});
	visited[0][0][k]=true;
	while(!q.empty()){
		info now = q.front();
		bool stay = false;
		if(now.x==m-1&&now.y==n-1){
			break;
		}
		q.pop();
		for(int i=0;i<4;++i){
			int nx=now.x+dx[i];
			int ny=now.y+dy[i];
			if(nx>-1&&ny>-1&&nx<m&&ny<n){
				if(v[ny][nx]=='0'&&!visited[ny][nx][now.c]){
					visited[ny][nx][now.c]=true;
					q.push({nx,ny,now.c,now.l+1});
				}
				if(v[ny][nx]=='1'&&now.c>=1&&!visited[ny][nx][now.c-1]&&now.l%2==0){
					visited[ny][nx][now.c-1]=true;
					q.push({nx,ny,now.c-1,now.l+1});
				}
				if(v[ny][nx]=='1'&&now.c>=1&&!visited[ny][nx][now.c-1]&&now.l%2==1&&!stay){
					q.push({now.x,now.y,now.c,now.l+1});
					stay=true;
				}
			}
		}
	}
	if(q.empty()) cout<<-1;
	else cout<<q.front().l+1;
	return 0;
}
