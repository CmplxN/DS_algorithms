#include <bits/stdc++.h>
using namespace std;
int dx[4]={0,0,-1,1};
int dy[4]={-1,1,0,0};
bool visited[125][125];
int Map[125][125];
typedef struct info{
	int x,y,n;
}info;
bool operator<(info a, info b){
	return a.n>=b.n;
}
int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);
	int T = 1;
	while (true) {
		int n;
		cin >> n;
		if (n == 0) return 0;
		memset(visited, false, sizeof(visited));
		for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) cin >> Map[i][j];
		priority_queue<info> pq;
		pq.push({0, 0, Map[0][0]});
		visited[0][0] = true;
		while (!pq.empty()) {
			info now = pq.top();
			if (now.x == n - 1 && now.y == n - 1) {
				cout << "Problem " << T++ << ": " << now.n << '\n';
				break;
			}
			pq.pop();
			for (int i = 0; i < 4; ++i) {
				int nx = now.x + dx[i];
				int ny = now.y + dy[i];
				if (nx < 0 || ny < 0 || nx >= n || ny >= n || visited[ny][nx]) continue;
				visited[ny][nx] = true;
				pq.push({nx, ny, now.n + Map[ny][nx]});
			}
		}
	}
}
