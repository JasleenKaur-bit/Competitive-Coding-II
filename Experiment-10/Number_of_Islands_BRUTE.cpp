#include<iostream>
#include<vector>
#include<string>
using namespace std;
class Solution{
    public:
    void dfs(vector<vector<char>>& grid,vector<vector<bool>>& visited,int r,int c){
        int m=grid.size();
        int n=grid[0].size();
        //Check boundaries and water
        if(r<0||r>=m||c<0||c>=n||grid[r][c]=='0'||visited[r][c]){
            return;
        }
        //Mark current cell visited
        visited[r][c]=true;
        //Visit four directions
        dfs(grid,visited,r-1,c);
        dfs(grid,visited,r+1,c);
        dfs(grid,visited,r,c-1);
        dfs(grid,visited,r,c+1);
    }
    int numIslands(vector<vector<char>>& grid){
        int m=grid.size();
        int n=grid[0].size();
        int count=0;
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        //Scan every cell
        for(int r=0;r<m;r++){
            for(int c=0;c<n;c++){
                if(grid[r][c]=='1'&&!visited[r][c]){
                    //Found a new island
                    count++;
                    dfs(grid,visited,r,c);
                }
            }
        }
        return count;
    }
};
int main(){
    Solution obj;
    int m,n;
    cout<<"Enter number of rows: ";
    cin>>m;
    cout<<"Enter number of columns: ";
    cin>>n;
    vector<vector<char>> grid(m,vector<char>(n));
    cout<<"Enter grid:\n";
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>grid[i][j];
        }
    }
    cout<<"Number of Islands: "<<obj.numIslands(grid);
    return 0;
}