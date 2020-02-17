#include <bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int frame = 0, cnt = 0, score = 0;
    int table[111];
    string s;
    cin>>s;
    for(int i = 0 ; i < s.size(); ++i){
        if(s[i] == '-')
            table[i] = 0;
        else if(s[i] == 'S')
            table[i] = 10;
		else if(s[i] == 'P')
			table[i] = 10 - table[i-1];
        else
            table[i] = s[i] - '0';
    }
    for(int i = 0 ; i < s.size(); ++i) {
        if (s[i] == 'S') {
            if (frame > 9)
                continue;
            score += table[i];
            if (i != s.size() - 1)
                score += table[i + 1];
            if (i != s.size() - 2 && i != s.size() - 1)
                score += table[i + 2];
            frame++;
            cnt = 0;
        } else if (s[i] == 'P') {
            if (frame > 9)
                continue;
            score += table[i];
            if (i != s.size() - 1)
                score += table[i + 1];
            frame++;
            cnt = 0;
        } else {
            if (frame > 9)
                continue;
            score += table[i];
            if (cnt == 0)
                cnt++;
            else {
                cnt = 0;
                frame++;
            }
        }
    }
    cout<<score;
    return 0;
}
