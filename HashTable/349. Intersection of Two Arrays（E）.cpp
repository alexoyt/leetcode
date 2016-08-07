/**
 * ����1���ҳ��������ϵĽ��������ҽ����в��ܹ����ظ���Ԫ��
 * ����map��Ψһ�Ժ͸�Ч�����ԣ�����Ч��Ϊlog(N)��
 * ��nums1��num2�ֱ𹹽�һ��map���޳��ظ���Ԫ�أ��ٱ���nums1������nums2���Ƿ��������������������array��
 * ʱ�临�Ӷ�O(n*logn),�ռ临�Ӷ�O(n)
 * 
 * ˼·2������Tag˼�������ȶ���������������������αȽϴ�С
 * (1)num1>num2ʱ��i++;(2)num1<num2ʱ��j++;(3)num1==num2ʱ������array�У�i++,j++,ֱ��num1[i]!=num1[i-1]��num2[i]!=num2[i-1]
 * ʱ�临�Ӷȡ��ռ临�Ӷ�ͬ��
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
