#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;

int main() {
  ifstream fin("reststops.in");
  ofstream fout("reststops.out");

  int l, n, rf, rb;
  fin >> l >> n >> rf >> rb;
  
  vector<pii> v;

  for(int i=0;i<n;i++) {
    int x, c;
    fin >> x >> c;
    v.push_back(pii(c,x));
  }

  sort(v.begin(), v.end());
  reverse(v.begin(), v.end());

  int lastX = 0;
  unsigned long long int sum = 0;
  for(int i=0;i<n;i++) {
    if(v[i].second < lastX) continue; // cant go backwards
    unsigned long long int t = (v[i].second - lastX) * (rf - rb);
    lastX = v[i].second;
    sum += t * v[i].first;
  }

  fout << sum << endl;

  fout.close();
  return 0;
}
