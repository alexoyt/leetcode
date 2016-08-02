/**
 * 先固定最高位，看次高位的取值范围，再固定次高位，看下一位的取值范围，以此类推
 * 当n=0时，初始数目为1；当n=1，位数为1时，范围为0~9,表示个位可取的个数是10，则总数目num=10;
 * 对于n>1，先假设最高位可取0，则第n位可取10，第n-1位可取9，以此类推；再减去最高位为0时，多计算的数目：9...(10-n+1)。
 * 则总数组num=array[n-1]+10*9...(10-n+1)-9...(10-n+1)=array[n-1]+9*8*(10-n-1)
 * 注意当n>10之后，10个数字，11位数必定有重复，所有可令array[n]=array[n-1];
 * 
 * 方法2，回溯，思路参照网上：设置一个数num，用它的二进制位的0,1表示0-9这9个数字是否被使用过；如果当前的数字未被使用过：
 * 1：将相应的二进制位设置为1，总次数count+1,递归调用；否则i++直到i>9,返回上一层。上一层返回后清除之前设置的标志位，i++直到i>9
 */ 
	
class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        vector<int> array;
        array.push_back(1);
        for(int i=1;i<=n;i++)
        {
            if(i>10)
                array.push_back(array[i-1]);
            int add=9,num=9;
            for(int j=1;j<i;j++)
            {
                add*=num;
                num--;
            }
            array.push_back(array[i-1]+add);
        }
        return array[n];
    }
};
