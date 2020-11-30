#include <iostream>
#include <queue>
#include <vector>
#define CHANGE(x) x = (x=='R') ? 'B' : 'R'

using namespace std;
int cnt, pairs, first, second, answer = 1;

void bfs(vector<int> graph[], vector<char> &color) {
  priority_queue<int> que;
  vector<int> mark(cnt+1, 0);
  que.push(first);
  color[first] = CHANGE(color[first]);

  while(!que.empty()) {
    int tmp = que.top();
    que.pop();
    mark[tmp] = 1;
    if(tmp == second) {
      cout << answer;
      exit(0);
    }
    for(int i=0; i<graph[tmp].size(); i++) {
      int next = graph[tmp][i];
      if(mark[next] == 0) {
        if(!(tmp== first && next == second)) {
          color[next] = CHANGE(color[next]);
          que.push(next);
          mark[next] = 1;
        }
      }
    }
  }
}

int main() {
  cin >> cnt >> pairs;
  vector<char> color(cnt+1, 'R');
  vector<int> graph[cnt+1];

  for(int i=0; i<pairs; i++) {
    cin >> first >> second;
    graph[first].push_back(second);
    graph[second].push_back(first);
    if(color[first] == color[second]) {
      bfs(graph, color);
    }
    answer++;
  }
  return 0;
}
