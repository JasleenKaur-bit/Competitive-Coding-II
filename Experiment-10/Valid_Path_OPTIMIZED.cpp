#include<iostream>
#include<vector>
using namespace std;
class Solution{
    public:
    bool dfs(int node,int destination,vector<vector<int>>& adj,vector<bool>& visited){
        //Destination reached
        if(node==destination){
            return true;
        }
        //Mark current node visited
        visited[node]=true;
        //Visit all connected nodes
        for(int next:adj[node]){
            if(!visited[next]&&dfs(next,destination,adj,visited)){
                return true;
            }
        }
        return false;
    }
    bool validPath(int n,vector<vector<int>>& edges,int source,int destination){
        //Build adjacency list
        vector<vector<int>> adj(n);
        for(auto& e:edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<bool> visited(n,false);
        return dfs(source,destination,adj,visited);
    }
};
int main(){
    Solution obj;
    int n,m;
    cout<<"Enter number of nodes: ";
    cin>>n;
    cout<<"Enter number of edges: ";
    cin>>m;
    vector<vector<int>> edges(m,vector<int>(2));
    cout<<"Enter edges: ";
    for(int i=0;i<m;i++){
        cin>>edges[i][0]>>edges[i][1];
    }
    int source,destination;
    cout<<"Enter source: ";
    cin>>source;
    cout<<"Enter destination: ";
    cin>>destination;
    cout<<(obj.validPath(n,edges,source,destination)?"true":"false");
    return 0;
}