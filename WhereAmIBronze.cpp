#include <bits/stdc++.h>
#include <cmath>
using namespace std;


int main() {
  ifstream fin("whereami.in");
  ofstream fout("whereami.out");

  int n, i=1;
  bool found = 0;
  string str;
  fin >> n >> str;
  for(; i <= n; i++) {
    unordered_set<string> s;
    found = 1;
    for(int j = 0; j <= n - i; j++) {
      string sub = str.substr(j, i);
      if(s.find(sub) != s.end()) {
        found = 0;
        continue;
      }
      s.insert(sub);
    }
    if(found) break;
  }

  fout << i << endl;
  
  fout.close();
  return 0;
}
