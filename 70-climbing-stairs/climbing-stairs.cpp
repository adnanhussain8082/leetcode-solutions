// class Solution {
// public:
//     int climbStairs(int n) {
//         if(n<=1) return 1;

//         return climbStairs(n-1)+climbStairs(n-2);
//     }
// };






//            memo(top down)

// class Solution {
// private:
//     int f(int n , vector<int>& dp){
//         //base case
//         if(n<=1) return 1;

//         //dp check
//         if(dp[n]!=0) return dp[n];

//         return dp[n] = f(n-1, dp) + f(n-2 , dp);
//     }   
// public:
//     int climbStairs(int n) {
//         vector<int> dp(n+1 , 0);
//         dp[0]=1;

//         return f(n , dp);
//     }
// };




//                tabulation(bottom up)

// class Solution {
// public:
//     int climbStairs(int n) {
//         vector<int> dp(n+1 , 0);
        
//         //base cases
//         dp[0]=1;
//         dp[1]=1;         //only one step from last stair

//         for(int i=2;i<=n;i++){
//             dp[i] = dp[i-1]+dp[i-2];
//         }

//         return dp[n];
//     }
// };



//                space-optimisation(bottom up)

class Solution {
public:
    int climbStairs(int n) {
        
        //base cases
        int prev2=1;
        int prev=1;         //only one step from last stair

        for(int i=2;i<=n;i++){
            int curr = prev+prev2;
            prev2=prev;
            prev=curr;
        }

        return prev;
    }
};

