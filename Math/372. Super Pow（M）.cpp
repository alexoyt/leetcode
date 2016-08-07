/**
 * ˼·: ��Ҫ�õ�����ѧ֪ʶ
 * 1. a^b % 1337 = (a%1337)^b % 1337
 * 2. xy % 1337 = ((x%1337) * (y%1337)) % 1337, ����xy��һ��������:45, 98�ȵ�
 * ��һ����ʽ������������a��ֵ, �ڶ�����ʽ���Խ�����һλλ�ļ���, ���� 12345^678, ����12345�����ȳ���1337, ����ΪX, ��ԭʽ�Ϳ��Ի�Ϊ: 
 * X^678 = ((X^670 % 1337) * (X^8 % 1337)) % 1337 = (pow((X^670 % 1337), 10) * (X^8 % 1337)) % 1337
 * ������������һ��pow�������ʾ X^670 = pow(X^670, 10), ��Ȼ���ǿ⺯������pow, ��Ϊ�ᳬ������
 * ���������Ҫ�Լ���дһ��pow��һ�����ı߳˱߳���.
 *copy�ԣ�http://blog.csdn.net/qq508618087/article/details/51860222
 */


class Solution {  
public:  
    int superPow(int a, int k)  
    {  
        if(k ==0) return 1;  
        int ans = 1;  
        for(int i = 1; i <= k; i++) ans = (ans*a) %1337;  
        return ans;  
    }  
      
    int superPow(int a, vector<int>& b) {  
        if(b.empty()) return 1;  
        a = a%1337;  
        int lastBit = b.back();  
        b.pop_back();  
        return (superPow(superPow(a, b), 10) * superPow(a, lastBit))%1337;  
    }  
}; 
