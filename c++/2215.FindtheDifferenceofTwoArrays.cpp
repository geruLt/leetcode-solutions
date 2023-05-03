class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<int> diff1 = {};
        vector<int> diff2 = {};
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        for (int i = 0; i < nums1.size(); i++) {
            for (int j = 0; j < nums2.size(); j++) {
                if (nums1[i] == nums2[j]) {
                    break;
                }
                else if (nums2[j] > nums1[i] || j == nums2.size()-1){
                    diff1.push_back(nums1[i]);
                    break;

                }
            }
        }

        for (int k = 0; k < nums2.size(); k++) {
            for (int l = 0; l < nums1.size(); l++) {
                if (nums2[k] == nums1[l]) {
                    break;
                }
                else if (nums1[l] > nums2[k] || l == nums1.size()-1){
                    diff2.push_back(nums2[k]);
                    break;
                }
            }
        }
        diff1.erase( unique( diff1.begin(), diff1.end() ), diff1.end() );
        diff2.erase( unique( diff2.begin(), diff2.end() ), diff2.end() );
        return {diff1, diff2};

    }
};