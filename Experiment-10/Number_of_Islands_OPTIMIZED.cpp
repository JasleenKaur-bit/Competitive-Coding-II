#include<iostream>
#include<vector>
using namespace std;
class Solution{
    public:
    void dfs(vector<vector<char>>& grid,int r,int c){
        int m=grid.size();
        int n=grid[0].size();
        //Check boundaries and water
        if(r<0||r>=m||c<0||c>=n||grid[r][c]!='1'){
            return;
        }
        //Mark land as visited
        grid[r][c]='0';
        //Visit four directions
        dfs(grid,r-1,c);
        dfs(grid,r+1,c);
        dfs(grid,r,c-1);
        dfs(grid,r,c+1);
    }
    int numIslands(vector<vector<char>>& grid){
        int m=grid.size();
        int n=grid[0].size();
        int count=0;
        //Scan every cell
        for(int r=0;r<m;r++){
            for(int c=0;c<n;c++){
                if(grid[r][c]=='1'){
                    //Found a new island
                    count++;
                    //Sink the complete island
                    dfs(grid,r,c);
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