#include<iostream>
using namespace std;
class Solution{
    public:
    int climbStairs(int n){
        //Base cases
        if(n<=2){
            return n;
        }
        //Count ways from the previous two steps
        return climbStairs(n-1)+climbStairs(n-2);
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