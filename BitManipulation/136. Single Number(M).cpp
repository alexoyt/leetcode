/**
 * ����1��ֱ��������map��Ψһ�ԣ������ݴ���map�У�ʱ�临�Ӷ�O(n),�ռ临�Ӷ�O(n)
 * ����2���������ϣ������������ԣ����ν�������������μ��ɵó�Ψһ������ʱ�临�Ӷ�O(n),�ռ临�Ӷ�O(1)
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
