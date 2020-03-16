#include <bits/stdc++.h>
using namespace std;
char cube[6][3][3];
void cube_init(){
	memset(cube[0],'w',sizeof(cube[0]));
	memset(cube[1],'y',sizeof(cube[1]));
	memset(cube[2],'r',sizeof(cube[2]));
	memset(cube[3],'o',sizeof(cube[3]));
	memset(cube[4],'g',sizeof(cube[4]));
	memset(cube[5],'b',sizeof(cube[5]));
}
void clock_wise(int no){
	char temp=cube[no][0][0];
	cube[no][0][0]=cube[no][0][2];
	cube[no][0][2]=cube[no][2][2];
	cube[no][2][2]=cube[no][2][0];
	cube[no][2][0]=temp;
	temp=cube[no][1][0];
	cube[no][1][0]=cube[no][0][1];
	cube[no][0][1]=cube[no][1][2];
	cube[no][1][2]=cube[no][2][1];
	cube[no][2][1]=temp;
}
void solve(int face){
	clock_wise(face);
	char a,b,c;
	if(face==0){
		a=cube[2][0][0], b=cube[2][1][0], c=cube[2][2][0];
		cube[2][0][0]=cube[5][0][0], cube[2][1][0]=cube[5][1][0], cube[2][2][0]=cube[5][2][0];
		cube[5][0][0]=cube[3][0][0], cube[5][1][0]=cube[3][1][0], cube[5][2][0]=cube[3][2][0];
		cube[3][0][0]=cube[4][0][0], cube[3][1][0]=cube[4][1][0], cube[3][2][0]=cube[4][2][0];
		cube[4][0][0]=a, cube[4][1][0]=b, cube[4][2][0]=c;
	}
	else if(face==1){
		a=cube[2][0][2], b=cube[2][1][2], c=cube[2][2][2];
		cube[2][0][2]=cube[4][0][2], cube[2][1][2]=cube[4][1][2], cube[2][2][2]=cube[4][2][2];
		cube[4][0][2]=cube[3][0][2], cube[4][1][2]=cube[3][1][2], cube[4][2][2]=cube[3][2][2];
		cube[3][0][2]=cube[5][0][2], cube[3][1][2]=cube[5][1][2], cube[3][2][2]=cube[5][2][2];
		cube[5][0][2]=a, cube[5][1][2]=b, cube[5][2][2]=c;
	}
	else if(face==2){
		a=cube[0][0][2], b=cube[0][1][2], c=cube[0][2][2];
		cube[0][0][2]=cube[4][2][2], cube[0][1][2]=cube[4][2][1], cube[0][2][2]=cube[4][2][0];
		cube[4][2][2]=cube[1][2][0], cube[4][2][1]=cube[1][1][0], cube[4][2][0]=cube[1][0][0];
		cube[1][2][0]=cube[5][0][0], cube[1][1][0]=cube[5][0][1], cube[1][0][0]=cube[5][0][2];
		cube[5][0][0]=a, cube[5][0][1]=b, cube[5][0][2]=c;
	}
	else if(face==3){
		a=cube[0][2][0], b=cube[0][1][0], c=cube[0][0][0];
		cube[0][2][0]=cube[5][2][2], cube[0][1][0]=cube[5][2][1], cube[0][0][0]=cube[5][2][0];
		cube[5][2][2]=cube[1][0][2], cube[5][2][1]=cube[1][1][2], cube[5][2][0]=cube[1][2][2];
		cube[1][0][2]=cube[4][0][0], cube[1][1][2]=cube[4][0][1], cube[1][2][2]=cube[4][0][2];
		cube[4][0][0]=a, cube[4][0][1]=b, cube[4][0][2]=c;
	}
	else if(face==4){
		a=cube[0][0][0], b=cube[0][0][1], c=cube[0][0][2];
		cube[0][0][0]=cube[3][2][2], cube[0][0][1]=cube[3][2][1], cube[0][0][2]=cube[3][2][0];
		cube[3][2][2]=cube[1][0][0], cube[3][2][1]=cube[1][0][1], cube[3][2][0]=cube[1][0][2];
		cube[1][0][0]=cube[2][0][0], cube[1][0][1]=cube[2][0][1], cube[1][0][2]=cube[2][0][2];
		cube[2][0][0]=a, cube[2][0][1]=b, cube[2][0][2]=c;
	}
	else if(face==5){
		a=cube[0][2][2], b=cube[0][2][1], c=cube[0][2][0];
		cube[0][2][2]=cube[2][2][2], cube[0][2][1]=cube[2][2][1], cube[0][2][0]=cube[2][2][0];
		cube[2][2][2]=cube[1][2][2], cube[2][2][1]=cube[1][2][1], cube[2][2][0]=cube[1][2][0];
		cube[1][2][2]=cube[3][0][0], cube[1][2][1]=cube[3][0][1], cube[1][2][0]=cube[3][0][2];
		cube[3][0][0]=a, cube[3][0][1]=b, cube[3][0][2]=c;
	}
}
int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);
	int t,n;
	string s;
	cin>>t;
	while(t--){
		cin>>n;
		cube_init();
		while(n--){
			cin>>s;
			int cnt=s[1]=='+'?1:3;
			int face=7;
			switch(s[0]) {
				case 'U':
					face = 0;
					break;
				case 'D':
					face = 1;
					break;
				case 'F':
					face = 2;
					break;
				case 'B':
					face = 3;
					break;
				case 'L':
					face = 4;
					break;
				case 'R':
					face = 5;
					break;
			}
			while(cnt--) solve(face);
		}
		for(int i=0;i<3;++i){
			for(int j=0;j<3;++j) cout<<cube[0][j][i];
			cout<<'\n';
		}
	}
	return 0;
}
