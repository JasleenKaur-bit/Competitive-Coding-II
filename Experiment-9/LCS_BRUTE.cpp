#include<iostream>
#include<string>
using namespace std;
class Solution{
    public:
    int lcs(string text1,string text2,int i,int j){
        //If either string is empty
        if(i==0||j==0){
            return 0;
        }
        //If characters match
        if(text1[i-1]==text2[j-1]){
            return 1+lcs(text1,text2,i-1,j-1);
        }
        //If characters do not match
        return max(lcs(text1,text2,i-1,j),lcs(text1,text2,i,j-1));
    }
    int longestCommonSubsequence(string text1,string text2){
        return lcs(text1,text2,text1.size(),text2.size());
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