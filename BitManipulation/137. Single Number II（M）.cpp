/**
 * 方法1：利用map
 * 方法2：利用位运算，设置一个大小为32的数组array，分别保存每bit位的出现次数，最后遍历一次array，找出模3不等于0的元素，
 * 再将各个元素移位相加起来即可。
 */


class Solution {
public:
    int singleNumber(vector<int>& nums) {
        vector<int> array(32,0);
        for(int i=0;i<nums.size();i++)
        {
            
            for(int j=0;j<32;j++)
            {
                int temp=(1<<j);

                if((nums[i]&(1<<j))!=0)
                {

                    array[j]++;

                }
            }
        }
        int res=0;
        for(int i=0;i<32;i++)
            if(array[i]%3!=0)
                res+=1<<i;
    
        return res;
    }
};
