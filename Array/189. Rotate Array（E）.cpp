/**
 * 空间复杂度O(1)解法：前半部分反转，后半部分反转，再整体反转。
 * reverse(nums, nums+(n-k));
 * reverse(nums+(n-k), nums+n);
 * reverse(nums, nums+n);
 */
 

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>array;
        k=k%n;
        for(int i=n-k;i<n;i++)
            array.push_back(nums[i]);
        for(int i=0;i<n-k;i++)
            array.push_back(nums[i]);
        nums=array;
    }
};
