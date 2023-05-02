class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int lastidx = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[lastidx]) {
                lastidx++;
                nums[lastidx] = nums[i];
            }
        }
        return lastidx + 1;
    }
};
