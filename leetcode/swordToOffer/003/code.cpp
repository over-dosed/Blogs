#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
        vector<int> countBits(int n) 
        {   
            vector<int> result = vector<int>(n+1,0);
            for(int i = 1; i<= n ; i = i+1)
            {
                result[i] = result[i>>1] + (i%2); 
            }
            return result;
        }
};

int main()
{
    Solution solution ;
    vector<int> result = solution.countBits(5);
    cout<<result[1];
}

