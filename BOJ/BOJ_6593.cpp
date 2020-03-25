#include <bits/stdc++.h>
using namespace std;
typedef struct coord{
	int x,y,z;
}coord;
int l,r,c;
int dx[6]={0,0,0,0,-1,1};
int dy[6]={0,0,1,-1,0,0};
int dz[6]={-1,1,0,0,0,0};
int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);
	while (true) {
		cin >> l >> r >> c;
		if (l == 0 && r == 0 && c == 0) break;
		vector<vector<string>> v(l);
		for (int i = 0; i < l; ++i)
			for (int j = 0; j < r; ++j) {
				string s;
				cin >> s;
				v[i].push_back(s);
			}
		queue<coord> q;
		for (int i = 0; i < l; ++i)
			for (int j = 0; j < r; ++j)
				for (int k = 0; k < c; ++k)
					if (v[i][j][k] == 'S') {
						q.push({k, j, i});
						v[i][j][k] = '#';
					}
		int ans = 0;
		bool solved = false;
		while (true) {
			int size = q.size();
			ans++;
			while (size--) {
				coord now = q.front();
				if (v[now.z][now.y][now.x] == 'E') {
					solved = true;
					break;
				}
				q.pop();
				for (int i = 0; i < 6; ++i) {
					int nx = now.x + dx[i];
					int ny = now.y + dy[i];
					int nz = now.z + dz[i];
					if (nx < 0 || ny < 0 || nz < 0 || nx >= c || ny >= r || nz >= l || v[nz][ny][nx] == '#') continue;
					q.push({nx, ny, nz});
					if (v[nz][ny][nx] != 'E') v[nz][ny][nx] = '#';
				}
			}
			if (solved || q.empty()) break;
		}
		if (!solved) cout << "Trapped!\n";
		else cout << "Escaped in " << ans - 1 << " minute(s).\n";
	}
	return 0;
}
