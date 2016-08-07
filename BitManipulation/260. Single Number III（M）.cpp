/**
 * ����1��map
 * ����2������bitλ��������������Ҫ�ҵ���������Ϊa,b, �� x = a ^ b��
    ���ȣ�a �϶������� b����ô˵�����ǵĶ�����λһ���ǲ���ȫ��ͬ�ģ����� x �϶���Ϊ 0��
    Ҳ����˵��a �� b һ�����ڡ�ĳһλ����ʹ���������е�ĳ��������0��������һ��������1����������֮���һ�����
    �������������ǿ��Խ����� nums ���Ϸֳ��������ϡ�һ������������ ��ĳһλ�� Ϊ 0 ����nums�е�������������Ϊ���� A��
    ����һ���������� ��ĳһλ�� Ϊ 1 ����nums�е���������
    ���� a ���� ��ĳһλ�� �� 0 ��b �������ĳһλ����1����ô��Ȼa�ڼ���A�У�b�ڼ����У�
    �����������ȫת��������1һ�������������⣬���ǿ��Եá�
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
