/*
문제를 잘못이해해서 장르별로 1~2개가 아니라 2개씩 끊어서 출력을 만들었었음
*/
#include <bits/stdc++.h>
using namespace std;
typedef struct info{
    string s;
    int play;
    int id;
}info;
unordered_map<string,int> ump;
bool operator<(info a, info b){
    if(ump[a.s]==ump[b.s]){
        if(a.play==b.play) return a.id<b.id;
        else return a.play>b.play;
    }
    return ump[a.s]>ump[b.s];
}
vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    vector<info> v;
    for(int i = 0 ; i < plays.size() ; ++i){
        v.push_back({genres[i],plays[i],i});
        ump[genres[i]]+=plays[i];
    }
    sort(v.begin(),v.end());
    for(int i = 0 ; i < v.size();){
        string s;
        if(i==v.size()-1){
            answer.push_back(v[i].id);
            break;
        }
        else if(v[i].s.compare(v[i+1].s)!=0){
            answer.push_back(v[i].id);
            s=v[i].s;
        }
        else{            
            answer.push_back(v[i].id);
            answer.push_back(v[i+1].id);
            s=v[i++].s;
        }
        i++;
        while(s.compare(v[i].s)==0) if(i++>v.size()-1) break;
    }
    return answer;
}
