/*
485.最大连续1的个数
*/
#include <vector>
using namespace std;

class Solution {
 public:
  int findMaxConsecutiveOnes(vector<int>& nums) {
    int sum = 0;     // 求和
    int result = 0;  // 输出结果

    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] != 0) {
        sum += nums[i];
      } else {
        result = max(result, sum);
        sum = 0;
      }
    }

    return max(result, sum);
  }
};