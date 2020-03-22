#include <bits/stdc++.h>
using namespace std;
#define MAX 100001
int cnt, T, N, M;
vector<bool> visited;
vector<int> v[MAX];
stack<int> stk;
void dfs(int no, bool mode) {
	visited[no] = true;
	for (int now : v[no]) {
		if (visited[now]) continue;
		dfs(now, mode);
	}
	if (mode) stk.push(no);
}
int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);
	cin >> T;
	while(T--) {
		cin >> N >> M;
		cnt = 0;
		visited = vector<bool>(N + 1, false);
		stk = stack<int>();
		for (auto & i : v) i.clear();
		for (int i = 0; i < M; ++i) {
			int a, b;
			cin >> a >> b;
			v[a].push_back(b);
		}
		for (int i = 1; i <= N; ++i) if (!visited[i]) dfs(i,true);
		visited.clear();
		visited = vector<bool>(N + 1, false);
		while (!stk.empty()) {
			int now = stk.top();
			stk.pop();
			if (visited[now]) continue;
			dfs(now,false);
			cnt++;
		}
		cout << cnt << '\n';
	}
	return 0;
}
