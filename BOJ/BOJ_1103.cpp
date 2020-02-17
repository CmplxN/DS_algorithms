#include <bits/stdc++.h>
using namespace std;
int n,m;
int dp[55][55], mp[55][55], visited[55][55];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int solve(int x, int y){
    if(x>=m||x<0||y<0||y>=n)
        return 0;
    if(mp[y][x]==0)
        return 0;
    if(visited[y][x] != 0){
        cout<<-1;
        exit(0);
    }
    if(dp[y][x] != 0)
        return dp[y][x];
    visited[y][x] = 1;
    for(int i = 0 ; i < 4; ++i) {
        dp[y][x] = max(dp[y][x], solve(x + dx[i] * mp[y][x], y + dy[i] * mp[y][x]) + 1);
    }
    visited[y][x] = 0;
    return dp[y][x];
}
int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    char c;
    cin>>n>>m;
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
           cin>>c;
           if(c == 'H'){
               mp[i][j] = 0;
               continue;
           }
           mp[i][j] = c - '0';
        }
    }
    int ans = solve(0,0);
    cout<<ans;
    return 0;
}
