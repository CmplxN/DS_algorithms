#include <bits/stdc++.h>
using namespace std;
typedef struct info{
	int cur_win = 0;
	int cursor = 0;
}info;
int N,K,table[9][9],KH[20],MH[20];
bool dfs(info j, info k, info m, int js, int who) {
	if (j.cur_win == K) {
		return true;
	}
	if (k.cur_win == K || m.cur_win == K) {
		return false;
	}
	bool won = false;
	int nwho;
	if (who == 0) {
		for (int i = 0; i < N; ++i) {
			if ((js & (1 << i)) != 0) continue;
			info nj = {j.cur_win, j.cursor};
			info nk = {k.cur_win, k.cursor};
			if (table[i][KH[nk.cursor]] == 2) {
				nwho = 1;
				nj.cur_win++;
			} else {
				nwho = 2;
				nk.cur_win++;
			}
			nk.cursor++;
			won = dfs(nj, nk, m, js | (1 << i), nwho) || won;
		}
	} else if (who == 1) {
		for (int i = 0; i < N; ++i) {
			if ((js & (1 << i)) != 0) continue;
			info nj = {j.cur_win, j.cursor};
			info nm = {m.cur_win, m.cursor};
			if (table[i][MH[nm.cursor]] == 2) {
				nwho = 0;
				nj.cur_win++;
			} else {
				nwho = 2;
				nm.cur_win++;
			}
			nm.cursor++;
			won = dfs(nj, k, nm, js | (1 << i), nwho) || won;
		}
	} else {
		if (table[KH[k.cursor]][MH[m.cursor]] == 2) {
			nwho = 0;
			k.cur_win++;
		} else {
			nwho = 1;
			m.cur_win++;
		}
		k.cursor++;
		m.cursor++;
		won = dfs(j, k, m, js, nwho);
	}
	return won;
}
int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);
	cin >> N >> K;
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			cin >> table[i][j];
	for (int &i : KH) {
		cin >> i;
		i--;
	}
	for (int &i : MH) {
		cin >> i;
		i--;
	}
	if (dfs({0, 0}, {0, 0}, {0, 0}, 0, 0)) cout << 1;
	else cout << 0;
	return 0;
}
