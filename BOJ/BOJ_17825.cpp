#include <bits/stdc++.h>
#define END 999
using namespace std;
int draft[33],score[33],nextt[33],coin[4],input[10],total;
void dfs(int dep, int cum){
	if(dep==10){
		total=total<cum?cum:total;
		return;
	}
	for(int i=0;i<4;++i){
		if(coin[i]==END) continue;
		int next;
		if(draft[coin[i]]) next = draft[coin[i]];
		else next = nextt[coin[i]];
		for(int j=1;j<input[dep];++j){
			if(next!=END) next=nextt[next];
			else break;
		}
		bool valid=true;
		for(int j=0;j<4;++j){
			if(j!=i&&coin[j]==next&&next!=END)
				valid =false;
		}
		if(!valid) continue;
		int nscore;
		if(next==END) nscore=0;
		else nscore=score[next];
		int temp=coin[i];
		coin[i]=next;
		dfs(dep+1,cum+nscore);
		coin[i]=temp;
	}
}
int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);
	for(int & i : input) cin>>i;
	for(int i=0;i<21;++i){
		score[i]=2*i;
		nextt[i]=i+1;
	}
	score[21]=13, score[22]=16, score[23]=19, score[24]=25, score[25]=30, score[26]=35;
	score[27]=22, score[28]=24, score[29]=26, score[30]=27, score[31]=28;
	nextt[21]=22, nextt[22]=23, nextt[23]=24, nextt[24]=25, nextt[25]=26, nextt[26]=20;
	nextt[27]=28, nextt[28]=24, nextt[29]=24, nextt[30]=29, nextt[31]=30, nextt[20]=END;
	draft[5]=21, draft[10]=27, draft[15]=31;
	dfs(0,0);
	cout<<total;
	return 0;
}
