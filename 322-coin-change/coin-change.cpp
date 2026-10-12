class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int m=coins.size();
        // vector<vector<int>> dp(m, vector<int>(amount+1,0));
        vector<int> prev(amount+1,0);

        for(int amt=1;amt<=amount;amt++){
            if(amt%coins[0]==0){
                prev[amt] = amt/coins[0];
            }
            else{
                prev[amt] = 1e9;
            }
        }

        for(int ind=1;ind<m;ind++){
            vector<int> curr(amount+1,0);
            for(int amt=1;amt<=amount;amt++){
                int not_take = prev[amt];
                int take=1e9;
                if(coins[ind]<=amt){
                    take = 1 + curr[amt-coins[ind]];
                }

                curr[amt] = min(take, not_take);
            }
            prev=curr;
        }

        if(prev[amount]==1e9) return -1;
        return prev[amount];
    }
};