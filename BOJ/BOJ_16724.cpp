#include <bits/stdc++.h>
using namespace std;
int N,M,ans,field[1000][1000],dest[1000][1000],used[1000][1000];
int dx[4]={0,0,-1,1};
int dy[4]={-1,1,0,0};
string s;
void explore(int x, int y) {
	if (dest[y][x] != -1) {
		if (used[y][x] == 0) {
			dest[y][x] = 0;
			used[y][x] = 1;
		}
		return;
	}
	dest[y][x] = 1;
	explore(x + dx[field[y][x]], y + dy[field[y][x]]);
	used[y][x] = 1;
}
int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);
	cin >> N >> M;
	for (int i = 0; i < N; ++i) {
		cin >> s;
		for (int j = 0; j < M; ++j) {
			if (s[j] == 'D') field[i][j] = 1;
			else if (s[j] == 'U') field[i][j] = 0;
			else if (s[j] == 'R') field[i][j] = 3;
			else field[i][j] = 2;
		}
	}
	memset(dest, -1, sizeof(dest));
	for (int i = 0; i < N; ++i) for (int j = 0; j < M; ++j) if (dest[i][j] == -1) explore(j, i);
	for (int i = 0; i < N; ++i) for (int j = 0; j < M; ++j) if (dest[i][j] == 0) ans++;
	cout << ans;
	return 0;
}
