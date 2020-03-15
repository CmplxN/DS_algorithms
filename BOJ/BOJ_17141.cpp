#include <bits/stdc++.h>
using namespace std;
typedef struct coord{
	int x,y;
}coord;
vector<coord> v;
vector<bool> bv;
int lab[51][51],temp[51][51],n,m,safe,ans=999999999;
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
void    solve(){
	int infect=safe,t=-1;
	memcpy(temp, lab, sizeof(lab));
	queue<coord> q;
	for(int i=0;i<bv.size();++i) if(bv[i]){
		infect--;
		temp[v[i].y][v[i].x]=1;
		q.push(v[i]);
	}
	while(true){
		int size = q.size();
		while(size--){
			coord now=q.front();
			q.pop();
			for(int i=0;i<4;++i){
				int nx=now.x+dx[i];
				int ny=now.y+dy[i];
				if(nx<0||ny<0||nx>=n||ny>=n||temp[ny][nx]!=0) continue;
				temp[ny][nx]=1;
				infect--;
				q.push({nx,ny});
			}
		}
		t++;
		if(q.empty()) break;
	}
	if(infect==0) ans=min(ans,t);
}
void    select(int s, int d){
	if(d==m){
		solve();
		return;
	}
	for(int i=s;i<bv.size();++i){
		bv[i]=true;
		select(i+1,d+1);
		bv[i]=false;
	}
}
int     main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=0;i<n;++i) for(int j=0;j<n;++j){
			cin>>lab[i][j];
			if(lab[i][j]==2){
				lab[i][j]=0;
				v.push_back({j,i});
				bv.push_back(false);
			}
			if(lab[i][j]==1) lab[i][j]=-1;
			else safe++;
		}
	select(0,0);
	if(ans==999999999) ans=-1;
	cout<<ans;
	return 0;
}
