#include<iostream>
#include<unordered_set>
#include<algorithm>
#include<set>
#include<vector>
#include<math.h>

using namespace std;

int main()
{
    set<vector<int>> myset;
    vector<int> vertor1;
    vector<int> vector2;
    vector<int> vector3;

    vertor1.push_back(1);
    vertor1.push_back(2);
    vertor1.push_back(3);

    vector2.push_back(1);
    vector2.push_back(2);
    vector2.push_back(3);
    vector2.push_back(3);

    vector3.push_back(2);
    vector3.push_back(1);
    vector3.push_back(3);

    vector2.erase(max_element(vector2.begin(),vector2.end()));
    cout<<"vector2";
}