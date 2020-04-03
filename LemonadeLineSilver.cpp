#include <bits/stdc++.h>
using namespace std;

int main() {
  ifstream fin("lemonade.in");
  ofstream fout("lemonade.out");

  int n;
  fin >> n;
  vector<int> v;
  for(int i=0;i<n;i++) {
    int w; fin >> w;
    v.push_back(w);
  }
  sort(v.begin(), v.end());

  int i = 0;
  while(v[n-1-i] >= i) i++;

  fout << i << endl;

  fout.close();
  return 0;
}
