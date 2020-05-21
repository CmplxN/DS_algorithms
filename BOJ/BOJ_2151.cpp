#include <bits/stdc++.h>
using namespace std;
typedef struct coord{
	int x,y,c,dir;
}coord;
bool operator<(coord a, coord b){
	return a.c>b.c;
}
priority_queue<coord> pq;
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,-1,1};
int n,visited[50][50][4],sx,sy;
bool found;
string field[50];
int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; ++i) cin >> field[i];
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			if (field[i][j] == '#' && !found) {
				sx = j;
				sy = i;
				found = true;
				for (int k = 0; k < 4; ++k) {
					pq.push({j, i, 0, k});
					visited[i][j][k] = 0;
				}
			} else
				for (int k = 0; k < 4; ++k)
					visited[i][j][k] = 999999999;
	while (!pq.empty()) {
		auto now = pq.top();
		pq.pop();
		if (field[now.y][now.x] == '#' && !(now.y == sy && now.x == sx)) {
			cout << now.c;
			break;
		}
		int nx = dx[now.dir] + now.x;
		int ny = dy[now.dir] + now.y;
		if (nx >= n || ny >= n || nx < 0 || ny < 0 || field[ny][nx] == '*' ||
		    visited[ny][nx][now.dir] <= now.c)
			continue;
		if (field[ny][nx] == '!') {
			if (now.dir > 1) {
				visited[ny][nx][0] = now.c;
				pq.push({nx, ny, now.c + 1, 0});
				visited[ny][nx][1] = now.c;
				pq.push({nx, ny, now.c + 1, 1});
			} else {
				visited[ny][nx][2] = now.c;
				pq.push({nx, ny, now.c + 1, 2});
				visited[ny][nx][3] = now.c;
				pq.push({nx, ny, now.c + 1, 3});
			}
		}
		visited[ny][nx][now.dir] = now.c;
		pq.push({nx, ny, now.c, now.dir});
	}
	return 0;
}
