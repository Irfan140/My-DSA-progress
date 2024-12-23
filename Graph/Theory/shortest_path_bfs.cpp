#include<iostream>
#include<vector>
#include<list>
#include<queue>
#include<unordered_set>
#include<climits>
using namespace std;

vector<list<int> > graph;
int v; // no. of vertices
unordered_set<int> visited;


void add_edge(int src, int dest, bool bi_dir = true){
    graph[src].push_back(dest);
    if(bi_dir) graph[dest].push_back(src);
}

void bfs(int src, int dest, vector<int> &dist){
    queue<int> qu;
    visited.clear();
    dist.resize(v, INT_MAX);
    dist[src] = 0;
    visited.insert(src);
    qu.push(src);
    while(!qu.empty()){
        int curr = qu.front();
        qu.pop();
        for(auto neighbour : graph[curr]){
            if(!visited.count(neighbour)){
                qu.push(neighbour);
                visited.insert(neighbour);
                dist[neighbour] = dist[curr] + 1;
            }
        }
    }
}

int main(){
    cin>>v;
    graph.resize(v,list<int> ());
    int e;
    cin>>e;
    visited.clear();
    while(e--){
        int s, d;
        cin>>s>>d;
        add_edge(s,d);
    }
    int x, y;
    cin>>x>>y;
    vector<int> dist;
    bfs(x,y,dist);
    for(auto x : dist) cout<<x<<" ";
}



