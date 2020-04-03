#include <bits/stdc++.h>
#include <cmath>
#define v2d vector<vector<int> >
#define v1d vector<int>
using namespace std;
v2d p;

v2d permutate(v1d nums) { // i wrote this before i found out about next_permutation
  v2d temp2d;
  if(nums.size() == 1) {
    temp2d.push_back(nums);
    return temp2d;
  }
  for(int i = 0; i < nums.size(); i++) {
    v1d temp1d = nums;
    temp1d.erase(temp1d.begin()+i);
    for(v1d v : permutate(temp1d)) {
      v.insert(v.begin(), nums[i]);
      temp2d.push_back(v);
    }
  }
  return temp2d;
}

int main() {
  ifstream fin("lineup.in");
  ofstream fout("lineup.out");

  string cows[] = {
    "Beatrice","Belinda","Bella","Bessie","Betsy","Blue","Buttercup","Sue"
  };
  unordered_map<string,int> m;
  for(int i = 0; i < 8; i++)
    m[cows[i]]=i;
  
  
  int n;
  fin >> n;
  pair<int,int> A[n];
  for(int i = 0; i < n; i++) {
    string a, b, c;
    fin >> a >> c >> c >> c >> c >> b;
    A[i].first = m[a];
    A[i].second = m[b];
  }

  v1d nums, order;
  for(int i = 0; i < 8; i++) nums.push_back(i);
  p = permutate(nums);
  for(v1d r : p) {
    for(int& e : r) cout << e << " ";
    cout << endl;
    bool valid = 1;
    for(auto& x : A) {
      auto i1 = find(r.begin(), r.end(), x.first);
      auto i2 = find(r.begin(), r.end(), x.second);
      if(abs(i1-i2) != 1) {
        valid = 0;
        break;
      }
    }
    if(valid) {
      order = r;
      break;
    }
  }

  string ans[8];
  for(int i = 0; i < 8; i++) {
    ans[i] = cows[order[i]];
  }

  for(string& e : ans)
    fout << e << endl;

  fout.close();
  return 0;
}
