/**
 * 解法参考：http://www.cnblogs.com/NickyYe/p/4337497.html
 * 
 * 方法1：所有除法归根到底都是减法，所以用dividend一次次减去divisor,同时计数count。超时，不可行
 * 
 * 方法2：基本思路：将除数加倍（左移k位），直到除数达到临界值（小于被除数），同时1左移k位，加到count上，被除数减去此临界值
 * 依次类推，直到被除数小于除数，得出count
 * 注意：
 * 1.由于数据会溢出，要分类为
 * dividend=INT_MIN,divisor=INT_MIN、   -2147483648/-2147483648，输出1
 * dividend=INT_MIN,divisor=-1、        -2147483648/-1，输出2147483647
 * dividend=INT_MIN,divisor!=INT_MIN、  -2147483648/正常数，count+1,dividend=dividend-abs(divisor)
 * dividend!=INT_MIN,divisor=INT_MIN    正常数/-2147483648，输出0
 * dividend=0、0/任何数，输出0
 * divisor=0、除数为0，输出2147483647
 * 正常
 * 2.判断正负号 ((dividend ^ divisor) >> 31) == 1
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
