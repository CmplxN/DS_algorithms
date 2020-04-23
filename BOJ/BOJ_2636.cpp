#include <bits/stdc++.h>
using namespace std;
int dx[4]={1,-1,0,0};
int dy[4]={0,0,-1,1};
int r, c, field[100][100], save[100][100], t, pre;
int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);
	cin >> r >> c;
	for (int i = 0; i < r; ++i) for (int j = 0; j < c; ++j) cin >> field[i][j];
	while (true) {
		memset(save, 0, sizeof(save));
		queue<pair<int, int>> q;
		q.push({0, 0});
		save[0][0] = 1;
		while (!q.empty()) {
			auto now = q.front();
			q.pop();
			for (int i = 0; i < 4; ++i) {
				int nx = now.first + dx[i];
				int ny = now.second + dy[i];
				if (nx < 0 || ny < 0 || nx >= c || ny >= r || save[ny][nx]) continue;
				if (field[ny][nx] != 0) {
					field[ny][nx]++;
					continue;
				}
				q.push({nx, ny});
				save[ny][nx] = 1;
			}
		}
		int cnt = 0;
		for (int i = 0; i < r; ++i)
			for (int j = 0; j < c; ++j) {
				if (field[i][j] > 1) {
					cnt++;
					field[i][j] = 0;
				}
			}
		if (cnt == 0) break;
		t++;
		pre = cnt;
	}
	cout << t << '\n' << pre;
	return 0;
}
