// class Solution {
// private:
//     int f(vector<int>& nums, int n){
//         if(n<0) return 0;

//         int take = nums[n] + f(nums, n-2);
//         int notTake = f(nums, n-1);

//         return max(take, notTake);

//     }
// public:
//     int rob(vector<int>& nums) {
//         return f(nums, nums.size()-1);


//     }
// };





// class Solution {
// private:
//     int f(vector<int>& nums, int n){
//         if(n<=0) return 0;

//         int take = nums[n-1] + f(nums, n-2);
//         int notTake = f(nums, n-1);

//         return max(take, notTake);

//     }
// public:
//     int rob(vector<int>& nums) {
//         return f(nums, nums.size());


//     }
// };






// class Solution {
// private:
//     int f(vector<int>& nums, int n, vector<int>& dp){
//         if(n<=0) return 0;

//         if(dp[n]!=0) return dp[n];

//         int take = nums[n-1] + f(nums, n-2 , dp);
//         int notTake = f(nums, n-1, dp);

//         return dp[n] = max(take, notTake);

//     }
// public:
//     int rob(vector<int>& nums) {
//         int n=nums.size();
//         vector<int>dp (n+1 , 0);
//         return f(nums, nums.size(), dp);


//     }
// };




class Solution {
private:
    int f(vector<int>& nums, int n, vector<int>& dp){

        for(int i=1;i<=n;i++){
            int take = nums[i-1];

            if(i-2>=0) take+=dp[i-2];

            int notTake = dp[i-1];

            dp[i] = max(take, notTake);
        }

        return dp[n];

    }
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp (n+1 , 0);
        return f(nums, nums.size(), dp);


    }
};