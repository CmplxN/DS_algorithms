#include <bits/stdc++.h>
using namespace std;
typedef struct coord {
	int x, y, z;
} coord;
bool visited[5][5][5];
int cand[5][4][5][5];
int perm[5] = {0, 1, 2, 3, 4};
int dx[6] = {1, -1, 0, 0, 0, 0};
int dy[6] = {0, 0, 1, -1, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};
int ans = 2147483647;
void rotate(int n, int r) {
	int temp = r;
	auto &s = cand[n];
	memcpy(s[r], s[0], sizeof(s[0]));
	while (temp--) {
		for(int j=0;j<4;++j) {
			int t = s[r][0][0];
			for (int i = 0; i < 4; ++i) s[r][i][0] = s[r][i + 1][0];
			for (int i = 0; i < 4; ++i) s[r][4][i] = s[r][4][i + 1];
			for (int i = 0; i < 4; ++i) s[r][4 - i][4] = s[r][4 - i - 1][4];
			for (int i = 0; i < 4; ++i) s[r][0][4 - i] = s[r][0][4 - i - 1];
			s[r][0][1] = t;
		}
		for(int j=0;j<2;++j) {
			int t = s[r][1][1];
			for (int i = 0; i < 2; ++i) s[r][i + 1][1] = s[r][i + 2][1];
			for (int i = 0; i < 2; ++i) s[r][3][i + 1] = s[r][3][i + 2];
			for (int i = 0; i < 2; ++i) s[r][3 - i][3] = s[r][2 - i][3];
			for (int i = 0; i < 2; ++i) s[r][1][3 - i] = s[r][1][2 - i];
			s[r][1][2] = t;
		}
	}
}
void bfs(int map[5][5][5]) {
	if (map[0][0][0] == 0) return;
	bool solved = false;
	int t = 0;
	queue<coord> q;
	visited[0][0][0] = true;
	q.push({0, 0, 0});
	memset(visited, false, sizeof(visited));
	while (true) {
		int size = q.size();
		while (size--) {
			coord now = q.front();
			if (now.x == 4 && now.y == 4 && now.z == 4) {
				solved = true;
				break;
			}
			q.pop();
			for (int i = 0; i < 6; ++i) {
				int nx = now.x + dx[i];
				int ny = now.y + dy[i];
				int nz = now.z + dz[i];
				if (nx < 0 || ny < 0 || nz < 0 || nx > 4 || ny > 4 || nz > 4 || visited[nz][ny][nx] ||
				    map[nz][ny][nx] == 0)
					continue;
				visited[nz][ny][nx] = true;
				q.push({nx, ny, nz});
			}
		}
		if (q.empty() || solved) break;
		t++;
	}
	if (solved) ans = min(ans, t);
}
void select() {
	int map[5][5][5];
	for (int a = 0; a < 4; ++a) {
		memcpy(map[0], cand[perm[0]][a], sizeof(cand[perm[0]][a]));
		for (int b = 0; b < 4; ++b) {
			memcpy(map[1], cand[perm[1]][b], sizeof(cand[perm[1]][b]));
			for (int c = 0; c < 4; ++c) {
				memcpy(map[2], cand[perm[2]][c], sizeof(cand[perm[2]][c]));
				for (int d = 0; d < 4; ++d) {
					memcpy(map[3], cand[perm[3]][d], sizeof(cand[perm[3]][d]));
					for (int e = 0; e < 4; ++e) {
						memcpy(map[4], cand[perm[4]][e], sizeof(cand[perm[4]][e]));
						bfs(map);
					}
				}
			}
		}
	}
}
int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);
	for (auto &n : cand) for (int j = 0; j < 5; ++j) for (int k = 0; k < 5; ++k) cin >> n[0][j][k];
	for (int i = 0; i < 5; ++i) for (int j = 1; j < 4; ++j) rotate(i, j);
	do {
		select();
	} while (next_permutation(perm, perm + 5));
	if (ans == 2147483647) ans = -1;
	cout << ans;
	return 0;
}
