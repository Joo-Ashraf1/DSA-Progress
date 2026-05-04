using namespace std;
#include <bits/stdc++.h>
class Solution {
public:
    bool visited[1000000];
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        dfs(rooms,0);
        for(int i=0;i<rooms.size();i++){
            if(!visited[i]){
                return false;
            }
        }
        return true;
        
    }
    void dfs(vector<vector<int>>& rooms,int node){
        visited[node]=true;
        for(auto v:rooms[node]){
            if(!visited[v]){
                dfs(rooms,v);
            }
        }
    } 
};