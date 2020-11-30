#include <iostream>
#include <vector>
#include <cmath>
#include <unordered_map>

inline size_t key(int i, int j) {return (size_t) i << 32 | (unsigned int) j;}
using namespace std;

int x, y, _x, _y, check_x, check_y, num, answer=0, even=0, odd=0;
vector<int> mark;
vector<int> adj[50000];

void bfs(int key, int depth) {
  if(adj[key].size() == 0) return ;
  if(mark[key] == 0) {
    if(depth == 1) odd++;
    else even++;
    mark[key] = 1;
    int next_depth = (depth == 1) ? 2 : 1;
    for(int i=0; i<adj[key].size(); i++) {
      bfs(adj[key][i], next_depth);
    }
  }
}

int main() {
  cin >> num;
  unordered_map<size_t, int> point;
  for(int i=0; i<num; i++) {
    cin >> x >> y;
    for(int _x=-5; _x<=5; _x++) {
      for(int _y=-5; _y<=5; _y++) {
        check_x = x +_x;
        check_y = y +_y;
        if(point.find(key(check_x, check_y)) != point.end()) {
          if(sqrt(pow(check_x-x, 2) + pow(check_y-y, 2)) <= 5) {
            adj[i].push_back(point[key(check_x, check_y)]);
            adj[point[key(check_x, check_y)]].push_back(i);
          }
        }
      }
    }
    point[key(x,y)] = i;
  }

  mark.assign(num,0);
  for(int i=0; i<num; i++) {
    odd = 0, even=0;
    if(mark[i]==0 && adj[i].size() != 0) {
      bfs(i, 1);
      answer += (even>odd) ? odd : even;
    }
  }
  cout << answer << endl;
}
