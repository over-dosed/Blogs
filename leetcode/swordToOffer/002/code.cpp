#include <iostream>

using namespace std;

class Solution
{
public:
    static string addBinary(string a, string b) 
    {
        int aLength = a.length();
        int bLength = b.length();
        int count = aLength > bLength ? aLength : bLength;
        int diff = aLength - bLength;

        string result = "";
        bool sign = false;        // 进位标志
        int i = count -1;

        if(diff >= 0)  //a 长度大于等于 b长度
        {
            for(int i = count-1; i>= 0; i = i - 1)
            {
                int num_a = a[i]-48;
                if(i < diff) //b遍历完了
                {
                    if(sign && num_a)  // 要进位
                    {
                        result = "0" + result;
                        sign = true;
                    }
                    else if(sign || num_a) // 
                    {
                        result = "1" + result;
                        sign = false;
                    }
                    else
                    {
                        result = "0" + result;
                    }
                    continue;
                }

                // b没遍历完
                int num = b[i-diff]-48 + num_a + sign;
                switch (num)
                {
                    case 2:
                    {
                        sign = true;
                        result = "0" + result;
                        break;
                    }
                    case 1:
                    {
                        sign = false;
                        result = "1" + result;
                        break;
                    }
                    case 0:
                    {
                        result = "0" + result;
                        break;
                    }
                    case 3:
                    {
                        result = "1" + result;
                        break;
                    }
                }
            }
        }
        else          // a 长度小于 b 长度
        {
            for(int i = count-1; i>= 0; i = i - 1)
            {
                int num_b = b[i]-48;
                if(i < -diff) //a遍历完了
                {
                    if(sign && num_b)  // 要进位
                    {
                        result = "0" + result;
                        sign = true;
                    }
                    else if(sign || num_b) // 
                    {
                        result = "1" + result;
                        sign = false;
                    }
                    else
                    {
                        result = "0" + result;
                    }
                    continue;
                }

                // a没遍历完
                int num = a[i+diff]-48 + num_b + sign;
                switch (num)
                {
                    case 2:
                    {
                        sign = true;
                        result = "0" + result;
                        break;
                    }
                    case 1:
                    {
                        sign = false;
                        result = "1" + result;
                        break;
                    }
                    case 0:
                    {
                        result = "0" + result;
                        break;
                    }
                    case 3:
                    {
                        result = "1" + result;
                        break;
                    }
                }
            }
        }
        if(sign) result = "1"+result;
        return result;
    }
};

int main()
{
    Solution solution ;
    string result = solution.addBinary("1","111");
    cout<<result;
}

