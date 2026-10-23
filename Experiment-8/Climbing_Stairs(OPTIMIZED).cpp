#include<iostream>
using namespace std;
class Solution{
    public:
    int climbStairs(int n){
        //Base cases
        if(n<=2){
            return n;
        }
        int prev1=1,prev2=2;
        //Calculate ways from step 3 to n
        for(int i=3;i<=n;i++){
            int current=prev1+prev2;
            //Shift the previous values
            prev1=prev2;
            prev2=current;
        }
        return prev2;
    }
};
int main(){
    Solution obj;
    int n;
    cout<<"Enter number of stairs: ";
    cin>>n;
    cout<<"Number of ways: "<<obj.climbStairs(n);
    return 0;
}