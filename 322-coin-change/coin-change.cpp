class Solution {
private:
    int f(int ind, vector<int>& coins, int amount, vector<vector<int>>& dp){
        //base case
        if(ind==0){
            if(amount%coins[ind]==0){
                return amount/coins[ind];
            }
            else{
                return 1e9;
            }
        }

        if(dp[ind][amount]!=0) return dp[ind][amount];

        int not_take = f(ind-1, coins, amount, dp);
        int take=1e9;
        if(coins[ind]<=amount){
            take = 1+f(ind, coins , amount-coins[ind], dp);
        }

        return dp[ind][amount] = min(take, not_take);
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        int m=coins.size();
        vector<vector<int>> dp(m, vector<int>(amount+1,0));
        int ans = f(m-1, coins, amount, dp);
        if(ans==1e9) return -1;
        return ans;
    }
};