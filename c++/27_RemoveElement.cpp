class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int lastidx = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != val) {
                nums[lastidx] = nums[i];
                lastidx++;
            }
        }
        return lastidx;
    }
};
