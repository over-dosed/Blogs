#include<iostream>
#include<math.h>
using namespace std;

class Solution {
public:
    int bulbSwitch(int n) 
    {
        return (int) sqrt(n);
    }
};

int main()
{
    Solution solution ;
    int result = solution.bulbSwitch(36);
    cout<<result;
}