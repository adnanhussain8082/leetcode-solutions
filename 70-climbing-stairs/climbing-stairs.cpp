// class Solution {
// public:
//     int climbStairs(int n) {
//         if(n<=1) return 1;

//         return climbStairs(n-1)+climbStairs(n-2);
//     }
// };






//            memo

class Solution {
private:
    int f(int n , vector<int>& dp){
        //base case
        if(n<=1) return 1;

        //dp check
        if(dp[n]!=0) return dp[n];

        return dp[n] = f(n-1, dp) + f(n-2 , dp);
    }   
public:
    int climbStairs(int n) {
        vector<int> dp(n+1 , 0);
        dp[0]=1;

        return f(n , dp);
    }
};