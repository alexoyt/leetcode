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
