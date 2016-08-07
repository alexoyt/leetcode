/**
 * 思路: 需要用到的数学知识
 * 1. a^b % 1337 = (a%1337)^b % 1337
 * 2. xy % 1337 = ((x%1337) * (y%1337)) % 1337, 其中xy是一个数字如:45, 98等等
 * 第一个公式可以用来削减a的值, 第二个公式可以将数组一位位的计算, 比如 12345^678, 首先12345可以先除余1337, 设结果为X, 则原式就可以化为: 
 * X^678 = ((X^670 % 1337) * (X^8 % 1337)) % 1337 = (pow((X^670 % 1337), 10) * (X^8 % 1337)) % 1337
 * 在上面我用了一个pow来化简表示 X^670 = pow(X^670, 10), 当然不是库函数里面pow, 因为会超出界限
 * 因此我们需要自己在写一个pow来一个个的边乘边除余.
 *copy自：http://blog.csdn.net/qq508618087/article/details/51860222
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
