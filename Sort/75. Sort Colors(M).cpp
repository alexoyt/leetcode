/**
 * ��Ŀ��˼�Ǹ��������������ɫ�ֱ���0,1,2���棬Ҫ����������ɫ������������
 * ����1��ֱ�Ӵ���һ���µ�vector<int>��������ԭ�������飬���ν�0,1,2��ӵ��������У�ʱ�临�Ӷ�O(n)���ռ临�Ӷ�O(n)
 * ����2������Ԫ��0��1��2,�ֱ����β�������飬�������ʱ��һֱ����ֱ���ҵ���0Ԫ��λ��i���������ʱ��һֱ����֪���ҵ�0Ԫ��λ��j
 * array[i]��array[j]������֪��i<j������������Ԫ��1��2ͬ��ʱ�临�Ӷ�O(n),�ռ临�Ӷ�O(1)
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
