#include <random>
#include <vector>
using namespace std;

class Solution {
 public:
  int partition(vector<int>& nums, int left, int right) {
    int i = rand() % (right - left + 1) + left;
    swap(nums[left], nums[i]);
    int pivotkey = nums[left];
    while (left < right) {
      while (left < right && nums[right] <= pivotkey) {
        right--;
      }
      swap(nums[left], nums[right]);
      while (left < right && nums[left] >= pivotkey) {
        left++;
      }
      swap(nums[left], nums[right]);
    }
    return left;
  }

  void quickSort(vector<int>& nums, int left, int right, int k) {
    int pivot;
    if (left < right) {
      pivot = partition(nums, left, right);
      if (pivot == k - 1) {
        return;
      } else if (pivot < k - 1) {
        quickSort(nums, pivot + 1, right, k);
      } else {
        quickSort(nums, left, pivot - 1, k);
      }
    }
  }

  int findKthLargest(vector<int>& nums, int k) {
    if (nums.size() == 0) {
      return 0;
    }
    if (k > nums.size()) {
      k = nums.size();
    }

    quickSort(nums, 0, nums.size() - 1, k);
    return nums[k - 1];
  }
};