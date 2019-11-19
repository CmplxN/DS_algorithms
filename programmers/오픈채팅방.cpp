/*
아이디-닉 일치화 한번 n
일치화 된 닉으로 출력 한번 n
unordered_map 처음 사용
*/
#include <bits/stdc++.h>
using namespace std;
vector<string> solution(vector<string> record) {
    vector<string> answer;
    unordered_map<string, string> ump;
    for(int i=0;i<record.size();++i){//id에 따른 최종 닉네임 저장
        string temp,nick;
        int s;
        if(record[i][0]=='E'){//아이디 및 닉네임 기록
            for(s = 6 ; record[i][s]!=' ';++s){
                temp.push_back(record[i][s]);
            }
            s++;
            for(;s<record[i].size();++s){
                nick.push_back(record[i][s]);
            }
            ump[temp]=nick;
        }
        else if(record[i][0]=='L'){//무효 메시지는 없으므로 무시
            
        }
        else{//아이디 및 닉네임 기록
            for(s = 7 ; record[i][s]!=' ';++s){
                temp.push_back(record[i][s]);
            }
            s++;
            for(;s<record[i].size();++s){
                nick.push_back(record[i][s]);
            }
            ump[temp]=nick;
        }
    }
    for(int i=0;i<record.size();++i){//다시한번 record를 읽으며 id에 따라 
        string temp,ans;
        int s;
        if(record[i][0]=='E'){
            for(s = 6 ; record[i][s]!=' ';++s){
                temp.push_back(record[i][s]);
            }
            ans+=ump[temp];
            ans+="님이 들어왔습니다.";
            answer.push_back(ans);
        }
        else if(record[i][0]=='L'){
            for(s = 6 ; s < record[i].size() ; ++s){
                temp.push_back(record[i][s]);
            }
            ans+=ump[temp];
            ans+="님이 나갔습니다.";
            answer.push_back(ans);
        }
        else{//닉 바꾼건 따로 한줄 안나감
            
        }
    }
    return answer;
}
