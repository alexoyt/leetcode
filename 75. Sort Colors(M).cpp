/**
 * 题目意思是给定红白蓝三中颜色分别用0,1,2代替，要求将这三种颜色按红白蓝排序好
 * 方法1：直接创建一个新的vector<int>遍历三次原来的数组，依次将0,1,2添加到新数组中，时间复杂度O(n)，空间复杂度O(n)
 * 方法2：对于元素0和1、2,分别从首尾遍历数组，正向遍历时，一直递增直到找到非0元素位置i，反向遍历时，一直递增知道找到0元素位置j
 * array[i]与array[j]交换，知道i<j不成立。对于元素1、2同理。时间复杂度O(n),空间复杂度O(1)
 *
 */

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size();
        int i,j;
        for(i=0,j=n-1;i<j;i++,j--)
        {
            while(i<j&&nums[i]==0)
                i++;
            while(j>i&&nums[j]!=0)
                j--;
            int temp=nums[i];
            nums[i]=nums[j];
            nums[j]=temp;
        }
        for(i=0;i<n;i++)
            if(nums[i]!=0)
                break;
        for(j=n-1;i<j;i++,j--)
        {
            while(i<j&&nums[i]==1)
                i++;
            while(j>i&&nums[j]==2)
                j--;
            int temp=nums[i];
            nums[i]=nums[j];
            nums[j]=temp;
        }
    }
};
