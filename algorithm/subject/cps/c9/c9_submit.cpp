#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int main() {
  int persons, y, _y, answer=0;
  cin >> persons;
  vector<pair<int,int>> score(persons, {0,0});
  vector<int> adj_list[persons];
  vector<int> check(persons ,0);

  for(int i=0; i<persons; i++) {
    cin >> score[i].first >> score[i].second;
  }

  sort(score.begin(), score.end());

  for(int p=0; p<persons-1; p++) {
    y = score[p].second;
    for(int j=p+1; j<persons; j++) {
      _y = score[j].second;
      if(y > _y) {
        adj_list[p].push_back(j);
        adj_list[j].push_back(p);
      }
    }
  }
  for(int i=0; i<persons; i++) {
    queue<int> q;
    if(adj_list[i].size() == 0) {
      answer++;
    }
    else if(adj_list[i].size() != 0 && check[i] == 0) {
      q.push(i);
      while(!q.empty()) {
        int tmp = q.front();
        check[tmp] = 1;
        q.pop();
        for(int j=0; j<adj_list[tmp].size(); j++) {
          if(check[adj_list[tmp][j]] == 0) {
            q.push(adj_list[tmp][j]);
          }
        }
      }
      answer++;
    }
  }
  printf("%d",answer);
}
