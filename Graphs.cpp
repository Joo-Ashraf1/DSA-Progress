
#include <bits/stdc++.h>
using namespace std;
const int N = 100000;
vector<int> graph[N];
int dist[N];
vector<Color> visited(N, WHITE);
enum Color { GREY, BLACK, WHITE };
void dfs(int node){
    visited[node]=GREY;
    for(auto v:graph[node]){
        if(visited[v]==WHITE){
            dfs(v);
        }
    }
    visited[node]=BLACK;
}

bool isCyclic(int node){
    visited[node]=GREY;
    for(auto v:graph[node]){
        if(visited[v]==GREY) return true;
        if(visited[v]==WHITE) return isCyclic(v);


    }
    visited[node]=BLACK;
    return false;


}



void bfs(int node){
    queue<int>q;
    memset(dist,-1,sizeof(dist));
    dist[node]=0;
    q.push(node);
    while(!q.empty()){
        int v=q.front();
        q.pop();
        for(auto child:graph[node]){
            if(dist[child]==-1){
                dist[child]=dist[node]+1;
                q.push(child);
            }
        }

    }
}