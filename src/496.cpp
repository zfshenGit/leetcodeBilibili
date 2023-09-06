/*
496.下一个更大元素
*/
#include <stack>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    stack<int> st;
    unordered_map<int, int> mp;

    for (int i = nums2.size() - 1; i >= 0; i--) {
      while (!st.empty() && nums2[i] > st.top()) {
        st.pop();
      }

      mp[nums2[i]] = st.empty() ? -1 : st.top();

      st.push(nums2[i]);
    }

    vector<int> result(nums1.size());
    for (int i = 0; i < nums1.size(); i++) {
      result[i] = mp[nums1[i]];
    }

    return result;
  }
};