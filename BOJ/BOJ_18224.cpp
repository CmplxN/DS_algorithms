#include <bits/stdc++.h>
using namespace std;
typedef struct info {
	int x,y,t;
}info;
int n,m,field[500][500];
bool visited[500][500][10][2];
int dx[4]={1,-1,0,0};
int dy[4]={0,0,-1,1};
queue<info> q;
int main() {
	scanf("%d %d",&n,&m);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			scanf("%d",&field[i][j]);
	q.push({0, 0, 0});
	visited[0][0][0][0] = true;
	while (!q.empty()) {
		auto now = q.front();
		q.pop();
		if (now.x == n - 1 && now.y == n - 1) {
			printf("%d ",now.t / (2 * m) + 1);
			if ((now.t / m) % 2 == 0) printf("sun");
			else printf("moon");
			return 0;
		}
		for (int i = 0; i < 4; ++i) {
			int nx = now.x + dx[i];
			int ny = now.y + dy[i];
			int nt = now.t + 1;
			if (nx < 0 || ny < 0 || nx >= n || ny >= n || visited[ny][nx][nt % m][(nt / m) % 2]) continue;
			if ((now.t / m) % 2 == 0 && field[ny][nx] == 1) continue;
			if (field[ny][nx] == 0) {
				q.push({nx, ny, now.t + 1});
				visited[ny][nx][nt % m][(nt / m) % 2] = true;
				continue;
			}
			while (nx >= 0 && ny >= 0 && nx < n && ny < n && field[ny][nx] == 1) {
				nx += dx[i];
				ny += dy[i];
			}
			if (nx >= 0 && ny >= 0 && nx < n && ny < n) {
				if(visited[ny][nx][nt % m][(nt / m) % 2]) continue;
				q.push({nx, ny, now.t + 1});
				visited[ny][nx][nt % m][(nt / m) % 2] = true;
			}
		}
	}
	cout << -1;
	return 0;
}
