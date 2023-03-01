class Solution {
public:
    void maxHeapify(vector<int>& nums, int size, int ind) {
        int left = 2*ind + 1;
        int right = 2*ind + 2;
        int largest = ind;

        if(left < size && nums[left] > nums[largest]) {
            largest = left;
        }

        if(right < size && nums[right] > nums[largest]) {
            largest = right;
        }

        if(largest != ind) {
            swap(nums[ind], nums[largest]);
            maxHeapify(nums, size, largest);
        }
    }

    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();

        for(int i=n/2-1; i>=0; i--) {
            maxHeapify(nums, n, i);
        }

        for(int i=n-1; i>=0; i--) {
            swap(nums[i], nums[0]);
            maxHeapify(nums, i, 0);
        }

        return nums;
    }
};