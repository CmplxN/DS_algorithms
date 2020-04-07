#include <bits/stdc++.h>
using namespace std;
typedef struct info{
	int x,y,dir,floor;
}info;
int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);
	int n, k, r, c, dir;
	int dx[4] = {1, -1, 0, 0};
	int dy[4] = {0, 0, -1, 1};
	cin >> n >> k;
	int color[n][n];
	vector<pair<int, int>> map[n][n];
	vector<info> v;
	for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) cin >> color[i][j];
	for (int i = 0; i < k; ++i) {
		cin >> r >> c >> dir;
		map[r - 1][c - 1].emplace_back(i, dir - 1);
		v.push_back({c - 1, r - 1, dir - 1, 0});
	}
	int t = 0;
	while (t++ < 1000) {
		int idx = 0;
		for (auto it : v) {
			int nx = it.x + dx[it.dir];
			int ny = it.y + dy[it.dir];
			bool done = false;
			if (ny < 0 || nx < 0 || nx >= n || ny >= n) {
				if (it.dir == 0 || it.dir == 2) it.dir++;
				else it.dir--;
				v[idx].dir = it.dir;
				nx += 2 * dx[it.dir];
				ny += 2 * dy[it.dir];
				if (color[ny][nx] == 2) {
					done = true;
					nx -= dx[it.dir];
					ny -= dy[it.dir];
				}
			}
			if (!done && color[ny][nx] == 0) {
				int temp = map[it.y][it.x].size() - it.floor;
				int ox = it.x;
				int oy = it.y;
				for (int i = it.floor; i < map[oy][ox].size(); ++i) {
					map[ny][nx].emplace_back(map[oy][ox][i].first, v[map[oy][ox][i].first].dir);
					v[map[oy][ox][i].first].x = nx;
					v[map[oy][ox][i].first].y = ny;
					v[map[oy][ox][i].first].floor = map[ny][nx].size() - 1;
				}
				for (int i = 0; i < temp; ++i) map[oy][ox].pop_back();
			} else if (!done && color[ny][nx] == 1) {
				int temp = map[it.y][it.x].size() - it.floor;
				int save = it.floor;
				int ox = it.x;
				int oy = it.y;
				for (int i = map[oy][ox].size() - 1; i >= save; --i) {
					map[ny][nx].emplace_back(map[oy][ox][i].first, v[map[oy][ox][i].first].dir);
					v[map[oy][ox][i].first].x = nx;
					v[map[oy][ox][i].first].y = ny;
					v[map[oy][ox][i].first].floor = map[ny][nx].size() - 1;
				}
				for (int i = 0; i < temp; ++i) map[oy][ox].pop_back();
			} else if (!done) {
				int ox = it.x;
				int oy = it.y;
				bool out = false;
				if (it.dir == 0 || it.dir == 2) it.dir++;
				else it.dir--;
				v[idx].dir = it.dir;
				nx += 2 * dx[it.dir];
				ny += 2 * dy[it.dir];
				if (nx < 0 || ny < 0 || nx >= n || ny >= n || color[ny][nx] == 2) {
					out = true;
					nx -= dx[it.dir];
					ny -= dy[it.dir];
				}
				if (!out) {
					if (color[ny][nx] == 0) {
						int temp = map[oy][ox].size() - it.floor;
						for (int i = it.floor; i < map[oy][ox].size(); ++i) {
							map[ny][nx].emplace_back(map[oy][ox][i].first, v[map[oy][ox][i].first].dir);
							v[map[oy][ox][i].first].x = nx;
							v[map[oy][ox][i].first].y = ny;
							v[map[oy][ox][i].first].floor = map[ny][nx].size() - 1;
						}
						for (int i = 0; i < temp; ++i) map[oy][ox].pop_back();
					} else {
						int temp = map[it.y][it.x].size() - it.floor;
						int save = it.floor;
						int ox = it.x;
						int oy = it.y;
						for (int i = map[oy][ox].size() - 1; i >= save; --i) {
							map[ny][nx].emplace_back(map[oy][ox][i].first, v[map[oy][ox][i].first].dir);
							v[map[oy][ox][i].first].x = nx;
							v[map[oy][ox][i].first].y = ny;
							v[map[oy][ox][i].first].floor = map[ny][nx].size() - 1;
						}
						for (int i = 0; i < temp; ++i) map[oy][ox].pop_back();
					}
				}
			}
			if (map[ny][nx].size() >= 4) {
				cout << t;
				return 0;
			}
			idx++;
		}
	}
	cout << -1;
	return 0;
}
