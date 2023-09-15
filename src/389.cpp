#include <set>
#include <string>
using namespace std;

class Solution {
 public:
  char findTheDifference(string s, string t) {
    int result = 0;
    for (char ch : s + t) {
      result ^= ch;
    }
    return result;
  }
};