using namespace std;
#include <bits/stdc++.h>
class Solution {
public:
    enum Color {GREY,WHITE,BLACK};
    vector<Color> visited;
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        for (auto& p : prerequisites) {
            graph[p[1]].push_back(p[0]);
        }
        visited.assign(numCourses, WHITE);

        // i made a asumption that all connected which is wrong so solve it 
        for(int i=0;i<numCourses;i++){
            if(visited[i]==WHITE){
                if(!dfs(graph,i)) return false;
            }
            
        }
        return true;
    }
    bool dfs(vector<vector<int>>& graph,int node){
    visited[node]=GREY;
    for(auto v:graph[node]){
        if (visited[v]==GREY) return false;

        else if(visited[v]==WHITE){
            if(!dfs(graph,v)) return false;
        }
    }
    visited[node]=BLACK;
    return true;
}
};