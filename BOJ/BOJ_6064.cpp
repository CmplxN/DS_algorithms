#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a,long long b){
	if(b==0) return a;
	else return gcd(b,a%b);
}
int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);
	long long T,N,M,x,y;
	cin>>T;
	while(T--){
		cin>>M>>N>>x>>y;
		long long ans = 0;
		long long lcm=M*N/gcd(M,N);
		while(true){
			if(ans>=lcm) break;
			if((ans+x-1)%N==y-1){
				break;
			}
			ans+=M;
		}
		if(ans>=lcm) ans=-1-x;
		cout<<ans+x<<'\n';
	}
	return 0;
}
