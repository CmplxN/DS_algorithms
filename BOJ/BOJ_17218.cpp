#include <bits/stdc++.h>
using namespace std;
string s1, s2;
list<char> ans;
int dp[41][41];
int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);
	cin>>s1>>s2;
	for(int i=0;i<s2.size();++i) for(int j=0;j<s1.size();++j){
		if(s2[i]==s1[j]){
			if(i==0||j==0) dp[i][j]=1;
			else dp[i][j]=dp[i-1][j-1]+1;
			continue;
		}
		if(i==0&&j==0) dp[i][j]=0;
		else if(i==0) dp[i][j]=dp[i][j-1];
		else if(j==0) dp[i][j]=dp[i-1][j];
		else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
	}
	int x=s1.size()-1, y=s2.size()-1;
	while(x>=0&&y>=0&&dp[y][x]!=0){
		bool moved=false;
		if(x-1>=0&&dp[y][x-1]==dp[y][x]){
			x--;
			moved=true;
		}
		if(y-1>=0&&dp[y-1][x]==dp[y][x]){
			y--;
			moved=true;
		}
		if(!moved){
			ans.push_front(s1[x]);
			x--;
			y--;
		}
	}
	for(auto c : ans) cout<<c;
}
