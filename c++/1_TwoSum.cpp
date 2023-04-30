class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int sum;
        int j_lim = 0;
        vector<int> solutions;
        for (int i = 0; i < nums.size() - 1; i++) {
            j_lim++;
            for (int j = j_lim; j < nums.size(); j++) {
                sum = nums[i] + nums[j];
                if (sum == target) {
                    solutions = {i, j};
                    return solutions;
                }
            }
        }
        return solutions;
    }
};