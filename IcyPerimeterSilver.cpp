#include <bits/stdc++.h>
#include <cmath>
using namespace std;
typedef pair<int,int> pii;

template <typename T,typename U>
pair<T,U> operator + (const pair<T,U> &l,const pair<T,U> &r) {
    return { l.first+r.first, l.second+r.second };
}

int n;

bool inBounds(pii p) {
  return p.first>=0&&p.first<n&&p.second>=0&&p.second<n;
}

int main() {
  ifstream fin("perimeter.in");
  ofstream fout("perimeter.out");

  fin >> n;
  vector<pii> dirs { pii(1,0),pii(-1,0),pii(0,1),pii(0,-1) };
  
  bool grid[n][n];
  bool visited[n][n];
  for(int i = 0; i < n; i++) {
    string line;
    fin >> line;
    for(int j = 0; j < n; j++) {
      grid[i][j] = line[j] == '#';
      visited[i][j] = false;
    }
  }

  int maxArea = 0, minPerimeter = INT_MAX;

  for(int r = 0; r < n; r++) {
    for(int c = 0; c < n; c++) {
      if(!grid[r][c] || visited[r][c]) continue;
      queue<pii> q;
      q.push(pii(r,c));
      int area = 0, perimeter = 0;
      while(!q.empty()) {
        pii cur = q.front();
        q.pop();
        if(visited[cur.first][cur.second]) continue;
        area++;
        perimeter += 4;
        visited[cur.first][cur.second] = true;

        for(pii dir : dirs) {
          pii adj = cur + dir;
          if(inBounds(adj) && grid[adj.first][adj.second]) {
            perimeter--;
            if(!visited[adj.first][adj.second])
              q.push(adj);
          }
        }
      }
      if(area >= maxArea) {
        if(area == maxArea)
          minPerimeter = min(minPerimeter, perimeter);
        else
          minPerimeter = perimeter;
        maxArea = area;
      }
    }
  }

  fout << maxArea << " " << minPerimeter << endl;

  fout.close();
  return 0;
}
