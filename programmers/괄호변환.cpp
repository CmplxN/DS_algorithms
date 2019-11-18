/*
비교에 =쓴 실수 하고 너무 오래 못찾음
*/
#include <bits/stdc++.h>
using namespace std;
bool check(string s){
    int a=0;
    int b=0;
    for(int i=0;i<s.size();++i){
        if(s[i]==')') a++;//여기에 =을 썼었다.
        else b++;
        if(a>b) return false;
    }
    return true;
}
string reverse(string s){
    string rtn;
    if(s.size()<=2){
        rtn="";
        return rtn;
    }
    for(int i=1;i<s.size()-1;++i){
        if(s[i]=='('){
            rtn.push_back(')');
        }
        else{
            rtn.push_back('(');
        }
    }
    return rtn;
}
string solve(string s){
    string u;
    string rtn;
    if(s.size()==0){
        rtn="";
        return rtn;
    }
    int count[2]={0,0};
    int i=0;
    do{
        if(s[i]=='('){
            count[0]++;
        }
        else{
            count[1]++;
        }
        u.push_back(s[i++]);
    }while(count[0]!=count[1]);
    //0~i-1까지 u i부터 size-1까지 v
    if(check(u)){
        return u+solve(s.substr(u.size()));
    }
    rtn.push_back('(');
    rtn+=solve(s.substr(u.size()));
    rtn.push_back(')');
    rtn+=reverse(u);
    return rtn;
}
string solution(string p){
    string answer = "";
    if(p.size()==0) return answer;
    answer=solve(p);
    return answer;
}
