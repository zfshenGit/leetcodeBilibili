/*
20.有效的括号
*/
#include <stack>
#include <string>
using namespace std;

class Solution {
 public:
  bool isValid(string s) {
    stack<int> st;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == '(') {
        st.push(')');
      } else if (s[i] == '[') {
        st.push(']');
      } else if (s[i] == '{') {
        st.push('}');
      } else if (st.empty()) {
        return false;
      } else if (s[i] != st.top()) {
        return false;
      } else {
        st.pop();
      }
    }
    return st.empty();
  }
};