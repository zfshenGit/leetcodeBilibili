/*
283.移动零
*/
#include <vector>
using namespace std;

class Solution {
 public:
  void moveZeroes(vector<int>& nums) {
    // 双指针，左指针寻找新列表的位置，右指针寻找新列表对应位置的元素
    int left = 0;
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] != 0) {
        nums[left] = nums[i];
        left++;
      }
    }

    for (int i = left; i < nums.size(); i++) {
      nums[i] = 0;
    }
  }
};