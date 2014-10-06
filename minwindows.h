#ifndef LEETCODE_H
#define LEETCODE_H

#include <map>
#include <string>
#include <utility>
#include <vector>
#include <list>
#include <climits>
#include <queue>
using namespace std;
#include <string.h>

class Solution {
  public:
    string minWindow(string S, string T) {
      map<char, int> counter;
      map<char, queue<list<int>::iterator>> c;
      list<int> queue;
      int remaining = T.length();
      int minimumLength = INT_MAX;
      string retValue = "";
      for (char t : T) {
        if (counter.count(t) == 0) {
          counter.insert(pair<char, int>(t, 0));
        }
        counter[t]++;
      }
      for (int j = 0; j < S.length(); j++) {
        if (counter.count(S[j]) != 0) {
          int i = counter[S[j]];
          if (i == 0) {
            auto i = c.at(S[j]).front();
            queue.erase(i);
            c[S[j]].pop();
          } else {
            counter[S[j]]--;
            remaining--;
          }
          queue.push_back(j);
          c[S[j]].push(--queue.end());
          if (remaining == 0 && j - queue.front() < minimumLength) {
            minimumLength = j - queue.front();
            retValue = S.substr(queue.front(), minimumLength + 1);
          }
        }
      }
      return retValue;
    }

};
#endif

