#include <random>
#include <vector>
using namespace std;

class Solution {
 public:
  void maxHeapify(vector<int>& nums, int m, int heapSize) {
    int left = m * 2 + 1;
    int right = m * 2 + 2;
    int largest = m;

    if (left < heapSize && nums[left] > nums[largest]) {
      largest = left;
    }
    if (right < heapSize && nums[right] > nums[largest]) {
      largest = right;
    }
    if (largest != m) {
      swap(nums[m], nums[largest]);
      maxHeapify(nums, largest, heapSize);
    }
  }

  void buildMaxHeap(vector<int>& nums, int heapSize) {
    for (int i = heapSize / 2; i >= 0; i--) {
      maxHeapify(nums, i, heapSize);
    }
  }

  int findKthLargest(vector<int>& nums, int k) {
    int heapSize = nums.size();
    buildMaxHeap(nums, heapSize);
    for (int i = nums.size() - 1; i >= nums.size() - k + 1; i--) {
      swap(nums[0], nums[i]);
      heapSize--;
      maxHeapify(nums, 0, heapSize);
    }
    return nums[0];
  }
};