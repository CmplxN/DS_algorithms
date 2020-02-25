#include <bits/stdc++.h>
bool check[2][1111111];
using namespace std;
int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);
	long long int a,b,cnt=0,range;
	cin>>a>>b;
	range=b-a+1;
	for(long long int i=2;i*i<=b;++i){
		if(check[0][i])
			continue;
		for(long long int j=i;j*j<=b;j+=i)
			check[0][j]=true;
		for(long long int j=i*i*((a-1)/(i*i)+1);j<=b;j+=i*i) {
			if (!check[1][j - a]) {
				check[1][j - a] = true;
				cnt++;
			}
		}
	}
	cout<<range-cnt;
	return 0;
}
