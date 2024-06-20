#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
   int leastInterval(vector<char> &tasks, int n)
   {
      int pos[26];
      memset(pos, -1, sizeof(pos));
      unordered_map<char, int> mp;
      for (int i = 0; i < tasks.size(); i++)
      {
         mp[tasks[i]]++;
      }
      priority_queue<pair<int, char>> pq;
      for (auto &x : mp)
      {
         pq.push({x.second, x.first});
      }
      int i = 0;
      int cycle=0;
      while (!pq.empty())
      {
         auto x = pq.top();
         pq.pop();
         int freq = x.first - 1;
         char c = x.second;
         if (pos[c - 'A'] == -1)
         {
            pos[c - 'A'] = i;
            i++;
            if (freq > 0)
            {
               pq.push({freq, c});
            }
            continue;
         }
         int p = i - pos[c - 'A'];
         if (p > n)
         {
            pos[c - 'A'] = i;
            i++;
            if (freq > 0)
            {
               pq.push({freq, c});
            }
            cycle++;
         }
         else{
            i=n-p-1;
            if(freq>0){
               pq.push({freq,c});
            }
            cycle++;
         }
      }
   }
};
int main()
{
   int n = 9, m = 1953125;
   cout << "Nth Root of " << m << " is: " << NthRoot(n, m) << endl;
   return 0;
}