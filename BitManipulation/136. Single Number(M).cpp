/**
 * 方法1：直接用利用map的唯一性，将数据存入map中，时间复杂度O(n),空间复杂度O(n)
 * 方法2：参照网上，利用异或的特性，依次将所有数异或依次即可得出唯一的数，时间复杂度O(n),空间复杂度O(1)
 */ 

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        map<int,int> Map;
        for(int i=0;i<nums.size();i++)
            Map[nums[i]]++;
        map<int,int>::iterator i;
        int res=0;
        for(i=Map.begin();i!=Map.end();i++)
            if(i->second==1)
                res=i->first;
        return res;
    }
};
