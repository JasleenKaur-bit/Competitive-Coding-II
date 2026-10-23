#include<iostream>
#include<vector>
#include<queue>
using namespace std;
bool validPath(int n,vector<vector<int>>& edges,int source,int destination){
    //Build adjacency list for nodes 1 to n
    vector<vector<int>> adj(n+1);
    for(auto& e:edges){
        adj[e[0]].push_back(e[1]);
        adj[e[1]].push_back(e[0]);
    }
    //Source and destination are same
    if(source==destination){
        return true;
    }
    vector<bool> visited(n+1,false);
    queue<int> q;
    //Start BFS
    q.push(source);
    visited[source]=true;
    while(!q.empty()){
        int node=q.front();
        q.pop();
        //Visit neighbours
        for(int next:adj[node]){
            if(next==destination){
                return true;
            }
            if(!visited[next]){
                visited[next]=true;
                q.push(next);
            }
        }
    }
    return false;
}
int main(){
    int n,m;
    cout<<"Enter number of nodes: ";
    cin>>n;
    cout<<"Enter number of edges: ";
    cin>>m;
    vector<vector<int>> edges(m,vector<int>(2));
    cout<<"Enter edges:\n";
    for(int i=0;i<m;i++){
        cin>>edges[i][0]>>edges[i][1];
    }
    int source,destination;
    cout<<"Enter source: ";
    cin>>source;
    cout<<"Enter destination: ";
    cin>>destination;
    cout<<"Path Exists: "<<(validPath(n,edges,source,destination)?"true":"false");
    return 0;
}