#include <bits/stdc++.h>
using namespace std;
#define MAX 10001
bool operator<(vector<int> v1, vector<int> v2){
	return v1[0]<v2[0];
}
int cnt,V,E;
vector<int> scc[MAX];
vector<bool> visited;
vector<int> dv[MAX],rv[MAX];
stack<int> stk;
void dfs(int no) {
	visited[no] = true;
	for (int now : dv[no]) {
		if (visited[now]) continue;
		dfs(now);
	}
	stk.push(no);
}
void rdfs(int no) {
	visited[no] = true;
	for (int now : rv[no]) {
		if (visited[now]) continue;
		rdfs(now);
	}
	scc[cnt].push_back(no);
}
int main() {
	cin>>V>>E;
	visited = vector<bool> (V + 1, false);
	for (int i = 0; i < E; ++i) {
		int a, b;
		cin>>a>>b;
		dv[a].push_back(b);
		rv[b].push_back(a);
	}
	for(int i = 1 ; i <= V ; ++i) if(!visited[i]) dfs(i);
	visited.clear();
	visited = vector<bool>(V + 1, false);
	while (!stk.empty()) {
		int now = stk.top();
		stk.pop();
		if (visited[now]) continue;
		rdfs(now);
		cnt++;
	}
	cout << cnt << '\n';
	for (int i = 0; i < cnt; ++i) sort(scc[i].begin(), scc[i].end());
	sort(scc, scc+cnt);
	for (int i = 0; i < cnt; ++i){
		for(int j : scc[i]) cout<<j<<' ';
		cout<<-1<<'\n';
	}
	return 0;
}
