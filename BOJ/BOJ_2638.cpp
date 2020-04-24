#include <bits/stdc++.h>
using namespace std;
int r,c,t,field[100][100];
bool visited[100][100];
int dx[4]={1,-1,0,0};
int dy[4]={0,0,-1,1};
int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);
	cin>>r>>c;
	for(int i=0;i<r;++i) for(int j=0;j<c;++j) cin>>field[i][j];
	while(true){
		queue<pair<int,int>> q;
		map<pair<int,int>,int> mp;
		memset(visited,false,sizeof(visited));
		q.emplace(0,0);
		visited[0][0]=true;
		while(!q.empty()){
			auto now = q.front();
			q.pop();
			for(int i=0;i<4;++i){
				int nx = now.first + dx[i];
				int ny = now.second + dy[i];
				if(nx<0||ny<0||nx>=c||ny>=r) continue;
				if(field[ny][nx]==0){
					if(!visited[ny][nx]){
						q.emplace(nx,ny);
						visited[ny][nx] = true;
					}
					continue;
				}
				if(mp.find(make_pair(nx,ny))==mp.end()) mp[make_pair(nx,ny)]=1;
				else mp[make_pair(nx,ny)]++;
			}
		}
		bool out = true;
		for(auto it : mp)
			if(it.second>=2){
				field[it.first.second][it.first.first]=0;
				out = false;
			}
		if(out) break;
		t++;
	}
	cout<<t;
	return 0;
}
