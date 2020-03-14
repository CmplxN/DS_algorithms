#include <bits/stdc++.h>
using namespace std;
typedef struct coord{
	int x,y;
}coord;
vector<coord> v,e;
int lab[9][9],temp[9][9];
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);
	int n,m,safe=0,ans=0;
	cin>>n>>m;
	for(int i=0;i<n;++i) for(int j=0;j<m;++j){
		cin>>lab[i][j];
		if(lab[i][j]==2) v.push_back({j,i});
		if(lab[i][j]==0){
			e.push_back({j,i});
			safe++;
		}
	}
	for(int i=0;i<e.size()-2;++i){
		for(int j=i+1;j<e.size()-1;++j){
			for(int k=j+1;k<e.size();++k){
				memcpy(temp,lab,sizeof(lab));
				temp[e[i].y][e[i].x]=1;
				temp[e[j].y][e[j].x]=1;
				temp[e[k].y][e[k].x]=1;
				queue<coord> q;
				int tr=3;
				for(auto & l : v) q.push({l.x,l.y});
				while(!q.empty()){
					coord now = q.front();
					q.pop();
					for(int h=0;h<4;++h){
						int nx=now.x+dx[h];
						int ny=now.y+dy[h];
						if(nx<0||ny<0||nx>=m||ny>=n||temp[ny][nx]!=0) continue;
						tr++;
						temp[ny][nx]=1;
						q.push({nx,ny});
					}
				}
				ans=ans>safe-tr?ans:safe-tr;
			}
		}
	}
	cout<<ans;
	return 0;
}
