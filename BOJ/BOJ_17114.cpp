#include <bits/stdc++.h>
using namespace std;
typedef struct coord{
	int m,n,o,p,q,r,s,t,u,v,w;
}coord;
int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);
	int mm, Nn, oo, pp, qq, rr, ss, tt, uu, vv, ww, tar = 0;
	int d[11][22];
	for (int i = 0; i < 11; ++i)
		for (int j = 0; j < 22; ++j) {
			if (j / 2 == i) {
				if (j % 2 == 0) d[i][j] = -1;
				else d[i][j] = 1;
			} else d[i][j] = 0;
		}
	cin >> mm >> Nn >> oo >> pp >> qq >> rr >> ss >> tt >> uu >> vv >> ww;
	int map[ww][vv][uu][tt][ss][rr][qq][pp][oo][Nn][mm];
	queue<coord> Q;
	for (int w = 0; w < ww; ++w)
		for (int v = 0; v < vv; ++v)
			for (int u = 0; u < uu; ++u)
				for (int t = 0; t < tt; ++t)
					for (int s = 0; s < ss; ++s)
						for (int r = 0; r < rr; ++r)
							for (int q = 0; q < qq; ++q)
								for (int p = 0; p < pp; ++p)
									for (int o = 0; o < oo; ++o)
										for (int n = 0; n < Nn; ++n)
											for (int m = 0; m < mm; ++m) {
												cin >> map[w][v][u][t][s][r][q][p][o][n][m];
												if (map[w][v][u][t][s][r][q][p][o][n][m] == 1)
													Q.push({m, n, o, p, q, r, s, t, u, v, w});
												if (map[w][v][u][t][s][r][q][p][o][n][m] == 0)
													tar++;
											}
	if (tar == 0) {
		cout << 0;
		return 0;
	}
	int T = 0, cnt = 0;
	while (true) {
		int size = Q.size();
		while (size--) {
			coord now = Q.front();
			Q.pop();
			for (int i = 0; i < 22; ++i) {
				int nm = now.m + d[0][i];
				int nn = now.n + d[1][i];
				int no = now.o + d[2][i];
				int np = now.p + d[3][i];
				int nq = now.q + d[4][i];
				int nr = now.r + d[5][i];
				int ns = now.s + d[6][i];
				int nt = now.t + d[7][i];
				int nu = now.u + d[8][i];
				int nv = now.v + d[9][i];
				int nw = now.w + d[10][i];
				if (nm >= mm || nn >= Nn || no >= oo || np >= pp || nq >= qq || nr >= rr || ns >= ss || nt >= tt ||
				    nu >= uu || nv >= vv || nw >= ww)
					continue;
				if (nm < 0 || nn < 0 || no < 0 || np < 0 || nq < 0 || nr < 0 || ns < 0 || nt < 0 || nu < 0 || nv < 0 ||
				    nw < 0)
					continue;
				if (map[nw][nv][nu][nt][ns][nr][nq][np][no][nn][nm] != 0) continue;
				map[nw][nv][nu][nt][ns][nr][nq][np][no][nn][nm] = 1;
				Q.push({nm, nn, no, np, nq, nr, ns, nt, nu, nv, nw});
				cnt++;
			}
		}
		T++;
		if (Q.empty() || cnt == tar) break;
	}
	if (cnt == tar) cout << T;
	else cout << -1;
	return 0;
}
