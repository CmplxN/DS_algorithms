#include <bits/stdc++.h>
using namespace std;
typedef struct {
	int x,y,b;
}coord;
int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);
	char mapp[20][20];
	bool visited[20][20][1024];
	int w,h;
	int dx[4]={1,-1,0,0};
	int dy[4]={0,0,1,-1};
	while(true){
		cin>>w>>h;
		if(w==0&&h==0) break;
		queue<coord> q;
		map<pair<int,int>,int> mapper;
		int dirty=0,t=-1,db=0;
		bool solved=false;
		memset(visited,false,sizeof(visited));
		for(int i=0;i<h;++i) for(int j=0;j<w;++j){
			cin >> mapp[i][j];
			if(mapp[i][j] == 'o') q.push({j,i,0});
			if(mapp[i][j] == '*'){
				mapper[make_pair(j,i)]=dirty;
				db+=1<<dirty++;
			}
		}
		while(true){
			int size=q.size();
			while(size--){
				coord now=q.front();
				if(now.b==db){
					solved=true;
					break;
				}
				q.pop();
				for(int i=0;i<4;++i){
					int nx=now.x+dx[i];
					int ny=now.y+dy[i];
					if(nx<0||ny<0||nx>=w||ny>=h||mapp[ny][nx]=='x') continue;
					if(visited[ny][nx][now.b]) continue;
					if(mapp[ny][nx]=='*'&&visited[ny][nx][now.b|(1<<mapper[make_pair(nx,ny)])]) continue;
					if((now.b&(1<<mapper[make_pair(nx,ny)]))==0&&mapp[ny][nx]=='*'){
						visited[ny][nx][now.b|(1<<mapper[make_pair(nx,ny)])]=true;
						q.push({nx,ny,now.b|(1<<mapper[make_pair(nx,ny)])});
					}
					else{
						visited[ny][nx][now.b]=true;
						q.push({nx,ny,now.b});
					}
				}
			}
			t++;
			if(solved||q.empty()) break;
		}
		if(solved) cout<<t<<'\n';
		else cout<<-1<<'\n';
	}
	return 0;
}
