#include <bits/stdc++.h>
#define MAX 99999999
using namespace std;
typedef struct info{
	int a,b,c;
}info;
vector<info> v;
vector<int> vv;
vector<bool> visited;
bool next_loop;
int T,n,m,w,s,e,t;
int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base :: sync_with_stdio(false);
	cin>>T;
	while(T--){
		next_loop=false;
		v.clear();
		vv.clear();
		visited.clear();
		cin>>n>>m>>w;
		for(int i=0;i<n;++i){
			visited.push_back(false);
			vv.push_back(MAX);
		}
		for(int i=0;i<m;++i){
			cin>>s>>e>>t;
			v.push_back({s-1,e-1,t});
			v.push_back({e-1,s-1,t});
		}
		for(int i=0;i<w;++i){
			cin>>s>>e>>t;
			t = t * -1;
			v.push_back({s-1,e-1,t});
		}
		for(int z=0;z<n;++z){
			if(visited[z]) continue;
			vv[z]=0;
			for(int i=0;i<n-1;++i){
				for(auto & j : v){
					if(vv[j.a] == MAX) continue;
					if(vv[j.b]>vv[j.a]+j.c)
						vv[j.b] = vv[j.a] + j.c;
				}
			}
			for(auto & j : v) {
				if(vv[j.a] == MAX) continue;
				if (vv[j.b] > vv[j.a] + j.c) {
					cout << "YES\n";
					next_loop = true;
					break;
				}
				else visited[j.a]=true;
			}
			if(next_loop) break;
			vv[z]=MAX;
		}
		if(!next_loop) cout<<"NO\n";
	}
	return 0;
}
