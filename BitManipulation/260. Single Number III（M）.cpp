/**
 * 方法1：map
 * 方法2：利用bit位操作。假设我们要找的这两个数为a,b, 而 x = a ^ b。
    首先，a 肯定不等于 b，那么说明它们的二进制位一定是不完全相同的，所以 x 肯定不为 0。
    也就是说，a 与 b 一定存在“某一位”，使得在它们中的某个数中是0，而在另一个数中是1，这是他们之间的一个差别。
    利用这个差别，我们可以将整个 nums 集合分成两个集合。一个集合中是这 “某一位” 为 0 的在nums中的所有数，假设为集合 A。
    而另一个集合是这 “某一位” 为 1 的在nums中的所有数。
    假设 a 的这 “某一位” 是 0 ，b 的这个“某一位”是1，那么显然a在集合A中，b在集合中，
    这样问题就完全转化成了与1一样的两个子问题，于是可以得。
    */

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int x=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            x=x^nums[i];
        }
        int temp=1;
        while((x&temp)==0)
            temp<<=1;
        int res1,res2;
        bool setres1=false,setres2=false;
        //cout<<x<<" "<<temp<<endl;
        for(int i=0;i<nums.size();i++)
        {
            if((nums[i]&temp)!=0)
            {
                if(!setres1)
                {
                    res1=nums[i];
                    setres1=true;
                }
                else
                    res1=res1^nums[i];
            }
            else
            {
                if(!setres2)
                {
                    res2=nums[i];
                    setres2=true;
                }
                else
                    res2=res2^nums[i];
            }
        }
        vector<int> array={res1,res2};
        return array;
    }
};
