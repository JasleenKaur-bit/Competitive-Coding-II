#include<iostream>
#include<vector>
using namespace std;
class Solution{
    public:
    int coinChange(vector<int>& coins,int amount){
        //amount+1 acts as infinity
        vector<int> dp(amount+1,amount+1);
        //Zero amount requires zero coins
        dp[0]=0;
        //Calculate answer for every amount
        for(int a=1;a<=amount;a++){
            //Try every coin
            for(int c:coins){
                if(c<=a){
                    dp[a]=min(dp[a],dp[a-c]+1);
                }
            }
        }
        //If still infinity, amount is impossible
        if(dp[amount]==amount+1){
            return -1;
        }
        return dp[amount];
    }
};
int main(){
    Solution obj;
    int n,amount;
    cout<<"Enter number of coins: ";
    cin>>n;
    vector<int> coins(n);
    cout<<"Enter coin denominations: ";
    for(int i=0;i<n;i++){
        cin>>coins[i];
    }
    cout<<"Enter amount: ";
    cin>>amount;
    cout<<"Minimum coins: "<<obj.coinChange(coins,amount);
    return 0;
}