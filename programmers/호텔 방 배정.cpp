#include <bits/stdc++.h>
using namespace std;
typedef struct info{
    long long anc,next;
}info;
vector<long long> solution(long long k, vector<long long> room_number) {
    vector<long long> answer;
    map<long long,info> mp;
    for(auto n : room_number){
        auto lit = mp.lower_bound(n);
        auto uit = mp.upper_bound(n);
        auto mit = mp.lower_bound(n-1);
        if(lit==mp.end()||lit->first!=n){
            answer.push_back(n);
            if(uit->first==n+1){
                if(mit==lit){
                    mp[n]={-1,uit->second.next};
                    uit->second.anc=n;
                }
                else{
                    long long temp=mit->first;
                    while(mp[temp].anc!=-1){
                        temp = mp[temp].anc;
                    }
                    long long updater=mit->first;
                    long long save;
                    while(mp[updater].anc!=-1){
                        save=updater;                        
                        updater=mp[updater].anc;
                        mp[save].anc=temp;
                    }
                    mp[n]={temp,uit->second.next};
                    mp[temp].next=uit->second.next;
                    uit->second.anc=temp;
                }
            }
            else{
                if(mit==lit){
                    mp[n]={-1,n+1};
                }
                else{
                    long long temp=mit->first;
                    while(mp[temp].anc!=-1){
                        temp=mp[temp].anc;
                    }
                    long long updater=mit->first;
                    long long save;
                    while(mp[updater].anc!=-1){
                        save=updater;                        
                        updater=mp[updater].anc;
                        mp[save].anc=temp;
                    }
                    mp[n]={temp,n+1};
                    mp[temp].next=n+1;
                }
            }
        }
        else{
            long long room = lit->first;
            while(mp[room].anc!=-1) room=mp[room].anc;
            long long myRoom = mp[room].next;
            long long updater = lit->first;
            long long save;
            while(mp[updater].anc!=-1){
                save=updater;                        
                updater=mp[updater].anc;
                mp[save].anc=room;
            }
            mp[myRoom]={room,0};
            long long nRoom = mp.upper_bound(myRoom)->first;
            if(nRoom==myRoom+1){
                mp[room].next=mp[nRoom].next;
                mp[nRoom].anc=room;
            }
            else{
                mp[room].next=myRoom+1;
            }
            answer.push_back(myRoom);
        }
    }
    return answer;
}
