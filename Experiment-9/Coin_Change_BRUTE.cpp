#include<iostream>
#include<vector>
#include<climits>
using namespace std;
class Solution{
    public:
    int solve(vector<int>& coins,int amount){
        //Zero amount needs zero coins
        if(amount==0){
            return 0;
        }
        int best=INT_MAX;
        //Try every possible coin
        for(int c:coins){
            if(c<=amount){
                int result=solve(coins,amount-c);
                //Check if remaining amount is possible
                if(result!=INT_MAX){
                    best=min(best,result+1);
                }
            }
        }
        return best;
    }
    int coinChange(vector<int>& coins,int amount){
        int result=solve(coins,amount);
        //Return -1 if amount cannot be formed
        if(result==INT_MAX){
            return -1;
        }
        return result;
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