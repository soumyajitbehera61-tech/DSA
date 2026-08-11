class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        
        
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < n - 2; i++) {
            
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            
            int left = i + 1;
            int right = n - 1;
            
            while (left < right) {
                int s = nums[i] + nums[left] + nums[right];
                
                if (s < 0) {
                    left++;
                }
                else if (s > 0) {
                    right--;
                }
                else {
                    ans.push_back({nums[i], nums[left], nums[right]});
                    left++;
                    right--;
                    
                    // Skip duplicates for the second element
                    while (left < right && nums[left] == nums[left - 1]) {
                        left++;
                    }
                    // Skip duplicates for the third element
                    while (left < right && nums[right] == nums[right + 1]) {
                        right--;
                    }
                }
            }
        }
        return ans;
    }
};