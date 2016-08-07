/**
 * �ⷨ�ο���http://www.cnblogs.com/NickyYe/p/4337497.html
 * 
 * ����1�����г���������׶��Ǽ�����������dividendһ�δμ�ȥdivisor,ͬʱ����count����ʱ��������
 * 
 * ����2������˼·���������ӱ�������kλ����ֱ�������ﵽ�ٽ�ֵ��С�ڱ���������ͬʱ1����kλ���ӵ�count�ϣ���������ȥ���ٽ�ֵ
 * �������ƣ�ֱ��������С�ڳ������ó�count
 * ע�⣺
 * 1.�������ݻ������Ҫ����Ϊ
 * dividend=INT_MIN,divisor=INT_MIN��   -2147483648/-2147483648�����1
 * dividend=INT_MIN,divisor=-1��        -2147483648/-1�����2147483647
 * dividend=INT_MIN,divisor!=INT_MIN��  -2147483648/��������count+1,dividend=dividend-abs(divisor)
 * dividend!=INT_MIN,divisor=INT_MIN    ������/-2147483648�����0
 * dividend=0��0/�κ��������0
 * divisor=0������Ϊ0�����2147483647
 * ����
 * 2.�ж������� ((dividend ^ divisor) >> 31) == 1
 */
 


class Solution {
public:
    int divide(int dividend, int divisor) {
        if(divisor==0)
            return INT_MAX;
        if(dividend==0)
            return 0;
        
        if(divisor==INT_MIN)
        {
            if(dividend==INT_MIN)
                return 1;
            else
                return 0;
        }
        
        if(dividend==INT_MIN)
            if(divisor==-1)
                return INT_MAX;
        
        bool ispos=true;
        long long count=0;
        if(dividend>0&&divisor<0)
            ispos=false;
        if(dividend<0&&divisor>0)
            ispos=false;
        
        if(dividend==INT_MIN)
        {
            count++;
            dividend+=abs(divisor);
        }
        if(divisor==INT_MIN)
            return count;
        dividend=abs(dividend);
        divisor=abs(divisor);
        //cout<<dividend<<" "<<divisor<<endl;
        while(dividend>=divisor)
        {
            long long  temp=divisor,i;
            for(i=0;temp<=dividend;i++,temp<<=1)
            {
            
            dividend-=temp;
            count+=1<<i;
            }
        }
        return ispos?count:(-count);
    }
};
