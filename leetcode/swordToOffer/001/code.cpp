#include <iostream>

using namespace std;

class Solution
{
public:
    static int divide(int a, int b)
    {
        if (a == 0) return 0;
        if (a == b) return 1;
        if (b == 1) return a;
        else if (b == -1)
        {
            if(a == INT32_MIN)
            {
                return INT32_MAX;
            }
            return -a;
        }

        short sign = -1;
        if(a>0&&b>0 || a<0&&b<0)          // 同号
        {
            if(a > 0) 
            {
                a = -a;
                b = -b;
            }
        }
        else               //异号
        {
            sign = 1;
            if(a > 0) a = -a;
            else b = -b;
        }

        int a_int[32] = {0};
        int b_int[32] = {0};

        b_int[0] = -1;
        b_int[1] = b;

        int i = 1;
        for(;i<32;i=i+1) //初始化b_int
        {
            bool breakout = false;
            if(a >= b_int[i])
            {
                if(a == b) i = i+1;
                break;
            }
            // 计算 b_int[i+1]
            for(int j = 0; j< -b;j=j+1)     // 这里直接-b不会溢出，因为运行到这里a,b不相等，且a<=b,所以 b != tmin
            {
                if(double(b_int[i+1]) + double(b_int[i]) < INT32_MIN)  //溢出
                {
                    i = i+1;
                    breakout = true;
                    break;
                }
                b_int[i+1] = b_int[i+1] + b_int[i];
            }
            if(breakout) break;
        }
        
        // 计算a_bool
        i = i - 1;
        for (;i>0;i=i-1) // a_int[0]值并不重要，会被舍弃，所以i=0：break
        {
            int j = 0;
            for(;j<-b;j++)
            {
                a = a - b_int[i];
                if(a >= 0)
                {
                    if(a == 0) j = j+1;
                    else  //剪多了，应加回来
                    {
                        a = a + b_int[i];
                    }
                    break;
                }
            }
            
            a_int [i] = j;
        }
        // 以上 ， a_int 也计算结束

        // 最后，右移后再转化为10进制则结束(这里a取值混乱是我为了提高效率，勿仿)
        a = 0;
        i = 0;
        for(;i<31;i=i+1)
        {
            int j = 0;
            while (j < a_int[i+1])
            {
                a = a + b_int[i];
                j = j + 1;
            }
        }

        return a * sign;
    };
};

int main()
{
    Solution solution ;
    int result = solution.divide(2147483647,3);
    cout<<result;
}