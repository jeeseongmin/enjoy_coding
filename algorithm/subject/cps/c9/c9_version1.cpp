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
  // cout << "(x,y)" << endl;
  // for(int i=0; i<persons; i++) {
  //   printf("(%d, %d)\n",score[i].first, score[i].second);
  // }
  // cout << endl;

  for(int p=0; p<persons-1; p++) {
    y = score[p].second;
    // printf("pivot : (%d, %d)\n",score[p].first,score[p].second);
    for(int j=p+1; j<persons; j++) {
      _y = score[j].second;
      // printf("check : (%d, %d)\n",score[j].first,score[j].second);
      if(y > _y) {
        adj_list[p].push_back(j);
        adj_list[j].push_back(p);
      }
    }
    // cout << endl;
  }

  // for(int i=0; i<persons; i++) {
  //   printf("adj_list[%d](size : %d) : ",i, adj_list[i].size());
  //   for(int j=0; j<adj_list[i].size(); j++) {
  //     printf("%d ",adj_list[i][j]);
  //   }
  //   cout << endl;
  // }
  // cout << endl;

  for(int i=0; i<persons; i++) {
    queue<int> q;
    if(adj_list[i].size() == 0) {
      // printf("group element : %d\n", i);
      answer++;
    }
    else if(adj_list[i].size() != 0 && check[i] == 0) {
      // printf("group element : ");
      q.push(i);
      while(!q.empty()) {
        int tmp = q.front();
        check[tmp] = 1;
        // printf("%d ", tmp);
        q.pop();
        for(int j=0; j<adj_list[tmp].size(); j++) {
          if(check[adj_list[i][j]] == 0) {
            q.push(adj_list[i][j]);
          }
        }
      }
      answer++;
      // cout<< endl;
    }
  }
  printf("%d",answer);
}
