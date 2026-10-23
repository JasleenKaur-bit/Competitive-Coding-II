#include<iostream>
#include<vector>
#include<climits>
#include<cmath>
using namespace std;
class Solution{
    public:
    int solve(int i,vector<int>& height,int k){
        //Base case: already at the first stone
        if(i==0){
            return 0;
        }
        int best=INT_MAX;
        //Try all valid previous stones
        for(int j=max(0,i-k);j<i;j++){
            int cost=solve(j,height,k)+abs(height[i]-height[j]);
            best=min(best,cost);
        }
        return best;
    }
    int minCost(vector<int>& height,int k){
        int n=height.size();
        return solve(n-1,height,k);
    }
};
int main(){
    Solution obj;
    int n,k;
    cout<<"Enter number of stones: ";
    cin>>n;
    vector<int> height(n);
    cout<<"Enter stone heights: ";
    for(int i=0;i<n;i++){
        cin>>height[i];
    }
    cout<<"Enter maximum jump distance k: ";
    cin>>k;
    cout<<"Minimum Cost: "<<obj.minCost(height,k);
    return 0;
}