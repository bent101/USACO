#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<lli ,lli > pii;

bool inint(lli x, pii p) {
  return x >= p.first && x <= p.second;
}

int main() {
  ifstream fin("socdist.in");
  ofstream fout("socdist.out");

  lli n, m;
  fin >> n >> m;
  vector<pii> v;
  for(lli i = 0; i < m; i++) {
    pii a;
    fin >> a.first >> a.second;
    v.push_back(a);
  }
  sort(v.begin(), v.end());

  lli
    a = v[0].first,
    b = v[v.size()-1].second,
    lo = 1,
    hi = (b-a)/(n-1) + 1, mid=2;

  while(lo < hi) {
    mid = lo + (hi-lo+1)/2;
    
    lli i = a, j = 0, numcowsleft = n;
    while(i <= b && numcowsleft > 0) {
      // put a cow and move d forward as many times as you can in this interval
      int numcows = (v[j].second-i) / mid + 1;
      numcowsleft -= numcows;
      i += mid * numcows;
      // interval catches up
      while(j < v.size() && !inint(i, v[j]) && i >= v[j].first)
        j++;
      if(j == v.size()) break;

      // if it goes ahead, i catches up
      if(i < v[j].first) i = v[j].first;

    }

    if(numcowsleft > 0) hi = mid-1;
    else lo = mid;
  }

  fout << lo << endl;

  return 0;
}
