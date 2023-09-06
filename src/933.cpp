/*
933.最近的请求次数
*/
#include <queue>
using namespace std;

class RecentCounter {
  queue<int> qe;

 public:
  RecentCounter() {}

  int ping(int t) {
    qe.push(t);
    while (t - qe.front() > 3000) {
      qe.pop();
    }
    return qe.size();
  }
};