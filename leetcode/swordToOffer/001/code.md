# 剑指offer 001 整数除法

![20220106194323](https://picture-1308922338.cos.ap-guangzhou.myqcloud.com/note/20220106194323.png)

一开始就是没有思路，只能想到**累加然后对比大小**（~~甚至不如减法~~）。后面修了很多越界的bug后，最后还是报时间错误，毕竟如果从1开始每个加1，加到 ~INT32_MAX~ 要加一万年。

后来受到评论区老哥的指导，采用二分法逐渐缩小范围，应该能达到想要的结果。

1. 首先对输入数据进行处理，包括符号一致（**此处采用负号域，因为从正数加"-"变负数不会出错，但反之则会**）；对MAX和MIN的直接输出，溢出判断等。
2. 处理好的数据（*两个负数*）进行求商操作。大体思路如下：

    ***将 a 转化为 b 进制编码，再右移一位，得到a/b结果***

    e.g. 将 a = -103 转化成 b = 3 进制结果，得到 10210 , 右移1位得到 1021 ， 3进制转10进制得到34即为所求

## 数据处理

    首先只有一个情况会溢出：a = tmin 且 b = -1 (当然事实上b = 1和-1都会直接考虑，但这个会溢出)
    
    首先判断 a ,a =0 : return 0;
    然后判断 b ,如果 b = -1 且 a = tmin ,return tmax;
    b = -1 , a = 其他值，直接返回 -a；
    b = 1, 返回 a;

    然后考虑sign值和正负转换，目的是将a和b转换成负数；
    -103/-3经过下述计算得到-34，而实际应为34，
    故输入ab同号则sign = -1; 异号则sign = 1:

~~~ C

    short sign = -1;
    if(a*b > 0)          // 同号
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
~~~

## 进制转化

    设置大小为32的bool数组a_bool,存储进制转化后的a；

    设置大小为32的int数组b_int,存储计算得到的b的i次方的值；如：
    b_int[0] = -1、
    b_int[1] = -3、
    b_int[2] = -9...... 计算过程如下：

    首先判断a 是否小于 b:
    b_int[0] = -1 : -103 < -1 ;
    b_int[1] = -3 : -103 < -3 ;
    b_int[2] = -9 : -103 < -9 ;
    b_int[3] = -27 : -103 < -27;
    b_int[4] = -81 : -103 < -81;
    b_int[5] = -243 : -103 > -243; (到4为止了)

    a - b_int[5] > 0 , 所以 a_bool[5] = 0; a = a

    a - b_int[4] = (-103) - (-81) = -22 < 0,
    所以 a_bool[4] = 1; a = -22;

    a - b_int[3] > 0, 所以 a_bool[3] = 0; a = a

    a - 2 * b_int[2] = (-22) - 2*(-9) = a = -4 < 0,
    所以 a_bool[2] = 2; a = -4;

    a - b_int[1] = (-4) - (-3) = a = -1 < 0,
    所以 a_bool[1] = 1; a = -1;

    所以 a_bool[0] = 1；

    所以得到a_bool = 00000...010211
    右移得到00000...01021

    转化b进制后得到 -34，得出结果。

## 代码

蚌埠住了，很多地方需要精修，比如求b_int时累加可能越界、比如求a_int时j的取值，各种各样的错误都可能出现，但是思路是对的，采用b进制编码的思路可以降低时间复杂度到log(n)，代码如下：

~~~C

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
~~~

## 结果测试通过

![20220107005010](https://picture-1308922338.cos.ap-guangzhou.myqcloud.com/note/20220107005010.png)
