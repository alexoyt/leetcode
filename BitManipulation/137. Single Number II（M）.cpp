/**
 * ����1������map
 * ����2������λ���㣬����һ����СΪ32������array���ֱ𱣴�ÿbitλ�ĳ��ִ�����������һ��array���ҳ�ģ3������0��Ԫ�أ�
 * �ٽ�����Ԫ����λ����������ɡ�
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
