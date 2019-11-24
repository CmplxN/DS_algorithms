#include <bits/stdc++.h>
using namespace std;
unordered_map<string,int> mp;
string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    for(int i=0;i<participant.size();++i){
        mp[participant[i]]++;
    }
    for(int i=0;i<completion.size();++i){
        mp[completion[i]]++;
    }
    for(int i=0;i<participant.size();++i){
        if(mp[participant[i]]%2==1){
            answer=participant[i];
            break;
        }
    }
    return answer;
}
