/*
27.移除元素
*/
#include <vector>
using namespace std;

class Solution {
 public:
  int removeElement(vector<int>& nums, int val) {
    int left = 0;
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] != val) {
        nums[left++] = nums[i];
      }
    }

    return left;
  }
};