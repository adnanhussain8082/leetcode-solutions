class Solution {
public:
    vector<int> targetIndices(vector<int>& A, int target) {
        // sort(begin(A), end(A));
        // vector<int> ans;
        // for (int i = 0; i < A.size(); ++i) {
        //     if (A[i] == target) ans.push_back(i);
        // }
        // return ans;

        vector<int> ans;
        //using two variables, one to count elements less and another equal to that of target

        int count_less=0, count_equal=0;


        for(int i=0;i<A.size();i++){
            if(A[i]==target){
                count_equal++;
            }
            else if(A[i]<target){
                count_less++;
            }
        }

        if(count_equal>0){

            for(int i=0;i<count_equal;i++){
                ans.push_back(count_less++);
            }
        }

        return ans;
    }
};