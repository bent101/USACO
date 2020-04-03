#include <bits/stdc++.h>
using namespace std;

struct Mtn {
  int x, y;
  bool under(Mtn m) {
    int xdif = abs(x - m.x);
    if(xdif > m.y) return false;
    return xdif <= m.y - y;
  }
};

int main() {
  ifstream fin("mountains.in");
  ofstream fout("mountains.out");

  vector<Mtn> mtns;
  int n;
  fin >> n;
  for(int i=0;i<n;i++) {
    Mtn m;
    fin >> m.x >> m.y;
    bool visible = true;
    for(Mtn& m2 : mtns) {
      if(m.under(m2)) visible = false;
      if(!visible) break;
    }
    if(visible) {
      mtns.push_back(m);
      for(int i=mtns.size()-2; i>=0; i--)
        if(mtns[i].under(m))
          mtns.erase(mtns.begin() + i);
    }
  }
  
  fout << mtns.size() << endl;

  fout.close();
  return 0;
}
