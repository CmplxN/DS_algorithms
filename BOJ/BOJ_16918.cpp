#include <bits/stdc++.h>
using namespace std;
int r,c,N,T=2;
int dx[4]={0,0,-1,1};
int dy[4]={-1,1,0,0};
string field[200];
int status[200][200];
int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);
	cin >> r >> c >> N;
	for (int i = 0; i < r; ++i)
		cin >> field[i];
	for (int i = 0; i < r; ++i)
		for (int j = 0; j < c; ++j)
			if (field[i][j] == 'O') status[i][j] = 3;

	while (T <= N) {
		for (int i = 0; i < r; ++i) {
			for (int j = 0; j < c; ++j) {
				if (status[i][j] == 0) {
					status[i][j] = T + 3;
				}
			}
		}
		for (int i = 0; i < r; ++i) {
			for (int j = 0; j < c; ++j) {
				if (status[i][j] == T) {
					status[i][j] = 0;
					for (int k = 0; k < 4; ++k) {
						int nx = j + dx[k];
						int ny = i + dy[k];
						if (nx < 0 || ny < 0 || nx >= c || ny >= r || status[ny][nx] == T) continue;
						status[ny][nx] = 0;
					}
				}
			}
		}
		T++;
	}
	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; ++j) {
			if (status[i][j] == 0) cout << '.';
			else cout << 'O';
		}
		cout << '\n';
	}
	return 0;
}
