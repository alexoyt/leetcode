/**
 * 很恨很典型的问题，碰到过不止一次了，不过还是不记得解法
 * 第一次先建立一个数组array维护每个灯泡的状态，再从1~n遍历一次，每次对i的倍数更改其array[i]的状态，时间复杂度O(n*n)超时
 * 之后想O(n*n)不行肯定是O(n)或O(nlogn)，即不能维护状态了，遍历一次就应该得出结果；
 * 观察发现状态的改变的次数实质是这个数可以分解为多少个数相乘，即12分解为1、2、3、4、6、12偶数个，所以最后状态为off
 * 再思考发现除了平方数，每个数都必然分解为偶数个数相乘，即最后都为off，所以遍历一次，输出平方数的个数，，时间复杂度O(n)，仍然超时
 * 最后查资料再发现自己sb了，直接调用sqrt(n)再强制类型转换为(int)就好了，根本不用遍历，时间复杂度为O(1);
 */
 



class Solution {
public:
    int bulbSwitch(int n) {
        return (int)sqrt(n);
    }
};
