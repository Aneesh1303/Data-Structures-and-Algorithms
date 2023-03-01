class Solution {
public:
    int partition(vector<int>& nums, int left, int right) {
        int pivot = nums[left];
        int l = left+1;
        int r = right;

        while(l <= r) {
            if(nums[l] < pivot && nums[r] > pivot) {
                swap(nums[l], nums[r]);
                l++;
                r--;
            }

            if(nums[l] >= pivot) {
                l++;
            }

            if(nums[r] <= pivot) {
                r--;
            }
        }

        swap(nums[left], nums[r]);
        return r;
    }

    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        int left = 0;
        int right = n-1;
        int kth;

        while(1) {
            int ind = partition(nums, left, right);

            if(ind == k-1) {
                kth = nums[ind];
                break;
            }
            
            if(ind < k-1) {
                left = ind+1;
            }
            else {
                right = ind-1;
            }
        }

        return kth;
    }
};