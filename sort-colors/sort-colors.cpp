class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int minInd;
        
        for(int i=0; i<n; i++) {
            minInd = i;
            for(int j=i+1; j<n; j++) {
                if(nums[j] < nums[minInd]) {
                    minInd = j;
                }
            }
            
            swap(nums[i], nums[minInd]);
        }
    }
};