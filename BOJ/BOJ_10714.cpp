#include <bits/stdc++.h>
using namespace std;
int n,input;
long long int sum[2002][2002],dp[2002][2002],maxi,total;
vector<long long int> v;
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin>>n;
	for(int i=0;i<n;++i){
		cin>>input;
		v.push_back(input);
		sum[i][i]=dp[i][i]=input;
		total+=input;
	}
	for(int i=0;i<n;++i)
		for(int j=1;j<n;++j)
			sum[i][(i+j)%n]=sum[i][(i+j-1)%n]+v[(i+j)%n];
	if(n%2==0){
		for(int l=1;l<=n-2;++l){
			if(l%2==1)
				for(int j=0;j<n;++j)
					dp[j%n][(j+l)%n]=sum[j%n][(j+l)%n]-min(dp[(j+1)%n][(j+l)%n],dp[j%n][(j+l-1)%n]);
			else{
				for(int j=0;j<n;++j){
					if(v[(j)%n]<v[(j+l)%n])
						dp[j%n][(j+l)%n]=v[(j+l)%n]+sum[j%n][(j+l-1)%n]-dp[j%n][(j+l-1)%n];
					else
						dp[j%n][(j+l)%n]=v[(j)%n]+sum[(j+1)%n][(j+l)%n]-dp[(j+1)%n][(j+l)%n];
				}
			}
		}
	}
	else{
		for(int l=1;l<=n-2;++l){
			if(l%2==1){
				for(int j=0;j<n;++j){
					if(v[(j)%n]<v[(j+l)%n])
						dp[j%n][(j+l)%n]=v[(j+l)%n]+sum[j%n][(j+l-1)%n]-dp[j%n][(j+l-1)%n];
					else
						dp[j%n][(j+l)%n]=v[(j)%n]+sum[(j+1)%n][(j+l)%n]-dp[(j+1)%n][(j+l)%n];
				}
			}
			else
				for(int j=0;j<n;++j)
					dp[j%n][(j+l)%n]=sum[j%n][(j+l)%n]-min(dp[(j+1)%n][(j+l)%n],dp[j%n][(j+l-1)%n]);
		}
	}
	for(int i=0;i<n;++i){
		long long int temp=total-dp[(1+i)%n][(n-1+i)%n];
		maxi=maxi>temp?maxi:temp;
	}
	cout<<maxi;
	return 0;
}
