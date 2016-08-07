/**
 * 方法1：找出两个集合的交集，并且交集中不能够有重复的元素
 * 利用map的唯一性和高效查找性（查找效率为log(N)）
 * 对nums1和num2分别构建一个map，剔除重复的元素，再遍历nums1，查找nums2中是否有这个数，如果有则加入array中
 * 时间复杂度O(n*logn),空间复杂度O(n)
 * 
 * 思路2：根据Tag思考可以先对两个数组排序，排序后依次比较大小
 * (1)num1>num2时，i++;(2)num1<num2时，j++;(3)num1==num2时，加入array中，i++,j++,直到num1[i]!=num1[i-1]，num2[i]!=num2[i-1]
 * 时间复杂度、空间复杂度同上
 *
 */
 


class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        map<int,bool> Map1,Map2;
        vector<int> array;
        for(int i=0;i<nums1.size();i++)
            Map1[nums1[i]]=true;
        for(int i=0;i<nums2.size();i++)
            Map2[nums2[i]]=true;
        map<int,bool>::iterator i=Map1.begin();
        for(;i!=Map1.end();i++)
            if(Map2.find(i->first)!=Map2.end())
                array.push_back(i->first);
        return array;
    }
};
