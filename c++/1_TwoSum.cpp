class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int to_complete;
        map<int,int> history;
        for (int i = 0; i < nums.size(); i++) {
            to_complete = target - nums[i];
            if (history.count(to_complete)) {
                return {history[to_complete],i};
            }
            history[nums[i]] = i;
        }
            return {};
    }
};