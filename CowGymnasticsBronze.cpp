#include <bits/stdc++.h>
#include <cmath>
using namespace std;


int main() {
  ifstream fin("gymnastics.in");
  ofstream fout("gymnastics.out");

  int k, n;
  fin >> k >> n;

  int A[k][n];
  for(int i = 0; i < k; i++) {
    for(int j = 0; j < n; j++) {
      int a;
      fin >> a;
      A[i][a-1] = j;
    }
  }
  int count = 0;
  for(int a = 0; a < n; a++) {
    for(int b = 0; b < n; b++) {
      if(a == b) continue;
      bool c = true;
      for(int i = 0; i < k && c; i++) {
        if(A[i][a] > A[i][b])
          c = false;
      }
      if(c) count++;
    }
  }

  fout << count << endl;
  
  fout.close();
  return 0;
}
