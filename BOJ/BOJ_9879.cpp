#include <bits/stdc++.h>

using namespace std;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int n, m, sx, sy, field[500][500], visited[500][500], waypoint[500][500];
queue<pair<int, int>> q;

bool check(int d) {
	memset(visited, false, sizeof(visited));
	q.emplace(sx, sy);
	visited[sy][sx] = true;
	while (!q.empty()) {
		auto now = q.front();
		q.pop();
		for (int i = 0; i < 4; ++i) {
			int nx = now.first + dx[i];
			int ny = now.second + dy[i];
			if (nx < 0 || ny < 0 || nx >= m || ny >= n || visited[ny][nx] ||
			    abs(field[now.second][now.first] - field[ny][nx]) > d)
				continue;
			q.emplace(nx, ny);
			visited[ny][nx] = true;
		}
	}
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			if (waypoint[i][j] == 1 && !visited[i][j])
				return false;

	return true;
}

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) cin >> field[i][j];
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j) {
			cin >> waypoint[i][j];
			if (waypoint[i][j] == 1) {
				sx = j;
				sy = i;
			}
		}
	int ans = 0;
	int min = 0;
	int max = 1000000000;
	while (min < max) {
		int mid = (min + max) / 2;
		if (check(mid)) {
			ans = mid;
			max = mid;
		} else min = mid + 1;
	}
	cout << ans;
}
