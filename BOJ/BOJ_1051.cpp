#include <bits/stdc++.h>
#define MAX 50
using namespace std;
int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);
	int N, M, field[MAX][MAX], ans = 1;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		string input;
		cin >> input;
		for (int j = 0; j < M; j++)
			field[i][j] = input[j] - '0';
	}
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			for (int k = 1; k < min(N, M); k++)
				if (i + k < N && j + k < M && field[i][j] == field[i][j + k] && field[i][j] == field[i + k][j] &&
				    field[i][j] == field[i + k][j + k])
					ans = max(ans, k + 1);
	cout << ans * ans << endl;
	return 0;
}
