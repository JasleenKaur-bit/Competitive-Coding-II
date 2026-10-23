#include<iostream>
#include<vector>
#include<climits>
#include<cmath>
using namespace std;
class Solution{
    public:
    int minCost(vector<int>& height,int k){
        int n=height.size();
        //dp[i] stores minimum cost to reach stone i
        vector<int> dp(n,INT_MAX);
        dp[0]=0;
        //Calculate minimum cost for each stone
        for(int i=1;i<n;i++){
            //Check all reachable previous stones
            for(int j=max(0,i-k);j<i;j++){
                int cost=dp[j]+abs(height[i]-height[j]);
                dp[i]=min(dp[i],cost);
            }
        }
        return dp[n-1];
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