#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/* it is using built-in function but is only supported to c++ not in other languages*/
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        next_permutation(nums.begin(), nums.end());
    }
};