#include<iostream>
#include<vector>
#include<string>
using namespace std;
class Solution{
    public:
    int longestCommonSubsequence(string text1,string text2){
        int m=text1.size();
        int n=text2.size();
        //Create DP table
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        //Fill the DP table
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                //If characters match
                if(text1[i-1]==text2[j-1]){
                    dp[i][j]=dp[i-1][j-1]+1;
                }
                else{
                    //Take the better of the two choices
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[m][n];
    }
};
int main(){
    Solution obj;
    string text1,text2;
    cout<<"Enter first string: ";
    cin>>text1;
    cout<<"Enter second string: ";
    cin>>text2;
    cout<<"Length of LCS: "<<obj.longestCommonSubsequence(text1,text2);
    return 0;
}